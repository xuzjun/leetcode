/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

#include <stdio.h>
#include <stdlib.h>

int canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
        char *g = calloc(numCourses * numCourses, sizeof(int));
        char *t = calloc(numCourses, sizeof(int));
        int i, j, m;
        for (i = 0; i < prerequisitesRowSize; ++i) {
                *(g + prerequisites[i][1] * numCourses + prerequisites[i][0]) = 1;
                t[prerequisites[i][0]] = 1;
        }

        
        for (i = 0; i < numCourses; ) {
                if (t[i] == 1) { i++; continue; }
                t[i] = 1;
                int flag = 0;
                for (j = 0; j < numCourses; ++j) {
                        if (*(g + i * numCourses + j) == 1) {
                                *(g + i * numCourses + j) = 0;
                                for (m = 0; m < numCourses; ++m)
                                        if (*(g + m * numCourses + j) == 1)
                                                break;
                                if (m == numCourses) {
                                        t[j] = 0;
                                        flag = 1;
                                }
                        }
                }
                if (flag == 1) i = 0;
                else i++;
        }

        for (i = 0; i < numCourses; ++i)
                for (j = 0; j < numCourses; ++j)
                        if (*(g + i * numCourses + j) == 1) return 0;

        return 1;
}

int main()
{
	int **nums;
	nums = (int **)malloc(3 * sizeof(int *));
	int i;
	for (i = 0; i < 3; ++i) {
		nums[i] = malloc(2 * sizeof(int));
	}
	nums[0][0] = 1;
	nums[0][1] = 0;
	nums[1][0] = 1;
	nums[1][1] = 2;
	nums[2][0] = 2;
	nums[2][1] = 0;
	int ret = canFinish(3, nums, 3, 2);
	printf("%d\n", ret);
	return 0;
}
