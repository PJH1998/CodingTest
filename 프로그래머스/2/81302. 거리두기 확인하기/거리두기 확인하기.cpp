#include <string>
#include <vector>

using namespace std;

bool Check_Out(int iRow, int iCol)
{
    return iRow < 0 || iRow >= 5 || iCol < 0 || iCol >= 5;
}

bool Check_Around_P(const vector<string>& places, int iRow, int iCol)
{
    int move[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    
    for(int i = 0; i < 4; ++i)
    {
        // 상하좌우 이웃
        int iMove_Row = iRow + move[i][0];
        int iMove_Col = iCol + move[i][1];
        if(false == Check_Out(iMove_Row, iMove_Col))
        {
            if(places[iMove_Row][iMove_Col] == 'P')
                return false;
        }

        // 상하좌우 2칸 이웃
        iMove_Row = iRow + move[i][0] * 2;
        iMove_Col = iCol + move[i][1] * 2;
        if(false == Check_Out(iMove_Row, iMove_Col))
        {
            if(places[iMove_Row][iMove_Col] == 'P')
            {
                if(places[(iRow + iMove_Row) / 2][(iCol + iMove_Col) / 2] == 'O')
                    return false;
            }
        }
        
        // 대각선
        iMove_Row = iRow + move[i][0] + move[(i+1) % 4][0];
        iMove_Col = iCol + move[i][1] + move[(i+1) % 4][1];
        
        if(false == Check_Out(iMove_Row, iMove_Col))
        {
            if(places[iMove_Row][iMove_Col] == 'P')
            {
                int iLeft_Row = iRow + move[i][0];
                int iLeft_Col = iCol + move[i][1];
                if(false == Check_Out(iLeft_Row, iLeft_Col))
                {
                    if(places[iLeft_Row][iLeft_Col] == 'O')
                        return false;
                }

                int iRight_Row = iRow + move[(i+1) % 4][0];
                int iRight_Col = iCol + move[(i+1) % 4][1];
                if(false == Check_Out(iRight_Row, iRight_Col))
                {
                    if(places[iRight_Row][iRight_Col] == 'O')
                        return false;
                }
            }
        }
    }
    
    return true;
}

bool Check_Room(const vector<string>& places)
{
    for(size_t i = 0; i < places.size(); ++i)
    {
        for(int j = 0; j < places[i].length(); ++j)
        {
            if(places[i][j] == 'P' && false == Check_Around_P(places, i, j))
                return false;
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(size_t i = 0; i < places.size(); ++i)
    {
        if(true == Check_Room(places[i]))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}