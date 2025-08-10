class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string res=to_string(n);
        sort(res.begin(),res.end());
        for(int i=0;i<32;i++){
            long long pow2=pow(2,i);
            string s=to_string(pow2);
            sort(s.begin(),s.end());

            if(s==res) return true;
        }

        return false;
    }
};