#include <string>
#include <vector>

using namespace std;

int Change_Time(int iTime)
{
    int iMax = iTime + 10;
    
    if(iMax % 100 >= 60)
        iMax += 40;
    
    return iMax;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    vector<int> maxtime;
    
    for(size_t i = 0; i < schedules.size(); ++i)
        maxtime.push_back(Change_Time(schedules[i]));
    
    for(size_t i = 0; i < timelogs.size(); ++i)
    {
        int iCount = {};
        for(size_t j = 0; j < timelogs[i].size(); ++j)
        {
            int iDay = j + startday;
            if(iDay % 7 == 6 || iDay % 7 == 0)
                continue;
            if(timelogs[i][j] > maxtime[i])
                break;
            ++iCount;
        }
        if(iCount == 5)
            ++answer;
    }
    
    return answer;
}