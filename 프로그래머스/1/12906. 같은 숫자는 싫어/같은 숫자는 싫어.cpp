#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int iNum = -1;

    for(size_t i = 0; i < arr.size(); ++i)
    {
        if(iNum != arr[i])
        {
            answer.push_back(arr[i]);
            iNum = arr[i];
        }
    }
    
    return answer;
}