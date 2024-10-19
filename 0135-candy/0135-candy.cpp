class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]  && candies[i]<=candies[i-1]){
                candies[i] = candies[i-1]+1;
            }
            // else if(ratings[i] == ratings[i-1]){
            //     candies[i] = candies[i-1];
            // }
        }

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]){
                candies[i] = candies[i+1]+1;
            }
            // else if(ratings[i] == ratings[i+1]){
            //     candies[i] = candies[i+1];
            // }
        }

        int sum = accumulate(candies.begin(),candies.end(),0);
        return sum;
    }
};

// 1 2 87 87 87 2 1

// 1 2 3 1 3 2 1


// 1 3 4 5 2

// 1 2 3 4 1