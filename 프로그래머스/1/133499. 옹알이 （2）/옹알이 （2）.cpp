#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    string str[4] = {"aya", "ye", "woo", "ma"};
    
    for(size_t i = 0; i < babbling.size(); ++i)
    {
        int iIndex = 0;
        int iStringType = -1;
        
        bool isFlag = true;
        
        while(isFlag)
        {
            for(int j = 0; j < 4; ++j)
            {
                if(babbling[i].find(str[j], iIndex) == iIndex && iStringType != j)
                {
                    iIndex += str[j].length();
                    iStringType = j;
                    if(iIndex == babbling[i].length())
                    {
                        isFlag = false;
                        ++answer;
                    }
                    break;
                }
                if(j == 3)
                    isFlag = false;
            }
        }
    }
    
    return answer;
}