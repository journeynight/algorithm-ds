#! /usr/bin/python3
class Solution:
   '''
   key point of recursive in this problem is p[1] == '*' or not
   '''
   def isMatch(self,s,p):
       if p == '':
           return s == ''
       if len(p) > 1 and p[1] == '*':
          return self.isMatch(s,p[2:]) or ((s!= '' and (s[0] == p[0] or p[0] == '.')) and self.isMatch(s[1:],p))
       else:
          return (s != '' and (s[0] == p[0] or p[0] == '.')) and self.isMatch(s[1:],p[1:])
if __name__ == '__main__':
    s = input('input str:')
    p = input('input pattern:')
    solution = Solution()
    print(solution.isMatch(s,p))
