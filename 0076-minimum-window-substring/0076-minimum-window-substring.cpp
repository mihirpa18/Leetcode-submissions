class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();

        unordered_map<int,int>mp;
        for(auto &it:t){
            mp[it]++;
        }

        int j=0,i=0;
        int len = INT_MAX, sInd=-1;
        int count = 0;
        for(int j=0; j<n ;j++){
            if(mp[s[j]]>0) count++;
            mp[s[j]]--;

            while(count == m){
                mp[s[i]]++;
                if(mp[s[i]]>0) count--;
                if(j-i+1 < len){
                    len = j-i+1;
                    sInd = i;
                }
                i++;
            }
        }

        return sInd == -1? "": s.substr(sInd,len);
    }
};