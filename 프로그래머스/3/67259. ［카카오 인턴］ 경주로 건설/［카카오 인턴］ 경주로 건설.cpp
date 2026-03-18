#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef struct tagInfo {
    
    tagInfo(int _iRow, int _iCol, int _iCharge, int _iDir)
        : iRow(_iRow), iCol(_iCol), iCharge(_iCharge), iDir(_iDir)
    {};
    
    int iRow = {};
    int iCol = {};
    int iCharge = {};
    int iDir = {};
}INFO;

bool CanMove(const vector<vector<int>>& board, pair<int, int>& Move)
{
    if(Move.first < 0 || Move.first >= board.size() 
        || Move.second < 0 || Move.second >= board.size())
        return false;
    
    if(board[Move.first][Move.second] == 1)
        return false;
    
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int N = board.size();
    
    queue<INFO> BFS;
    vector<vector<int>> charge(N, vector<int>(N, INT_MAX));
    
    BFS.push(INFO(N-1, N-1, 0, -1));
    charge[N-1][N-1] = 0;
    
    while(!BFS.empty())
    {
        pair<int, int> XY = make_pair(BFS.front().iRow, BFS.front().iCol);
        int iPreCharge = BFS.front().iCharge;
        int iDir = BFS.front().iDir;
        BFS.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            pair<int, int> Move = make_pair(XY.first + dir[i][0], XY.second + dir[i][1]);
            if(false == CanMove(board, Move))
                continue;
            
            int iCharge = iPreCharge;
            if(iDir == i || iDir == -1)
                iCharge += 100;
            else
                iCharge += 600;
            
            if(iCharge <= charge[Move.first][Move.second])
            {
                BFS.push(INFO(Move.first, Move.second, iCharge, i));
                charge[Move.first][Move.second] = iCharge;
            }
        }
    }
    
    answer = charge[0][0];
    
    return answer;
}