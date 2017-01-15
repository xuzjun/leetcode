/*
Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.
*/

#include <stdio.h>
#include <stdlib.h>

int PredictTheWinner(int* nums, int numsSize)
{
    int l = 0, r = numsSize - 1, i = 0, j = 0;
    int *player1 = calloc(numsSize / 2 + 1, sizeof(int));
    int *player2 = calloc(numsSize / 2 + 1, sizeof(int));

#define MAX(a, b) (a) > (b) ? (a) : (b)
    int max1 = 0, max2 = 0;
    while (1) {
        if (l == r) { player1[i++] = nums[l]; break; }
		if (l + 1 == r) {
			if (nums[l] > nums[r]) {
				player1[i++] = nums[l];
				l++;
			} else {
				player1[i++] = nums[r];
				r--;
			}
		} else {
        max1 = MAX(nums[l + 1] - nums[l], nums[r] - nums[l]);
        max2 = MAX(nums[l] - nums[r], nums[r - 1] - nums[r]);
        if (max1 > max2) { 
            player1[i++] = nums[r];
            r--;
        } else {
            player1[i++] = nums[l];
            l++;
        }
		}
        if (l == r) { player2[j++] = nums[l]; break; }
		if (l + 1 == r) {
			if (nums[l] > nums[r]) {
				player2[j++] = nums[l];
				l++;
			} else {
				player2[j++] = nums[r];
				r--;
			}
		} else {
        max1 = MAX(nums[l + 1] - nums[l], nums[r] - nums[l]);
        max2 = MAX(nums[l] - nums[r], nums[r - 1] - nums[r]);
        if (max1 > max2) { 
            player2[j++] = nums[r];
            r--;
        } else {
            player2[j++] = nums[l];
            l++;
        }
		}
    }
    max1 = max2 = 0;
    for (i = 0; i < numsSize / 2 + 1; ++i)
        max1 += player1[i];

    for (i = 0; i < numsSize / 2 + 1; ++i)
        max2 += player2[i];

    return max1 >= max2;
}

int main()
{

	int nums[19] = {3606449,6,5,9,452429,7,9580316,9857582,8514433,9,6,6614512,753594,5474165,4,2697293,8,7,1};
	// int nums[3] = {1, 5, 2};
	int ret = PredictTheWinner(nums, 19);
	printf("%d\n", ret);
	return 0;
}
