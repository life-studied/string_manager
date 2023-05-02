#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class string_manager
{
private:
	string txt;				//文本
	vector<string> lines;	//文本的每行
public:
	static const string Tend;	//结束标志
public:
	string_manager(string txt);
	string getNewline(bool ignoreN = false);						//自动获取下一行（参数：忽略换行符）
	string replaceAll(const string& from, const string& to);		//替换文本（从txt中）
	static string replaceAll(string context, const string& from, const string& to);	//替换文本（自定义文本）
	vector<string> parseStrToWords() const;							//解析文本至单词（从txt中）
	static vector<string> parseStrToWords(const string& otherTxt);	//解析单词（自定义文本）
};

