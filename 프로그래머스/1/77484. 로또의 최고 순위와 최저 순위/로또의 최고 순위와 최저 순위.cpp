#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int iCorrect = {};
    int iErase = {};
    
    for(int i = 0; i < 6; ++i)
    {
        if(lottos[i] == 0)
        {
            ++iErase;
            continue;
        }

        auto iter = find(win_nums.begin(), win_nums.end(), lottos[i]);
        if(iter != win_nums.end())
            ++iCorrect;
    }
    
    int iMax = 7 - (iCorrect + iErase);
    answer.push_back(min(6, iMax));
    
    int iMin = 7 - iCorrect;
    answer.push_back(min(6, iMin));
    
    return answer;
}