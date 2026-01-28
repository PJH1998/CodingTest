#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {

    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == ' ')
            continue;
        
        int iNum = static_cast<int>(s[i]) + n;
        
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            int iGap = iNum - static_cast<int>('Z');
            if(iGap > 0)
                s[i] = 'A' + (iGap - 1);
            else
                s[i] = s[i] + n;
        }
        else if(s[i] >= 'a' && s[i] <= 'z')
        {
            int iGap = iNum - static_cast<int>('z');
            if(iGap > 0)
                s[i] = 'a' + (iGap - 1);
            else
                s[i] = s[i] + n;
        }
        
    }
        
    return s;
}