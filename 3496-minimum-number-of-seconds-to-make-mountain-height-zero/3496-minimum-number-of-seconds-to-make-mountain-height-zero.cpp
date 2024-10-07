#define ll long long
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTime) {
        int n = workerTime.size();
        ll maxi = *max_element(workerTime.begin(),workerTime.end());
        ll lo = 0;
        ll hi = maxi*(mountainHeight*(mountainHeight+1LL)/2);
        ll ans;

        while(lo<=hi){
            ll mid = lo+(hi-lo)/2; //time

            ll height = 0; //checking what height we can form in the time 'mid'
            for(auto &it: workerTime){
                ll cycleByWorker = mid/it; //workers are working simultaneously
                height += (-1 + sqrt(1 + 4 * 2 * cycleByWorker)) / 2; // height that worker can reduce
            }

            if(height >= mountainHeight){ 
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
        
    }
};