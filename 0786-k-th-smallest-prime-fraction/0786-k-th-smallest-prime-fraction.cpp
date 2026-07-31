class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<tuple<double,int,int>,vector<tuple<double,int,int>>,greater<tuple<double,int,int>>> pq;

        for(int i=0;i<n-1;i++){
            pq.push({(double)arr[i]/arr[n-1],i,n-1});
        }

        while(k>1){
            auto [val,i,j] = pq.top();
            // cout<<i<<" "<<j<<endl;
            pq.pop();

            if(j-1 > i) pq.push({(double)arr[i]/arr[j-1],i,j-1});
            k--;
        }

        auto [val,i,j] = pq.top();

        return {arr[i],arr[j]};
    }
};