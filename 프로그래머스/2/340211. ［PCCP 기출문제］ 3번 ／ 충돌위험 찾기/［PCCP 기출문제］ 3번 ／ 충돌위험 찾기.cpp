#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    int table[101][101] = {};
    
    int iNum = routes.size();
    vector<pair<int, int>> Robot;
    vector<int> Dest(iNum, 1);
    vector<bool> Check(iNum, false);
    
    // Robot 초기 위치
    for(int i = 0; i < iNum; ++i)
    {
        int iStart = routes[i][0] - 1;
        Robot.push_back(make_pair(points[iStart][0], points[iStart][1]));
        
        if(table[Robot[i].first][Robot[i].second] == 1)
            ++answer;
        
        ++table[Robot[i].first][Robot[i].second];
    }
    
    bool isEnd = false;
    while(!isEnd)
    {
        // Clear
        for(int i = 0; i < iNum; ++i)
            table[Robot[i].first][Robot[i].second] = 0;
        
        for(int i = 0; i < iNum; ++i)
        {
            if(Check[i])
                continue;
            
            int iMove_Row = Robot[i].first;
            int iMove_Col = Robot[i].second;
            // Row
            int iNext = routes[i][Dest[i]] - 1;
            if(iMove_Row != points[iNext][0])
                iMove_Row += (iMove_Row < points[iNext][0]) ? 1 : -1;
            // Col
            else if(iMove_Col != points[iNext][1])
                iMove_Col += (iMove_Col < points[iNext][1]) ? 1 : -1;
            
            if(table[iMove_Row][iMove_Col] == 1)
                ++answer;
            
            ++table[iMove_Row][iMove_Col];
            
            Robot[i].first = iMove_Row;
            Robot[i].second = iMove_Col;
            
            if(iMove_Row == points[iNext][0] && iMove_Col == points[iNext][1])
            {
                ++Dest[i];
                if(routes[i].size() == Dest[i])
                    Check[i] = true;
            }
        }
        
        if(find(Check.begin(), Check.end(), false) == Check.end())
            isEnd = true;
    }
    
    return answer;
}