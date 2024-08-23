class Solution {
public:
    vector<pair<int, int>> convert(string &expression){
        vector<pair<int, int>> fractions;
        stringstream ss(expression);
        char op;
        int num, denom;

        while(ss >> num >> op >> denom){
            fractions.push_back({num, denom});
            cout << num << "," << op<<" "<<denom << endl;
        }
        return fractions;
    }

    pair<int, int> add(pair<int, int> a, pair<int, int> b){
        int num = a.first * b.second + b.first * a.second;
        int denom = a.second * b.second;
        int gcd = __gcd(num, denom);
        return {num / gcd, denom / gcd};
    }

    string fractionAddition(string expression) {
        auto fractions = convert(expression);
        pair<int, int> ans = {0, 1};
        for(auto& f: fractions){
            ans = add(ans, f);
        }
        string s;
        cout<<ans.first<<" "<<ans.second;
        if((ans.second < 0 && ans.first<0) || (ans.second >= 0 && ans.first>=0)){
            s = to_string(abs(ans.first)) + "/" + to_string(abs(ans.second));
        }else{
            s = "-" + to_string(abs(ans.first)) + "/" + to_string(abs(ans.second));
        }
        // string s = to_string(ans.first) + "/" + to_string(ans.second);
        return s;
    }
};