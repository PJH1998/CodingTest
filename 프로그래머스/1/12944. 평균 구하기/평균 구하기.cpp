#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    double sum = 0;
    
    for(auto& num : arr)
        sum += num;
    
    int iSize = arr.size();
    
    answer = sum / static_cast<double>(iSize);
    
    return answer;
}