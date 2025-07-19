class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>res;
        int n=folder.size();
        unordered_map<string,int>map;
        for(auto it:folder){
            string temp="";
            int i;
            for(i=0;i<it.size();i++){ 
                if(it[i]=='/'){
                    temp+=it[i];
                    continue;
                }
                while(it[i]!='/' && i<it.size()){
                    temp+=it[i];
                    i++;
                }             
                i--;
                if(map[temp]!=0){
                   break;
                }
                else if(temp==it && map[temp]==0){
                    map[it]++;
                    res.push_back(it);
                    break;
                }
            }            
        }

        return res;
    }
};