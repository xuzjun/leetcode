'''
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
'''

class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """

		lp = list(pattern)
		ls = str.split()

		lenp = len(lp)
		lens = len(ls)

		if lenp != lens:
			return False

		for i in range(lenp):
			for j in range(i + 1, lenp, 1):
				if (lp[i] == lp[j] and ls[i] != ls[j]) || (lp[i] != lp[j] and ls[i] == ls[j]):
					return False

		return True
		
