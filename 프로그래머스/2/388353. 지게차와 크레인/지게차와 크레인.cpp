#include <string>
#include <vector>

using namespace std;

bool Dispatch(const vector<string>& table, vector<vector<int>>& Mapping, int iRow, int iCol, int iDepth)
{
    if(iRow < 0 || iRow >= table.size() || iCol < 0 || iCol >= table[0].length())
        return true;
    
    if(Mapping[iRow][iCol] != 0 || (iDepth > 0 && table[iRow][iCol] != '0'))
        return false;
    
    Mapping[iRow][iCol] = 1;
    
    int iDir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    for(int i = 0; i < 4; ++i)
    {
        if(true == Dispatch(table, Mapping, iRow + iDir[i][0], iCol + iDir[i][1], iDepth + 1))
            return true;
    }
    
    return false;
}

void Fork(const vector<string>& table, vector<string>& storage, const char alpha)
{
    for(size_t i = 0; i < table.size(); ++i)
    {
        for(int j = 0; j < table[i].length(); ++j)
        {
            if(table[i][j] == alpha)
            {
                vector<vector<int>> Mapping(table.size(), vector<int>(table[0].length(), 0));
                if(true == Dispatch(table, Mapping, i, j, 0))
                {
                    storage[i][j] = '0';
                }    
            }
        }
    }
}

void Crain(vector<string>& storage, const char alpha)
{
    for(size_t i = 0; i < storage.size(); ++i)
    {
        for(int j = 0; j < storage[i].length(); ++j)
        {
            if(storage[i][j] == alpha)
                storage[i][j] = '0';
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    for(size_t i = 0; i < requests.size(); ++i)
    {
        vector<string> table = storage;
        
        // 지게차
        if(requests[i].length() == 1)
        {
            Fork(table, storage, requests[i][0]);
        }
        // 크레인
        else
        {
            Crain(storage, requests[i][0]);
        }
    }
    
    for(size_t i = 0; i < storage.size(); ++i)
    {
        for(int j = 0; j < storage[i].length(); ++j)
        {
            if(storage[i][j] != '0')
                ++answer;
        }
    }
    
    return answer;
}