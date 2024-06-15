class Solution {
    #define pii pair<int,int>

// private:
//     struct compare{
//         bool operator()(const pii &a, const pii &b){
//             return ((a.first>b.first) || ((a.first == b.first) && (a.second < b.second)));
//         }
//     };

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();   
        vector<pii> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end()); 
        // 1 1
        // 1 2
        // 2 3
        priority_queue<int> pq;
        int i = 0;

        while(k--){
            while(i<n && arr[i].first <= w){
                pq.push(arr[i].second);
                i++;
            }
            //3
            //2
            //1

            if(pq.empty()) break; //ek v chota nhi so not possible further
            w += pq.top();
            pq.pop();
        }

        return w;


        // int n = profits.size();
        // priority_queue<pii,vector<pii>,compare> pq; //min heap
        // for(int i=0;i<n;i++) pq.push({capital[i],profits[i]});

        // // for(int i=0;i<n;i++){
        // //     auto it = pq.top();
        // //     pq.pop();
        // //     auto cap = it.first;
        // //     auto pro = it.second;
        // //     cout<<cap<<" "<<pro<<endl;
        // // }

        // // return 0;

        // int cnt = 0;
        // int wc = w;
        // // int ans = 0;
        // while(!pq.empty()){
        //     auto it = pq.top();
        //     pq.pop();
        //     auto cap = it.first;
        //     auto pro = it.second;
        //     if(cap<=wc){
        //         // ans += pro;
        //         wc+=pro;
        //         cnt++;
        //     }
        //     if(cnt>=k) break;
        // }

        // return wc;
    }
};