class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        int i=0;

        if(n==k) return "0";

        string res="";
        stack<char>st;

        while(i<n){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
        }

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());
        
        if(k>0){
            res=res.substr(0,res.size()-k);
        }
        i=0;
        while(res[i]=='0') i++;

        return i==res.size()?"0":res.substr(i,res.size());
    }
};