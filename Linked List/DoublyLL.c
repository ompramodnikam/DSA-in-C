#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE First)
{
    printf("\nNULL <=>");
    while(First != NULL)
    {
        printf("| %d | <=> ",First ->data);
        First = First ->next;
    }
    printf("NULL\n");
}

int Count(PNODE First)
{
    int iCount = 0;

    while(First != NULL)
    {
        First = First ->next;
        iCount++;
    }
    return iCount;
}

void InsertFirst(PPNODE First, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = No;
    newn ->next = NULL;
    newn ->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else 
    {
        newn ->next = *First;
        (*First) ->prev = newn;
        *First = newn;  
    } 
}

void InsertLast(PPNODE First , int No)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = No;
    newn ->next = NULL;
    newn ->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else 
    {
        temp = *First;
        while(temp ->next != NULL)
        {
            temp = temp ->next;
        }
        newn ->prev = temp;
        temp ->next = newn;
    } 
}

void InsertAtPos(PPNODE First , int No, int iPos)
{
    int iLength = 0;
    int i = 0;

    iLength = Count(*First);
    
    PNODE newn = NULL;
    PNODE temp = NULL;

    if((iPos < 1 ) || (iPos > iLength+1))
    {
        printf("Invalid Input...\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First,No);
    }
    else if(iPos == (iLength+1))
    {
        InsertLast(First,No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn ->data = No;
        newn ->next = NULL;
        newn ->prev = NULL;

        temp = *First;
        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp ->next;
        }
        newn ->next = temp ->next;
        temp ->next->prev = newn;
        temp ->next = newn;
        newn ->prev = temp;
    }
}

void DeleteFirst(PPNODE First)
{
    if(*First == NULL)
    {
        printf("Unable to delete..");
        return;
    }
    else if((*First) -> next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        *First = (*First) ->next;
        free((*First) ->prev);
        (*First) ->prev = NULL;
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = NULL;

    if(*First == NULL)
    {
        printf("Unable to delete..");
        return;
    }
    else if((*First) -> next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        temp = *First;

        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        free(temp ->next);
        temp ->next = NULL;
    }
}

void DeleteAtPos(PPNODE First, int iPos)
{
    int i = 0;

    PNODE temp = NULL;

    int iLength = 0;    
    iLength = Count(*First);

    if((iPos < 1 ) || (iPos > iLength+1))
    {
        printf("Invalid Position...\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(First);
    }
    else if(iPos == (iLength+1))
    {
        DeleteLast(First);
    }
    else 
    {
        temp = *First;
        for(i = 1 ; i < (iPos-1) ; i++)
        {
            temp = temp ->next;
        }
        temp ->next = temp ->next->next;
        free(temp ->next->prev);
        temp ->next->prev = temp;
    }
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    printf("-------------- Implementation of Doubly Linear Linked List --------------\n");

    //InsertFirst :
    InsertFirst(&Head,151);
    InsertFirst(&Head,101);
    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);
    Display(Head);
    iRet = Count(Head);
    printf("Number of Nodes is : %d\n",iRet);

    //DeleteFirst :
    InsertLast(&Head,201);
    Display(Head);
    iRet = Count(Head);
    printf("Number of Nodes is : %d\n",iRet);

    //InsertAtPos : 
    InsertAtPos(&Head,25,3);
    Display(Head);
    iRet = Count(Head);
    printf("Number of Nodes is : %d\n",iRet);

    //DeleteFirst :
    DeleteFirst(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of Nodes is : %d\n",iRet);

    //DeleteLast : 
    DeleteLast(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of Nodes is : %d\n",iRet);

    //DeleteAtPos : 
    DeleteAtPos(&Head,3);
    Display(Head);
    iRet = Count(Head);
    printf("Number of Nodes is : %d\n",iRet);


    return 0;
}