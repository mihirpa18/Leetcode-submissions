class Solution {
    bool isValid(vector<vector<int>>& tasks,int sum){
        for(auto &t : tasks){
            // cout<<t[1]<<" "<<sum<<endl;
            if(t[1] <= sum){
                sum -= t[0];
            }
            else{
                cout<<endl;
                return false;
            }
        }
        cout<<endl;
        return true;
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int maxBeg = 0;
        int sum = 0;

        sort(tasks.begin(), tasks.end(), [](vector<int>a, vector<int>b){
            return a[1]-a[0] > b[1]-b[0];
        });

        for(auto &t : tasks){
            maxBeg = max(t[1],maxBeg);
            sum += t[1];
        }   

        int l = maxBeg;
        int h = sum;

        int res = -1;

        while(l<=h){
            int mid = (l+h)/2;

            if(isValid(tasks, mid)){
                res = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }

            // cout<<l<<" "<<h<<endl;
        }

        return res;

    }
};