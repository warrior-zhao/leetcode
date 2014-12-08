#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>

using std::string;
using std::map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t len = s.size();
        if(len <= 1)
        {
            return len;
        }
        
        int longest_len = -1;
        int last_index = 0;
        map<char, int> exist_map;
        for(size_t index=0; index<len; index++)
        {
            char cur_char = s[index];
            int len = 0;
            if((exist_map.find(cur_char) != exist_map.end())
              && (last_index < exist_map[cur_char]))
            {
                len = index - exist_map[cur_char];
                last_index = index;
            }
            else
            {
                len = index - last_index;
            }

            if(len > longest_len)
            {
                longest_len = len;
            }

            exist_map[cur_char] = index;
        }
        return longest_len;
    }
};


int main(int argc, char* argv[])
{
    string s = "abc";
    if(argc > 1)
    {
        s = argv[1];
    }
    Solution solution1;
    int len = solution1.lengthOfLongestSubstring(s);
    printf("%d\n", len);
    return 0;
}