#define ll long long
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int q = queries.size();

        //max gcd = maximum element in array (eg arr = 4 4 2 1)
        int maxgcd = *max_element(nums.begin(),nums.end()); 

        vector<ll> cntDivisors(maxgcd+1,0);

        for(int i=0;i<n;i++){
            int num = nums[i];
            for(int j=1; j*j <= num; j++){
                //divisors come in pairs, so only go for sqrt(num) ie j*j<=num
                if(num%j == 0){
                    int div1 = j;
                    int div2 = num/j;

                    cntDivisors[div1]++;
                    if(div1 != div2){
                        cntDivisors[div2]++;
                    }
                }
            }
        }

        for(auto it: cntDivisors){
            cout<< it<<" ";
        }
        cout<<endl;

        vector<ll> cntgcd(maxgcd+1,0); //cnt pairs

        for(int g = maxgcd; g>0; g--){
            // nC2 -> number of pairs -> n*(n-1)/2;
            ll t = cntDivisors[g];
            ll cnt = t*1LL*(t-1)/2;
            cntgcd[g] = cnt;

            // reduce the multiples from the gcd array, like if we calculate the gcd pair cnt for 4, then gcd pair cnt for 2 will also contain gcd pair cnt for 4, so we'll need to remove the 2 multiples 
            for(int j=g*1LL*2; j<=maxgcd; j+=g){
                cntgcd[g] -= cntgcd[j];
            } 
        }

        for(auto it: cntgcd){
            cout<< it<<" ";
        }
        cout<<endl;

        // ** GAVE MLE** dont store all the gcds
        // vector<ll> formgcd;

        // int i=0;
        // for(auto &it: cntgcd){
        //     while(it--){
        //         formgcd.push_back(i);
        //     }
        //     i++;
        // }

        // for(auto it: formgcd) cout<<it<<" ";
        // cout<<endl;

        // vector<int> ans;

        // for(auto it: queries){
        //     ans.push_back(formgcd[it]);
        // }

        // Create prefix sum array for cumulative gcd pairs
        vector<ll> prefixSum(maxgcd + 1, 0);
        for (int i = 1; i <= maxgcd; i++) {
            prefixSum[i] = prefixSum[i - 1] + cntgcd[i];
        }

        vector<int> ans;

        // Answer each query by finding the smallest gcd with >= `it+1` pairs
        for (auto it : queries) {
            // Find the smallest gcd such that the number of pairs >= query value
            auto it2 = lower_bound(prefixSum.begin(), prefixSum.end(), it+1) - prefixSum.begin();
            ans.push_back(it2);
        }

        return ans;
    }
};