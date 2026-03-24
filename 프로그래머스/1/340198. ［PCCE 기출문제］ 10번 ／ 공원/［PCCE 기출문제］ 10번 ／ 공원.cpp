#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    
    vector<vector<int>> table(park.size(), vector<int>(park[0].size(), 0));
    
    sort(mats.begin(), mats.end(), greater<>());
    
    for(size_t i = 0; i < park.size(); ++i)
    {
        for(size_t j = 0; j < park[i].size(); ++j)
        {
            if(park[i][j] != "-1")
                continue;
            
            int iUp = i - 1;
            int iLeft = j - 1;
            
            if(iUp < 0 || iLeft < 0)
            {
                table[i][j] = 1;
                continue;
            }
            
            int iNum = min(table[iUp][j], min(table[i][iLeft], table[iUp][iLeft])) + 1;
            
            if(answer < iNum)
                answer = iNum;
            
            table[i][j] = iNum;
        }
    }
    
    for(size_t i = 0; i < mats.size(); ++i)
    {
        if(mats[i] <= answer)
            return mats[i];
    }
    
    return -1;
}