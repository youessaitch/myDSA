class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int t = n;
        // int i=n-1;
        while (t != 0) {
            digits.push_back(t % 10);
            t /= 10;
        }

        reverse(digits.begin(),digits.end());

        for(int i=0;i<digits.size();i++){
            cout<<digits[i]<<" ";
        }

        // Use next_permutation to get the next greater permutation
        if (!next_permutation(digits.begin(), digits.end())) {
            return -1;
        }

        // Convert the digits back to a number
        long long nextGreater = 0;
        for (int digit : digits) {
            nextGreater = nextGreater * 10 + digit;
        }

        // Check if the resulting number is within the 32-bit integer range
        if (nextGreater > INT_MAX) {
            return -1;
        }

        return static_cast<int>(nextGreater);
    }
};