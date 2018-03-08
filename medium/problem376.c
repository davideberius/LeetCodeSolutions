int wiggleMaxLength(int* nums, int numsSize) {
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
    
    int i, sign, prev, count = 1;
    if(nums[1] > nums[0]){
        sign = 1;
        count++;
    }
    else if(nums[1] < nums[0]){
        sign = -1;
        count++;
    }
    else{
        sign = 0;
    }
    for(i = 2; i < numsSize; i++){
        if(sign == 1){
            if(nums[i] < nums[i-1]){
                sign = -1;
                count++;
            }
        }
        else if(sign == -1){
            if(nums[i] > nums[i-1]){
                sign = 1;
                count++;
            }
        }
        else{
            if(nums[i] > nums[i-1]){
                sign = 1;
                count++;
            }
            else if(nums[i] < nums[i-1]){
                sign = -1;
                count++;
            }
            else{
                sign = 0;
            }
        }
    }
    return count;
}
