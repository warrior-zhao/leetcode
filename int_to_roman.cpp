#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using std::vector;
using std::string;

class Solution {
public:
    string intToRoman(int num) {
        static const vector<int> roman_nums = {
            1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
        };
        static const vector<string> roman_strs = {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I", 
        };

        if(num <= 0)
        {
            return "";
        }

        size_t roman_size = roman_nums.size();
        size_t index = 0;
        string cur_str = "";
        for(index=0; index<roman_size; index++)
        {
            if(num >= roman_nums[index])
            {
                num -= roman_nums[index];
                cur_str = roman_strs[index];
                break;
            }
        }

        return cur_str + intToRoman(num);
    }
};

int main(int argc, char* argv[])
{
    int arabic_no = 99;
    if(argc > 1)
    {
        arabic_no = atoi(argv[1]);
    }

    Solution solution1;
    string roman_str = solution1.intToRoman(arabic_no);
    printf("%s\n", roman_str.c_str());
    return 0;
}