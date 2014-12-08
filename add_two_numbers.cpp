/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* head_node = NULL;
        ListNode* node = head_node;
        int sum = 0;
        while(l1 || l2)
        {

            int val1 = 0;
            int val2 = 0;
            if(l1)
            {
                val1 = l1->val;
                l1 = l1->next;
            }
                
            if(l2)
            {
                val2 = l2->val;
                l2 = l2->next;  
            }

            int val = (val1 + val2 + sum)%10;
            ListNode* cur_node = new ListNode(val);
            if(!head_node)
            {
                head_node = cur_node;
                node = head_node;
            }
            else
            {
                node->next = cur_node;
                node = node->next;
            }
            sum = (val1 + val2 + sum)/10;     
        }
        
        if(sum != 0)
        {
            node->next = new ListNode(sum);
        } 
    }
};

int main(int argc, char* argv[])
{
    
    Solution solution1;
    ListNode* head1 = NULL;
    ListNode* node1 = head1;
    for(int index=0; index<3; index++)
    {
        //node1 = &(nodes[index]);
        ListNode* cur_node  = new ListNode(index + 5);
        if(!head1)
        {
            head1 = cur_node;
            node1 = head1;
        }else
        {
            node1->next = cur_node;
            node1 = node1->next;
        }
    }

    ListNode* head2 = NULL;
    ListNode* node2 = head1;
    for(int index=0; index<3; index++)
    {
        //node1 = &(nodes[index]);
        ListNode* cur_node  = new ListNode(index + 6);
        if(!head2)
        {
            head2 = cur_node;
            node2 = head2;
        }else
        {
            node2->next = cur_node;
            node2 = node2->next;
        }
    }

    ListNode* node = solution1.addTwoNumbers(head1, head2);
    while(node)
    {
        printf("%d, \n", node->val);
        node = node->next;
    }


    return 0;
}