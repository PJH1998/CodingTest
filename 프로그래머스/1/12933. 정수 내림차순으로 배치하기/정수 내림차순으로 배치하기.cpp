#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<int> Nums;
    while(n > 0)
    {
        Nums.push_back(n % 10);
        n /= 10;
    }
    
    sort(Nums.rbegin(), Nums.rend());
    
    int iLength = Nums.size();
    
    for(int i = 0; i < iLength; ++i)
        answer += static_cast<long long>(Nums[i]) * pow(10, iLength - i - 1);
    
    return answer;
}