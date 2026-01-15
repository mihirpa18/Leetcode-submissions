class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hsize=hBars.size();
        int vsize=vBars.size();
        int hc=1;
        int vc=1;
        for(int i=1;i<hsize;i++){
            int count=1;
            while(i<hsize && hBars[i]==(hBars[i-1]+1)){
                count++;
                i++;
            }
            hc=max(hc,count);
        }

        for(int i=1;i<vsize;i++){
            int count=1;
            while(i<vsize && vBars[i]==(vBars[i-1]+1)){
                count++;
                i++;
            }
            vc=max(vc,count);
        }

        int side=min(hc,vc)+1;

        return side*side;
    }
};