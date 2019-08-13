#pragma once
#include"Common.h"
class SqliteManager
{
public:
	SqliteManager()
		:_db(nullptr)
	{
	}
	~SqliteManager()
	{
		Close();
	}
	void Open(const std::string& path);
	void Close();
	void ExecuteSql(const std::string& sql);
	void GetTable(const std::string& sql, int& row, int& col, char** &ppRet);
	SqliteManager(const SqliteManager&) = delete;
	SqliteManager& operator=(const SqliteManager&) = delete;
private:
	sqlite3* _db; // 数据库对象
};
#define DB_NAME "doc.db"
#define TB_NAME "tb0_doc"
class DataManager{
public:
	~DataManager()
	{
		_dbmgr.Close();
	}
	void Init();//建表，打开数据库
	void GetDocs(const std::string path, std::set<std::string>& docs);//查看path下所有子文档
	void InsertDoc(const std::string path, std::string name);
	void DeleteDoc(const std::string path, std::string name);
	void Search(std::string& key, std::vector<std::pair<std::string, std::string>>&doc_paths);
	void highclub(std::string& key, std::vector<std::pair<std::string, std::string>>&doc_paths);
	DataManager()
	{
		_dbmgr.Open(DB_NAME);
		Init();
	}
private:
	DataManager(const DataManager&) = delete;
	SqliteManager _dbmgr;
};
////////////////////////RAII
class AutoGetTable{
public:
	AutoGetTable(SqliteManager *dbObject, int &Row, int &Col, const std::string &sql, char **&ppRet) :_dbObject(dbObject), _ppLRet(0)
	{
		_dbObject->GetTable(sql, Row, Col, ppRet);
		_ppLRet = ppRet;
	}
	~AutoGetTable()
	{
		if (_ppLRet)
			sqlite3_free_table(_ppLRet);
	}
	AutoGetTable(const AutoGetTable &) = delete;
	AutoGetTable operator = (const AutoGetTable &) = delete;
private:
	SqliteManager * _dbObject;
	char**        _ppLRet;
};
