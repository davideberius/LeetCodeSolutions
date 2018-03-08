uint32_t reverseBits(uint32_t n) {
    if(n == 0)
        return n;
    
    int i;
    /* Our return value starts as all 0's and power starts as a 1 followed
     * by 31 0's
     */
    uint32_t ret = 0, power = 2147483648;
    const uint32_t one = 1;
    /* Always look at the rightmost bit of n and simply shift n to the
     * right each iteration.  If the rightmost bit is a 1, OR ret with
     * power which should be a 1 in the correct position.  Shift power
     * to the right 1 after each iteration so it is in the right position.
     */
    for(i = 0; i < 32; i++){
        if(n & one){
            ret |= power;
        }
        power = power >> 1;
        n = n >> 1;
    }
    return ret;
}
