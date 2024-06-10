#define ll long long
using pii = pair<ll, ll>;
#define F first
#define S second
#define vi vector<int>
#define vii vector<pii>
#define vll vector<ll>
#define vvi vector<vector<ll>>
#define fo(i, n) for (ll i = 0; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i < n; i++)
#define fo2(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define all(x) x.begin(), x.end()

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        int cnt = 0;
        fo(i,n){
            if(nums[i]==1){
                cnt++;
                maxi = max(maxi,cnt); 
            }else cnt=0;
        }
        return maxi;
    }
};