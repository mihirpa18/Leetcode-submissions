class Solution {
    int bs(int &val,vector<int>&arr,long long &succ){
        int l=0,h=arr.size()-1;
        int ans=arr.size();
        while(l<=h){
            int mid=(l+h)/2;
            long long midVal=1ll*arr[mid]*val;
            if(midVal<succ){
                l=mid+1;
            }
            else{
                ans=mid;
                h=mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m=potions.size();
        int n=spells.size();
        sort(potions.begin(),potions.end());
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(m-bs(spells[i],potions,success));    
        }
        return res;
    }
};