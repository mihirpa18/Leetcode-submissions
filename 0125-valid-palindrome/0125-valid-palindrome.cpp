class Solution {
    bool valid(char c){
        return (c>='A' && c<='Z' || c>='a' && c<='z' || c>='0' && c<='9');
    }
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            while(i<j && !valid(s[i])) i++;
            while(j>i && !valid(s[j])) j--;

            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};