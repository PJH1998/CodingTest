#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer = 0;

    for(int i = 0; i < s.length(); ++i)
    {
        int iOffset = 0;
        // 짝수
        while(i - iOffset >= 0 && 
            i + iOffset + 1 < s.length() && 
            s[i - iOffset] == s[i + iOffset + 1])
        {
            int iNum = (iOffset + 1) * 2;
            if(answer < iNum)
                answer = iNum;
            ++iOffset;
        }
        // 홀수
        iOffset = 0;
        while(i - iOffset >= 0 && 
              i + iOffset < s.length() && 
              s[i - iOffset] == s[i + iOffset])
        {
            int iNum = iOffset * 2 + 1;
            if(answer < iNum)
                answer = iNum;
            ++iOffset;
        }
    }

    return answer;
}