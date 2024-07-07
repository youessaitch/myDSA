class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        while(numBottles>=numExchange){
            int drank = numBottles/numExchange;
            int left = numBottles%numExchange;
            sum += drank;
            numBottles = drank + left;
        }
        return sum;
    }
};

//15 3 