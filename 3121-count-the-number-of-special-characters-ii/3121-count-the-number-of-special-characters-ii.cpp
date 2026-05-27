class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int>lower(26,0);
        vector<int>upper(26,0);

        for(int i=0; i<n; i++){
            if(islower(word[i])){
                if(upper[toupper(word[i])-'A'] > 0){
                    lower[word[i]-'a'] = 0;
                }
                else{
                    lower[word[i]-'a']++;
                }
            }
            else{
                upper[word[i]-'A']++;
            }
        }

        int res=0;
        for(int i=0; i<26; i++){
            if(lower[i]>0 && upper[i]>0) res++;
        }

        return res;
    }
};