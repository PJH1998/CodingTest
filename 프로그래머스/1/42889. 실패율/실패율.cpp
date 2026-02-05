#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Desc(pair<int, float> A, pair<int, float> B)
{
    if(A.second == B.second)
        return A.first < B.first;
    return A.second > B.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // 실패율
    vector<pair<int, float>> FailRate(N, make_pair(0, 0));
    // 성공한 사람
    vector<int> Clear(N, 0);
    // 도달한 사람
    vector<int> User(N + 1, 0);
    
    sort(stages.begin(), stages.end(), greater<>());
    
    for(size_t i = 0; i < stages.size(); ++i)
        ++User[stages[i] - 1];
    
    for(int i = N - 1; i >= 0; --i)
    {
        Clear[i] += User[i + 1];
        User[i] += User[i + 1];
    }
        
    for(int i = 0; i < N; ++i)
        FailRate[i] = make_pair(i + 1, max(0.f, (User[i] - Clear[i]) / static_cast<float>(User[i])));
    
    sort(FailRate.begin(), FailRate.end(), Desc);
    
    for(int i = 0; i < N; ++i)
        answer.push_back(FailRate[i].first);
    
    return answer;
}