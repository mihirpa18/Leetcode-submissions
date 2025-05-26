class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;int j=n-1;
        if(n==1) return 0;
        int volume=0;

        while(i<j){
            int mini=min(height[i],height[j]);
            int tempvol=mini*(j-i);
            volume=max(volume,tempvol);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }

        return volume;

    }
};