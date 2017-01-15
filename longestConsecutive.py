class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret, dic = 1, {}
	for n in nums:
		if n not in dic:
			l = dic.get(n - 1, 0)
			r = dic.get(n + 1, 0)
			length = l + r + 1
			dic[n] = length
			dic[n - l] = length
			dic[n + r] = length
			ret = max(ret, length)

	return ret

if __name__ == "__main__":
	sol = Solution()
	ret = sol.longestConsecutive([1,2,0,1])
	print(ret)
