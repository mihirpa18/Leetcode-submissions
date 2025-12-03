class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        unordered_map<float,vector<float>>mc; //slope-intercept map
        unordered_map<float,vector<float>>mm;  //midPoint-slope to avoid parallelograms 
        //midpoint of diagonal is same for both ||l sides of ||gram
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                
                int dx=x1-x2;
                int dy=y1-y2;
                float m;
                float c;
                if(dx==0){
                    m=1e9+7;
                    c=x1;
                }
                else{
                    m=(float)dy/dx;
                    c=(float)(y1*dx-x1*dy)/dx; // y=mx+c
                }

                int midpt=(x1+x2)*10000+(y1+y2);

                mc[m].push_back(c);
                mm[midpt].push_back(m); 
            }
        }

        for(auto &it:mc){
            if(it.second.size()<=1) continue;
            map<float,int>mp;
            //slope -> y1,y1,y2.....etc
            for(auto &y:it.second){
                mp[y]++;
            }

            int prev=0;
            for(auto &c:mp){
                res+=prev*c.second;  //duplicates also included
                prev+=c.second;
            }
        }

        //remove duplicates
        for(auto &it:mm){
            if(it.second.size()<=1) continue;
            map<float,int>mp;
            //slope -> y1,y1,y2.....etc
            for(auto &y:it.second){
                mp[y]++;
            }

            int prev=0;
            for(auto &c:mp){
                res-=prev*c.second;
                prev+=c.second;
            }
        }

        return res;
    }
};