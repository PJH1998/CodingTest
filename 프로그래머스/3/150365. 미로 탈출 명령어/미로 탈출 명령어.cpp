#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct tagNode {
    
    tagNode(int r, int c, int d, string str)
        : iRow(r), iCol(c), iDepth(d), strRoute(str)
    {}
    
    int iRow = {};
    int iCol = {};
    int iDepth = {};
    string strRoute = "";
}NODE;

// d -> l -> r -> u
string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int iRowGap = abs(r - x);
    int iColGap = abs(c - y);
    int iMinLength = iRowGap + iColGap;
    
    if(iMinLength > k || (k - iMinLength) % 2 == 1)
        return "impossible";
    
    int iMove[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    char Dir[4] = {'u', 'r', 'l', 'd'};
    stack<NODE> DFS;
    NODE node = {x - 1, y - 1, 0, ""};
    DFS.push(node);
    
    while(!DFS.empty())
    {
        NODE node = DFS.top();
        DFS.pop();
        
        // 도달
        if(node.iDepth == k)
        {
            answer = node.strRoute;
            continue;
        }
        
        for(int i = 0; i < 4; ++i)
        {
            int iMove_Row = node.iRow + iMove[i][0];
            int iMove_Col = node.iCol + iMove[i][1];
            if(iMove_Row < 0 || iMove_Row >= n || iMove_Col < 0 || iMove_Col >= m)
                continue;
            
            NODE next = {iMove_Row, iMove_Col, node.iDepth + 1, node.strRoute + Dir[i]};
            // 남은 길이 가능 여부
            int iLength = abs(next.iRow - (r - 1)) + abs(next.iCol - (c - 1));
            if(iLength > k - next.iDepth)
                continue;
            
            // Route 비교
            if(answer != "" && answer < next.strRoute)
                continue;
            
            DFS.push(next);
        }
    }
    
    return answer;
}