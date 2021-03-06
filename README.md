## 用到的知识点
1. tcp/ip协议介绍
2. ping命令原理
3. 套接字有关函数使用

## ping实现原理
ping 使用的是ICMP协议
ICMP 是（Internet Control Message Protocol）Internet 控制报文协议。它是 TCP/IP 协议族的一个子协议，用于在 IP 主机、路由器之间传递控制消息。
ICMP是IP协议不可分割的一部分,ICMP是属于网络层的一个协议.

## ping 命令的机制
回显请求和回显应答消息。具体表现是向网络上的另一个主机系统发送 ICMP 报文，如果指定系统得到了报文，它将把报文一模一样地传回给发送者。

## 控制消息有
1. 目的不可达消息
2. 超时信息
3. 重定向消息
4. 时间戳请求和时间戳响应消息
5. 回显请求和回显应答消息

## 回显请求和回显应答消息 ICMP 报文格式
类型字段:
回显请求报文其中类型为 0，代码为 0。
回显应答报文其中类型为 8，代码为 0。

校验和字段：
包括数据在内的整个 ICMP 协议数据包的校验和，具体实现方法会在下面详细介绍。

标识符字段：
用于唯一标识 ICMP 报文，本项目使用程序的进程 id。因为如果同时在两个命令行终端执行 ping 命令的话，每个 ping 命令都会接收到所有的回显应答，所以需要根据标识符来判断回显应答是否应该接收。

序号字段：
ICMP 报文的序号。

数据字段：
也就是报文，本项目中我们将发送报文的时间戳放入数据字段，这样当接收到该报文应答的时候可以取出发送时间戳，将接收应答的时间戳减去发送时间戳就是报文往返时间（rtt）。提前预告一下，这里使用gettimeofday()API函数获取时间戳，详细介绍会在函数介绍部分说明。

## 函数介绍
1. `gettimeofday()` 精确存入当前时间
2. `inet_addr()` 转换点分十进制-->32位整形
3. `inet_ntoa()` 转换32位整形-->点分十进制
4. `gethostbyname()` 通过域名得到IP
5. `unsigned short htons(unsigned short)`
6. `unsigned short ntohs(unsigned short)`
7. `unsigned long  htonl(unsigned long)`
8. `unsigned long  ntohl(unsigned long)`

- 上面的函数非常简单，通过函数名就能知道它们的功能，htonl/htons 中的h代表主机（host）字节序，n代表网络（network）字节序，s指的是 short，l指的是 long（需要注意一下，linux 中 long 类型只占4个字节，跟int类型一样）。
