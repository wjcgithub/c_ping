#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

int main(void) {
    //将32位大端序整型格式IP地址转换为点分十进制格式  inet_ntoa
    struct in_addr addr1, addr2;
    char *str1, *str2;

    addr1.s_addr = htonl(0x1020304);
    addr2.s_addr = htonl(0xc0a80101);

    str1 = inet_ntoa(addr1);
    str2 = inet_ntoa(addr2);

    printf("%#lx -> %s \n", (long)addr1.s_addr, str1);
    printf("%#lx -> %s \n", (long)addr2.s_addr, str2);

    return 0;
}
