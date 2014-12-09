#include <string>
#include <map>
#include <stdio.h>

using std::string;
using std::map;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman_map;
        roman_map['i'] = 1;
        roman_map['v'] = 5;
        roman_map['x'] = 10;
        roman_map['l'] = 50;
        roman_map['c'] = 100;
        roman_map['d'] = 500;
        roman_map['m'] = 1000;

        int roman_value = 0;
        int last_val = 0;
        for(size_t char_index=0; char_index<s.size(); char_index++)
        {
            char cur_char = tolower(s[char_index]);
            if(roman_map.find(cur_char) == roman_map.end())
            {
                break;
            }

            int cur_val = roman_map[cur_char];
            if(cur_val > last_val)
            {
                roman_value = roman_value + cur_val - last_val*2;
            }
            else
            {
                roman_value += cur_val;
            }

            last_val = cur_val;

        }

        return roman_value;
    }
};

int main(int argc, char* argv[])
{
    string roman_str = "XLV";
    if(argc > 1)
    {
        roman_str = argv[1];
    }

    Solution solution1;
    int roman_value = solution1.romanToInt(roman_str);
    printf("%d", roman_value);
    return 0;
}