#include <iostream>
using namespace std;
//ö������
enum day{Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
void nextday(day &D);
void display(day D);
int main()
{
	day today = Sunday;
	for (int i = 0; i < 7;i++)
	{
		cout << "��today�����������Ϊ" << today << endl;
		display(today);
		nextday(today);
	}
	system("pause");
}

void nextday(day &D)
{
	switch (D)
	{
	case Sunday:
		D = Monday;
		break;
	case Monday:
		D = Tuesday;
		break;
	case Tuesday:
		D = Wednesday;
		break;
	case Wednesday:
		D = Thursday;
		break;
	case Thursday:
		D = Friday;
		break;
	case Friday:
		D = Saturday;
		break;
	case Saturday:
		D = Sunday;
	}
}
void display(day D)
{
	switch (D)
	{
	case Sunday:
		cout << "������" << endl;
		break;
	case Monday:
		cout << "����һ" << endl;
		break;
	case Tuesday:
		cout << "���ڶ�" << endl;
		break;
	case Wednesday:
		cout << "������" << endl;
		break;
	case Thursday:
		cout << "������" << endl;
		break;
	case Friday:
		cout << "������" << endl;
		break;
	case Saturday:
		cout << "������" << endl;
		break;
	}
}
//�ṹ����
struct student
{
	int  idNumber;
	char  name[15];
	int  age;
	char  department[20];
	float gpa;
};
//���������µ���Ϊstudent�������͡�
int main()
{
	student s1, s2;
	cout << "������ѧ�ţ�";
	cin >> s1.idNumber;
	cout << "����������";
	cin >> s1.name;
	cout << "��������";
	cin >> s1.age;
	cout << "����Ժϵ";
	cin >> s1.department;
	cout << "����ɼ�";
	cin >> s1.gpa;
	cout << "ѧ��s1��Ϣ:" << endl << "ѧ�ţ�" << s1.idNumber << "������" << s1.name << "���䣺" << s1.age
		<< endl << "Ժϵ: " << s1.department << "�ɼ�" << s1.gpa << endl;
	s2 = s1;
	cout << "ѧ��s2��Ϣ:" << endl << "ѧ�ţ�" << s2.idNumber << "������" << s2.name << "���䣺" << s2.age
		<< endl << "Ժϵ: " << s2.department << "�ɼ�" << s2.gpa << endl;
	system("pause");
}