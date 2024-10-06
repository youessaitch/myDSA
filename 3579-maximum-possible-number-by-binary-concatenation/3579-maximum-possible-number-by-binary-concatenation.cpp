class Solution {
public:
    void binHehe(int n, string &s){
        for(int i=31;i>=0;i--){
            if(n&(1<<i)) s+='1';
            else s+='0';
        }
        int i=0;
        while(s[i]=='0'){
            i++;
        }

        if(i==s.size()){
            s = "0";
        }else{
            s = s.substr(i);
        }
    }

    int maxGoodNumber(vector<int>& nums) {
        int n = nums.size();

        string s1;
        string s2;
        string s3;

        binHehe(nums[0],s1);
        binHehe(nums[1],s2);
        binHehe(nums[2],s3);

        // string s = "";

        // s+=s1;
        // s+=s2;
        // s+=s3;

        vector<string> v;
        v.push_back(s1);
        v.push_back(s2);
        v.push_back(s3);

        int maxi = INT_MIN;

        for(int i=0;i<6;i++){
            next_permutation(v.begin(),v.end());
            int ans = 0;
            int j=0;
            string s = "";
            for(int i=0;i<v.size();i++){
                s+=v[i];
            }
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='1'){
                    ans += pow(2,j);
                }
                j++;
            }
            maxi = max(maxi,ans);
        }

        // sort(s.rbegin(),s.rend());

        
        // cout<<s<<endl;

        

        cout<<s1<<" "<<s2<<" "<<s3<<endl;

        return maxi;
    }
};