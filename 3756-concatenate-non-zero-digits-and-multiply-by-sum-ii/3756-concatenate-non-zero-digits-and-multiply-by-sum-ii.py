from typing import List

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(s)

        preSum = [0] * (n + 1)
        preNum = [0] * (n + 1)
        prePow = [1] * (n + 1)
        length = [0] * (n + 1)

        # powers of 10 modulo MOD
        for i in range(1, n + 1):
            prePow[i] = (prePow[i - 1] * 10) % MOD

        # prefix arrays
        for i in range(1, n + 1):
            d = ord(s[i - 1]) - ord('0')

            preSum[i] = preSum[i - 1] + d

            if d != 0:
                preNum[i] = (preNum[i - 1] * 10 + d) % MOD
                length[i] = length[i - 1] + 1
            else:
                preNum[i] = preNum[i - 1]
                length[i] = length[i - 1]

        ans = []

        for l, r in queries:
            r += 1

            digit_sum = preSum[r] - preSum[l]
            cnt = length[r] - length[l]

            num = (
                preNum[r]
                - preNum[l] * prePow[cnt] % MOD
                + MOD
            ) % MOD

            ans.append((num * digit_sum) % MOD)

        return ans