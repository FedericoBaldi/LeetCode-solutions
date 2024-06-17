# Save in a classic map, check all the keys with prefix
# TC: o(n*p) SC: o(n)
class MapSum:

    def __init__(self):
        self.map = {}

    def insert(self, key: str, val: int) -> None:
        self.map[key] = val

    def sum(self, prefix: str) -> int:
        res = 0
        for key in self.map.keys():
            if len(prefix) > len(key):
                continue
            res += self.map[key]
            for i in range(len(prefix)):
                if prefix[i] != key[i]:
                    res -= self.map[key]
                    break
        return res