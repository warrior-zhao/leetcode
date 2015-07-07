#include <string>
#include <stdio.h>

using std::string;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == p)
        {
            return true;
        }
        if(p.empty())
        {
            return false;
        }

        bool char_match = false;
        if(!s.empty() && (s.at(0) == p.at(0) || '.' == p.at(0)))
        {
            char_match = true;
        }

        bool expression_matched = false;
        if(p.size() >= 2 && '*' == p.at(1))
        {
            expression_matched = isMatch(s, p.substr(2));
            if(char_match && !expression_matched)
            {
                //*匹配需要匹配多个字符的情况。 如果第一个字符不匹配，*匹配只能匹配0个字符
                expression_matched = isMatch(s.substr(1), p);
            } 
        }
        else if(char_match)
        {
            expression_matched = isMatch(s.substr(1), p.substr(1));
        }

        return expression_matched;
    }

};

int main(int argc, char* argv[])
{
    if(argc <= 2)
    {
        return 0;
    }

    Solution solution;
    bool is_matched = solution.isMatch(argv[1], argv[2]);
    if(is_matched)
    {
        printf("%s %s matched! \n", argv[1], argv[2]);
    }
    else
    {
        printf("%s %s NOT matched!\n", argv[1], argv[2]);
    }
    return 0;
}