#include <string>
#include <vector>
#include <stdio.h>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string longest_prefix;
        if(strs.empty())
        {
            return longest_prefix;
        }

        string& first_str = strs.front();
        size_t prefix_len = 0;
        bool prefix_matched = true;
        for(prefix_len=0; prefix_len<first_str.size(); prefix_len++)
        {
            

            for(size_t str_index=1; str_index<strs.size(); str_index++)
            {
                string& cur_str = strs[str_index];
                if(cur_str[prefix_len] != first_str[prefix_len])
                {
                    prefix_matched = false;
                    break;
                }
            }

            if(!prefix_matched)
            {
                break;
            }
        }

        return first_str.substr(0, prefix_len);
    }
};


int main(int argc, char* argv[])
{
    vector<string> strs;
    strs.push_back("ab");
    strs.push_back("ac");
    strs.push_back("ad");
    Solution solution1;
    string prefix = solution1.longestCommonPrefix(strs);
    printf("%s", prefix.c_str());
    return 0;
}