#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    queue<int> Servers;
    
    for(size_t i = 0; i < players.size(); ++i)
    {
        while(Servers.size() > 0 && i - Servers.front() >= k)
            Servers.pop();
        
        while(Servers.size() < players[i] / m)
        {
            Servers.push(i);
            ++answer;
        }
    }
    
    return answer;
}