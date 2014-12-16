#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using std::vector;
using std::string;

class Solution {
public:
    /**
     * 阿拉伯数字转为罗马数字.
     * 罗马数字共7个{i, v, x, l, c, d, m}，对应的数字为 {1，5，10,50,100,500,1000}。
     * 转换原则：
     *  a. 大数在左边，小数在右边，俩数相加
     *  b. 大数在右边，小数在左边，大数减小数（右加左减）
     *  c. 只有i x c能作为左减数字,且左减数字只有一位
     *  d. 右加数字不可连续超过三位
     * @param  num [输入的阿拉伯数字]
     * @return     [返回罗马数字的字符串形式]
     */
    string intToRoman(int num) {

        //C++98 不支持vector的直接赋值，编译时可以使用 '-std=c++11' 选项
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