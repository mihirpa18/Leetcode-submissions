class Solution {
    int gain(string pat,string &s,int &pt){
        string temp;
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(temp.size() && temp.back()==pat[0] && s[i]==pat[1]){
                temp.pop_back();
                sum+=pt;
            }
            else{
                temp.push_back(s[i]);
            }
        }

        s=temp;

        return sum;
    }
public:
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        int res=0;
        if(x>y){
            res+=gain("ab",s,x);
            res+=gain("ba",s,y);
        }
        else{
            res+=gain("ba",s,y);
            res+=gain("ab",s,x);
        }

        return res;
    }
};