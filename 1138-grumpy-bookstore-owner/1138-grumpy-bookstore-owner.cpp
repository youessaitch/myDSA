class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxi = -1e6;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
        }
        maxi = sum;

        for(int i=0;i<minutes;i++){
            if(grumpy[i]!=0){
                sum+=customers[i];
            }
        }
        maxi = max(maxi,sum);

        int i=minutes;
        int j=0;

        while(i<n){
            if(grumpy[i]==1){
                sum+=customers[i];
            }
            if(grumpy[j]==1){
                sum-=customers[j];
            }
            i++;
            j++;
            maxi = max(maxi,sum);
        }

        return maxi;
    }
};