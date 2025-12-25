class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long  res=0;
        int n=happiness.size();
        sort(happiness.begin(),happiness.end(),greater<>());

        long long dec=0;
        int i=0;
        while(k>0 && i<n){
            if(happiness[i]-dec>0) res+=happiness[i]-dec;
            else break;
            dec++;
            i++;
            k--;
        }

        return res;
    }
};