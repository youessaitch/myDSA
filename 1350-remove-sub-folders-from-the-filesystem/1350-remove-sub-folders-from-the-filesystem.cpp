class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(),folder.end());

        unordered_map<string,int> mpp;

        for(auto it: folder){
            string temp = "";
            bool flag = true;
            for(int i=0;i<it.size();i++){
                if(i!=0 && it[i] == '/'){
                    if(mpp.find(temp)!=mpp.end()){
                        flag = false;
                        break;
                    }
                }
                temp+=it[i];
            }
            if(flag) mpp[temp]++;
        }

        vector<string> ans;
        for(auto it: mpp) ans.push_back(it.first);
        return ans;
    }
};