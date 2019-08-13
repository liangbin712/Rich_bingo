#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<ifaddrs.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include"httplib.h"
#include<boost/filesystem.hpp>
#include<ostream>
using namespace httplib;
namespace bf = boost::filesystem;
#define SHARED_PATH "Shared"
class P2P{
  public:
    static void PairHandler(const Request &req,Response &rsp)
    {
      std::cerr << "recv a hostpair request\n";
      rsp.status = 200;
    }
    static void ListHandler(const Request &req,Response &rsp) //设置boost内的内置迭代器，将（SHARED_PATH）作为文件的开头，
    {
      bf::directory_iterator item_begin(SHARED_PATH) ;
      bf::directory_iterator item_end;
      std::stringstream body;
    //  body << "</body></html>";
      for(;item_begin != item_end;++item_begin)   //对共享文件夹内的文件进行迭代，先将文件的.path路径从文件迭代器中取出
      {
        if(bf::is_directory(item_begin->status()))
          continue;
        bf::path path = item_begin->path();
        std::string name = path.filename().string();//再将.path结构体中包含信息.filename转换成name。
        rsp.body +=name+"\n";
      //  body << "<h4><a href = '/list/"<<name<<"'>";//href将文件搞成超链接属性
       // body << name;
      //  body <<"</a></h4>";
      }
      //body << "</body></html>";
     // rsp.body = body.str();//给响应报文传body；
      rsp.set_header("Content-Type","text/html");//文本类型html
      rsp.status = 200;
    }
    static void DownLoadHandler(const Request &req,Response &rsp)
    {
      bf::path path(req.path.c_str());                 //使用boost库的文件系统中的路径用客户端请求路径，
      std::string mid = SHARED_PATH;
      mid += "/";
      std::string name = mid+ path.filename().string();
      if(!(bf::exists(name)))
      {
        rsp.status = 404;
        return;
      }
      if(bf::is_directory(name))
      {
        rsp.status = 403;
        return;
      }
      std::ifstream file(name.c_str(),std::ios::binary); //把文件名化为二进制形式打开文件
      if(!file.is_open())
      {
        std::cerr <<"open file" <<name<< "failed\n";
        rsp.status = 404;
        return;
      }
      int64_t fsize = bf::file_size(name);
      rsp.body.resize(fsize);//响应body此时需要扩容大小为传输文件的大小
      file.read(&rsp.body[0],fsize);  //然后再写入到响应body中
      if(!file.good())
      {
        std::cerr << "read file"<<name<<"failed\n";
        rsp.status = 500;//服务器内部错误
        return;
      }
      file.close();
      rsp.status = 200;
      rsp.set_header("Content-Type","application/ocet-stream");
    }
  private:
    Server _server;
  public:
    P2P(){
      //判断共享目录，若不存在，则创建
      if(!bf::exists(SHARED_PATH))
      {
        bf::create_directory(SHARED_PATH);
      }
    }
    bool Start(uint16_t port)
    {
      _server.Get("/hostpair",PairHandler);
      _server.Get("/list",ListHandler);
      _server.Get("/list/(.*)",DownLoadHandler);
      _server.listen("0.0.0.0",port);
      return true;
    }
};
int main(){
  P2P a;
  a.Start(9000);
  return 0;
}
