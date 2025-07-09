class Solution {
    
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxlen=0;
        string res="";
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){             
                if(r-l+1>maxlen){
                    res="";
                    for(int k=l;k<=r;k++){
                        res.push_back(s[k]);
                    }
                    maxlen=r-l+1;
                }
                l--;
                r++;
            }

            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){             
                if(r-l+1>maxlen){
                    res="";
                    for(int k=l;k<=r;k++){
                        res.push_back(s[k]);
                    }
                    maxlen=r-l+1;
                }
                l--;
                r++;
            }

        }
        return res;

    }
};