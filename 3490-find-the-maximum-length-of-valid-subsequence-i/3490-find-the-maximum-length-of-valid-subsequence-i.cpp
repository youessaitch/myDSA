class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        int cntEven = 0;
        int cntOdd = 0;
        for (int num : nums) {
            if (num % 2 == 1) {
                cntOdd++; // 1 1 1 1 1
            } else {
                cntEven++; // 0 0 0 0 0
            }
        }
        maxi = max(cntEven, cntOdd);

        int cntZO = 0, cntOZ = 0;
        int reqZO = 0, reqOZ = 1;;
        for (int num : nums) {
            int newNum = num % 2;
            if (newNum == reqZO) { // 0 1 0 1 0 1
                cntZO++;
                reqZO ^= 1;
            } 
            
            if(newNum == reqOZ) { // 1 0 1 0 1 0 
                cntOZ++;
                reqOZ ^= 1;
            }
        }
        maxi = max(maxi, max(cntZO, cntOZ));

        return maxi;
    }
};