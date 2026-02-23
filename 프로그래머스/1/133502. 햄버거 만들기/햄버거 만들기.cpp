#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int> Stack;
    
    for(size_t i = 0; i < ingredient.size(); ++i)
    {
        Stack.push_back(ingredient[i]);
        
        if(Stack.size() >= 4)
        {
            int iSize = Stack.size();
            if(Stack[iSize - 4] == 1 && Stack[iSize - 3] == 2 
               && Stack[iSize - 2] == 3 && Stack[iSize - 1] == 1)
            {
                ++answer;
                for(int j = 0; j < 4; ++j)
                    Stack.pop_back();
            }    
        }
    }
    
    return answer;
}