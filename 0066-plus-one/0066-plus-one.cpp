class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>res=digits;
        // cout<<res.size();
        int n=digits.size();
        if(digits[n-1]==9){
            int i=n-1;
            while(i>=0 && res[i]==9){
                res[i]=0;
                i--;
            }
            if(i<0){
                res.resize(n+1,0);
                res[0]=1;
            }
            else res[i]++;
        }
        else{
            res[n-1]++;
        }

        return res;
    }
};