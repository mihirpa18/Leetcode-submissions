class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        int nxt=numRows+(numRows-2);
        string res;
        int j=0;
        if(numRows==n || numRows==1){
            return s;
        }
        for(int i=0;i<numRows;i++){
            int tempNxt=nxt-i;
            j=i;
            while(j<n ){
                if(nxt==tempNxt){
                    res.push_back(s[j]);
                    j=j+nxt;
                }
                else{
                    res.push_back(s[j]);
                    if(tempNxt<n && tempNxt!=i){
                        res.push_back(s[tempNxt]);
                        tempNxt=tempNxt+nxt;
                    }
                    j=j+nxt;
                }
            }
        }

        return res;
    }
};