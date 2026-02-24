#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

void Split(string str, char del, vector<string>& result)
{
    stringstream ss(str);
    string temp;
    
    while(getline(ss, temp, del))
        result.push_back(temp);
}

bool Compute_Delete(string strToday, int iTerm, string strPrivacy)
{
    vector<string> Days;
    Split(strPrivacy, '.', Days);
    
    int iYear{}, iMon{}, iDay{};
    iYear = stoi(Days[0]);
    iMon = stoi(Days[1]);
    iDay = stoi(Days[2]);
    
    iMon += iTerm;
    iDay -= 1;
    
    if(iDay < 1)
    {
        iDay = 28;
        --iMon;
    }
    
    if(iMon > 12)
    {
        if(iMon % 12 > 0)
        {
            iYear += iMon / 12;
            iMon = iMon % 12;
        }
        else
        {
            iYear += iMon / 12 - 1;
            iMon = 12;
        }
      
    }
    
    vector<string> Todays;
    Split(strToday, '.', Todays);
    int iYear_Today{}, iMon_Today{}, iDay_Today{};
    iYear_Today = stoi(Todays[0]);
    iMon_Today = stoi(Todays[1]);
    iDay_Today = stoi(Todays[2]);
    
    if(iYear > iYear_Today)
        return true;
    else if(iYear == iYear_Today)
    {
        if(iMon > iMon_Today)
            return true;
        else if(iMon == iMon_Today)
        {
            if(iDay >= iDay_Today)
                return true;
        }
    }
    
    return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    map<string, int> Terms;
    for(size_t i = 0; i < terms.size(); ++i)
    {
        vector<string> Con;
        Split(terms[i], ' ', Con);
        Terms.emplace(Con[0], stoi(Con[1]));
    }
    
    for(size_t i = 0; i < privacies.size(); ++i)
    {
        vector<string> Con;
        Split(privacies[i], ' ', Con);
        if(false == Compute_Delete(today, Terms[Con[1]], Con[0]))
            answer.push_back(i + 1);
    }
    
    return answer;
}