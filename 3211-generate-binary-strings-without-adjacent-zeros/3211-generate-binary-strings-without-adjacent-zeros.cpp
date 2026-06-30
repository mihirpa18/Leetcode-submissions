class Solution {
    void solve(string s, vector<string>&res,int &n){
        if(s.size()==n){
            res.push_back(s);
            return;
        }
        
        s+='1';
        solve(s,res,n);
        s.pop_back();

        if(s.empty()){
            s+='0';
            solve(s,res,n);
            s.pop_back();
        }
        if(!s.empty() && s[s.size()-1]!='0'){
            s+='0';
            solve(s,res,n);
            s.pop_back();
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string>res;

        solve("",res,n);

        return res;
    }
};