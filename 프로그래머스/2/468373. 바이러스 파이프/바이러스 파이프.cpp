#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(vector<int> Cells, const vector<vector<int>>& table, int iPipe, int iDepth, int k)
{
    if(iDepth >= k)
        return Cells.size();
    
    ++iDepth;
    
    for(size_t i = 0; i < Cells.size(); ++i)
    {
        int iCell = Cells[i];
        for(size_t j = 0; j < table[iCell].size(); ++j)
        {
            if(table[iCell][j] == iPipe && find(Cells.begin(), Cells.end(), j) == Cells.end())
            {
                Cells.push_back(j);
            }
        }
    }
    
    return max(DFS(Cells, table, 1, iDepth, k), 
               max(DFS(Cells, table, 2, iDepth, k), DFS(Cells, table, 3, iDepth, k)));
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    vector<int> Cells;
    Cells.push_back(infection);
    
    for(size_t i = 0; i < edges.size(); ++i)
    {
        for(size_t j = 0; j < edges[i].size(); ++j)
        {
            table[edges[i][0]][edges[i][1]] = edges[i][2];
            table[edges[i][1]][edges[i][0]] = edges[i][2];
        }
    }
    
    answer = max(DFS(Cells, table, 1, 0, k), max(DFS(Cells, table, 2, 0, k), DFS(Cells, table, 3, 0, k)));
    
    return answer;
}