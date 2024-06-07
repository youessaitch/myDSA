struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }

    Node* get(int bit) {
        return links[bit]; 
    }

    void put(int bit, Node* node) {
        links[bit] = node; 
    }
};

class Trie{
private: Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1; //check if set or not

            if(!node->containsKey(bit)){
                node->put(bit,new Node()); //if not in the trie then add
            }
            node = node->get(bit); //move next
        }
    }

    //To find max XOR value of a number
    int getMax(int num){
        Node* node = root;
        int maxi = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1; //check if set or not
            int opp = 1-bit; //opposite of bit
            if(node->containsKey(opp)){
                maxi = maxi|(1<<i); //if 1 & 0 exist then Xor = 1 | 0
                node = node->get(opp); //move to opp
            }
            else{
                node = node->get(bit); //move to bit
            }
        }
        return maxi;
    }     
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        Trie trie;

        vector<vector<int>> v; // Vector to store sorted queries

        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0]; // num to take XOR with
            int a = queries[i][1]; // should be <= a
            v.push_back({a, x, i}); // {num,limit,index}
        }

        sort(v.begin(),v.end()); //sort wrt to a

        vector<int> ans(queries.size(),-1); //to store the ans

        int j=0;

        for(int i=0;i<v.size();i++){
            int x = v[i][1];
            int a = v[i][0];
            int idx = v[i][2];

            while(j<n && nums[j]<=a){
                trie.insert(nums[j]);
                j++;
            }

            if(j!=0){
                ans[idx] = trie.getMax(x);
            }
        }
        return ans;
    }
};