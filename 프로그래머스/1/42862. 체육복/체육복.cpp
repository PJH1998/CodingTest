#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check_Num(const vector<int>& Con, int iNum)
{
    auto iter = find(Con.begin(), Con.end(), iNum);
    
    if(iter == Con.end())
        return false;
    return true;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> Check(n+1, 0);
    
    for(int i = 1; i < n + 1; ++i)
    {
        // 현재 학생 체육복 체크
        if(false == Check_Num(lost, i))
            ++Check[i];
        // 현재 학생 여분 체크
        if(true == Check_Num(reserve, i))
            ++Check[i];
    }
    
    for(int i = 1; i < n + 1; ++i)
    {
        // 여분 있는지
        if(Check[i] == 2)
        {
            // 이전 사람 검사
            if(i > 1 && Check[i - 1] == 0)
            {
                --Check[i];
                ++Check[i - 1];
            }
            // 다음 사람 검사
            else if(i < n && Check[i + 1] == 0)
            {
                --Check[i];
                ++Check[i + 1];
            }
        }
    }
    
    for(int i = 1; i < n + 1; ++i)
    {
        if(Check[i] > 0)
            ++answer;
    }
    
    return answer;
}