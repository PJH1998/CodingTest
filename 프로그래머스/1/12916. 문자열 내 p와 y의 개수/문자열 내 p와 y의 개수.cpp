#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int iNumP = 0;
    int iNumY = 0;
    
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == 'P' || s[i] == 'p')
            ++iNumP;
        else if(s[i] == 'Y' || s[i] == 'y')
            ++iNumY;
    }

    return iNumP == iNumY ? true : false;
}