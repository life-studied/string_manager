#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class string_manager
{
private:
	string txt;				//�ı�
	vector<string> lines;	//�ı���ÿ��
public:
	static const string Tend;	//������־
public:
	string_manager(string txt);
	string getNewline(bool ignoreN = false);						//�Զ���ȡ��һ�У����������Ի��з���
	string replaceAll(const string& from, const string& to);		//�滻�ı�����txt�У�
	static string replaceAll(string context, const string& from, const string& to);	//�滻�ı����Զ����ı���
	vector<string> parseStrToWords() const;							//�����ı������ʣ���txt�У�
	static vector<string> parseStrToWords(const string& otherTxt);	//�������ʣ��Զ����ı���
};

