#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int iRow = board.size();
    int iCol = board[0].size();
    vector<vector<int>> sum(iRow + 1, vector<int>(iCol + 1, 0));
    
    for(size_t i = 0; i < skill.size(); ++i)
    {
        int iTop = skill[i][1];
        int iLeft = skill[i][2];
        int iBottom = skill[i][3];
        int iRight = skill[i][4];
        
        int iDegree = skill[i][0] == 1 ? skill[i][5] : skill[i][5] * -1;
        sum[iTop][iLeft] += iDegree;
        sum[iBottom + 1][iRight + 1] += iDegree;
        sum[iTop][iRight + 1] -= iDegree;
        sum[iBottom + 1][iLeft] -= iDegree;
    }
    
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        {
            int iLeft{}, iUp{}, iLU{};
            if(j - 1 >= 0)
                iLeft = sum[i][j-1];
            if(i - 1 >= 0)
                iUp = sum[i-1][j];
            if(j - 1 >= 0 && i - 1 >= 0)
                iLU = sum[i-1][j-1];
            
            sum[i][j] += iLeft + iUp - iLU;
            
            if(board[i][j] - sum[i][j] > 0)
                ++answer;
        }
    }
    
    return answer;
}