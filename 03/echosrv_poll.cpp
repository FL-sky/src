#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <poll.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <vector>
#include <iostream>

#define ERR_EXIT(m)         \
	do                      \
	{                       \
		perror(m);          \
		exit(EXIT_FAILURE); \
	} while (0)

typedef std::vector<struct pollfd>
	PollFdList;

int main(void)
{
	///https://blog.csdn.net/xinguan1267/article/details/17357093
	signal(SIGPIPE, SIG_IGN);
	signal(SIGCHLD, SIG_IGN); //,ignore

	//int idlefd = open("/dev/null", O_RDONLY | O_CLOEXEC);
	int listenfd;

	//if ((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	// 	/*  创建一个socket  */
	// int socket(int family, int type, int protocol);

	// /*  参数说明  */
	// // domain：使用哪个底层协议族
	// // type：指定服务类型
	// // protocol：使用哪个协议
	// https://www.cnblogs.com/xzxl/p/9562427.html
	if ((listenfd = socket(PF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP)) < 0)
	{
		//PF是protocol family，AF是address family	PF_INET, AF_INET： Ipv4网络协议；
		//SOCK_STREAM提供面向连接的稳定数据传输，即TCP协议。SOCK_STREAM应用在C语言socket编程中，在进行网络连接前，需要用socket函数向系统申请一个通信端口。

		ERR_EXIT("socket");
	}
	// 	1. type参数指定的服务类型有SOCK_STREAM服务（流服务）和SOCK_DGRAM服务（数据报服务）

	// 对TCP/IP协议族而言，其值取SOCK_STREAM表示传输层使用TCP协议，取SOCK_DGRAM表示传输层使用UDP协议。
	// 补：type参数可以接受上述服务类型与下面两个重要的标志相与的值：SOCK_NONBLOCK和SOCK_CLOEXEC。它们分别表示将新创建的socket设为非阻塞的，以及用fork调用创建子进程时在子进程中关闭该socket。

	// 2. protocol参数一般都设置为0，表示使用默认协议

	// 因为它是在前两个参数构成的协议集合下，再选择一个具体的协议。而前两个参数已经完全决定了它的值。
	// 在UNIX/Linux下，所有东西都是文件，socket也不例外，它就是可读、可写、可控制、可关闭的文件描述符。

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5188);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	int on = 1;
	/// setsockopt https://blog.csdn.net/u010144805/article/details/78579771
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
		ERR_EXIT("setsockopt");

	if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		ERR_EXIT("bind");
	if (listen(listenfd, SOMAXCONN) < 0)
		ERR_EXIT("listen");

	struct pollfd pfd;
	pfd.fd = listenfd;
	pfd.events = POLLIN; // 例如fds[0].events = POLLIN; /*将测试条件设置成普通或优先级带数据可读*/ 关注POLLIN事件
	/*
	常量
	说明
	POLLIN // There is data to read.
	普通或优先级带数据可读
	POLLRDNORM
	普通数据可读
	POLLRDBAND
	优先级带数据可读
	POLLPRI
	高优先级数据可读
	POLLOUT
	普通数据可写
	POLLWRNORM
	普通数据可写
	POLLWRBAND
	优先级带数据可写
	POLLERR
	发生错误
	POLLHUP
	发生挂起
	POLLNVAL
	描述字不是一个打开的文件
*/
	PollFdList pollfds;
	pollfds.push_back(pfd);

	int nready;

	struct sockaddr_in peeraddr;
	socklen_t peerlen;
	int connfd;

	while (1)
	{
		nready = poll(&*pollfds.begin(), pollfds.size(), -1);
		if (nready == -1)
		{
			if (errno == EINTR)
				continue;

			ERR_EXIT("poll");
		}
		if (nready == 0) // nothing happended
			continue;

		if (pollfds[0].revents & POLLIN)
		{
			peerlen = sizeof(peeraddr);
			connfd = accept4(listenfd, (struct sockaddr *)&peeraddr,
							 &peerlen, SOCK_NONBLOCK | SOCK_CLOEXEC);

			if (connfd == -1)
				ERR_EXIT("accept4");

			/*
			if (connfd == -1)
			{
				if (errno == EMFILE)
				{
					close(idlefd);
					idlefd = accept(listenfd, NULL, NULL);
					close(idlefd);
					idlefd = open("/dev/null", O_RDONLY | O_CLOEXEC);
					continue;
				}
				else
					ERR_EXIT("accept4");
			}
*/

			pfd.fd = connfd;
			pfd.events = POLLIN;
			pfd.revents = 0;
			pollfds.push_back(pfd);
			--nready;

			// 连接成功
			std::cout << "ip=" << inet_ntoa(peeraddr.sin_addr) << " port=" << ntohs(peeraddr.sin_port) << std::endl;
			if (nready == 0)
				continue;
		}

		//std::cout<<pollfds.size()<<std::endl;
		//std::cout<<nready<<std::endl;
		for (PollFdList::iterator it = pollfds.begin() + 1; ////跳过监听套接字
			 it != pollfds.end() && nready > 0; ++it)
		{
			if (it->revents & POLLIN)
			{
				--nready;
				connfd = it->fd;
				char buf[1024] = {0};
				int ret = read(connfd, buf, 1024);
				if (ret == -1)
					ERR_EXIT("read");
				if (ret == 0)
				{
					std::cout << "client close" << std::endl;
					it = pollfds.erase(it); // 返回it的下一个：An iterator pointing to the next element (or end())
					--it;

					close(connfd);
					continue;
				}

				std::cout << buf;
				write(connfd, buf, strlen(buf));
			}
		}
	}

	return 0;
}
