class Solution {
public:
    int countPrimes(int n) {
        // if(n==2) return 0;
        bool prime[n + 1];
        // vector<int> pr;
        int cnt = 0;
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (int p = 2; p < n; p++)
        {
            if (prime[p])
            {
                cnt++;
                // pr.push_back(p);
            }
        }

        // for(int i=0;i<pr.size();i++) cout<<pr[i]<<" ";
        return cnt;
    }
};