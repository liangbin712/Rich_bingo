#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define PERSON_INFO_MAX_SIZE 1000
typedef struct PersonInfo {
  char name[1024];
  char phone[12];
  char sex[2];
  char address[100];
  char age[3];
}PersonInfo;
typedef struct AddressBook{
  PersonInfo *infos;
  int capacity;
  int size; 
}AddressBook;
AddressBook g_address_book;
void Init(AddressBook *addr_book){
  assert(addr_book != NULL);
  //对 addr_book 初始化
  //size控制了结构体数组中有效元素的区间范围，只要设为0,无论数组中存的是啥都是没有意义的，不
  //太需要把数组元素都设为某些特定值。
  addr_book->size = 0;
  addr_book->capacity = 10;
  addr_book->infos = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
}
void Realloc(AddressBook *addr_book)
{ 
  assert(addr_book != NULL);
//  1.修改capacity的取值
    addr_book->capacity *= 2;
//  2.申请一个更大的内存
    AddressBook * old = 0;
    old->infos = addr_book->infos;
    addr_book->infos = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);  
//  3.把原有内存复制过来
    for(int i = 0;i < addr_book->size;i++)
    {
    addr_book->infos[i] = old->infos[i];
    }
//  4.释放内存
    free(old->infos);
}
void AddPersonInfo(AddressBook * addr_book){
  assert(addr_book != NULL);
  printf("请插入一个联系人！\n");
  if(addr_book->size >= addr_book->capacity){
    printf("当前通讯录已满,进行扩容！\n");
    Realloc(addr_book);
  }
  //每次把这个联系人放到有效数组的最后一个元素上
  //此处不能取一个结构体变量，只能取结构体指针 
  //如果取的是结构体变量，该变量相当于数组中对应元素的副本
  //此时修改结构体变量只是对副本的修改，没有影响到原来的数组
  //PersonInfo p = &addr_book -> infos[addr_book->size];
  PersonInfo* p = &addr_book->infos[addr_book->size];
  printf("请输入联系人姓名:");
  scanf("%s",p->name);
  printf("请输入新增的联系人电话:");
  scanf("%s",p->phone);
  printf("请输入联系人性别:");
  scanf("%s",p->sex);
  printf("请输入新增的联系人住址:");
  scanf("%s",p->address);
  printf("请输入新增的联系人年龄:");
  scanf("%s",p->age);
  printf("插入联系人成功！"); 
  //新增完成后，需要更新 size 
  ++addr_book->size;
}
void DelPersonInfo(AddressBook * addr_book){
  assert(addr_book != NULL);
  printf("删除联系人！\n");
  printf("请输入要删除的联系人序号");
  int id = 0;
  scanf("%d",&id);
  if(id < 0 || id >= addr_book->size)
  {
    printf("您输入的序号有误！删除失败！\n");
    return;
  }
  PersonInfo* p = &addr_book->infos[id];
  printf("您要删除的联系人为[%d] %s,确认请输入Y：",id,p->name);
  char cmd[1024] = {0};
  scanf("%s",cmd);
  if(strcmp(cmd,"Y") != 0)
  {
    printf("删除操作已经取消！\n");
    return;
  }
  PersonInfo* from = &addr_book->infos[addr_book->size - 1];
  PersonInfo* to = p;
  *to = *from;
  --addr_book->size;
  printf("删除成功！\n");
}
void ModifyPersonInfo(AddressBook * addr_book){
  int id = 0;
  scanf("%d",&id);
  if(id < 0 || id >= addr_book->size)
  {
    printf("您输入的序号错误!\n");
    return;
  }
  PersonInfo* p = &addr_book->infos[id]; 
  char input[1024] = {0};
  printf("请输入要修改的姓名：");
  scanf("%s",input);
  if(strcmp(input, "#") != 0)
  {
    strcpy(p->name, input);
  }
  printf("请输入要修改的电话：");
  scanf("%s",input);
  if(strcmp(input, "#") != 0)
  {
    strcat(p->phone,input);
  }
  printf("请输入要修改的性别：");
  scanf("%s",input);
  if(strcmp(input, "#") != 0)
  {
    strcat(p->sex,input);
  }
  printf("请输入要修改的住址：");
  scanf("%s",input);
  if(strcmp(input, "#") != 0)
  {
    strcpy(p->address, input);
  }
  printf("请输入要修改的年龄：");
  scanf("%s",input);
  if(strcmp(input, "#") != 0)
  {
    strcpy(p->age, input);
  }
  printf("修改成功!");
}
void FindPersonInfo(AddressBook * addr_book){
  assert(addr_book != NULL);
  printf("开始进行查找！\n");
  printf("请输入要查找的姓名：");
  char name[1024] = {0};
  scanf("%s",name);
  int count = 0;
  for(int i = 0;i < addr_book->size;++i)
  {
    PersonInfo *p = &addr_book->infos[i];
    if(strcmp(name, p->name) == 0)
    {
      printf("[%d] %s\t%s\t%s\n%s\t%s",i ,p->name, p->phone,p->sex,p->address,p->age);
      ++count;
    }
  }
  printf("查找完毕！共找到%d\n条记录",count);
}
void SortPersonInfo(AddressBook * addr_book){
  assert(addr_book != NULL);
  printf("显示所有联系人!\n");
  for(int i = 0;i < addr_book->size;++i)
  {
    for(int j = 0;j < 1024;++j)
    {
      PersonInfo *oppo = &addr_book->infos[i];
      if(oppo->name[j] < oppo->name[j+1])
      {
        break;
      }
      else if(oppo->name[i] > oppo->name[i+1])
      {
        char temp;
        temp = oppo->name[i];
        oppo->name[i] = oppo->name[i+1];
        oppo->name[i+1] = temp;
        break;
      }
      else if(oppo->name[i] == oppo->name[i+1])
      {
         continue;
      }
    }
  }
  for(int i = 0; i < addr_book->size; ++i)
  {
    PersonInfo * p = &addr_book->infos[i]; 
    printf("[%d] %s  %s  %s\n%s %s\n",i ,p->name, p->phone,p->sex,p->address,p->age);
  }
  printf("共显示了 %d 条数据\n",addr_book->size); 
} 
void PrintAllPersonInfo(AddressBook * addr_book){
  assert(addr_book != NULL);
  printf("显示所有联系人！\n");
  for(int i = 0; i < addr_book->size; ++i)
  {
    PersonInfo * p = &addr_book->infos[i]; 
     printf("[%d] %s  %s  %s\n%s %s\n",i ,p->name, p->phone,p->sex,p->address,p->age);
  }
  printf("共显示了 %d 条数据\n",addr_book->size); 
}
void ClearAllPersonInfo(AddressBook * addr_book){
  assert(addr_book != NULL);
  printf("清空所有记录！\n");
  printf("您确认要清空所有的记录吗？输入 Y 表示确认\n");
  char cmd[1024] = {0};
  scanf("%s",cmd);
  if(strcmp(cmd, "Y") != 0)
  {
    printf("清空操作取消！");
    return;
  }
  addr_book->size = 0;
  printf("清空操作成功！");
}
int Menu()
{
  printf("======================\n");
  printf("1.新增\n");
  printf("2.删除\n"); 
  printf("3.修改\n");
  printf("4.查找\n");
  printf("5.排序\n");
  printf("6.显示全部\n");
  printf("7.清空全部\n");
  printf("0.退出\n");
  printf("======================\n");
  printf("请输入你的选择\n");
  int choice = 0;
  scanf("%d",&choice);
  return choice;
}
int main()
{
  //1.对通讯录进行初始化
  Init(&g_address_book);
  typedef  void (*pfunc_t)(AddressBook*);
  pfunc_t table[] = {
    AddPersonInfo,
    DelPersonInfo,
    ModifyPersonInfo,
    FindPersonInfo,
    SortPersonInfo,
    PrintAllPersonInfo,
    ClearAllPersonInfo
  };
  while(1){
    int choice = Menu();
    if(choice < 0 || choice >(int)(sizeof(table)/sizeof(table[0])))
    {
      printf("你的输入有误！\n");
      continue;
    }
    if(choice == 0)
    {
      printf("goodbye!\n");
      break;
    }
    table[choice - 1](&g_address_book);
  }
    return 0;
}
