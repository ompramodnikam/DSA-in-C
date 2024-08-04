#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Push(PPNODE First, int No)//InsertFirst()
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = No;
    newn ->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else 
    {
        newn ->next = *First;
        *First = newn;
    }
}

int Pop(PPNODE First)//DeleteLast()
{
    int i = 0;
    int iValue = 0;

    PNODE temp = NULL;

    if(*First == NULL)
    {
        printf("Linked List is empty...\n");
    }
    else if((*First) ->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        temp = *First;
        while(temp ->next->next != NULL)
        {
            temp = temp ->next;
        }

        iValue = temp ->next->data;
        free(temp->next);
        temp->next = NULL;
    }
    return iValue;
}

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("%d\n",First->data);
        First = First ->next;
    }
}

int Count(PNODE First)
{
    int iCount = 0;

    while(First != NULL)
    {
        iCount++;
        First = First ->next;
    }
    return iCount;
}

int main()
{
    PNODE Head = NULL;

    int iPoped = 0;
    int iRet = 0;
    
    printf("Elements before Poped is : \n");
    Push(&Head,10);
    Push(&Head,20);
    Push(&Head,30);
    Push(&Head,40);
    Push(&Head,50);
    Display(Head);
    iRet = Count(Head);
    printf("Total Elements in the stach is : %d\n",iRet);

    printf("Elements after Poped is : \n");
    iPoped = Pop(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Poped value is : %d\n",iRet);
    printf("Total Elements in the stach is : %d\n",iRet);

    return 0;
}