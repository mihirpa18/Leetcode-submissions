class Solution {
    bool isSorted(vector<string>&temp){
        vector<string>dummy=temp;
        sort(dummy.begin(),dummy.end());

        for(int i=0;i<temp.size();i++){
            if(temp[i]!=dummy[i]) return false;
        }

        return true;
    }
public:
    int minDeletionSize(vector<string>& str) {
        int n=str.size();
        int m=str[0].size();
        vector<string>temp(n);
        int res=0;

        for(int i=0;i<m;i++){
            int j=1;
            for(j=0;j<n;j++){
                temp[j].push_back(str[j][i]);
            }
            if(!isSorted(temp)){
                res++;
                for(j=0;j<n;j++){
                    temp[j].pop_back();
                }   
            }
        }

        return res;
    }
};