Question: 1
Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.
Examples: (Should not use the examples to submit your code. These examples are for your understanding)
Input:
V = 5, E = 7
edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]

Output: 
[[1,4], [0,2,3,4], [1,3], [1,2,4], [0,1,3]]
Explanation:
Node 0 is connected to 1 and 4.
Node 1 is connected to 0,2,3 and 4.
Node 2 is connected to 1 and 3.
Node 3 is connected to 1,2 and 4.0 1
Node 4 is connected to 0,1 and 3.
