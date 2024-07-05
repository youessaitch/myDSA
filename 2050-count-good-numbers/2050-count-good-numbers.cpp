class Solution {
public:
    int m = 1e9+7;
    #define ll long long
    ll binExp(ll a, ll b, ll p)
    {
        ll ans = 1;
        while (b > 0)
        {
            if (b & 1)
                ans = (ans * 1LL * a) % p;
            a = (a * 1LL * a) % p;
            b >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        // - - - -
        // 5 4 5 4 
        if(n==1) return 5;
        long long ans = 1;
        if(n%2==1){
            long long even = n/2 + 1;
            long long prime = n - even;
            long long Evenans = binExp(5,even,m);
            long long Primeans = binExp(4,prime,m);
            ans = (Evenans*Primeans)%m;
        }else{
            long long even = n/2;
            ans = binExp(20,even,m);
        }
        return ans;
    }
};