# https://leetcode.com/problems/minimum-height-trees
# TC: o(e+n) SC: o(n) n = nodes, e = edges
# BFS from outside to inside
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
            
        graph = defaultdict(set)
        for i in range(len(edges)):
            graph[edges[i][0]].add(edges[i][1])
            graph[edges[i][1]].add(edges[i][0])

        queue = deque()
        for node in graph:
            if len(graph[node]) == 1:
                queue.append(node)
        left_nodes = n
        while left_nodes > 2:
            left_nodes -= len(queue)
            for _ in range(len(queue)):
                node = queue.popleft()
                edge = graph[node].pop()
                graph[edge].remove(node)
                if len(graph[edge]) == 1:
                    queue.append(edge)
        return queue
