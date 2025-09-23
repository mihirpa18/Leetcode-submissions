class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        int n=version1.size(),m=version2.size();
        while(i<n && j<m){
            string temp1="";
            while(version1[i]!='.' && i<n){
                temp1+=version1[i];
                i++;
            }
            i++;
            string temp2="";
            while(version2[j]!='.' && j<m){
                temp2+=version2[j];
                j++;
            }
            j++;

            int a=stoi(temp1);
            int b=stoi(temp2);
            if(a<b) return -1;
            if(a>b) return 1;    
        }
        while(i<n){
            if(version1[i]!='0' && version1[i]!='.') return 1;
            i++;
        }
        while(j<m){
            if(version2[j]!='0' && version2[j]!='.') return -1;
            j++;
        }

        return 0;
    }
};