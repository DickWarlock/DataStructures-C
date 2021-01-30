/*
Array vs Linked list:           ARRAY                                   LLIST
                Cost access:        O(1)                                      O(n) (average)
                Memory usage:  unused memory                   not unused memory but extra memory for pointers variables
                                           may not use large blocks     can use multiple small blocks
         Cost insert element:  beginning: O(n)                    beginning: O(1)
                                           end: O(1)                               end: O(n)
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;
node *head; //Global head, change if you want

/*
    Create a node with a number as parameter.
*/
node *createNode(int num)
{
    node *ret = (node *)malloc(sizeof(node));
    ret->data = num;
    ret->next = NULL;
    return ret;
}

/*
    Insert a number at beginning of the list
*/
void insertBeginning(int num)
{
    node *ret = createNode(num);
    ret->next = head;
    head = ret;
}

/*
    Insert a number at the n-th position
    Only insert in valid positions
*/
void insertAtPosition(int num, int pos)
{
    int i;
    node *ret = createNode(num);
    if (pos == 1)
    {
        insertBeginning(num);
    }

    node *temp = head;
    for (i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    ret->next = temp->next;
    temp->next = ret;
}

/*
    Delete element at the n-th position
    Only valid positions
*/
void deleteAtPosition(int pos)
{
    int i;
    node *temp = head;
    if (pos == 1)
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        for (i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }

        node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

/*
    Print linked list
*/
void printLinkedList()
{
    node *temp = head;

    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    head = NULL;

    //Example code
    int i;
    for (i = 0; i < 10; i++)
    {
        insertBeginning(i);
    }
    insertAtPosition(24, 7);
    printLinkedList();
    printf("\n");
    deleteAtPosition(7);
    printLinkedList();
    return 0;
}