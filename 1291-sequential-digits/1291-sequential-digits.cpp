class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";
        string lo = to_string(low);
        string hy = to_string(high);

        vector<int>res;

        for(int i=lo.size();i<=hy.size();i++){
            for(int j = 0;j<=9-i;j++){
                string s = num.substr(j,i);
                // cout<<j<<" "<<i<<" "<<s<<endl;
                int num_s = stoi(s);

                if(num_s >= low && num_s<=high){
                    res.push_back(num_s);
                }
            }
        }

        return res;
    }
};