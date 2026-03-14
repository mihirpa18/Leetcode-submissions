class Solution {
    // void generate(string s,int i,int n,vector<string>&arr){
    //     cout<<s<<" ";
    //     if(i==n){
    //         arr.push_back(s);
    //         return;
    //     }
    //     if(i==0 || s==""){
    //         generate(s+'a',i+1,n,arr);
    //         generate(s+'b',i+1,n,arr);
    //         generate(s+'c',i+1,n,arr);
    //     }
    //     else{
    //         if(s[i-1]!='a') generate(s+'a',i+1,n,arr);
    //         if(s[i-1]!='b') generate(s+'b',i+1,n,arr);
    //         if(s[i-1]!='c') generate(s+'c',i+1,n,arr);
    //     }
    // }
public:
    string getHappyString(int n, int k) {
        int totalStrings = 3 * (1<<(n-1));  //3*2^(n-1)
        if(k > totalStrings) return "";
        
        //each string can be divided in 3 blocks (starting with a,b,and c) so totalString/3
        int blockSize = 1<<(n-1);

        string res = "";
        k--;  //0 indexed

        int firstCharIdx = k/blockSize;    //finding first char -> since divided into blocks
        res+=(char)('a' + firstCharIdx);  

        k= k % blockSize;  //how much th item in block 

        for(int i = 1; i<n ;i++){
            blockSize = blockSize >> 1;     //halve the blockSize
            int charIdx = k/blockSize;   

            char prev = res.back();

            if(prev == 'a'){
                if(charIdx == 0) res += 'b';
                else res += 'c';
            }
            else if(prev == 'b'){
                if(charIdx == 0) res += 'a';
                else res += 'c';
            }
            else{
                if(charIdx == 0) res += 'a';
                else res += 'b';
            }
            
            k %= blockSize;   //update k for next iteration
        }

        return res;

    }
};