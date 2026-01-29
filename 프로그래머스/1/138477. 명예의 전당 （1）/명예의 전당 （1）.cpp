#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    vector<int> minscore;
    
    for(size_t i = 0; i < score.size(); ++i)
    {
        if(minscore.size() < k)
        {
            minscore.push_back(score[i]);
        }
        else if(minscore.back() < score[i])
        {
            minscore.pop_back();
            minscore.push_back(score[i]);
        }
        sort(minscore.begin(), minscore.end(), greater<>());
        answer.push_back(minscore.back());
    }
    
    return answer;
}