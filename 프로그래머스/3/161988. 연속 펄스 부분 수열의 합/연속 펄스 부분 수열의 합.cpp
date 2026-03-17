#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    vector<long long> DP(sequence.size());
    DP[0] = sequence[0];
    
    vector<long long> DPInv(sequence.size());
    DPInv[0] = sequence[0] * -1;
    
    answer = max(DP[0], DPInv[0]);
    
    for(size_t i = 1; i < sequence.size(); ++i)
    {
        int iPulse = i % 2 == 0 ? sequence[i] : sequence[i] * -1;
        int iPulse_Inv = iPulse * -1;
        
        long long llPulse = DP[i-1] + iPulse;
        long long llPulse_Inv = DPInv[i-1] + iPulse_Inv;
        
        if(llPulse < iPulse)
            DP[i] = iPulse;
        else
            DP[i] = llPulse;
        
        if(llPulse_Inv < iPulse_Inv)
            DPInv[i] = iPulse_Inv;
        else
            DPInv[i] = llPulse_Inv;
        
        long long llMax = max(DP[i], DPInv[i]);
        if(llMax > answer)
            answer = llMax;
    }
    
    return answer;
}