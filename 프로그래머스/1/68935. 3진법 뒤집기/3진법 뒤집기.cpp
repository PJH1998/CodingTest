#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> Three;
    
    int iNum = 3;
    
    while(n > 0)
    {
        Three.push_back(n % iNum);
        n /= iNum;
    }
    
    int iSize = Three.size();
    for(size_t i = 0; i < iSize; ++i)
        answer += Three[i] * pow(3, iSize - i - 1);
    
    return answer;
}