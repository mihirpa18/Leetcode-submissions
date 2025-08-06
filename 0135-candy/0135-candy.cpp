class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1;
        int sum=1;
        while(i<n){
            int peak=1,down=0;
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            while(i<n && ratings[i]<ratings[i-1]){
                down++;
                sum+=down;
                i++;
            }
            down++;
            if(down>peak){
                sum+=(down-peak);
            }
          
        }
        return sum;
    }
};