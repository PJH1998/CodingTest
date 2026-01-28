#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if(n > m)
        swap(n, m);
    
    int iNum = n;
    
    // 최대공약수
    while(iNum > 0)
    {
        if(n % iNum == 0 && m % iNum == 0)
            break;
        --iNum;
    }
    answer.push_back(iNum);
    
    // 최소공배수
    answer.push_back(n * m / iNum);
    
    return answer;
}