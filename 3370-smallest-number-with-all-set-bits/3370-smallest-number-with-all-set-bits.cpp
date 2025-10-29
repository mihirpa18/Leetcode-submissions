class Solution {
public:
    int smallestNumber(int n) {
        int pow=1;
        while(1){
            if(pow>n){
                return pow-1;
            }
            pow=pow<<1;
            
        }
        return -1;
    }
};