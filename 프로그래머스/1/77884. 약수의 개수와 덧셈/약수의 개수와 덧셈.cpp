#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    while(left <= right)
    {
        double dSqrt = sqrt(left);
        int iFloor = floor(dSqrt);

        (dSqrt == iFloor) ? answer -= left : answer += left;
        
        ++left;
    }
    
    return answer;
}