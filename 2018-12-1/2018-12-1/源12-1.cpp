#include <iostream>
using namespace std;
// struct student
// {
// 	int idNumber;
// 	char name[15];
// 	int age;
// 	char department[20];
// 	float gpa;
// };
// /*void display(student arg);*///�ṹ��Ϊ����
// void display(student arg)
// {
// 	cout << "ѧ��: " << arg.idNumber << "������" << arg.name << "���䣺" << arg.age << "Ժϵ��" << arg.department <<
// 		"�ɼ���" << arg.gpa << endl;
// 	cout << "arg.name�ĵ�ַ" << &arg.name << endl;
// 	for (int i = 0; i < 6;i++)
// 	{
// 		arg.name[i] = 'A';
// 	}
// 	arg.age++;
// 	arg.gpa = 99.9f;
// }
// int main()
// {
// 	student s1 = { 3039, "tomo", 20, "ComputerScience", 92.5 };//����s1������s1��ʼ����
// 	cout << "s1.name�ĵ�ַ" << &s1.name << endl;
// 	display(s1);
// 	cout << "�βα��޸ĺ󡭡�" << endl;
// 	display(s1);
// 	system("pause");
// }
// struct student
// {
// 	int idNumber;
// 	char name[15];
// 	int age;
// 	char department[20];
// 	float gpa;
// };
// void display(student arg)
// {
// 	cout << "ѧ��: " << arg.idNumber << "������" << arg.name << "���䣺" << arg.age << "Ժϵ��" << arg.department <<
// 		"�ɼ���" << arg.gpa << endl;
// }
// student initial()
// {
// 	student s1 = { 3039, "tomo", 20, "ComputerScience", 92.5 };
// 	return s1;
// }
int main()
{
	int c = 5;
	int a=4128244;
	int &b = a;
	int b = 3;
	cout << &c <<" "<<b;
	system("pause");
}