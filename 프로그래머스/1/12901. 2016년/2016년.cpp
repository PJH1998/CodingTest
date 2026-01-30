#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    vector<string> str {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    vector<int> month {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int iDay = -1;
    
    for(int i = 0; i < a - 1; ++i)
        iDay += month[i];
    iDay += b;

    iDay = (5 + iDay % 7) % 7;
    
    return str[iDay];
}