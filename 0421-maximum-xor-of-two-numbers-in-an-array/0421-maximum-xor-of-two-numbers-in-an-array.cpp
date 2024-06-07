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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie; //object
        for(auto it: nums) trie.insert(it);

        int maxi = 0;
        for(auto it: nums){
            maxi = max(maxi, trie.getMax(it));
        }
        return maxi;
    }
};