class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        string prefix="";
        vector<vector<string>>res;

        for(auto c:searchWord){
            prefix+=c;
            auto first=lower_bound(products.begin(),products.end(),prefix);
            vector<string>ans;
            for(int i=0;i<3 && first+i!=products.end();i++){
                string temp=(*(first+i)).substr(0,prefix.size());
                if(temp==prefix){
                    ans.push_back(*(first+i));
                }
            }

            res.push_back(ans);
        }

        return res;
    }
};