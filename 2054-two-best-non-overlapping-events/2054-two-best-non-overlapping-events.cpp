class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        vector<vector<int>>time;
        for(auto &it:events){
            time.push_back({it[0],1,it[2]});
            time.push_back({it[1]+1,0,it[2]});  //+1 since start and end time is inclusive
        }
        sort(time.begin(),time.end(),[](auto &a,auto &b){
            return (a[0]==b[0])?a[1]<b[1]:a[0]<b[0];
        });
        
        //since we can only take 2 events just maintain maxVal seen sofar and maxSum
        int maxVal=0,res=0;
        for(auto &it:time){

            //if its start-> maximize sum
            if(it[1]==1){
                res=max(res,it[2]+maxVal);
            }
            //if the interval is ended , we can add maxVal(if) ,so maximize value
            else{
                maxVal=max(maxVal,it[2]);
            }
        }
        
        return res;
    }
};