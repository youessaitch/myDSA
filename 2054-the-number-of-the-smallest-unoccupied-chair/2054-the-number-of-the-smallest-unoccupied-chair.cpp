class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // Priority queue to store available chairs and occupied chairs
        int nextChair = 0;
        int targetStart = times[targetFriend][0];
        
        // Sort times based on arrival time
        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leave_chair;
        priority_queue<int, vector<int>, greater<int>> available_chairs;

        // Iterate over the sorted times
        for (auto& time : times) {
            int start = time[0], leave = time[1];

            // Free up chairs for people who have left
            while (!leave_chair.empty() && leave_chair.top().first <= start) {
                available_chairs.push(leave_chair.top().second);
                leave_chair.pop();
            }

            // Assign the smallest available chair or a new chair if none are available
            int sat;
            if (!available_chairs.empty()) {
                sat = available_chairs.top();
                available_chairs.pop();
            } else {
                sat = nextChair++;
            }

            // Push the leaving time and chair number into the leave_chair queue
            leave_chair.push({leave, sat});

            // Return the chair number if it's the target friend
            if (start == targetStart) {
                return sat;
            }
        }

        return -1; // Default case (should never reach here)
    }
};