#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int Compute_Length(pair<int, int>& Keypad, pair<int, int>& Hand)
{
    return abs(Keypad.first - Hand.first) + abs(Keypad.second - Hand.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    map<int, pair<int, int>> Keypad;
    
    for(int i = 1; i <= 9; ++i)
        Keypad.emplace(i, make_pair((i - 1) % 3, (i - 1) / 3));
    Keypad.emplace(0, make_pair(1, 3));
    
    pair<int, int> Left = make_pair(0, 3);
    pair<int, int> Right = make_pair(2, 3);
    
    for(size_t i = 0; i < numbers.size(); ++i)
    {
        // 1, 4, 7
        if(numbers[i] % 3 == 1)
        {
            answer += "L";
            Left = Keypad[numbers[i]];
        }
        // 3, 6, 9
        else if(numbers[i] > 0 && numbers[i] % 3 == 0)
        {
            answer += "R";
            Right = Keypad[numbers[i]];
        }
        // 2, 5, 8, 0
        else
        {
            int iLeft_Length = Compute_Length(Keypad[numbers[i]], Left);
            int iRight_Length = Compute_Length(Keypad[numbers[i]], Right);

            if(iLeft_Length < iRight_Length)
            {
                answer += "L";
                Left = Keypad[numbers[i]];
            }
            else if(iLeft_Length > iRight_Length)
            {
                answer += "R";
                Right = Keypad[numbers[i]];
            }
            else
            {
                if(hand == "left")
                {
                    answer += "L";
                    Left = Keypad[numbers[i]];
                }
                else
                {
                    answer += "R";
                    Right = Keypad[numbers[i]];
                }
            }
        }
    }
    
    return answer;
}