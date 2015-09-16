#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef struct _ListNode{
    int val;
    _ListNode* next;
    _ListNode(int x):val(x), next(NULL)
    {

    }
}ListNode;


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head_node = NULL;
        ListNode* tail_node = NULL;
        while((l1 != NULL) && (l2 != NULL))
        {
            if(l1 == l2)
            {
                break;
            }

            ListNode* tmp_node = NULL;
            if(l1->val <= l2->val)
            {
                tmp_node = l1;
                l1 = l1->next;
            }
            else
            {
                tmp_node = l2;
                l2 = l2->next;
            }

            if(head_node == NULL)
            {
                head_node = tmp_node;
                tail_node = head_node;
            }
            else
            {
                tail_node->next = tmp_node;
                tail_node = tmp_node;
            }

        }

        if(l1 != NULL)
        {
            if(head_node == NULL)
            {
                head_node = l1;
            }
            else
            {
               tail_node->next = l1; 
            }
            
        }
        else if(l2 != NULL)
        {
            if(head_node == NULL)
            {
                head_node = l2;
            }
            else
            {
               tail_node->next = l2; 
            }
        }

        return head_node;
    }
};

void PrintList(ListNode* list)
{
    while(list != NULL)
    {
        printf("%d->", list->val);
        list = list->next;
    }

    printf("\n");
}

int main(int argc, char* argv[])
{
    Solution solution1;
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);

    node1.next = &node2;
    node3.next = &node4;
    ListNode* merged_list = solution1.mergeTwoLists(NULL, &node3);
    PrintList(merged_list);
    return 0;
}