class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>map;
        int len=0;
        for(auto it:words){
            string temp=it;
            reverse(it.begin(),it.end());
            if(map[temp]>0){
                len+=4;
                map[temp]--;
            }
            else{
                map[it]++;
            }
        }

        for(auto it:map){
            string word=it.first;
            int count=it.second;

            if(word[0]==word[1] && count>0){
                len+=2;
                break;
            }
        }


        return len;
    }
};