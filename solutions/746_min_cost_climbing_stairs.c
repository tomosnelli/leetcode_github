/*
    746. Min Cost Climbing Stairs
*/
#include <stdio.h>
#include <stdlib.h>

#define MIN(x,y) ((x > y) ? y : x)

/* recursive */
//int minCostClimbingStairs(int* cost, int costSize)
//{
//    int* dp = malloc(costSize * sizeof(int));
//}

int minCostClimbingStairs(int* cost, int costSize)
{
    int* dp = malloc(costSize * sizeof(int));

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i < costSize; ++i){
        dp[i] = cost[i] + MIN(dp[i-1], dp[i-2]);
    }

    int result = MIN(dp[costSize-1], dp[costSize-2]);

    free(dp);

    return result;
}