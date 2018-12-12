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
void Insert(node *&head, char keyWord);
void Delete(node *&head, char keyWord);
void Destroy(node * &head);
int main()
{
	node *head;
	head = Create();    //�Ѵ����õ������ͷ
	Showlist(head);      //��ͷ��������
	char keyWord, deletep;
	cout << "������Ҫ���ҵ�����" << endl;
	cin >> keyWord;
	Insert(head, keyWord);
	Showlist(head);
	cout << "������Ҫɾ����������" << endl;
	cin >> deletep;
	Delete(head, deletep);
	Showlist(head);
	cout << "�Ƿ�Ҫ�������,��ѡ0�������ⰴ" << endl;
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
	while (pRead != NULL)  //������ָ�����ʱ����û�е����β֮��
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
		pRead = pRead->next;//���ݲ�ƥ�䣬pReadָ������ƶ���׼��������һ����㡣
	}
	return NULL;          //���н�㶼��ƥ�䣬����NULL
}
//������
void Insert(node *&head, char keyWord)  //����keyword�ַ��������µĽ��
{
	Search(head, keyWord);
	while (Search(head, keyWord) == NULL)
	{
		cout << "û���ҵ���Ӧ���" << endl;
		cout << "����������Ҫ���ҵ�����" << endl;
		cin >> keyWord;
	}
	char newdata;
	cout << "������Ҫ�����������" << endl;
	cin >> newdata;
	node *newnode = new node; //����һ���½��
	newnode->data = newdata;  //���½�������newdata�����½��
	node *pGuard = Search(head, keyWord);  //pGuard�ǲ���λ��ǰ�Ľ��ָ��
	if (head == NULL || pGuard == NULL)    //�������û�н������Ҳ����ؼ��ֽ��
	{                                    //���뵽��ͷλ��
		newnode->next = head;      //����
		head = newnode;             //���
	}
	else
	{                     //�ҵ��Ļ����뵽pGuard֮��
		newnode->next = pGuard->next;//����
		pGuard->next = newnode; //���  
	}
}
//�����ɾ��
void Delete(node *&head, char keyWord)
{
	if (head != NULL)//������û�н��ʱ ,��ֱ�����
	{
		node *p;  //����һ��ɾ��ָ��
		node *pGuard = head; //��ʼ��ɨ��ָ��
		//ɾ�������Ϊ�������
		//1.��������ͷ���
		//2.�����㲻��ͷ���
		if (head->data == keyWord)
		{
			p = head;   //ͷ�Ǵ�ɾ���Ľ��
			head = head->next;  //����
			delete p;      //��ɾ
			cout << "��ɾ������" << keyWord << endl;
			return;
		}
		else
		{
			while (pGuard->next != NULL) //��û��ɨ�赽��βʱ
			{
				if (pGuard->next->data == keyWord)//���pGuard�����������ݷ��Ϲؼ���
				{
					p = pGuard->next;   //pGuard����Ľ���Ǵ�ɾ���Ľ��
					pGuard->next = p->next;  //����
					delete p;   //��ɾ
					cout << "��ɾ������" << keyWord << endl;
					return;
				}
				pGuard = pGuard->next;//ָ�����
			}
		}
	}
}
void Destroy(node * &head)   // ��������
{
	node *p;   //����һ��ɾ��ָ��
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
	cout << "The link has been deleted!" << endl;
}