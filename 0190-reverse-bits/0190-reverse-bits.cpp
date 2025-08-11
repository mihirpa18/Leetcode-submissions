class Solution {
public:
    int reverseBits(int n) {
        int res;
        for(int i=0;i<32;i++){
            int temp=(n>>i)&1;
            res+=(temp<<(31-i));
        }

        return res;
    }
};