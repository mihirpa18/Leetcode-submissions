class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        if(n==1) return 0;

        int res=0;
        int i=0,j=1;
        while(i<n && j<n){
            if(directions[i]=='R' && directions[j]=='L'){
                res+=2;
                directions[i]='S';
                directions[j]='S';
            }
            else if(directions[i]=='S' && directions[j]=='L'){
                res+=1;
                directions[i]='S';
                directions[j]='S';
            }
            else if(directions[i]=='R' && directions[j]=='S'){
                res+=1;
                directions[i]='S';
                directions[j]='S';
            }
            i++;
            j++;
        }

        int first=0,last=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(directions[i]=='S' && flag){
                first=i,last=i;
                flag=false;
            }
            else if(directions[i]=='S'){
                last=i;
            }
        }
        cout<<first<<" "<<last<<endl;
        for(int i=0;i<n;i++){
            
            if(i>first && i<last && (directions[i]=='R' || directions[i]=='L')){
                res++;
            }
            else if(i<first && last!=0 && directions[i]=='R') res++;
            else if(i>last && last!=0 && directions[i]=='L') res++;
        }
        return res;
    }
};