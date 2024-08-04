class Solution {
public:
    int m = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        multiset<int> st;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                st.insert(sum);
            }
        }
        int i=0;
        bool ch = false;
        int ans = 0;
        for(auto it: st){
            if(i==left-1){
                cout<<"left: "<< i<<endl;
                ch = true;
            }

            if(ch){
                ans = (ans+it)%m;
                // ans=ans%m; 
            }
            if(i==right-1){ 
                cout<<"left: "<< i<<endl;
                break;
            }
            i++;
        }
        return ans;
    }
};