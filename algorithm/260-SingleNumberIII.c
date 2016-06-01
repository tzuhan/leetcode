#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int AND=0, OR=0, XOR=0;
    int nums[] = {1,2,5,7,8,3,3,6,5,2};
    int* result = (int*)malloc(sizeof(int)*10);
    int numsSize = 10;
    for(i=0; i<numsSize;i++){
        AND&=nums[i];
        OR|=nums[i];
        XOR^=nums[i];
    }
    int returnSize = 10;
    int j=0;
    for(i=0;i<numsSize && j<returnSize;i++){
        if((nums[i]&AND)==AND && (nums[i]|OR)==OR){
            result[j++]=nums[i];
        }
    }
    for(i=0;i<returnSize;i++)
        printf("%d ",result[i]);
    return 0;
}

