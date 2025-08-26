class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        double res=0;
        int maxArea=0;
        int c=0;
        int ans=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
                int l=dimensions[i][0];
                int w=dimensions[i][1];
                int len=l*l;
                int wid=w*w;
                double diag=sqrt(len+wid);
                int area=l*w;
                cout<<diag<<" "<<res<<" "<<area<<" ";
                if(diag==res){
                    c=1;
                    maxArea=max(area,maxArea);
                }
                if(diag>res){
                    c=0;
                    res=diag;
                    ans=area;
                }
        }

        return c==0?ans:maxArea;
    }
};