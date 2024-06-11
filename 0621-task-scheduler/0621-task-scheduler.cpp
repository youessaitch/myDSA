class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++) freq[tasks[i]-'A']++;

        //taking pq bcuz we want the char with max freq on top
        priority_queue<int> pq; //max heap

        for(auto it: freq){
            if(it>0) pq.push(it);
        }

        int cnt = 0;

        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int f = pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                }
            }

            for(auto t: temp){
                if(t>0) pq.push(t);
            }

            if(!pq.empty()){
                cnt+=n+1;
            }else{
                cnt+=temp.size();
            }
            
        }
        return cnt;
    }
};