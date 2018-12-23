#! /usr/bin/python3
class Solution:
    def isMatch(self,s,p):
        m,n = len(s),len(p)
        dp  = [[False] * (n + 1) for i in range(m + 1)]
        dp[0][0] = True
        for i in range(1,m+1,1):
            dp[i][0] = False
        for j in range(2,n+1,1):
            dp[0][j] =   p[j-1] == '*' and dp[0][j-2]
        for i in range(1,m+1,1):
            for j in range(1,n+1,1):
                if p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2] or ((s[i-1] == p[j-2] or p[j-2] == '.') and dp[i-1][j])
                else:
                    dp[i][j] = (s[i-1] == p[j-1] or p[j-1] == '.') and dp[i-1][j-1]
        return dp[m][n]
if __name__ == '__main__':
    solution = Solution()
    while True:
        s = input("input string:")
        p = input("input pattern:")
        print(solution.isMatch(s,p))                 
