#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int iWallet_Max = max(wallet[0], wallet[1]);
    int iWallet_Min = min(wallet[0], wallet[1]);
    
    int iBill_Max = max(bill[0], bill[1]);
    int iBill_Min = min(bill[0], bill[1]);
    
    while(iBill_Max > iWallet_Max || iBill_Min > iWallet_Min)
    {
        ++answer;
        iBill_Max /= 2;
        
        if(iBill_Max < iBill_Min)
            swap(iBill_Max, iBill_Min);
    }
    
    return answer;
}