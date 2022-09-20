#include <stdio.h>
int help_findLength(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int max_len = 0, i = 0, j = 0, curr_len = 0;
    
    while (i < nums1Size && nums1Size - i > max_len)
    {
        j = 0;
        while (j < nums2Size && nums2Size - j > max_len){
            curr_len = 0;
            while (i < nums1Size && j < nums2Size && nums1[i] == nums2[j])
            {
                i++;
                j++;
                curr_len++;
            }
            if (curr_len > max_len)
                max_len = curr_len;
            i = i - curr_len;
            j = j - curr_len + 1;
        }
        i++;
    }
    return (max_len);
}

int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int a = help_findLength(nums1, nums1Size, nums2, nums2Size), b = help_findLength(nums2, nums2Size, nums1, nums1Size);
    if (a > b)
        return (a);
    else
        return (b);
}

int main()
{
    int arr1[10] = {0,0,0,0,0,0,1,0,0,0}, arr2[10] = {0,0,0,0,0,0,0,1,0,0}, a = 10, b = 10;

    printf("%d \n", findLength(arr1, a, arr2, b));
}

