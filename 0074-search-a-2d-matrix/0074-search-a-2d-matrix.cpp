class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int c=matrix[0].size(),r=matrix.size();
        int l=0,h=r*c-1;
        while(l<=h){
            int mid=(l+h)/2;
            int row=mid/c,col=mid%c;
            if(matrix[row][col]==target){
                return true;
            }
            if(matrix[row][col]>target){
                h=mid-1;
            }
            else if(matrix[row][col]<target){
                l=mid+1;
            }
        }
        return false;
    }
};