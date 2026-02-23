#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> Stack;
    
    for(size_t i = 0; i < moves.size(); ++i)
    {
        int iSelect = moves[i] - 1;

        int iDoll = {};
        for(int j = 0; j < board.size(); ++j)
        {
            if(board[j][iSelect] > 0)
            {
                iDoll = board[j][iSelect];
                board[j][iSelect] = 0;
                break;
            }
        }
        
        if(iDoll == 0)
            continue;
        
        if(Stack.size() > 0 && Stack.back() == iDoll)
        {
            answer += 2;
            Stack.pop_back();
        }
        else
            Stack.push_back(iDoll);
    }
    
    return answer;
}