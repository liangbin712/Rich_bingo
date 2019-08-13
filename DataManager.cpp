#pragma once
#include"DataManager.h"
#include<algorithm>
using std::string;
using std::vector;
void SqliteManager::Open(const string& path)
{
	int ret = sqlite3_open(path.c_str(), &_db);
	if (ret != SQLITE_OK)
	{
		ERROE_LOG("sqlite3_open\n");
	}
	else{
		TRACE_LOG("sqlite3_pen sucess!\n");
	}
}
void SqliteManager::Close()
{
	int ret = sqlite3_close(_db);
	if (ret != SQLITE_OK)
	{
		ERROE_LOG("sqlite3_close\n");
	}
	else{
		TRACE_LOG("sqlite3_close sucess!\n");
	}
}
void SqliteManager::ExecuteSql(const string& sql)
{
	char *errmsg;
	int ret = sqlite3_exec(_db, sql.c_str(), NULL, NULL, &errmsg);
	if (ret != SQLITE_OK)
	{
		ERROE_LOG("sqlite3_exec(&s)\n", sql.c_str());
	}
	else{
		TRACE_LOG("sqlite3_exec sucess(%s)!\n", sql.c_str());
	}
}
void SqliteManager::GetTable(const string& sql, int& row, int& col, char**& pRet)
{
	char *errmsg;
	int ret = sqlite3_get_table(_db, sql.c_str(), &pRet, &row, &col, &errmsg);
	if (ret != SQLITE_OK)
	{
		ERROE_LOG("sqlite3_get_table(&s)\n", sql.c_str());
	}
	else{
		TRACE_LOG("sqlite3_get_table sucess(%s)!\n", sql.c_str());
	}
}
void DataManager::Init()
{
	char sql[256];
	sprintf(sql, "CREATE TABLE if not exists %s (ID integer PRIMARY KEY AUTOINCREMENT, name char(50), path char(100), pinying char(50), letter char(50)); ", TB_NAME);
	_dbmgr.ExecuteSql(sql);
}
void DataManager::GetDocs(const std::string path, std::set<std::string>& docs)
{
	char sql[256];
	sprintf(sql, "select name from %s where path = '%s';", TB_NAME, path.c_str());
	int row, col;
	char **ppRet;
	AutoGetTable agt(&_dbmgr, row, col, sql, ppRet);
	for (int i = 1; i <= row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			docs.insert(ppRet[i*col + j]);
		}
	}
}
void DataManager::InsertDoc(const std::string path, std::string name)
{
	string pinying = ChineseConvertPinYinAllSpell(name);
	string letter = ChineseConvertPinYinInitials(name);
	char sql[256];
	sprintf(sql, "insert into %s (path, name,pinying,letter) values('%s','%s','%s','%s');", TB_NAME, path.c_str(), name.c_str(), pinying.c_str(), letter.c_str());
	_dbmgr.ExecuteSql(sql);
}
void DataManager::DeleteDoc(const std::string path, std::string name)
{
	char sql[256];
	sprintf(sql, "delete from %s where name = '%s' and path = '%s';", TB_NAME, name.c_str(), path.c_str());
	_dbmgr.ExecuteSql(sql);
}
void DataManager::Search(std::string& key, std::vector<std::pair<std::string, std::string>>&doc_paths)
{
	char sql[256];
	string pinying = ChineseConvertPinYinAllSpell(key);
	string letter = ChineseConvertPinYinInitials(key);
	sprintf(sql, "select name,path from %s where pinying like '%%%s%%'or letter like '%%%s%%';", TB_NAME, pinying.c_str(), letter.c_str());
	int row, col;
	char **ppRet;
	AutoGetTable agt(&_dbmgr, row, col, sql, ppRet);
	for (int i = 1; i <= row; i++)
	{
		doc_paths.push_back(std::make_pair(ppRet[i*col], ppRet[i*col + 1]));
	}
	highclub(key, doc_paths);
}
static void ColourPrintf(const char* str)
{
	// 0-黑 1-蓝 2-绿 3-浅绿 4-红 5-紫 6-黄 7-白 8-灰 9-淡蓝 10-淡绿
	// 11-淡浅绿 12-淡红 13-淡紫 14-淡黄 15-亮白
	//颜色：前景色 + 背景色*0x10
	//例如：字是红色，背景色是白色，即 红色 + 亮白 = 4 + 15*0x10
	WORD color = 4 + 15 * 0x10;
	WORD colorOld;
	HANDLE handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(handle, &csbi);
	colorOld = csbi.wAttributes;
	SetConsoleTextAttribute(handle, color);
	printf("%s", str);
	SetConsoleTextAttribute(handle, colorOld);
}
void HighLight(std::string &docs, std::string &key, std::string &prefix, std::string &infix, std::string&suffix);
void DataManager::highclub(std::string& key, std::vector<std::pair<std::string, std::string>>&doc_paths)
{
	cout << key << endl;
	std::string prefix; std::string infix; std::string suffix;
	for (int i = 0; i < doc_paths.size(); i++)
	{
		prefix.clear(); infix.clear(); suffix.clear();
		HighLight(doc_paths[i].first, key, prefix, infix, suffix);
		int len1 = prefix.size();
		int len2 = doc_paths[i].first.size();
		int len3 = suffix.size(), ch = 0;
		infix.clear();
		for (int j = len1; ch < len2 - len1 - len3; j++, ch++)
		{
			infix += doc_paths[i].first[j];
		}
		std::cout << doc_paths[i].second << "    " << prefix;
		ColourPrintf(infix.c_str());
		std::cout << suffix << endl;
	}
}

void HighLightever(const std::string &docs, const std::string &key, std::string &prefix, std::string &infix, std::string&suffix, size_t &docs_begin);
void HighLight(std::string &docs, std::string &key, std::string &prefix, std::string &infix, std::string&suffix)
{
	size_t i = 0, flag = 0, jlen = 1;
	size_t docs_begin = 0;
	string fack, mid, last;
	string docs0 = docs; string key0 = key;
	string fu1 = ChineseConvertPinYinAllSpell(key);
	string fu2 = ChineseConvertPinYinAllSpell(docs);
	for (int i = 0; i < key0.size(); i++)
	{
		if (key0[i] >= 'a' &&key0[i] <= 'z')
		{
			key0[i] -= 'a' - 'A';
		}
	}
	for (int i = 0; i < docs0.size(); i++)
	{
		if (docs0[i] >= 'a' &&docs0[i] <= 'z')
		{
			docs0[i] -= 'a' - 'A';
		}
	}
	if (docs0 == fu2 && key0 == fu1)
	{
		HighLightever(docs, key, prefix, infix, suffix, docs_begin);
	}
	else{
		if (key[0] >= 0 && key[0] <= 128)
		{
		}
		else{
			i = 1;
			flag = 1;
			jlen = 1;
		}
		for (int j = 0; i < key.size(); i++, jlen++, j++)
		{
			if (key[i] >= 0 && key[i] <= 128)
				last = key.substr(jlen - 1, 1);
			else{
				last = key.substr(jlen - 1, jlen + 1);
			}
			HighLightever(docs, last, prefix, infix, suffix, docs_begin);
			if (flag == 1 || i == 0)
			{
				fack = prefix;
				flag = 0;
			}
			mid += infix;
			last.clear();
			if (key[jlen - 1] >= 0 && key[jlen - 1] <= 128)
			{
			}
			else{
				jlen += 1;
			}
		}
		infix = mid;
		prefix = fack;
	}
}
void HighLightever(const std::string &docs, const std::string &key, std::string &prefix, std::string &infix, std::string&suffix, size_t &docs_begin)
{
	size_t howf = docs_begin;
	docs_begin = 0;
	string copy = docs;
	for (int i = 0; i < copy.size(); i++)
	{
		if ((ChineseConvertPinYinAllSpell(copy.substr(i, 1)).size() == 1))
		{
			if (copy[i] >= 'a' &&copy[i] <= 'z')
				copy[i] -= 32;
		}
	}
	size_t psize = docs.size();
	size_t ksize = key.size();
	size_t flag = 0;
	//中文处理
	{
		for (size_t x = 0; x < ksize; x++)
		{
			if (key[x] >= 0 && key[x] <= 128)
			{
			}
			else{
				flag = 1;
			}
		}
		if (flag == 1){
			size_t pos1 = docs.find(key);
			size_t end_index = 0, i = pos1, j = 0;
			while (i < docs.size() && j < ksize)
			{
				if (key[j] == docs[i])
				{
					j += 2;
					i += 2;
				}
				if (j == ksize * 2 - 2)
				{
					end_index = i;
					break;
				}
			}
			if (pos1 != string::npos)
			{
				prefix = docs.substr(0, pos1);
				infix = docs.substr(pos1, (end_index - pos1 - 1) * 2);
				//infix = key;
				suffix = docs.substr(end_index, psize - end_index);
				return;
			}
		}
	}
	//拼音处理
	{
		string docs_pinyin = ChineseConvertPinYinAllSpell(docs);
		string key_pinyin = ChineseConvertPinYinAllSpell(key);
		if (key_pinyin.size() != 1)
		{
			size_t pos = docs_pinyin.find(key_pinyin);
			size_t docs_begin = 0; size_t docs_end = 0;
			size_t key_begin = 0; size_t key_end = 0;
			if (pos != string::npos)
			{
				docs_begin = pos;
				docs_end = pos;
				while (1)
				{
					if (docs_pinyin[docs_end] == key_pinyin[key_begin])
					{
						docs_end++;
						key_begin++;
						if (key_begin == ksize)
						{
							docs_end--;
							break;
						}
						else if (key_begin > ksize)
						{
							docs_end -= 2;
							break;
						}
					}
					else{
						return;
					}
				}
				if (copy == docs_pinyin)
				{
					prefix = docs.substr(0, (docs_begin));
					infix = docs.substr(docs_begin, (docs_end - docs_begin + 1));
					//	cout << infix << endl;
					suffix = docs.substr((docs_end + 1), (psize - docs_end + 1));
				}
				else{
					prefix = docs.substr(0, (docs_begin)* 2);
					infix = docs.substr(docs_begin * 2, (docs_end - docs_begin + 1) * 2);
					//	cout << infix << endl;
					suffix = docs.substr((docs_end + 1) * 2, (psize - docs_end + 1) * 2);
				}
				return;
			}
		}
	}
	//首字母处理
	{
		string docs_letter = ChineseConvertPinYinInitials(docs);
		for (int i = 0; i < docs_letter.size(); i++)
		{
			if (docs_letter[i] >= 'a' &&docs_letter[i] <= 'z')
			{
				docs_letter[i] -= 'a' - 'A';
			}
		}
		string key_letter = ChineseConvertPinYinInitials(key);
		for (int i = 0; i < key_letter.size(); i++)
		{
			if (key_letter[i] >= 'a' &&key_letter[i] <= 'z')
			{
				key_letter[i] -= 'a' - 'A';
			}
		}
		size_t pos = docs_letter.find(key_letter);
		size_t docs_end = 0;
		size_t key_begin = 0; size_t key_end = 0;
		if (pos != string::npos)
		{
			docs_begin = pos;
			docs_end = pos;
			while (1)
			{
				if (docs_letter[docs_end] == key_letter[key_begin])
				{
					docs_end++;
					key_begin++;
					if (key_begin == ksize)
					{
						docs_end--;
						break;
					}
					else if (key_begin > ksize)
					{
						docs_end -= 2;
						break;
					}
				}
				else{
					break;
				}
			}
			string lin;
			int num = -1, sign = 0, sum = 0, b = 1, flag = 0, chui = 0;
			int length = docs_letter.size();
			if (length < docs.size())
			{
				for (int x = 0; x < docs.size(); x++)
				{
					string qiu = docs.substr(x, 1);
					if (docs.substr(x, 1)[0]>128 || docs.substr(x, 1)[0] < 0)
					{
						flag = 1;
					}
					if (flag == 1)
					{
						if (chui == 0)
						{
							lin = docs.substr(x, 2);
							chui = 1;
						}
						else{
							x++;
							lin = docs.substr(x, 2);
						}
						flag = 0;
					}
					else{
						lin = docs.substr(x, 1);
					}
					string pinyin;
					if ((docs.substr(x, 1)[0] > 128 || docs.substr(x, 1)[0] < 0))
					{
						pinyin = ChineseConvertPinYinAllSpell(docs.substr(x, 2));
						if (pinyin.find(key_letter) != string::npos &&docs_begin + num > howf + 1)
						{
							sign = 0;
						}
						else{
							sign = 1;
						}
					}
					else{
						pinyin = ChineseConvertPinYinAllSpell(docs.substr(x, 1));
						sign = 0;
					}
					if (sign == 1)
						num++;
				}
				docs_begin += num;
				docs_end = docs_begin + 2;
			}
			if (length < docs.size())
			{
				prefix = docs.substr(0, (docs_begin));
				infix = docs.substr(docs_begin, (docs_end - docs_begin));
				suffix = docs.substr((docs_end), (psize - docs_end));
				return;
			}
			if (copy == docs_letter)
			{
				prefix = docs.substr(0, (docs_begin));
				infix = docs.substr(docs_begin, (docs_end - docs_begin + 1));
				suffix = docs.substr((docs_end + 1), (psize - docs_end + 1));
			}
			else{
				prefix = docs.substr(0, (docs_begin)* 2);
				infix = docs.substr(docs_begin * 2, (docs_end - docs_begin + 1) * 2);
				suffix = docs.substr((docs_end + 1) * 2, (psize - docs_end + 1) * 2);
			}
			return;
		}
	}
}
