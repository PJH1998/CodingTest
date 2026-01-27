#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;

    while(num <= n)
    {
        ++answer;

        int iRemain = num % w;
        if(iRemain == 0)
            num = num + 1;
        else
            num = num + (w - iRemain) * 2 + 1;
    }

    return answer;
}