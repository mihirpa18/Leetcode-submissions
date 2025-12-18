class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        long long sum=0;

        for(int i=0;i<n;i++){
            sum+=prices[i]*strategy[i];
        }
        cout<<sum<<" ";
        long long og_sum=0;
        long long new_sum=0;
        int mid=k/2;

        for(int i=0;i<k;i++){
            og_sum+=(prices[i]*strategy[i]);
            // cout<<"og"<<og_sum<<" ";

            if(i>=mid) new_sum+=prices[i];  //since strategy=1 and before it it is 0

            // cout<<new_sum<<" ";
        }

        long long diff=new_sum-og_sum;
        cout<<diff<<" ";
        for(int i=1;i<=n-k;i++){
            //remove first ele from og
            og_sum-=(prices[i-1]*strategy[i-1]);
            //add last ele
            og_sum+=(prices[i+k-1]*strategy[i+k-1]);
            //remove mid ele since it becomes 0 now
            new_sum-=prices[i+mid-1];
            //add last ele since strategy becomes 1 
            new_sum+=prices[i+k-1];

            diff=max(diff,(new_sum-og_sum));
            cout<<diff<<" ";
        }

        return sum+max(0*1ll,diff);
        
    }
};