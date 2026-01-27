#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define THS 121

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;

    vector<int> DP(m, THS);
    DP[0] = 0;
    
    for(size_t i = 0; i < info.size(); ++i)
    {
        int iA = info[i][0];
        int iB = info[i][1];
        
        vector<int> NDP(m, THS);
        
        for(int j = 0; j < m; ++j)
        {
            if(DP[j] == THS)
                continue;
            
            int iIndex = j + iB;
            
            if(DP[j] + iA < n)
                NDP[j] = min(NDP[j], DP[j] + iA);
            if(iIndex < m)
                NDP[iIndex] = min(NDP[iIndex], DP[j]);
        }
        swap(DP, NDP);
    }
    
    answer = *min_element(DP.begin(), DP.end());
    
    if(answer == THS)
        return -1;
    
    return answer;
}