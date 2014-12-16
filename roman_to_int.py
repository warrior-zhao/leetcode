class Solution:
    # @return an integer
    def romanToInt(self, s):
        s = s.lower()
        roman_val_map = {'i':1, 'v':5, 'x':10, 'l':50, 'c':100, 'd':500, 'm':1000}
        sum = 0
        last_val = 0
        for c in s:
            cur_val = roman_val_map[c]
            if(cur_val > last_val):
                sum = sum + cur_val - 2*last_val
            else:
                sum += cur_val
        return sum

roman_to_int = Solution()
print roman_to_int.romanToInt('DC')
