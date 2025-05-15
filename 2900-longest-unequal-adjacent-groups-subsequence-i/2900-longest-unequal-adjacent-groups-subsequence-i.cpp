class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>res;
        int i=0,j=1;
        int n=groups.size();
        if(n==1) return words;
        while(j<n && i<n){
            while(j<n && groups[i]==groups[j]){
                j++;
            }
            res.push_back(words[i]);
            i=j;
           
        }
        return res;
    }
};