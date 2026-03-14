class Solution {
    void generate(string s,int i,int n,vector<string>&arr){
        cout<<s<<" ";
        if(i==n){
            arr.push_back(s);
            return;
        }
        if(i==0 || s==""){
            generate(s+'a',i+1,n,arr);
            generate(s+'b',i+1,n,arr);
            generate(s+'c',i+1,n,arr);
        }
        else{
            if(s[i-1]!='a') generate(s+'a',i+1,n,arr);
            if(s[i-1]!='b') generate(s+'b',i+1,n,arr);
            if(s[i-1]!='c') generate(s+'c',i+1,n,arr);
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string>arr;
        generate("",0,n,arr);
        sort(arr.begin(),arr.end());
        return arr.size()>=k?arr[k-1]:"";

    }
};