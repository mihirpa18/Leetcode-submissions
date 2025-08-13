class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int pow=1;
        while(pow<=n){
            if(pow==n) return true;
            pow*=3;
        }

        return false;
    }
};