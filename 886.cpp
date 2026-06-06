from collections import defaultdict

class Solution:
    def possibleBipartition(self, n: int, dislikes: list[list[int]]) -> bool:
        graph = defaultdict(list)
        for u, v in dislikes:
            graph[u].append(v)
            graph[v].append(u)

        color = {}

        def dfs(node, c):
            color[node] = c
            for neighbor in graph[node]:
                if neighbor not in color:
                    if not dfs(neighbor, -c):
                        return False
                elif color[neighbor] == c:
                    return False
            return True

        for node in range(1, n + 1):
            if node not in color:
                if not dfs(node, 1):
                    return False

        return True