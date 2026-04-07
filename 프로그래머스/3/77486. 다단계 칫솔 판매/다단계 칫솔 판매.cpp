#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    
    vector<int> Index(enroll.size(), -1);
    
    for(size_t i = 0; i < referral.size(); ++i)
    {
        if(referral[i] == "-")
            continue;
        
        auto iter = find(enroll.begin(), enroll.end(), referral[i]);
        Index[i] = iter - enroll.begin();
    }
    
    for(size_t i = 0; i < seller.size(); ++i)
    {
        auto iter = find(enroll.begin(), enroll.end(), seller[i]);
        int iIndex = iter - enroll.begin();
        
        int iCost = amount[i] * 100;

        while(iIndex >= 0)
        {
            int iMine = ceil(iCost * 0.9f);
            int iDuty = iCost - iMine;
            answer[iIndex] += iMine;
            
            if(iDuty < 1)
                break;
            iCost = iDuty;
            iIndex = Index[iIndex];
        }
    }
    
    return answer;
}