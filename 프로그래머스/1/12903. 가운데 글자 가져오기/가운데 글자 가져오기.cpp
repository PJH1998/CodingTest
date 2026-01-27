#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int iLength = s.length();

    return (iLength % 2 == 0) ? s.substr(iLength/2-1, 2) : s.substr(iLength/2, 1);
}