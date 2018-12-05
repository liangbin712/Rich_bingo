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
// /*void display(student arg);*///结构作为参数
// void display(student arg)
// {
// 	cout << "学号: " << arg.idNumber << "姓名：" << arg.name << "年龄：" << arg.age << "院系：" << arg.department <<
// 		"成绩：" << arg.gpa << endl;
// 	cout << "arg.name的地址" << &arg.name << endl;
// 	for (int i = 0; i < 6;i++)
// 	{
// 		arg.name[i] = 'A';
// 	}
// 	arg.age++;
// 	arg.gpa = 99.9f;
// }
// int main()
// {
// 	student s1 = { 3039, "tomo", 20, "ComputerScience", 92.5 };//声明s1，并对s1初始化；
// 	cout << "s1.name的地址" << &s1.name << endl;
// 	display(s1);
// 	cout << "形参被修改后……" << endl;
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
// 	cout << "学号: " << arg.idNumber << "姓名：" << arg.name << "年龄：" << arg.age << "院系：" << arg.department <<
// 		"成绩：" << arg.gpa << endl;
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