/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    int i, j, k, minimum = list1Size + list2Size, count = 0;
    
    for(i = 0; i < list1Size; i++){
        for(j = 0; j < list2Size; j++){
            if(strcmp(list1[i], list2[j]) == 0){
                if((i+j) < minimum){
                    minimum = i+j;
                    count = 1;
                }
                else if((i+j) == minimum){
                    count++;
                }
            }
        }
    }
    
    *returnSize = count;
    char **answer = (char**)malloc(count * sizeof(char*));
    
    k = 0;
    for(i = 0; i < list1Size; i++){
        for(j = 0; j < list2Size; j++){
            if(strcmp(list1[i], list2[j]) == 0){
                if((i+j) == minimum){
                    answer[k] = (char*)malloc((strlen(list1[i]) + 1) * sizeof(char));
                    strcpy(answer[k++], list1[i]);
                }
            }
        }
    }
    
    return answer;
}
