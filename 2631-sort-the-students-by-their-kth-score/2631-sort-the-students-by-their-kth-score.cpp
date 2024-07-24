class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        int m = score[0].size();

        auto lambda = [k](const vector<int>& A,const vector<int>& B){
            return A[k]>B[k];
        };

        sort(score.begin(),score.end(),lambda);
        return score;
    }
};