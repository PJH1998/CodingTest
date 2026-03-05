#include <string>
#include <vector>
#include <climits>
#include <deque>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = INT_MAX;
    
    deque<pair<int, int>> table;
    
    for(size_t i = 0; i < stones.size(); ++i)
    {
        pair<int, int> p = make_pair(stones[i], i);
        while(table.size() > 0 && table.back().first <= p.first)
            table.pop_back();
        
        table.push_back(p);

        int iMin = i - k;
        while(table.size() > 0 && table.front().second <= iMin)
            table.pop_front();  
        
        if(i >= k - 1 && table.front().first < answer)
            answer = table.front().first;
        
    }
    
    return answer;
}