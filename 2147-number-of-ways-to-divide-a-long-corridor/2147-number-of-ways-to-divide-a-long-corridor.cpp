class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size();
        vector<int>pos;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S') pos.push_back(i);
        }

        if(pos.size()==0 || pos.size()%2==1) return 0;
        if(pos.size()==2) return 1;

        int mod=1e9+7;
        long long res=1;
        for(int i=2;i<pos.size();i+=2){
            int temp=pos[i]-pos[i-1];
            res=(res*temp)%mod;
        }

        return res;
    }
};