class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";

        vector<pair<int, char>> temp;
        temp.push_back({a, 'a'});
        temp.push_back({b, 'b'});
        temp.push_back({c, 'c'});

        while (true) {
            
            auto lambda = [](pair<int, char> &p1, pair<int, char> &p2) {
                return p1.first > p2.first;  
            };
            sort(temp.begin(), temp.end(),lambda);

            if (temp[0].first == 0) break;

            // Try adding the most frequent character (temp[0])
            int len = ans.length();
            if (len >= 2 && ans[len - 1] == temp[0].second && ans[len - 2] == temp[0].second) {
                if (temp[1].first == 0) break; 
                ans += temp[1].second;
                temp[1].first--; 
            } else {
                ans += temp[0].second;
                temp[0].first--;
            }
        }

        return ans;
    }

};