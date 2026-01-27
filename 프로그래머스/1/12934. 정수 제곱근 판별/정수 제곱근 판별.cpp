#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    double dSqrt = sqrt(n);
    long long llNum = static_cast<long long>(dSqrt);
    
    if(dSqrt == llNum)
        answer = pow(llNum + 1, 2);
    else
        return -1;
    
    return answer;
}