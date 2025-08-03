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
    long long minSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>t=nse(arr);
        vector<int>s=pse(arr);

        long long sum=0;
        long mod=1e9+7;
        for(int i=0;i<n;i++){
            int l=i-s[i];
            int r=t[i]-i;
            sum=(sum+l*r*arr[i]);
        }

        return sum;
    }
    vector<int>nge(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            res[i]=st.empty()?n:st.top();
            st.push(i);
        }

        return res;
    }
    vector<int>pge(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            res[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        return res;
    }
    long long maxSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>t=nge(arr);
        vector<int>s=pge(arr);

        long long sum=0;
        long mod=1e9+7;
        for(int i=0;i<n;i++){
            int l=i-s[i];
            int r=t[i]-i;
            sum=(sum+l*r*arr[i]);
        }

        return sum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return maxSum(nums)-minSum(nums);
    }
};