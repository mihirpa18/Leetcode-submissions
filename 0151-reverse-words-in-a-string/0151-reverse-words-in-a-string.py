class Solution:
    def reverseWords(self, s: str) -> str:
        arr = s.split()
        arr.reverse()
        n=" ".join(arr)
        return n