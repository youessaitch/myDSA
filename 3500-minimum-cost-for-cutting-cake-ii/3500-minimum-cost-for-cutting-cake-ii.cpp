#define ll long long
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int s1 = horizontalCut.size();
        int s2 = verticalCut.size();

        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
        sort(verticalCut.begin(),verticalCut.end(),greater<int>());

        int v_pieces = 1;
        int h_pieces = 1;

        int i=0,j=0;
        ll ans = 0;
        while(i<s1 && j<s2){
            if(horizontalCut[i]>=verticalCut[j]){
                ans += (ll)horizontalCut[i]*v_pieces;
                i++;
                h_pieces++;
            }else{
                ans += (ll)verticalCut[j]*h_pieces;
                j++;
                v_pieces++;
            }
        }

        while(i<s1){
            ans += (ll)horizontalCut[i]*v_pieces;
            i++;
            h_pieces++;
        }

        while(j<s2){
            ans += (ll)verticalCut[j]*h_pieces;
            j++;
            v_pieces++;
        }

        return ans;
    }
};