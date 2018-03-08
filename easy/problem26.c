int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    else if(numsSize == 1)
        return 1;
    else if(numsSize == 2){
        if(nums[0] == nums[1])
            return 1;
        else
            return 2;
    }
    
    int start = 0, next = 1, size = 1;
    
    while(next != numsSize){
        while(nums[next] == nums[start]){
            next++;
            if(next == numsSize)
                return size;
        }
        start++;
        if(start != next)
            nums[start] = nums[next];
        size++;
        next++;
    }
    return size;
}
