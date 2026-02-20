#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int iEqual{}, iDiff{};
    
    int iIndex = {};
    int iLength = s.length();
    
    for(int i = 0; i < iLength; ++i)
    {
        if(s[i] == s[iIndex])
            ++iEqual;
        else
            ++iDiff;
        
        if(iEqual == iDiff)
        {
            ++answer;
            iEqual = 0;
            iDiff = 0;
            iIndex = i + 1;
        }
        else if(i == iLength - 1)
            ++answer;
    }
    
    return answer;
}