class Solution {
public:
    //**BRUTE FORCE**
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int n = gas.size();
    //     //Lets code brute force, check for every index
    //     for(int i=0;i<n;i++){
    //         if(gas[i]<cost[i]) continue;
    //         int j = (i+1)%n;
    //         int currtank = gas[i] - cost[i] + gas[j];
    //         //gas[i] = ith gas, cost[i] = ith cost, gas[j] = (i+1)th gas
    //         while(j!=i){
    //             if(currtank < cost[j]){
    //                 break;
    //             }

    //             int costForMovingFromThisJ = cost[j];
    //             j=(j+1)%n;
    //             int gasEarnedInNextStation = gas[j];

    //             currtank = currtank - costForMovingFromThisJ + gasEarnedInNextStation;
    //         }
    //         if(j==i) return i;
    //     }
    //     return -1;
    // }

    //***GREEDY***
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int n = gas.size();
        int totalGas = accumulate(gas.begin(),gas.end(),0);
        int totalCost = accumulate(cost.begin(),cost.end(),0);
        if(totalCost>totalGas) return -1; //never possible
        //But agar total cost, total kamai se lam hai then for sure ek answer milega hi

        int total = 0;
        int res = 0;
        for(int i=0;i<n;i++){
            total = total - cost[i] + gas[i];
            if(total < 0){
                total = 0;
                res = i+1; //i to answer nhi ho skta
            }
        }
        return res;
    }
};