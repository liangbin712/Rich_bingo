#include<iostream>
#include<string>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<netinet/ip.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
using std::cin;
using std::cout;
using std::endl;
class Udpsocket{
  public:
  bool Socket()
    {
      _socket = socket(AF_INET,SOCK_DGRAM,17);
      if(_socket == -1)
      {
        perror("create socket error\n");
        return false;
      }
      return true;
    }
  bool Bind(std::string &ip,uint16_t port)
  {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    socklen_t len = sizeof(sockaddr_in);
    bind(_socket,(struct sockaddr*)&addr,len);
    return true;
  }
  bool Recv(std::string &buf,struct sockaddr_in *addr)
  {
    socklen_t len = sizeof( sockaddr_in);
    char tmp[1023] = {0};
    int ret = recvfrom(_socket,tmp,1024,0,(struct sockaddr *)addr,&len);
    if(ret == -1)
    {
      perror("receive error\n");
      return false;
    }
   buf.assign(tmp,ret);
   return true;
  }
  bool Sendto(std::string &buf,struct sockaddr_in *addr)
  {
    socklen_t len = sizeof(sockaddr_in);
    //int sendto(int s, const void *msg, size_t len, int flags, const struct sockaddr *to, socklen_t tolen);
    int ret = sendto(_socket,buf.c_str(),buf.size(),0,(struct sockaddr *)addr,len);
    if(ret == -1)
    {
      perror("send error\n");
      return false;
    }
    return true;
  }
  bool Close()
  {
    close(_socket);
    return true;
  }
  private:
   int _socket;
};
