class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n%2!=0) return false;
        for(int i=0;i<=32;i++){
            if(log2(n)==i) return true;
        }

        return false;;
    }
};