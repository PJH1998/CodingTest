#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int iWidth = 0;
    int iHeight = 0;
    
    for(size_t i = 0; i < sizes.size(); ++i)
    {
        if(sizes[i][0] < sizes[i][1])
            swap(sizes[i][0], sizes[i][1]);
        
        if(iWidth < sizes[i][0])
            iWidth = sizes[i][0];
        if(iHeight < sizes[i][1])
            iHeight = sizes[i][1];
    }

    
    return iWidth * iHeight;
}