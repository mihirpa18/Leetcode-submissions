class Solution {
    int merge(int l,int h,int mid,vector<int>&nums){
        int res=0;
        vector<int>temp;
        int left=l,right=mid+1;
        if(l>=h) return res;
        
        for(int i=l;i<=mid;i++){
            while(right<=h && nums[i]>2*1ll*nums[right]){
                right++;
            }
            res+=(right-(mid+1));
        }
        right=mid+1;
        while(left<=mid && right<=h){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=h){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=l;i<=h;i++){
            nums[i]=temp[i-l];
        }

        return res;
    }

    int mergeSort(int l,int h,vector<int>&nums){
        int res=0;
        if(l>=h) return res;
        int mid=(l+h)/2;

        res+=mergeSort(l,mid,nums);
        res+=mergeSort(mid+1,h,nums);
        res+=merge(l,h,mid,nums);

        return res;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(0,n-1,nums);
    }
};