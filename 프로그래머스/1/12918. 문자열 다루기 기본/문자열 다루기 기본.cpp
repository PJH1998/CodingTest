#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    int iLength = s.length();
    
    for(int i = 0; i < iLength; ++i)
    {
        int iNum = s[i] - '0';
        if(iNum > 9 )
            return false;
    }
    
    if(iLength != 4 && iLength != 6)
        return false;
    
    return answer;
}