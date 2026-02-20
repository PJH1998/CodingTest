#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int iDir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int iRow{}, iCol{};
    int iLength_Row = board.size();
    int iLength_Col = board[0].size();
    
    for(int i = 0; i < 4; ++i)
    {
        iRow = h + iDir[i][1];
        iCol = w + iDir[i][0];
        if(iRow < 0 || iRow >= iLength_Row)
            continue;
        if(iCol < 0 || iCol >= iLength_Col)
            continue;
        if(board[h][w] == board[iRow][iCol])
            ++answer;
    }
    
    return answer;
}