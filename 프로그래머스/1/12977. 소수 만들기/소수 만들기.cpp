#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool Check_Prime(int iNum)
{
    int iSqrt = sqrt(iNum);
    
    int iDivide = 2;
    
    while(iDivide <= iSqrt)
    {
        if(iNum % iDivide == 0)
            return false;
        
        ++iDivide;
    }
    
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    for(int i = 0; i < nums.size() - 2; ++i)
    {
        for(int j = i + 1; j < nums.size() - 1; ++j)
        {
            for(int k = j + 1; k < nums.size(); ++k)
            {
                int iNum = nums[i] + nums[j] + nums[k];
                if(true == Check_Prime(iNum))
                    ++answer;
            }
        }
    }

    return answer;
}