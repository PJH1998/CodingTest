#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    float fSqrt = sqrt(n);
    
    int iNum = 1;
    while(iNum <= fSqrt)
    {
        if(n % iNum == 0)
            answer += (iNum == fSqrt) ? iNum : iNum + n / iNum;
        
        ++iNum;
    }
    
    return answer;
}