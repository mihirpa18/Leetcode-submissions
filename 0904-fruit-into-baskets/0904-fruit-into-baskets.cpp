class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int count=2;
        unordered_map<int,int>map;
        int n=fruits.size();
        int len=0;
        while(j<n && i<n){
            map[fruits[j]]++;
            while(map.size()>2){
                map[fruits[i]]--;
                if(map[fruits[i]]==0) map.erase(fruits[i]);
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};