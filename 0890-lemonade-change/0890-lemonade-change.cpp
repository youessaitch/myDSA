class Solution {
public:
    int n;
    bool lemonadeChange(vector<int>& bills) {
        n = bills.size();
        int five=0,ten=0,twen=0;
        bool ch = true;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five++;
                continue;
            }
            if(bills[i]==10){
                ten++;
                if(five==0) {
                    ch = false;
                    break;
                }
                five--;
                continue;
            }
            if(bills[i]==20){
                twen++;
                if((five>=1 && ten>=1) || (five>=3 && ten==0)){
                    ch = true;
                }else{
                    ch = false;
                    break;
                }
                if(ten>=1 && five>=1){
                    ten--;
                    five--;
                    continue;
                }

                if(ten==0 && five>=3){
                    five-=3;
                    continue;
                }
            }
        }
        return ch;
    }
};