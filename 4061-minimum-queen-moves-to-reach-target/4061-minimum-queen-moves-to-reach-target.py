class Solution:
    def minQueenMoves(self, source: list[int], target: list[int]) -> int:
        if(source[0] == target[0] and source[1]==target[1]):
            return 0
        elif((abs(source[0]-target[0]) == abs(target[1]-source[1])) or source[0] == target[0] or source[1]==target[1]):
            return 1
        else:
            return 2