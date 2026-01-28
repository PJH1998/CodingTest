#include <string>
#include <vector>

#define THS 1e9

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    vector<int> Alpha(26, THS);
    
    for(size_t i = 0; i < keymap.size(); ++i)
    {
        for(int j = 0; j < keymap[i].length(); ++j)
        {
            if(Alpha[keymap[i][j] - 'A'] > j + 1)
                Alpha[keymap[i][j] - 'A'] = j + 1;
        }
    }
    
    for(size_t i = 0; i < targets.size(); ++i)
    {
        int iSum = 0;
        for(int j = 0; j < targets[i].length(); ++j)
        {
            if(Alpha[targets[i][j] - 'A'] == THS)
            {
                answer.push_back(-1);
                iSum = 0;
                break;
            }
            iSum += Alpha[targets[i][j] - 'A'];
        }
        if(iSum > 0)
            answer.push_back(iSum);
    }
    
    return answer;
}