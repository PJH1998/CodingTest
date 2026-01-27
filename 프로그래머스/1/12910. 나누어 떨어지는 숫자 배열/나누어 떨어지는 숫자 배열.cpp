#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(auto& iNum : arr)
    {
        if(iNum % divisor == 0)
            answer.push_back(iNum);
    }
    
    if(answer.size() == 0)
        answer.push_back(-1);
    
    sort(answer.begin(), answer.end());
    
    return answer;
}