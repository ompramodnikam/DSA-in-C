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

void EnQueue(PPNODE First, int No)//InsertLast()
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn ->data = No;
    newn ->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        temp = *First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp ->next = newn;
    }
}

void DeQueue(PPNODE First)//DeleteFirst()
{
    PNODE temp = NULL;

    if(*First == NULL)
    {
        printf("Linked List is empty...\n");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        temp = *First;
        *First = (*First) ->next;
        free(temp);
    }
}

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("%d\t",First ->data);
        First = First ->next;
    }
    printf("\n");
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

    int iRet = 0;

    EnQueue(&Head,10);
    EnQueue(&Head,20);
    EnQueue(&Head,30);
    EnQueue(&Head,40);
    Display(Head);
    iRet = Count(Head);
    printf("Total elements are : %d\n",iRet);

    DeQueue(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Total elements are : %d\n",iRet);


    return 0;
}