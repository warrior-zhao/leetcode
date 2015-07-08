class Solution:
    # @param {string} s
    # @param {string} p
    # @return {boolean}
    def isMatch(self, s, p):
        if s == p:
            return True
        if len(p) == 0:
            return False
            
        char_matched = False
        if len(s) > 0 and (s[0] == p[0] or p[0] == '.'):
            char_matched = True

        expression_matched = False
        if len(p) >= 2 and p[1] == '*':
            expression_matched = self.isMatch(s, p[2:])
            if char_matched and not expression_matched:
                expression_matched = self.isMatch(s[1:], p)
        elif char_matched:
            expression_matched = self.isMatch(s[1:], p[1:])
        return expression_matched

import sys

s = sys.argv[1]
p = sys.argv[2]
solution = Solution()
matched = solution.isMatch(s, p)
print matched