#include <string>
#include <vector>

using namespace std;

bool StringtoInt(string& s, string strNumTag, int iNum)
{
    auto Index = s.find(strNumTag);
    if(Index == string::npos)
        return false;
    
    s.erase(Index + 1, strNumTag.length() - 1);
    s[Index] = '0' + iNum;
    
    return true;
}

int solution(string s) {
    int answer = 0;
    
    string strNum[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    while(true)
    {
        bool isFlag = false;
        for(int i = 0; i < 10; ++i)
        {
            if(isFlag = StringtoInt(s, strNum[i], i))
                break;
        }
        if(!isFlag)
        {
            answer = stoi(s);
            break;
        }
    }
    
    return answer;
}