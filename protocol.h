#ifndef PROTOCOL_H_INCLUDED
#define PROTOCOL_H_INCLUDED

struct icmp {
    unsigned char type;        //类型
    unsigned char code;        //代码
    unsigned short checksum;   //校验和
    unsigned short id;         //标识符
    unsigned short sequence;   //序号
    struct timeval timestamp;  //时间戳
}

struct ip {
    unsigned char version:4;  //版本
    unsigned char hlen:4;      //首部长度
    unsigned char tos;        //服务类型
    unsigned short len;       //总长度
    unsigned short id;        //标识符
    unsigned short offest;    //标志和片偏移
    unsigned char ttl;        //生存时间
    unsigned char protocol;   //协议
    unsigned short checksum;  //校验和
    struct in_addr ipsrc;     //32位源ip地址
    struct in_addr ipdst;     //32位目的ip地址
}

#endif // PROTOCOL_H_INCLUDED
