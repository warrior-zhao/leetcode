#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    bool isPalindrome(int x) {
        /*if(x < 0)
        {
            return false;
        } 

        int tmp_val = 0;
        bool is_palindrome = true;
        while(x > tmp_val)
        {
            int dec_val = x%10;
            tmp_val = tmp_val*10 + dec_val;
            if((x == tmp_val) && (x >= 10))
            {
                break;
            }

            x = x/10;
        }

        if(x != tmp_val)
        {
            is_palindrome = false;
        }

        return is_palindrome;*/
        if(x < 0)
        {
            return false;
        } 

        int tmp_x = x;
        int tmp_val = 0;
        while(x > 0)
        {
            int dec_val = x%10;
            tmp_val = tmp_val*10 + dec_val;
            x = x/10;
        }

        return (tmp_val == tmp_x);
    }
};

int main(int argc, char* argv[])
{
    Solution solution1;
    int x_val = 12321;
    if(argc > 1)
    {
        x_val = atoi(argv[1]);
    }
    bool is_par = solution1.isPalindrome(x_val);
    printf("%d", is_par);
    return 0;
}