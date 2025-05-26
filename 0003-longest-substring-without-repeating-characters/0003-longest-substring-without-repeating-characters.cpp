class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,0);
        int n=s.length();
        int i=0;int j=0;
        int len=0;
        while(j<n && i<n){
            hash[s[j]]++;
            while(hash[s[j]]>1){
                hash[s[i]]--;
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};