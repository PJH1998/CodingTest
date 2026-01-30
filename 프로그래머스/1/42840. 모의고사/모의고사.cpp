#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> pick1 {1,2,3,4,5};
    vector<int> pick2 {2,1,2,3,2,4,2,5};
    vector<int> pick3 {3,3,1,1,2,2,4,4,5,5};
    
    vector<int> score(3, 0);
    
    for(size_t i = 0; i < answers.size(); ++i)
    {
        if(answers[i] == pick1[i % pick1.size()])
            ++score[0];
        if(answers[i] == pick2[i % pick2.size()])
            ++score[1];
        if(answers[i] == pick3[i % pick3.size()])
            ++score[2];
    }
    
    int iMax = *max_element(score.begin(), score.end());
    
    for(int i = 0; i < 3; ++i)
    {
        if(iMax == score[i])
            answer.push_back(i+1);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}