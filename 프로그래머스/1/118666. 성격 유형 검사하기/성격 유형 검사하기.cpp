#include <string>
#include <vector>
#include <map>

using namespace std;

char Select(map<char, int>& Count, char A, char B)
{
    if(Count[A] == Count[B])
    {
        if(A < B)
            return A;
        else
            return B;
    }
    else if(Count[A] < Count[B])
        return B;
    else
        return A;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> Count;
    Count.emplace('R', 0);
    Count.emplace('T', 0);
    Count.emplace('C', 0);
    Count.emplace('F', 0);
    Count.emplace('J', 0);
    Count.emplace('M', 0);
    Count.emplace('A', 0);
    Count.emplace('N', 0);
    
    for(size_t i = 0; i < survey.size(); ++i)
    {
        int iScore = abs(choices[i] - 4);
        // 동의
        if(choices[i] > 3)
            Count[survey[i][1]] += iScore;
        else
            Count[survey[i][0]] += iScore;
    }
    
    answer += Select(Count, 'R', 'T');
    answer += Select(Count, 'C', 'F');
    answer += Select(Count, 'J', 'M');
    answer += Select(Count, 'A', 'N');
    
    return answer;
}