#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {

    int iLeft = 0;
    int iRight = *max_element(diffs.begin(), diffs.end());
    
    int iLevel = 0;
    
    while(true)
    {
        iLevel = ceil((iLeft + iRight) / 2.f);
        if(iLevel == iRight)
            break;
        
        long long llSum = times[0];
        for(size_t i = 1; i < diffs.size(); ++i)
        {
            if(iLevel < diffs[i])
                llSum += (diffs[i] - iLevel) * (times[i] + times[i-1]) + times[i];
            else
                llSum += times[i];
        }
        
        if(llSum <= limit)
            iRight = iLevel;
        else
            iLeft = iLevel;
    }
    
    return iLevel;
}