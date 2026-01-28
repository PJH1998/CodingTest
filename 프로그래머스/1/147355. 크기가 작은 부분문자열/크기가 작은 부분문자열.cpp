#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    //long long iNum_p = stoi(p);
    int iLength_p = p.length();
    
    for(int i = 0; i < t.length() - iLength_p + 1; ++i)
    {
        string str = t.substr(i, iLength_p);
        //long long iNum_s = stoi(str);
        
        if(str <= p)
            ++answer;
    }
    
    return answer;
}