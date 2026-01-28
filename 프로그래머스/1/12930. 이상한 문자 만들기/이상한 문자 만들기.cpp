#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int iCount = 0;
    
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == ' ')
        {
            iCount = 0;
            continue;
        }
        
        if(iCount % 2 == 0 && (s[i] >= 'a' && s[i] <= 'z'))
            s[i] = s[i] - ('a' - 'A');
        else if(iCount % 2 == 1 && (s[i] >= 'A' && s[i] <= 'Z'))
            s[i] = s[i] + ('a' - 'A');
        
        ++iCount;
    }
    
    return s;
}