class Solution {
    int n;
    bool canReach(int i, vector<int>& arr, vector<bool>&vis){
        if(i>=n || i<0) return false;
        if(arr[i] == 0) return true;

        vis[i] = true;
        bool front = false,back = false;
        if(i+arr[i] < n && vis[i+arr[i]] != true){
            front = canReach(i+arr[i], arr, vis);
        }
        if(i-arr[i] >= 0 && vis[i-arr[i]] != true){
            back = canReach(i-arr[i], arr, vis);
        }
        return front || back;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<bool>vis(n,false);
        return canReach(start,arr,vis);
    }
};