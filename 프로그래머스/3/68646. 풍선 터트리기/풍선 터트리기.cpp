#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define MAX 1000000001

using namespace std;

typedef struct tagBal {
    int iVal = {};
    int iIdx = {};
}BAL;

int solution(vector<int> a) {
    int answer = 0;
    int iSize = a.size();
    answer = iSize;
    
    vector<BAL> bal;
    for(int i = 0; i < iSize; ++i)
    {
        BAL tmp = BAL{a[i], i};
        bal.push_back(tmp);
    }
    
    sort(bal.begin(), bal.end(), [&](const BAL& dst, const BAL& src){
        return dst.iVal > src.iVal;
    });
    
    int iLeft_Min = MAX;
    int iRight_Min = bal.back().iVal;
    
    for(int i = 0; i < iSize; ++i)
    {
        if(iLeft_Min < a[i] && iRight_Min < a[i])
            --answer;
        
        if(iLeft_Min > a[i])
            iLeft_Min = a[i];
            
        if(iRight_Min == a[i])
        {
            while(!bal.empty() && bal.back().iIdx <= i)
            {
                bal.pop_back();
            }
            if(!bal.empty())
                iRight_Min = bal.back().iVal;
        }
            
    }
    
    return answer;
}