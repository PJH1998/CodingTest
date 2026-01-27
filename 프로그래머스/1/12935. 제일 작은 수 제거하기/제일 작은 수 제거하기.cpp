#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size() == 1)
        answer.push_back(-1);
    else
    {
        auto iter = min_element(arr.begin(), arr.end());
        arr.erase(iter);
        answer = arr;
    }

    return answer;
}