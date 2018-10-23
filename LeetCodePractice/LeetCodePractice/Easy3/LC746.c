/*
 On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 
 Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
 
 Example 1:
 Input: cost = [10, 15, 20]
 Output: 15
 Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
 Example 2:
 Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 Output: 6
 Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
 Note:
 cost will have a length in the range [2, 1000].
 Every cost[i] will be an integer in the range [0, 999].
 */

#include "LC746.h"

int minCostClimbingStairs(int* cost, int costSize) {
    if (costSize <= 1) {
        return 0;
    } else {
        int oneStep = cost[0] + minCostClimbingStairs(cost+1, costSize-1);
        int twpSteps = cost[1] + minCostClimbingStairs(cost+2, costSize-2);
        return min(oneStep, twpSteps);
    }
}

//以上递归算法 预料中的超时

//动态规划
int minCostClimbingStairsDP(int* cost, int costSize) {
    int first = cost[0];
    int second = cost[1];
    
    for (int i = 2; i < costSize; i++) {
        int third = cost[i] + min(first, second);
        first = second;
        second = third;
    }
    
    return min(first, second);
}
