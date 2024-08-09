class Solution {
public:

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        int ans = 0;

        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                unordered_set<int> st; 
                unordered_map<int,int> mpp;

                //check for values
                bool br = false;
                for(int r=i;r<=i+2;r++){
                    for(int c=j;c<=j+2;c++){
                        mpp[grid[r][c]]++;
                        if(grid[r][c]>9 || grid[r][c]<=0){
                            br = true;
                            break;
                        }
                    }
                    if(br) break;
                }

                if(mpp.size()!=9) br=true;
                if(br) continue;

                //row sum
                for(int r=i;r<=i+2;r++){
                    int sum = grid[r][j]+grid[r][j+1]+grid[r][j+2];
                    st.insert(sum);
                }
                
                // col sum
                for(int c=j;c<=j+2;c++){
                    int sum = grid[i][c]+grid[i+1][c]+grid[i+2][c];
                    st.insert(sum);
                }
                
                int d1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                st.insert(d1);

                int d2 = grid[i+2][j] + grid[i+1][j+1]+grid[i][j+2];
                st.insert(d2);

                if(st.size()==1) ans++;
            }
            
        }
        return ans;
    }
};