#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    int iSum = accumulate(d.begin(), d.end(), 0);
    sort(d.begin(), d.end());
    
    while(d.size() > 0)
    {
        if(iSum <= budget)
            break;
        iSum -= d.back();
        d.pop_back();
    }
    
    return d.size();
}