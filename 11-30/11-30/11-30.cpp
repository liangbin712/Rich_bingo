#include <iostream>
using namespace std;
//枚举类型
enum day{Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
void nextday(day &D);
void display(day D);
int main()
{
	day today = Sunday;
	for (int i = 0; i < 7;i++)
	{
		cout << "在today变量里的数据为" << today << endl;
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
		cout << "星期天" << endl;
		break;
	case Monday:
		cout << "星期一" << endl;
		break;
	case Tuesday:
		cout << "星期二" << endl;
		break;
	case Wednesday:
		cout << "星期三" << endl;
		break;
	case Thursday:
		cout << "星期四" << endl;
		break;
	case Friday:
		cout << "星期五" << endl;
		break;
	case Saturday:
		cout << "星期六" << endl;
		break;
	}
}
//结构类型
struct student
{
	int  idNumber;
	char  name[15];
	int  age;
	char  department[20];
	float gpa;
};
//这样有了新的名为student数据类型。
int main()
{
	student s1, s2;
	cout << "请输入学号：";
	cin >> s1.idNumber;
	cout << "输入姓名：";
	cin >> s1.name;
	cout << "输入年龄";
	cin >> s1.age;
	cout << "输入院系";
	cin >> s1.department;
	cout << "输入成绩";
	cin >> s1.gpa;
	cout << "学生s1信息:" << endl << "学号：" << s1.idNumber << "姓名：" << s1.name << "年龄：" << s1.age
		<< endl << "院系: " << s1.department << "成绩" << s1.gpa << endl;
	s2 = s1;
	cout << "学生s2信息:" << endl << "学号：" << s2.idNumber << "姓名：" << s2.name << "年龄：" << s2.age
		<< endl << "院系: " << s2.department << "成绩" << s2.gpa << endl;
	system("pause");
}