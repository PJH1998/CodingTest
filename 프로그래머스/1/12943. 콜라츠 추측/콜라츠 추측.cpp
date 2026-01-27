#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    long long llNum = num;
    
    while(llNum != 1)
    {
        if(answer >= 500)
            return -1;
        
        ++answer;
        
        llNum = (llNum % 2 == 0) ? llNum / 2 : llNum * 3 + 1;
    }
    
    return answer;
}