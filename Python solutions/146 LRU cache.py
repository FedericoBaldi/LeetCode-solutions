# https://leetcode.com/problems/lru-cache
# TC: o(1) SC: o(1)
class Node:
    def __init__(self, key = 0, val=0, prev = None, next=None):
        self.key = key
        self.val = val
        self.prev = prev
        self.next = next

class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}
        self.left = Node()
        self.right = Node()
        self.left.next, self.right.prev = self.right, self.left

    def _remove(self, node: Node) -> None:
        prev_n, next_n = node.prev, node.next
        prev_n.next, next_n.prev = next_n, prev_n

    def _insert(self, node: Node):
        head = self.left.next
        node.next, head.prev = head, node
        self.left.next, node.prev = node, self.left

    def get(self, key: int) -> int:
        if key in self.cache:
            self._remove(self.cache[key])
            self._insert(self.cache[key])
            return self.cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self._remove(self.cache[key])
        node = Node(key, value, None, None)
        self.cache[key] = node
        self._insert(node)

        if len(self.cache) > self.cap:
            last = self.right.prev
            self._remove(last)
            self.cache.pop(last.key)
