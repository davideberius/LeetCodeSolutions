/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int *answer = (int*)calloc((2+numsSize), sizeof(int));
    int i;
    
    for(i = 0; i < numsSize; i++){
        answer[1] ^= (i+1) ^ nums[i];
        if(++answer[nums[i]+1] == 2)
            answer[0] = nums[i];
    }
    answer[1] ^= answer[0];
    
    *returnSize = 2;
    return answer;
}
