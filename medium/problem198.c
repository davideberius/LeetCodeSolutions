int rob(int* nums, int numsSize) {
    int i, prev[2], cur[2];
    
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    
    prev[0] = 0;
    prev[1] = nums[0];
    for(i = 1; i < numsSize; i++){
        if(prev[0] > prev[1])
            cur[0] = prev[0];
        else
            cur[0] = prev[1];
        cur[1] = prev[0] + nums[i];
        prev[0] = cur[0];
        prev[1] = cur[1];
    }
    
    if(cur[0] > cur[1])
        return cur[0];
    else
        return cur[1];
}
