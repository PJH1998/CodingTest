#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    for(int i = h1; i <= h2; ++i)
    {
        int iMin_Start = {};
        int iMin_End = {};
        if(i == h1)
            iMin_Start = m1;
        else
            iMin_Start = 0;
        
        if(i == h2)
            iMin_End = m2;
        else
            iMin_End = 59;
        
        for(int j = iMin_Start; j <= iMin_End; ++j)
        {
            float fHour = 30 * (i % 12) + 0.5f * j;
            float fMin = 6 * j;
            double fSec_ToMin = fMin / 5.9f; // 분침과 시침이 겹칠 때 초
            double fSec_ToHour = fHour / (6.f - 360.f / (12 * 60 * 60));
            
            float fStart_Sec = {};
            float fEnd_Sec = {};
            if(i == h1 && j == m1)
                fStart_Sec = s1;
            else
                fStart_Sec = 0.f;
            
            if(i == h2 && j == m2)
                fEnd_Sec = s2;
            else
                fEnd_Sec = 60.f;
 
            if(j < 59 && fSec_ToMin >= fStart_Sec && fSec_ToMin <= fEnd_Sec)
                ++answer;
               
            if(i % 12 == 11 && j == 59)
                continue;
            if(fSec_ToHour >= fStart_Sec && fSec_ToHour <= fEnd_Sec && fSec_ToHour != fSec_ToMin)
                ++answer;
        }
    }
    
    return answer;
}