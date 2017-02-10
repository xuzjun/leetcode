/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/
#include <iostream>
#include <vector>
#include <set>
#include <tuple>

class Solution {
public:
	
    std::vector<std::pair<int, int>> pacificAtlantic(std::vector<std::vector<int>>& matrix) {
  	    std::vector<std::pair<int, int>> ret;
		std::tuple<int, int> shape;

		if ((std::get<0>(shape) = matrix.size()) == 0 || (std::get<1>(shape) = matrix[0].size()) == 0)
			return ret;

		std::cout << "matrix shape (" << std::get<0>(shape) << ", " << std::get<1>(shape) << ")\n";
	
		int len = std::get<0>(shape) * std::get<1>(shape);
		std::vector<std::tuple<int, std::set<int>>> adj(len);

		unsigned int m = 0;
		for (int i = 0; i < std::get<0>(shape); ++i) {
			for (int j = 0; j < std::get<1>(shape); ++j) {
				std::get<0>(adj[m]) = matrix[i][j];
				if (j - 1 >= 0 && matrix[i][j - 1] <= matrix[i][j])
					std::get<1>(adj[m]).insert(i * std::get<0>(shape) + j - 1);

				if (j + 1 < std::get<1>(shape) && matrix[i][j + 1] <= matrix[i][j])
					std::get<1>(adj[m]).insert(i * std::get<0>(shape) + j + 1);

				if (i - 1 >= 0 && matrix[i - 1][j] <= matrix[i][j])
					std::get<1>(adj[m]).insert((i - 1) * std::get<0>(shape) + j);

				if (i + 1 < std::get<0>(shape) && matrix[i + 1][j] <= matrix[i][j])
					std::get<1>(adj[m]).insert((i + 1) * std::get<0>(shape) + j);

				m++;
			}
		}

		m = 0;
		for (m = 0; m < adj.size(); ++m) {
			std::cout << "pos: " << m << "\n";
			std::cout << "  val: " << std::get<0>(adj[m]) << "\n";
			std::set<int> l = std::get<1>(adj[m]);
			std::cout << "  adj: ";
			for (std::set<int>::iterator it = l.begin(); it != l.end(); ++it)
				std::cout << *it << ", ";

			std::cout << "\n";
		}

		return ret;
	}
};

int main()
{
	std::vector<int> v1(5);
	std::vector<std::vector<int>> v2(5);

	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 2;
	v1[3] = 3;
	v1[4] = 5;

	v2[0] = v1;

	v1[0] = 3;
	v1[1] = 2;
	v1[2] = 3;
	v1[3] = 4;
	v1[4] = 4;

	v2[1] = v1;

	v1[0] = 2;
	v1[1] = 4;
	v1[2] = 5;
	v1[3] = 3;
	v1[4] = 1;

	v2[2] = v1;

	v1[0] = 6;
	v1[1] = 7;
	v1[2] = 1;
	v1[3] = 4;
	v1[4] = 5;

	v2[3] = v1;

	v1[0] = 5;
	v1[1] = 1;
	v1[2] = 1;
	v1[3] = 2;
	v1[4] = 4;

	v2[4] = v1;

	std::cout << "matrix: " << std::endl;
	for (std::vector<std::vector<int>>::iterator it = v2.begin(); it != v2.end(); ++it) {
		std::cout << "       ";
		for (std::vector<int>::iterator it1 = (*it).begin(); it1 != (*it).end(); ++it1) {
			std::cout << *it1 << ", ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";

	Solution solution;
    std::vector<std::pair<int, int>> ret = solution.pacificAtlantic(v2);

	for (std::vector<std::pair<int, int>>::iterator it = ret.begin(); it != ret.end(); ++it)
		std::cout << (*it).first << ", " << (*it).second << std::endl;

	return 0;
}
