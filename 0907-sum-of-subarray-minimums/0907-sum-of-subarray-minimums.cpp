class Solution {
    vector<int>nse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            res[i]=st.empty()?n:st.top();
            st.push(i);
        }

        return res;
    }
    vector<int>pse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            res[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        return res;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>t=nse(arr);
        vector<int>s=pse(arr);

        long long sum=0;
        long mod=1e9+7;
        for(int i=0;i<n;i++){
            int l=i-s[i];
            int r=t[i]-i;
            sum=((sum+(((l*r)%mod)*arr[i])%mod)%mod)%mod;
        }

        return sum;
    }
};