#include <string>
#include <stdio.h>
#include <stdlib.h>

using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.size() <= 1)
        {
            return s;
        }

        string palind_str;
        size_t str_len = s.size();
        for(size_t index=0; index<str_len; index++)
        {
            size_t left = index;
            size_t right = index;
            while((left >= 0) && (right < str_len) && (s[left] == s[right]))
            {
                left--;
                right++;
            }
            string cur_palind = s.substr(left+1, right-left-1);
            if(cur_palind.size() > palind_str.size())
            {
                palind_str = cur_palind;
            }

            left = index;
            right = index + 1;
            while((left >= 0) && (right < str_len) && (s[left] == s[right]))
            {
                left--;
                right++;
            }
            cur_palind = s.substr(left+1, right-left-1);
            if(cur_palind.size() > palind_str.size())
            {
                palind_str = cur_palind;
            }
        }

        return palind_str;
    }
};

int main(int argc, char* argv[])
{
    Solution solution1;
    string s = argv[1];
    string longest_palind = solution1.longestPalindrome(s);
    printf("%s", longest_palind.c_str());
    return 0;
}