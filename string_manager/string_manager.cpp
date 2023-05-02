#include "string_manager.h"
const string string_manager::Tend = "~`!@#$ % ^&*()_ + -= {}[] |\";'<>?,./";
string_manager::string_manager(string txt): txt(txt)
{
    size_t pos{};
    size_t lookHere{};
    while ((pos = this->txt.find('\n', lookHere)) != string::npos)           //前n行
    {
        lines.push_back(this->txt.substr(lookHere, pos - lookHere));
        lookHere = pos + 1;
    }
    //最后1行
    if (lookHere != this->txt.size())     //残留不带\n的一行字符串
    {
        lines.push_back(this->txt.substr(lookHere, this->txt.size() - lookHere));
    }
}

string string_manager::getNewline(bool ignoreN)
{
    static size_t lineNum = 0;
    if (lineNum == lines.size())
        return Tend;
    return ignoreN ? lines[lineNum++].substr(0, lines[lineNum].size() - 1) : lines[lineNum++];
}

string string_manager::replaceAll(const string& from, const string& to)
{
    return replaceAll(txt, from, to);
}

string string_manager::replaceAll(string context, const string& from, const string& to)
{
    size_t lookHere = 0;
    size_t foundHere;
    while ((foundHere = context.find(from, lookHere)) != string::npos)		// find from lookHere
    {																					// to avoid the string
        context.replace(foundHere, from.size(), to);					//"to" is the substr
        lookHere = foundHere + to.size();												// of "from"
    }
    return context;
}

vector<string> string_manager::parseStrToWords() const
{
    return parseStrToWords(txt);
}

vector<string> string_manager::parseStrToWords(const string& otherTxt)
{
    size_t foundHere_a = 0, foundHere_b = 0;
    string englishWord;
    for (char i = 'a'; i <= 'z'; i++)
        englishWord += i;
    for (char i = 'A'; i <= 'Z'; i++)
        englishWord += i;
    foundHere_a = otherTxt.find_first_not_of(englishWord);
    if (foundHere_a == string::npos)
        return std::move(vector<string>());
    vector<string> words;
    while ((foundHere_b = otherTxt.find_first_not_of(englishWord, foundHere_a + 1)) != string::npos)
    {
        if (foundHere_b == foundHere_a + 1)
        {
            foundHere_a = foundHere_b;
            continue;
        }
        words.push_back(otherTxt.substr(foundHere_a + 1, foundHere_b - foundHere_a - 1));
        foundHere_a = foundHere_b;
    }
    words.push_back(otherTxt.substr(foundHere_a + 1, otherTxt.size() - foundHere_a - 1));
    return words;
}

