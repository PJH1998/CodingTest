#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string CreateKey(const vector<int>& Comb)
{
    string str = "";
    for(size_t i = 0; i < Comb.size(); ++i)
    {
        if(Comb[i] == 1)
            str += '0' + i;
    }
    
    return str;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    vector<string> Key;
    
    int iCol = relation[0].size();
    
    for(int i = 0; i < iCol; ++i)
    {
        vector<int> Comb(iCol, 0);
        for(int j = 0; j < i + 1; ++j)
            Comb[iCol - j - 1] = 1;
        
        do
        {
            bool isFlag = false;
            string str = CreateKey(Comb);
            for(size_t k = 0; k < Key.size(); ++k)
            {
                int iCnt = 0;
                for(int iLen = 0; iLen < str.length(); ++iLen)
                {
                    if(Key[k].find(str[iLen]) != string::npos)
                        ++iCnt;
                }
                if(iCnt == Key[k].length())
                {
                    isFlag = true;
                    break;
                }
            }
            
            if(false == isFlag)
            {
                vector<string> CK;
                for(size_t iRow = 0; iRow < relation.size(); ++iRow)
                {
                    string strCanKey = "";
                    for(int iLen = 0; iLen < str.length(); ++iLen)
                    {
                        strCanKey += relation[iRow][str[iLen] - '0'];
                    }
                    if(find(CK.begin(), CK.end(), strCanKey) == CK.end())
                        CK.push_back(strCanKey);
                    else
                    {
                        break;
                    }
                }
                if(CK.size() == relation.size())
                    Key.push_back(str);
            }
            
        }while(next_permutation(Comb.begin(), Comb.end()));
    }
    
    return Key.size();
}