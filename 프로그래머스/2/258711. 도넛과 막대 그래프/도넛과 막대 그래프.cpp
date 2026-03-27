#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct tagNode {
    vector<int> Out;
    vector<int> In;
}NODE;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    
    // 노드 연결 정리
    map<int, NODE> Nodes;
    for(size_t i = 0; i < edges.size(); ++i)
    {
        int iLeft = edges[i][0];
        int iRight = edges[i][1];
        
        if(Nodes.find(iLeft) == Nodes.end())
            Nodes.emplace(iLeft, NODE{});
        if(Nodes.find(iRight) == Nodes.end())
            Nodes.emplace(iRight, NODE{});
        
        Nodes[iLeft].Out.push_back(iRight);
        Nodes[iRight].In.push_back(iLeft);
    }
    vector<bool> Visit(Nodes.size() + 1, false);
    
    // 생성 노드 탐색
    int iStart = {};
    for(auto& Pair : Nodes)
    {
        if(Pair.second.Out.size() >= 2 && Pair.second.In.size() == 0)
        {
            iStart = Pair.first;
            break;
        }
    }
    answer[0] = iStart;
    
    // 그래프 개수 확인
    for(size_t i = 0; i < Nodes[iStart].Out.size(); ++i)
    {
        int iOut = Nodes[iStart].Out[i];
        
        queue<int> q;
        q.push(iOut);
        
        int iNumNode = {};
        int iNumEdge = {};
        
        bool isEight = false;
        while(!q.empty())
        {
            int iNode = q.front();
            q.pop();
            
            if(Nodes[iNode].Out.size() == 2 && Nodes[iNode].In.size() >= 2)
            {
                isEight = true;
                break;
            }
            
            if(Visit[iNode] == false)
            {
                Visit[iNode] = true;
                ++iNumNode;
            }
            
            if(Nodes[iNode].Out.size() == 0)
                continue;
            
            int iNext = Nodes[iNode].Out.back();
            Nodes[iNode].Out.pop_back();
            q.push(iNext);
            ++iNumEdge;
        }
        // 8
        if(isEight || iNumNode + 1 == iNumEdge)
            ++answer[3];
        // 막대
        else if(iNumNode == iNumEdge + 1)
            ++answer[2];
        // 도넛
        else if(iNumNode == iNumEdge)
            ++answer[1];
    }
    
    return answer;
}