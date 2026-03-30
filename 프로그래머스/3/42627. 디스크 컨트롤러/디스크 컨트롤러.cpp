#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct tagJob{
    int iIndex = {};
    int iRequest = {};
    int iDuration = {};
}JOB;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    auto cmp = [&](const JOB& Src, const JOB& Dst)->bool{
        if(Src.iDuration == Dst.iDuration)
        {
            if(Src.iRequest == Dst.iRequest)
                return Src.iIndex > Dst.iIndex;
            else
                return Src.iRequest > Dst.iRequest;
        }
        else
            return Src.iDuration > Dst.iDuration;
    };
    
    priority_queue<JOB, vector<JOB>, decltype(cmp)> pq(cmp);
    
    vector<JOB> List(jobs.size());
    for(size_t i = 0; i < jobs.size(); ++i)
    {
        JOB job = {};
        job.iIndex = i;
        job.iRequest = jobs[i][0];
        job.iDuration = jobs[i][1];
        List[i] = job;
    }
    
    sort(List.begin(), List.end(), [&](const JOB& Src, const JOB& Dst)->bool{
       return Src.iRequest > Dst.iRequest; 
    });
    
    int iTime = {};
    
    while(!List.empty() || !pq.empty())
    {
        if(!List.empty() && pq.empty() && iTime < List.back().iRequest)
            iTime = List.back().iRequest;
        
        while(!List.empty() && iTime >= List.back().iRequest)
        {
            JOB job = List.back();
            List.pop_back();
            pq.push(job);
        }
        
        JOB CurJob = pq.top();
        pq.pop();
        
        iTime += CurJob.iDuration;
        answer += iTime - CurJob.iRequest;
        
    };
    
    return answer / jobs.size();
}