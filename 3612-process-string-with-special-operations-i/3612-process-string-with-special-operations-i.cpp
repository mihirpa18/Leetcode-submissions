class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        int i = 0;
        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                int m=res.length();
                if(m>0){
                    res.pop_back();  
                }
                
            } else if (s[i] == '#') {
                int m = res.length();
                for (int j = 0; j < m; j++) {
                    res += res[j];
                }
            } else if (s[i] == '%') {
                int m = res.length();
                int k = 0, p = m - 1;
                while (k <= p) {
                    swap(res[k], res[p]);
                    k++;
                    p--;
                }
            } else {
                res += s[i];
            }
        }

        return res;
    }
};