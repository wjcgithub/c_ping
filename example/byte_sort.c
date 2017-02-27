#include <stdio.h>
#include <arpa/inet.h>

int main(void)
{
    //将点分十进制字符串格式表示的IP地址转换成32位大端序整型。  inet_addr
    int a = 0x403214;
    printf("%d\n", a);
    char *addr1 = "1.2.3.4";
    char *addr2 = "192.168.1.1";

    in_addr_t data;

    data = inet_addr(addr1);
    printf("%s -> %#lx \n", addr1, (long)data);

    data = inet_addr(addr2);
    printf("%s -> %#lx \n", addr2, (long)data);

    return 0;
}
