#include"udpsocket.hpp"
#define CHECK_IN(q) if((q) == false) {return -1;}
int main(int argc,char *argv[])
{
  if(argc != 3)
  {
    perror("cli error\n");
    return -1;
  }
  std::string ip;
  ip = argv[1];
  uint16_t port = atoi(argv[2]); 
  Udpsocket sock;
  CHECK_IN(sock.Socket());
  struct sockaddr_in srv_addr;
  srv_addr.sin_family = AF_INET;
  srv_addr.sin_port = htons(port);
  srv_addr.sin_addr.s_addr = inet_addr(ip.c_str());
  while(1)
  {
    std::string buf;
    cout<<"client say:";
    cin>>buf;
    fflush(stdout);
    CHECK_IN(sock.Sendto(buf,&srv_addr));
    CHECK_IN(sock.Recv(buf,&srv_addr));
    cout<<"server say:"<<buf<<endl;
  }
  sock.Close();
}
