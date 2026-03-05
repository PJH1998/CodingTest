#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct tagNode {
    int iIndex = {};
    int iLength = {};
}NODE;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<bool>> table(n + 1, vector<bool>(n + 1, false));
    
    for(size_t i = 0; i < edge.size(); ++i)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        table[a][b] = true;
        table[b][a] = true;
    }
    
    queue<NODE> q;
    vector<int> BFS(n + 1, 1e9);
    BFS[0] = 0;
    
    NODE node = {};
    node.iIndex = 1;
    node.iLength = 0;
    q.push(node);

    while(!q.empty())
    {
        int iIndex = q.front().iIndex;
        int iLength = q.front().iLength;
        q.pop();
        
        if(BFS[iIndex] <= iLength)
            continue;
        BFS[iIndex] = iLength;
        
        for(size_t i = 1; i < n + 1; ++i)
        {
            if(table[iIndex][i] == true)
            {
                NODE node = {};
                node.iIndex = i;
                node.iLength = iLength + 1;
                q.push(node);
            }
        }
    };
    
    int iMax = *max_element(BFS.begin(), BFS.end());
    
    for(auto& Len : BFS)
    {
        if(iMax == Len)
            ++answer;
    }
    
    return answer;
}