/*
    11. Container With Most Water
*/
#include "../utils/common.h"

#define MIN(x,y)((x > y) ? y : x)

int maxArea(int* height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;
    int max = 0;

    while (left < right){
        int distance = right - left;
        int area = MIN(height[left], height[right]) * distance;
        
        max = area > max ? area : max;

        if(height[left] > height[right])
            right -= 1;
        else
            left += 1;
        
    }

    return max;
}