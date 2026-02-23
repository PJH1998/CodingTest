#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    map<string, int> IndexMap;
    IndexMap.emplace("code", 0);
    IndexMap.emplace("date", 1);
    IndexMap.emplace("maximum", 2);
    IndexMap.emplace("remain", 3);
    
    for(size_t i = 0; i < data.size(); ++i)
    {
        int iIndex_ext = IndexMap[ext];
        if(data[i][iIndex_ext] < val_ext)
            answer.push_back(data[i]);
    }
    
    int iSortIndex = IndexMap[sort_by];
    
    sort(answer.begin(), answer.end(), [&](const vector<int>& a, const vector<int>& b)->bool{
        return a[iSortIndex] < b[iSortIndex];
    });
    
    return answer;
}