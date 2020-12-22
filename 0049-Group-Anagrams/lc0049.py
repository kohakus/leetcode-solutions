# Python solution.

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash = collections.defaultdict(list)
        for s in strs:
            buckets = [0] * 26
            for c in s:
                buckets[ord(c) - 97] += 1
            hash[tuple(buckets)].append(s)
        return list(hash.values())
