class Solution {
    bool isValid(string &s){
        for(auto &c:s){
            if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122) || c=='_') continue;
            else return false;
        }

        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        unordered_map<string,int>mp={
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}
        };
        vector<pair<int,string>>temp;
        for(int i=0;i<n;i++){
            if(!isActive[i]) continue;
            if(mp.find(businessLine[i])==mp.end()) continue;
            if(code[i]=="") continue;

            if(!isValid(code[i])) continue;

            int ind=mp[businessLine[i]];
            temp.push_back({ind,code[i]});
        }

        sort(temp.begin(),temp.end());

        vector<string>res;
        for(auto &it:temp){
            res.push_back(it.second);
        }

        return res;
    }
};