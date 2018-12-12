#include <iostream>
using namespace std;
struct node    //定义结点结构类型
{
	char data;   //用于存放字符数据
	node *next;   //用于指向下一个结点（后继结点）
};
node * Create();          //创建链表函数，返回表头
void Showlist(node *head);   //遍历链表的函数，参数为表头
node * Search(node *head, char keyWord);
void Insert(node *&head, char keyWord);
void Delete(node *&head, char keyWord);
void Destroy(node * &head);
int main()
{
	node *head;
	head = Create();    //把创建好的链表给头
	Showlist(head);      //把头给它遍历
	char keyWord, deletep;
	cout << "请输入要查找的数据" << endl;
	cin >> keyWord;
	Insert(head, keyWord);
	Showlist(head);
	cout << "请输入要删除结点的数据" << endl;
	cin >> deletep;
	Delete(head, deletep);
	Showlist(head);
	cout << "是否要清除链表,是选0，否任意按" << endl;
	int a;
	cin >> a;
	if (a < 0)
	{
		Destroy(head);
	}
	Showlist(head);
	system("pause");
}
node *Create()
{
	node *head = NULL;    //表头指针，一开始没有任何结点，所以为NULL
	node *pEnd = head;    //表为指针，一开始没有任何结点，所以指向表头
	node *pS;             //创建新结点时使用的指针
	char temp;            //用于存放从键盘输入的字符
	cout << "请输入字符串，以#结尾" << endl;
	do                        //循环至少运行一次
	{
		cin >> temp;
		if (temp != '#')     //输入字符串不是#号，则建立新结点
		{
			pS = new node;    //创建新结点
			pS->data = temp;   //新结点的数据为 temp
			pS->next = NULL;  //新结点此时成为表尾，所以next为NULL
			if (head == NULL)  //如果链表还没有任何结点存在
			{
				head = pS;   //则表头指针指向新结点
			}
			else      //链表存在了结点
			{
				pEnd->next = pS;  // 把这个新结点连接在表尾
			}
			pEnd = pS;     //这个新结点成为了新的表尾
		}
	} while (temp != '#');
	return head;
}
void Showlist(node *head) //遍历链表的函数，参数为表头
{
	node *pRead = head;   //访问指针一开始指向表头
	cout << "链表中的数据为" << endl;
	while (pRead != NULL)  //当访问指针存在时（即没有到达表尾之后）
	{
		cout << pRead->data; //输出链表代表字符串
		pRead = pRead->next;//访问指针向后移动
	}
	cout << endl;
}
//返回结点的指针
node * Search(node *head, char keyWord)//链表的查询
{
	node *pRead = head;   //读指针从头开始读
	while (pRead != NULL)   //读指针如果不等于NULL就开始从链表里找，因为链表末端才会是NULL
	{
		if (pRead->data == keyWord)   //如果与所要寻找的数据与链表的数据相同
		{
			return pRead;    //则返回当前指针
		}
		pRead = pRead->next;//数据不匹配，pRead指针向后移动，准备查找下一个结点。
	}
	return NULL;          //所有结点都不匹配，返回NULL
}
//插入结点
void Insert(node *&head, char keyWord)  //是在keyword字符处插入新的结点
{
	Search(head, keyWord);
	while (Search(head, keyWord) == NULL)
	{
		cout << "没有找到相应结点" << endl;
		cout << "请重新输入要查找的数据" << endl;
		cin >> keyWord;
	}
	char newdata;
	cout << "请输入要插入结点的数据" << endl;
	cin >> newdata;
	node *newnode = new node; //建立一个新结点
	newnode->data = newdata;  //把新结点的数据newdata传给新结点
	node *pGuard = Search(head, keyWord);  //pGuard是插入位置前的结点指针
	if (head == NULL || pGuard == NULL)    //如果链表没有结点或者找不到关键字结点
	{                                    //插入到表头位置
		newnode->next = head;      //先连
		head = newnode;             //后断
	}
	else
	{                     //找到的话插入到pGuard之后
		newnode->next = pGuard->next;//先连
		pGuard->next = newnode; //后断  
	}
}
//链表的删除
void Delete(node *&head, char keyWord)
{
	if (head != NULL)//当链表没有结点时 ,就直接输出
	{
		node *p;  //定义一个删除指针
		node *pGuard = head; //初始化扫描指针
		//删除链表分为两种情况
		//1.链表结点是头结点
		//2.链表结点不是头结点
		if (head->data == keyWord)
		{
			p = head;   //头是待删除的结点
			head = head->next;  //先连
			delete p;      //后删
			cout << "被删除的是" << keyWord << endl;
			return;
		}
		else
		{
			while (pGuard->next != NULL) //当没有扫描到结尾时
			{
				if (pGuard->next->data == keyWord)//如果pGuard后续结点的数据符合关键字
				{
					p = pGuard->next;   //pGuard后面的结点是待删除的结点
					pGuard->next = p->next;  //先连
					delete p;   //后删
					cout << "被删除的是" << keyWord << endl;
					return;
				}
				pGuard = pGuard->next;//指针后移
			}
		}
	}
}
void Destroy(node * &head)   // 链表的清除
{
	node *p;   //定义一个删除指针
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
	cout << "The link has been deleted!" << endl;
}