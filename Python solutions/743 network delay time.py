# https://leetcode.com/problems/network-delay-time
# TC: o(ElogV) SC: o(E + V) E = edges, V = vertices
# Dijkstra
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = defaultdict(list)
        for e1, e2, time in times:
            graph[e1].append([e2, time])
        min_time = 0
        min_heap = []
        heappush(min_heap, (0, k))
        visited = set()
        while min_heap:
            node = heappop(min_heap)
            if node[1] in visited:
                continue
            visited.add(node[1])
            min_time = node[0]
            
            for next_node in graph[node[1]]:
                heappush(min_heap, (node[0] + next_node[1], next_node[0]))
        return min_time else -1

