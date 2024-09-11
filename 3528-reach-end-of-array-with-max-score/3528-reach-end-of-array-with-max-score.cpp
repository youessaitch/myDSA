#define ll long long
class Solution {
public:
    int n;
    long long findMaximumScore(vector<int>& nums) {
        n = nums.size();

        //lets calculate index of next greater element using stack
        vector<ll> nger(n,-1);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty() && nums[st.top()]>nums[i]) nger[i]=st.top();
            st.push(i);
        }

        //debug
        // for(int i=0;i<n;i++){
        //     cout<<nger[i]<<" ";
        // }
        // cout<<endl;

        ll cnt = 0; 
        ll i = 0; //index

        while(i<n){
            if(nger[i]==-1){ //if we encounter theres no more greater element to right then take all the indices upto last
                cnt += (ll)nums[i] * (n - 1 - i);
                break;
            }

            //else calculate upto the next greater element
            cnt += (ll)nums[i]*(nger[i]-i);
            i = nger[i];
        }
        return cnt;
    }   
};