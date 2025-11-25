class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0) return -1;
        if(k==1) return 1;

        int res=1;
        string num="";
        while(num.size()<10000){
            num+='1';
            int rem=res%k;
            if(rem==0) return num.size();
            res=rem*10+1;
        }

        return -1;
    }
};