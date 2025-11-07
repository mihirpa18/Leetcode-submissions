class Solution {

    int possible(long long &val,vector<long long>&diff,int &r,int &k){
        vector<long long>copy=diff;
        int rem=k;
        long long sum=0;

        for(int i=0;i<diff.size()-1;i++){
            sum+=copy[i];
            if(sum<val){
                long long add=val-sum;
                if(rem<add) return false;

                rem-=add;
                int end=i+(2*r)+1;
                if(end<diff.size()) copy[end]-=add;
                sum+=add;
            }
        }
        return true;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        vector<long long>diff(n+1,0);
        //difference array that is take sum till index to get window sum
        for(int i=0;i<n;i++){
            int l=max(0,i-r);
            int right=min(n,i+r+1);
            diff[l]+=stations[i];
            diff[right]-=stations[i];
        }

        long long l=*min_element(stations.begin(),stations.end());
        long long h=accumulate(stations.begin(),stations.end(),0LL)+k;
        long long res=l;
        while(l<=h){
            long long mid=(l+h)/2;
            if(possible(mid,diff,r,k)){
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