int findPeakElement(int* nums, int numsSize) {
    /* Check the ends first since we only need one comparison
     * and it makes the loop simpler.
     */
    if(nums[numsSize-1] > nums[numsSize-2])
        return numsSize-1;
    
    int i;
    for(i = 0; i < numsSize-1; i++){
        /* If this element is greater than both of its neighbors, it's a peak.
         * So, since we start at 0 whose left element is -infinity, we simply
         * need to find the first element which is greater then the element to
         * its right.
         */
        if(nums[i] > nums[i+1])
            return i;
    }
    return 0;
}
