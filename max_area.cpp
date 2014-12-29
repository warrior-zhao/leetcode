#include <vector>
#include <stdio.h>
#include <limits.h>

using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int maxArea(vector<int> &height) {
        size_t array_size = height.size();
        if(array_size <= 1)
        {
            return 0;
        }

        /**
         *NOTE:
         * 从两头开始选择两条边计算最大面积。
         * 查找的时候，对于较大的一条边，如果继续从这条边开始找最大值，那么无论如何后面的面积都不会比当前面积要大
         * （如果与较大边相邻的边更大，则高度不变，宽度变小；如果相邻边更小，那么高度更小且宽度更小），因此每次移动较小
         * 的那条边即可以找到最大面积，时间复杂度O(n)
         */
        int max_area = 0;
        int left = 0;
        int right = (int)(array_size - 1);
        while(left < right)
        {
            max_area = max(max_area, (right-left)*min(height[left], height[right]));
            if(height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        
        return max_area;
    }
};

int main(int argc, char* argv[])
{
    vector<int> height = {1,2,3};
    Solution solution1;
    int area = solution1.maxArea(height);
    printf("%d\n", area);
    return 0;
}