double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int M = nums1Size, N = nums2Size, T = M+N;
    int is_odd, target = (T >> 1), m_index = 0, n_index = 0;
    
    int *arr = (int*)malloc(T * sizeof(int));
    
    if(T % 2 == 1){
        is_odd = 1;
    }
    else{
        is_odd = 0;
    }
    
    int i = 0;
    printf("[");
    for(i = 0; i < T; i++){
        if(m_index < M && n_index < N){
            if(nums1[m_index] < nums2[n_index]){
                arr[i] = nums1[m_index++];
            }
            else{
                arr[i] = nums2[n_index++];
            }
        }
        else if(m_index == M){
            arr[i] = nums2[n_index++];
        }
        else{
            arr[i] = nums1[m_index++];
        }
        printf("%d,", arr[i]);
    }
    printf("]\n");
    printf("Target: %d\n", target);
    
    if(is_odd){
        return arr[target];
    }
    else{
        return (arr[target] + arr[target-1]) / 2.0;
    }
    
    /*if(T % 2 == 1){
        is_odd = 1;
    }
    else{
        is_odd = 0;
    }
    
    if(M == 0){
        if(is_odd){
            return nums2[target];
        }
        else{
            //printf("(%d + %d) / 2 = %lf\n", nums2[target], nums2[target-1], (nums2[target] + nums2[target-1]) / 2.0);
            return (nums2[target] + nums2[target-1]) / 2.0;
        }
    }
    if(N == 0){
        if(is_odd){
            return nums1[target];
        }
        else{
            return (nums1[target] + nums1[target-1]) / 2.0;
        }
    }
    
    if(!is_odd)
        target--;
    
    printf("Target: %d\n", target);
    
    while(m_index + n_index < target){
        if(nums1[m_index] < nums2[n_index]){
            if(m_index + 1 == M)
                break;
            else
                m_index++;
        }
        else{
            if(n_index + 1 == N)
                break;
            else
                n_index++;
        }
    }
    
    printf("%d -> %d\n%d -> %d\n", m_index, nums1[m_index], n_index, nums2[n_index]);
    
    if(is_odd){
        if(nums1[m_index] > nums2[n_index]){
            return nums2[n_index];
        }
        else{
            return nums1[m_index];
        }
    }
    else{
        return (nums1[m_index] + nums2[n_index]) / 2.0;
        }*/
}
