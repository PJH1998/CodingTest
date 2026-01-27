#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a == b)
        return a;
    
    int iGap = abs(b - a) + 1;

    return static_cast<long long>(a + b) * (iGap * static_cast<double>(0.5f));
}