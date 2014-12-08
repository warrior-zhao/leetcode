#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    int reverse(int x) {    
        int is_negtive = (x<0)?-1:1;
        x = abs(x);
        int result = 0;
        while(x >= 10)
        {
            int high_digit = x%10;
            result = result*10 + high_digit;
            x = x/10;
        }

        result = result*10 + x;
        result *= is_negtive;

        return result;
    }
};

int main(void)
{
    Solution solution1;
    int int_val = -123;
    int result = solution1.reverse(int_val);
    printf("%d", result);
    return 0;
}