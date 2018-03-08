int rob(int* nums, int numsSize) {
    int i, max, prev[4], cur[4];
    
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    if(numsSize == 2){
        if(nums[0] > nums[1])
            return nums[0];
        else
            return nums[1];
    }
    if(numsSize == 3){
        max = nums[0];
        for(i = 1; i < 3; i++){
            if(nums[i] > max)
                max = nums[i];
        }
        return max;
    }
    
    prev[0] = nums[1];
    prev[1] = nums[2];
    prev[2] = nums[0];
    prev[3] = nums[0] + nums[2];
    
    for(i = 3; i < numsSize; i++){
        //printf("[%d %d]\n[%d %d]\n", cur[0], cur[2], cur[1], cur[3]);
        if(prev[0] > prev[1])
            cur[0] = prev[0];
        else
            cur[0] = prev[1];
        cur[1] = prev[0] + nums[i];
        prev[0] = cur[0];
        prev[1] = cur[1];
        
        if(prev[2] > prev[3])
            cur[2] = prev[2];
        else
            cur[2] = prev[3];
        cur[3] = prev[2] + nums[i];
        prev[2] = cur[2];
        prev[3] = cur[3];
        //printf("[%d %d]\n[%d %d]\n", cur[0], cur[2], cur[1], cur[3]);
    }
    
    //printf("[%d %d]\n[%d %d]\n", cur[0], cur[2], cur[1], cur[3]);
    
    max = cur[0];
    for(i = 1; i < 3; i++){
        printf("%d -> %d\n", i, cur[i]);
        if(cur[i] > max)
            max = cur[i];
    }
    
    return max;
}
