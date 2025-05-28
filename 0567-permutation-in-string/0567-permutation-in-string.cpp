class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        int i=0,j=0;
        vector<int>map(26,0),temp(26,0);

        for(auto it:s1){
            map[it-'a']++;
        }   
        temp=map;

        while(j<m && i<m){
            if(temp[s2[j]-'a']>0){
                temp[s2[j]-'a']--;
                if((j-i+1)==n){
                    return true;
                }
                j++;
                
            }
            else{
                temp=map;
                i++;
                j=i;
            }

        }
        return false;


    }
};