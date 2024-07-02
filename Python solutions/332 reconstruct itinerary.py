# https://leetcode.com/problems/reconstruct-itinerary
# TC: o(nlogn) SC: o(n)
# Reconstruct the itinerary backwords selecting the smaller lexical order first
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        tickets.sort()
        tickets.reverse()
        graph = defaultdict(list)
        for start, stop in tickets:
            graph[start].append((stop))
        
        res = []
        def dfs(curr):
            while graph[curr]:
                dfs(graph[curr].pop())
            res.append(curr)
        dfs("JFK")

        res.reverse()
        return res