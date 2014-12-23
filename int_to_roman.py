class Solution:
    # @return a string
    def intToRoman(self, num):
        if num <= 0:
            return ''
        roman_nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        roman_strs = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        roman_str = ''
        for index in range(len(roman_nums)):
            print index, roman_strs[index]
            cur_val = roman_nums[index]
            if num >= cur_val:
                num -= cur_val
                roman_str += roman_strs[index]
                break;
        roman_str += self.intToRoman(num)
        return roman_str

int_to_roman = Solution()
print int_to_roman.intToRoman(98)