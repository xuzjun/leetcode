/*
Given a sorted array and a target value,
return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
[3,5,7,9,10], 8 → 3
*/

int searchInsert(int* nums, int numsSize, int target) {
	int l, r, mid;
	l = 0;
	r = numsSize - 1;

	while (l <= r) {
		mid = l + (r - l) / 2; // "(l + r) / 2" may overflow
		if (nums[mid] == target) return mid;
		if (nums[mid] < target) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int main()
{

}
