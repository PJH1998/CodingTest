#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; ++i)
    {
        int iNum = arr1[i] | arr2[i];
        string str = "";
        for(int j = n - 1; j >= 0; --j)
        {
            if(iNum & static_cast<int>(pow(2, j)))
                str.push_back('#');
            else
                str.push_back(' ');
        }
        answer.push_back(str);
    }
    
    return answer;
}