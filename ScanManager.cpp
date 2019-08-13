#include"ScanManager.h"
ScanManager ScanManager::m_instance1;
void ScanManager::scan(const string &path)
{
	vector<string> localdirs;
	vector<string> localfiles;
	Directorylist(path, localdirs, localfiles);
	std::set<string> localset;
	localset.insert(localdirs.begin(), localdirs.end());       // local        db
	localset.insert(localfiles.begin(), localfiles.end());    //1 3 5 7 9 10  1 3 5 6 7 12
	std::set<string> dbset;
	_datamgr.GetDocs(path, dbset);
	auto localit = localset.begin();
	auto dbit = dbset.begin();
	while (localit != localset.end() && dbit != dbset.end())
	{
		if (*localit == *dbit)
		{
			++localit;
			++dbit;
		}
		else if (*localit > *dbit)
		{
			_datamgr.DeleteDoc(path, *dbit);
			++dbit;
		}
		else{
			_datamgr.InsertDoc(path, *localit);
			++localit;
		}
	}
	while (localit != localset.end())
	{
		_datamgr.InsertDoc(path, *localit);
		localit++;
	}
	while (dbit != dbset.end())
	{
		_datamgr.DeleteDoc(path, *dbit);
		dbit++;
	}
	for (auto e : localdirs)        //const e
	{
		string subpath = path;
		subpath += "\\";
		subpath += e;
		scan(subpath);
	}
}
