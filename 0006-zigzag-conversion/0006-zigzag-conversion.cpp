class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        vector<vector<char>> mat(numRows);
        int i = 0, d = 1; //d is for direction up or down
        for(char c: s){
            mat[i].push_back(c);
            if(i==0) d=1;
            else if(i==numRows-1) d=-1;
            i+=d;
        }

        string ans="";
        for(auto row: mat){
            for(auto c: row){
                ans+=c;
            }
        }
        return ans;

    }
};