#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *CreateList(int *nums,int n)
{
    if(n == 0)
        return NULL;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(NULL != head);
    head->val = nums[0];
    head->next = NULL;
    struct ListNode *fixedHead = head;
    int i;
    for(i = 1;i < n;++i)
    {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        assert(NULL != node);
        node->val = nums[i];
        node->next = NULL;
        head->next = node;
        head = node;
    }
    return fixedHead;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(NULL != head);
    head->val = 0;
    head->next = NULL;
    struct ListNode *ret = head;
    int carry = 0,val = 0,num1 = 0,num2 = 0;
    while(l1 || l2 || carry)
    {
        num1 = 0;
        num2 = 0;
        if (l1)
        {
            num1 = l1->val;
            l1 = l1->next;
        }
        if(l2)
        {
            num2 = l2->val;
            l2 = l2->next;
        }
        val = (num1 + num2 +carry) % 10;
        carry = (num1 + num2 +carry) / 10;
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        assert(NULL != node);
        node->val = val;
        node ->next = NULL;
        head->next = node;
        head = node;
    }
    return ret->next;
}
int main(int ar2gc, char const *argv[])
{
    int arr1[5] = {7,8,9};
    int arr2[5] = {9,9,9};
    struct ListNode *list1 = CreateList(arr1,3);
    struct ListNode *list2 = CreateList(arr2,3);
    struct ListNode *head1 = list1;
    struct ListNode *head2 = list2;
    while(list1)
    {
        printf("%d-->", list1->val);
        list1 = list1->next;
    }
    printf("\n");
    while(list2)
    {
        printf("%d-->", list2->val);
        list2 = list2->next;
    }
    struct ListNode* sum = addTwoNumbers(head1,head2);
    printf("\n");
    while(sum)
    {
        printf("%d-->", sum->val);
        sum = sum->next;
    }
    return 0;
}

