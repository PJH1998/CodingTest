#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> check;
    
    for(auto& name : participant)
    {
        auto iter = check.find(name);
        if(iter == check.end())
            check.emplace(name, 0);
        ++check[name];
    }
    
    for(auto& name : completion)
        --check[name];
    
    for(auto& Pair : check)
    {
        if(Pair.second > 0)
        {
            answer = Pair.first;
            break;
        }
    }
    
    return answer;
}