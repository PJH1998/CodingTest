#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<>());
    
    for(size_t i = 0; i < score.size(); i += m)
    {
        int iMinIndex = i + m - 1;
        if(iMinIndex >= score.size())
            break;
        answer += score[iMinIndex] * m;
    }
    
    return answer;
}