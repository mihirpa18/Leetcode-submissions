class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(auto &it:nums){
            int count=0;
            int sum=0;
            // cout<<it/2;
            for(int i=1;i<=sqrt(it);i++){
                if(it%i==0){
                    count++;
                    sum+=i;

                    int rev=it/i;

                    if(i!=rev){
                        count++;
                        sum+=rev;
                    }
                }
            }
            if(count==4) res+=sum;
        }

        return res;
    }
};