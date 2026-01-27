#include <algorithm>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long llSum = 0;
    
    while(count > 0)
    {
        llSum += price * count;
        --count;
    }
    
    answer = llSum - money < 0 ? 0 : llSum - money;

    return answer;
}