/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

int maxProfit(int* prices, int pricesSize)
{
        int imin = 0, imax = 0;
        int i;
        int max = 0;
        for (i = 1; i < pricesSize; ++i) {
                if (imax >= imin) {
			max = (prices[imax] - prices[imin]) > max ? max : (prices[imax] - prices[imin]);
		}
                if (prices[i] < prices[imin]) imin = i;
                if (prices[i] > prices[imax]) imax = i;
        }

        return max;    
}
}

int main()
{

}
