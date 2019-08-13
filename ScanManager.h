#pragma once
#include"DataManager.h"
class ScanManager{
public:
	void scan(const string &path);
	void StartScan(const string path)
	{
		while (1)
		{
			scan(path);
			std::this_thread::sleep_for(std::chrono::seconds(5));
		}
	}
	static ScanManager	* CreateIntaince(const string path, std::string key)
	{
		static ScanManager scanmgr;
		static std::thread thd(&StartScan, &scanmgr, path);
		scanmgr.Mid(key);
		thd.detach();
		return &m_instance1;

	}
	void Mid(std::string key)
	{
		std::vector<std::pair<std::string, std::string>>doc_paths;
		_datamgr.Search(key, doc_paths);
	}
private:
	ScanManager()
	{
		_datamgr.Init();
	}
	/*ScanManager(std::string key, const string path) :_key(key), _path(path)
	{
	scan(path);
	std::vector<std::pair<std::string, std::string>>doc_paths;
	_datamgr.Search(key, doc_paths);
	}*/
	DataManager _datamgr;
	static ScanManager m_instance1;
	//static std::string _key;
};
