class Solution {
    
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tg=0;
        int tc=0;
        int sum=0;
        int i=0;
        for(int k=0;k<n;k++){
            tg+=gas[k];
            tc+=cost[k];
            sum+=(gas[k]-cost[k]);
            if(sum<0){
                sum=0;
                i=k+1;
            }
        }
        

        return tg<tc?-1:i;
    }
};