#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1, 2단계
    for(auto iter = new_id.begin(); iter != new_id.end();)
    {
        if(*iter >= 'A' && *iter <= 'Z')
            *iter = *iter - 'A' + 'a';
        if((*iter >= 'a' && *iter <= 'z') || 
           (*iter >= '0' && *iter <= '9') || 
           *iter == '-' || *iter == '_' || *iter == '.')
        {
            ++iter;
            continue;
        }
        iter = new_id.erase(iter);
    }
    
    // 3단계
    while(true)
    {
        int iPos = new_id.find("..");
        if(iPos == string::npos)
            break;
        new_id.replace(iPos, 2, ".");
    }
    
    // 4단계
    if(new_id[0] == '.')
        new_id.erase(new_id.begin());
    if(new_id[new_id.length() - 1] == '.')
        new_id.erase(new_id.end() - 1);
    
    // 5단계
    if(new_id.length() == 0)
        new_id = "a";
    
    // 6단계
    if(new_id.length() >= 16)
        new_id.erase(15, new_id.length() - 15);
    if(new_id[new_id.length() - 1] == '.')
        new_id.erase(new_id.end() - 1);
    
    // 7단계
    while(new_id.length() < 3)
        new_id += new_id[new_id.length() - 1];
    
    return new_id;
}