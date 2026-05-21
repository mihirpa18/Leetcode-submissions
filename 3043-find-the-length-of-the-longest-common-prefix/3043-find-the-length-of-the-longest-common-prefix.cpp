class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        unordered_set<int>mp;
        for(int i=0;i<m;i++){
            int num = arr2[i];
            while(num>0){
                mp.insert(num);
                num/=10;
            }
        }

        int res = 0;

        for(int i=0;i<n;i++){
            int num = arr1[i];
            while(num>0){
                if(mp.count(num)){
                    res = max(res, (int)log10(num) + 1);
                    break;
                }
                num/=10;
            }
        }

        return res;
    }
};