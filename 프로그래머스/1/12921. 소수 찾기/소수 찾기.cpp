#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool Check_Prime(int iNum)
{
    int iSqrt = sqrt(iNum);
    int iDivide = 2;
    while(iDivide <= iSqrt)
    {
        if(iNum % iDivide == 0)
            return false;
        ++iDivide;
    }
    
    return true;
}

int solution(int n) {
    int answer = 0;
    
    for(int i = 2; i <= n; ++i)
    {
        if(true == Check_Prime(i))
            ++answer;
    }
    
    return answer;
}