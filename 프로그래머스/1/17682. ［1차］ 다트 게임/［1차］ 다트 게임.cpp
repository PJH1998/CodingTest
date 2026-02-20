#include <string>
#include <map>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    
    int iScore[3] = {};
    
    string strNum = "";
    int iIndex = {-1};
    
    map<char, int> bonus;
    bonus.emplace('S', 1);
    bonus.emplace('D', 2);
    bonus.emplace('T', 3);
    
    for(int i = 0; i < dartResult.length(); ++i)
    {
        if(dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            if(strNum == "")
                ++iIndex;
            strNum += dartResult[i];
        }  
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T')
        {
            iScore[iIndex] = stoi(strNum);
            strNum = "";
            iScore[iIndex] = pow(iScore[iIndex], bonus[dartResult[i]]);
        }
        else
        {
            if(dartResult[i] == '*')
            {
                iScore[iIndex] *= 2;
                if(iIndex - 1 >= 0)
                    iScore[iIndex - 1] *= 2;
            }
            else if(dartResult[i] == '#')
            {
                iScore[iIndex] *= -1;
            }
        }
    }
    
    return iScore[0] + iScore[1] + iScore[2];
}