#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n+1);
        //v[i] = ith ugly number, return v[n];
        //v[0] = not of any use

        //pointing to first ugly number
        int i2=1,i3=1,i5=1;

        //1st ugly number is 1
        v[1]=1;

        for(int i=2;i<=n;i++){
            int t2 = v[i2]*2;
            int t3 = v[i3]*3;
            int t5 = v[i5]*5;

            int mini = min(t2,min(t3,t5));

            v[i] = mini;

            //increase the pointer that is pointing towards the minimum
            if(mini==t2) i2++;
            if(mini==t3) i3++;
            if(mini==t5) i5++;
        }

        return v[n];
    }
};