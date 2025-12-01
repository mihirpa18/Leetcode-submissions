class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=*min_element(batteries.begin(),batteries.end());
        long long h=accumulate(batteries.begin(),batteries.end(),0LL)/n;
        long long sum=h;
        long long res=l;
        while(l<=h){
            long long mid=(l+h)/2;
            long long temp=0;
            for(auto &it:batteries){
                temp+=min((long long)it,mid);
            }
            if(temp>=mid*n){
                res=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }

        return res;
    }
};