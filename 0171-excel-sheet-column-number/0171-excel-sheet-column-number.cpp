class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long  res=0;
        long long mul=1;
        int i=columnTitle.size()-1;
        unordered_map<char,int>map;
        char s='A';
        for(int i=1;i<=26;i++){
            map[s]=i;
            s++;
        }
        while(i>=0){
            res=res+(map[columnTitle[i]]*mul);
            mul*=26;
            i--;
        }
        return res;
    }
};