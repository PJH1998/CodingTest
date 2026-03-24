#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsCode(const vector<vector<int>>& q, const vector<int>& ans, const vector<int>& Code)
{
    for(size_t i = 0; i < q.size(); ++i)
    {
        int iCnt = 0;
        for(int j = 0; j < 5; ++j)
        {
            if(Code.end() != find(Code.begin(), Code.end(), q[i][j]))
                ++iCnt;
        }
        if(ans[i] != iCnt)
            return false;
    }
    
    return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    vector<int> Combination(n, 0);
    for(int i = 0; i < 5; ++i)
        Combination[n - i - 1] = 1;
    
    do
    {
        vector<int> Code;
        for(int i = 0; i < n; ++i)
        {
            if(Combination[i] == 1)
                Code.push_back(i + 1);
        }
        
        if(true == IsCode(q, ans, Code))
            ++answer;

    }while(next_permutation(Combination.begin(), Combination.end()));
    
    return answer;
}