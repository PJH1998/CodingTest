#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool Desc(pair<char, string> A, pair<char, string> B)
{
    if(A.first == B.first)
        return A.second < B.second;
    return A.first < B.first;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    vector<pair<char, string>> list;
    
    for(size_t i = 0; i < strings.size(); ++i)
    {
        pair<char, string> p = make_pair(strings[i][n], strings[i]);
        list.push_back(p);
    }
    
    sort(list.begin(), list.end(), Desc);
    
    for(size_t i = 0; i < list.size(); ++i)
        answer.push_back(list[i].second);
    
    return answer;
}