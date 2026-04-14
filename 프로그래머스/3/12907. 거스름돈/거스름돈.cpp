#include <string>
#include <vector>
#include <set>

using namespace std;

#define MOD 1000000007

int solution(int n, vector<int> money) {
    int answer = 0;
    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for(int iCost : money)
    {
        for(int iMoney = iCost; iMoney <= n; ++iMoney)
        {
            int iPre = iMoney - iCost;
            dp[iMoney] += dp[iPre];
            if(dp[iMoney] > MOD) dp[iMoney] -= MOD;
        }
    }
    
    return dp[n];
}