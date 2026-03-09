#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

bool Check_AllRoute(const map<string, int>& Check)
{
    for(auto& Pair : Check)
    {
        if(Pair.second > 0)
            return false;
    }
    
    return true;
}

bool DFS(vector<string>& answer, map<string, vector<string>>& Route, map<string, int>& Check, string str)
{  
    answer.push_back(str);
    
    if(true == Check_AllRoute(Check))
        return true;
    
    for(size_t i = 0; i < Route[str].size(); ++i)
    {
        string strKey = str + Route[str][i];

        if(Check[strKey] > 0)
        {
            --Check[strKey];
            if(true == DFS(answer, Route, Check, Route[str][i]))
                return true;
            else
                ++Check[strKey];
                
        }
    }

    answer.pop_back();
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    map<string, vector<string>> Route;
    map<string, int> Check;
    
    // 초기화
    for(size_t i = 0; i < tickets.size(); ++i)
    {
        auto iter = Route.find(tickets[i][0]);
        if(iter == Route.end())
        {
            vector<string> v;
            v.push_back(tickets[i][1]);
            Route.emplace(tickets[i][0], v);
        }
        else
        {
            Route[tickets[i][0]].push_back(tickets[i][1]);
        }
        
        sort(Route[tickets[i][0]].begin(), Route[tickets[i][0]].end());
        
        string str = tickets[i][0] + tickets[i][1];
        
        if(Check.find(str) == Check.end())
            Check.emplace(str, 1);
        else
            ++Check[str];
    }
    
    DFS(answer, Route, Check, "ICN");
    
    return answer;
}