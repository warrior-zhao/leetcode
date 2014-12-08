#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m < 0) || (n < 0) || ((m+n) <= 0))
        {
            return 0.0;
        }

        int first = 0;
        int second = 0;
        int index1 = 0;
        int index2 = 0;
        int count = 0;
        while(count <= (m + n)/2)
        {
            first = second;
            if((index1 < m) && (index2 < n) && (A[index1] < B[index2]))
            {
                second = A[index1];
                index1++;
            }
            else if(index2 < n)
            {
                second = B[index2];
                index2++;
            }
            else
            {
                second = A[index1];
                index1++;
            }
            count++;
        }

        double result = 0;
        if((m+n)%2 != 0)
        {
            result = second;    
        }
        else
        {
            result = ((double)(first + second))/2;
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    int a[1] = {2};
    int b[3] = {2,4,6};

    Solution solution1;
    double result = solution1.findMedianSortedArrays(a, 1, b, 0);
    printf("%g", result);
    return 0;
}