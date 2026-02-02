class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string res;
        for(auto &c:s){
            if(c=='('){
                count++;
                if(count>1){
                    res.push_back('(');
                }
            }
            else{
                count--;
                if(count>0) res.push_back(')');
            }
        }

        return res;
    }
};