#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    map<int, int> poketmon;
    
    for(size_t i = 0; i < nums.size(); ++i)
    {
        auto iter = poketmon.find(nums[i]);
        if(iter == poketmon.end())
            poketmon.emplace(nums[i], 1);
        else
            ++poketmon[nums[i]];
    }
    
    answer = min(nums.size() / 2, poketmon.size());
    
    return answer;
}