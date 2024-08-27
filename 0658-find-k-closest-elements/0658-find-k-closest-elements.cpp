class Solution {
public:
    int n;
    
    int findFloor(vector<int> &arr, int x) {
        int i = 0, j = n - 1;
        int ans = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (arr[mid] <= x) {
                ans = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        n = arr.size();
        vector<int> ans;
        
        // Find the floor index
        int idx = findFloor(arr, x);
        
        // Initialize pointers around idx
        int i = idx;
        int j = idx + 1;
        
        // Expand outwards from the closest element
        while (k > 0) {
            if (i >= 0 && j < n) {
                if (x - arr[i] <= arr[j] - x) {
                    ans.push_back(arr[i--]);
                } else {
                    ans.push_back(arr[j++]);
                }
            } else if (i >= 0) {
                ans.push_back(arr[i--]);
            } else if (j < n) {
                ans.push_back(arr[j++]);
            }
            k--;
        }
        
        // Sort the result to maintain the order
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
