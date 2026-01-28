#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    sort(number.begin(), number.end());
    
    for(int i = 0; i < number.size(); ++i)
    {
        if(number[i] > 0)
            break;
        for(int j = number.size() - 1; j > i; --j)
        {
            if(number[j] + number[i] > abs(number[i]))
                continue;
            for(int k = i + 1; k < j; k++)
            {
                if(number[i] + number[j] + number[k] == 0)
                    ++answer;
            }
        }
    }
    
    return answer;
}