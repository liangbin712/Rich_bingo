#include <iostream>
using namespace std;
struct node    //������ṹ����
{
	char data;   //���ڴ���ַ�����
	node *next;   //����ָ����һ����㣨��̽�㣩
};
node * Create();          //���������������ر�ͷ
void Showlist(node *head);   //��������ĺ���������Ϊ��ͷ
node * Search(node *head, char keyWord);
void Insert(node *&head, char keyWord, char newdata);
int main()
{
	while (1)
	{
		node *head;
		head = Create();    //�Ѵ����õ������ͷ
		Showlist(head);      //��ͷ��������
		char keyWord,newdata;
		cout << "������Ҫ���ҵ�����" << endl;
		cin >> keyWord;
		cout << "������Ҫ�����������" << endl;
		cin >> newdata;
		Insert(*&head, keyWord, newdata);
		/*Search(head, keyWord);
		cout << Search(head, keyWord)->data << endl;*/
		system("pause");
	}
}
node *Create()
{
	node *head = NULL;    //��ͷָ�룬һ��ʼû���κν�㣬����ΪNULL
	node *pEnd = head;    //��Ϊָ�룬һ��ʼû���κν�㣬����ָ���ͷ
	node *pS;             //�����½��ʱʹ�õ�ָ��
	char temp;            //���ڴ�ŴӼ���������ַ�
	cout << "�������ַ�������#��β" << endl;
	do                        //ѭ����������һ��
	{
		cin >> temp;
		if (temp != '#')     //�����ַ�������#�ţ������½��
		{
			pS = new node;    //�����½��
			pS->data = temp;   //�½�������Ϊ temp
			pS->next = NULL;  //�½���ʱ��Ϊ��β������nextΪNULL
			if (head == NULL)  //�������û���κν�����
			{
				head = pS;   //���ͷָ��ָ���½��
			}
			else      //��������˽��
			{
				pEnd->next = pS;  // ������½�������ڱ�β
			}
			pEnd = pS;     //����½���Ϊ���µı�β
		}
	} while (temp != '#');
	return head;
}
void Showlist(node *head) //��������ĺ���������Ϊ��ͷ
{
	node *pRead = head;   //����ָ��һ��ʼָ���ͷ
	cout << "�����е�����Ϊ" << endl;
	while (pRead!=NULL)  //������ָ�����ʱ����û�е����β֮��
	{
		cout << pRead->data; //�����������ַ���
		pRead = pRead->next;//����ָ������ƶ�
	}
	cout << endl;
}
//���ؽ���ָ��
node * Search(node *head, char keyWord)//����Ĳ�ѯ
{
	node *pRead = head;   //��ָ���ͷ��ʼ��
	while (pRead != NULL)   //��ָ�����������NULL�Ϳ�ʼ���������ң���Ϊ����ĩ�˲Ż���NULL
	{
		if (pRead->data == keyWord)   //�������ҪѰ�ҵ������������������ͬ
		{
			return pRead;    //�򷵻ص�ǰָ��
		}
	}
	return NULL;          //���н�㶼��ƥ�䣬����NULL
}
//������
void Insert(node *&head, char keyWord, char newdata)  //����keyword�ַ��������µĽ��
{
	node *newnode = new node; //����һ���½��
	newnode->data = newdata;  //���½�������newdata�����½��
	node *pGuard = Search(head, keyWord);  //pGuard�ǲ���λ��ǰ�Ľ��ָ��
	if (head == NULL|| pGuard == NULL)    //�������û�н������Ҳ����ؼ��ֽ��
	{                                    //���뵽��ͷλ��
		newnode->next = head;      //����
		head = newnode;             //���
	}
	else
	{                     //�ҵ��Ļ����뵽pGuard֮��
		newnode->next = pGuard->next;//����
		pGuard->next = newnode; //���  
	}
	Showlist(head);
}
