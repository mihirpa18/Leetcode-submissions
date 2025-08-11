void bubbleSort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int missingNumber(int* nums, int numsSize) {
    int miss;
    bubbleSort(nums,numsSize);
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=i){
            return i;
        }
    }
    return miss;
}