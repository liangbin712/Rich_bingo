#include"udpsocket.hpp" 
#define CHECK_IN(q) if((q) == false) {return -1;}
int main(int argc ,char *argv[])
{
  if(argc != 3)
  {
    perror("sdsdada\n");
  }
  std::string ip;
  ip =argv[1];
  uint16_t port = atoi(argv[2]);
  Udpsocket socket;
  CHECK_IN(socket.Socket());
  CHECK_IN(socket.Bind(ip,port));
  while(1)
  {
    std::string buf;
    struct sockaddr_in cli_addr;
    CHECK_IN(socket.Recv(buf,&cli_addr));
    cout <<"client say:"<<buf<<std::endl; 
    cout <<"server say:";
    fflush(stdout);
    std::cin>>buf;
    CHECK_IN(socket.Sendto(buf,&cli_addr));
  }
  socket.Close();
}
