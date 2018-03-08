void rotate(int* nums, int numsSize, int k) {
    if(numsSize < 2)
        return;
    
    k = k % numsSize;
    if(k == 0)
        return;
    
    int *new_nums = (int*)malloc(numsSize * sizeof(int));
    int i, j = numsSize-k;
    
    for(i = 0; i < numsSize; i++){
        new_nums[i] = nums[j];
        j = (j+1) % numsSize;
    }
    for(i = 0; i < numsSize; i++){
        nums[i] = new_nums[i];
    }
    free(new_nums);
    
    // O(k*N)
    /*int i, j, prev, cur;
    for(i = 0; i < k; i++){
        prev = nums[0];
        nums[0] = nums[numsSize-1];
        for(j = 1; j < numsSize; j++){
            cur = nums[j];
            nums[j] = prev;
            prev = cur;
        }
        }*/
}
