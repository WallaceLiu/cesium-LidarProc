// LidarProc.cpp: 定义控制台应用程序的入口点。
//
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <exception>
#include <fstream>
#include <iterator>

#include "httplib.h"

#include "LidarUtil/FileHelper.h"
#include "LidarBase/LASReceive.h"
#include "LidarResearch/LASFormatTransform.h"

using namespace rapidjson;
string apiDoc="";

/**
* 字符串分割
* @param const string& s 带分割的字符串
* @param vector<string>& result	分割结果
* @param const string seperator	分割字符
*/
void static SplitString(const string& s, vector<string>& result, const string seperator)
{
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//找到字符串中首个不等于分隔符的字母；
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x]) {
					++i;
					flag = 0;
					break;
				}
		}

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
}



int main(int argc, char **argv)
{
    using namespace httplib;
    Server svr;

	string pageInfo="";
	//查看系统信息
	string apiInfo="Api:http://localhost:1234/info\nParams:null\nParamType:null\nRequestType:GET\nDesc:查看系统信息\n\n";
    svr.Get("/info", [](const Request& req, Response& res) {
		ifstream incpu("/proc/cpuinfo");
		istreambuf_iterator<char> cpu_begin(incpu);
		istreambuf_iterator<char> cpu_end;
		string cpu_str(cpu_begin, cpu_end);

		ifstream inmem("/proc/cpuinfo");
		istreambuf_iterator<char> mem_begin(inmem);
		istreambuf_iterator<char> mem_end;
		string mem_str(mem_begin, mem_end);

		string info = cpu_str+"\n"+mem_str;

        res.set_content(info, "text/plain");
    });
	pageInfo+=apiInfo;

	//查看所有可以展示的点云数据
	string apiExhibitlist="Api:http://localhost:1234/exhibitlist\nParams:null\nParamType:null\nRequestType:GET\nDesc:列出所有可展示数据文件夹\n\n";
	svr.Get("/exhibitlist", [](const Request& req, Response& res){
		string dirNameList="";
		vector<string> namelist;
		FileHelper::listDirNames("./www/pointclouds/",namelist);
		for(int i=0;i<namelist.size();++i)
			dirNameList+=namelist[i]+";";
		res.set_content(dirNameList, "text/plain");
		res.status=200;
	});
	pageInfo+=apiExhibitlist;

	//列出所有可处理数据
	string apiDatalist="Api:http://localhost:1234/datalist\nParams:null\nParamType:null\nRequestType:GET\nDesc:列出所有可处理数据\n\n";
	svr.Get("/datalist", [](const Request& req, Response& res){
		string jstr="";
		vector<string> dirs;
		FileHelper::listDirNames("../data/",dirs);
		for(int i=0;i<dirs.size();++i)
		{
			jstr+=","+dirs[i]+";";
			vector<string> filelist;
			FileHelper::listNames(string("../data/"+dirs[i]+"/"),filelist,"las");
			for(int j=0;j<filelist.size();++j)
			{
				jstr+=filelist[j]+";";
			}
		}
		res.set_content(jstr, "text/plain");
		res.status=200;
	});
	pageInfo+=apiDatalist;

	//删除处理数据
	string apiDatadelete="Api:http://localhost:1234/datadelete\nParams:待删除数据文件名（根据列出数据文件获取）\nParamType:url参数\nRequestType:GET\nDesc:删除处理数据\n\n";
	svr.Get(R"(/datadelete/(.*?))",[](const Request& req, Response& res){
		string path="../data/"+string(req.matches[1]);
		remove(path.c_str());
        res.set_content("deleted", "text/plain");
		res.status=200;
	});
	pageInfo+=apiDatadelete;

	//删除展示数据
	string apiExhibitdelete="Api:http://localhost:1234/exhibitdelete\nParams:待删除数据文件夹（根据列出数据文件获取）\nParamType:url参数\nRequestType:GET\nDesc:删除展示数据\n\n";
	svr.Get(R"(/exhibitdelete/(.*?))",[](const Request& req, Response& res){
		string path="../data/"+string(req.matches[1]);
		remove(path.c_str());
        res.set_content("deleted", "text/plain");
		res.status=200;
	});
	pageInfo+=apiExhibitdelete;

	//处理数据转换为展示数据
	string apiDatatrans="Api:http://localhost:1234/datatrans\nParams:待转换数据文件名\nParamType:url参数\nRequestType:GET\nDesc:将处理数据转换为展示数据\n\n";
	svr.Get(R"(/datatrans/(.*?))",[](const Request& req, Response& res){
		string path="../data/"+string(req.matches[1]);
		LASTransToPotree lasTrans;
		lasTrans.LASTransToPotree_Trans(path.c_str());
        res.set_content("transed", "text/plain");
		res.status=200;
	});
	pageInfo+=apiDatatrans;

	//获取点云分类类型
	string apiDataclasstype="Api:http://localhost:1234/dataclasstype\nParams:null\nParamType:\nRequestType:GET\nDesc:将处理数据转换为展示数据\n\n";
	svr.Get("/dataclasstype",[](const Request& req, Response& res){
		FILE *fs = fopen("./config/classtype.conf","r+");
		char line[2048];
		string jstr="";
		while(fgets (line, 2048, fs)!=NULL)
		{
			vector<string> lineItems;
			SplitString(string(line),lineItems,",");
			jstr+=lineItems[0]+","+lineItems[1]+";";
		}
		fclose(fs);
		res.set_content(jstr, "text/plain");
		res.status=200;
	});


	//查看doc文档
	pageInfo+=apiDataclasstype;
	apiDoc=pageInfo;
	svr.Get("/apidoc",[](const Request& req, Response& res){
		string doc=apiDoc;
		res.set_content(apiDoc, "text/plain;charset=utf-8");
		res.status=200;
	});
	int port=1234;

	printf("localhost:%d\n",port);

	//the max parallel connection count
	svr.set_keep_alive_max_count(500);
	svr.set_base_dir("./www");
    svr.listen("localhost", port);

}