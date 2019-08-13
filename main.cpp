#include"Common.h"
#include"ScanManager.h"
/*void TestDirectoryList()
{
vector<string> dics;
vector<string> file;
Directorylist("D:\\快玩", dics, file);
for (auto e : dics)
cout << e << endl;
for (auto e : file)
cout << e << endl;
}
void Testsqlite()
{
SqliteManager sq;
sq.Open("db.db");
sq.ExecuteSql("create table COMPANY(ID INT PRIMARY KEY  NOT NULL,NAME TEXT  NOT NULL,AGE INT NOT NULL,ADDRESS CHAR(50)); ");
sq.ExecuteSql("insert into COMPANY(ID,NAME,AGE,ADDRESS,SALARY) VALUES(1, 'Paul', 32, 'California', 20000.00);");
sq.ExecuteSql("insert into COMPANY(ID, NAME, AGE, ADDRESS, SALARY) VALUES(2, 'Allen', 25, 'Texas', 15000.00);");
string get = "select *from COMPANY ;";
int row, col;
char **ppRet;
sq.GetTable(get, row, col, ppRet);
for (int i = 1; i <= row; i++)
{
for (int j = 0; j < col; j++)
{
cout << ppRet[i*col + j] << " ";
}
cout << endl;
}
sqlite3_free_table(ppRet);
sq.Close();
}*/
void Datatest()
{
	string key = "game";
	string path = "D:\\快玩";
	ScanManager::CreateIntaince(path, key);
}
int main()
{
	//TestDirectoryList();
	//Testsqlite();
	Datatest();
	getchar();
}
