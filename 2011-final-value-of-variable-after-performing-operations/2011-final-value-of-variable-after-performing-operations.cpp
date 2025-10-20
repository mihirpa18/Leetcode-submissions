class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res=0;
        for(auto it:operations){
            for(int i=0;i<it.size();i++){
                if(it[i]=='-'){
                    res--;
                    break;
                }
                else if(it[i]=='+'){
                    res++;
                    break;
                }
                else continue;
            }
        }

        return res;
    }
};