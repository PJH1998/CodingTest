#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    for(int row = 0; row < b; ++row)
    {
        for(int col = 0; col < a; ++col)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}