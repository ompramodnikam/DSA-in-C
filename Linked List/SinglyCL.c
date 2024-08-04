#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE First, PNODE Last)
{   printf("\n");
    do
    {
        printf("| %d | <=> ",First ->data);
        First = First ->next;
    }while(First != Last ->next);
    printf("\n");
}

int Count(PNODE First, PNODE Last)
{
    int iCount = 0;

    do
    {
        iCount++;
        First = First ->next;
    }while(First != Last ->next);

    return iCount;
}

void InsertFirst(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = No;
    newn ->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
        *Last = newn;
    }
    else 
    {
        newn ->next = *First;
        *First = newn;
    }
    (*Last) ->next = * First;
}

void InsertLast(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = No;
    newn ->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
        *Last = newn;
    }
    else 
    {
        (*Last)->next = newn;
        *Last = newn;
    }
    (*Last) ->next = * First;
}

void InsertAtPos(PPNODE First, PPNODE Last, int No, int iPos)
{
    int i = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    int iLength = 0;
    iLength = Count(*First,*Last);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Input..\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First,Last,No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(First,Last,No);
    }
    else 
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn ->data = No;
        newn ->next = NULL;

        temp = *First;

        for(i = 1 ; i < (iPos-1) ; i++)
        {
            temp = temp ->next;
        }

        newn ->next = temp ->next;
        temp ->next = newn;

        (*Last) ->next = * First;
    }
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
    if(*First == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else 
    {
        *First = (*First) ->next;
        free((*Last) ->next);
    }
    (*Last) ->next = * First;
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    PNODE temp = NULL;

    if(*First == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else 
    {
        temp = *First;

        while(temp ->next->next != *First)
        {
            temp = temp ->next;
        }
        *Last = temp ;
        free((*Last) ->next);
    }
    (*Last) ->next = * First;

}

void DeleteAtPos(PPNODE First, PPNODE Last, int iPos)
{
    int i = 0;

    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    int iLength = 0;
    iLength = Count(*First,*Last);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Input..\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(First,Last);
    }
    else if(iPos == iLength)
    {
        DeleteLast(First,Last);
    }
    else 
    {
        temp1 = *First;

        for(i = 1 ; i < (iPos-1) ; i++)
        {
            temp1 = temp1 ->next;
        }
        
        temp2 = temp1 ->next->next;
        free(temp1 ->next);
        temp1 ->next = temp2;

        (*Last) ->next = * First;
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;

    int iRet = 0;

    printf("------------Implimentation of Singly Circular Linked List------------\n");
    
    //InsertFirst : 
    InsertFirst(&Head,&Tail,151);
    InsertFirst(&Head,&Tail,101);
    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,11);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes is : %d\n",iRet);

    //InsertLast : 
    InsertLast(&Head,&Tail,171);
    InsertLast(&Head,&Tail,201);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes is : %d\n",iRet);

    //InsertAtPos : 
    InsertAtPos(&Head,&Tail,5,2);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes is : %d\n",iRet);

    //DeleteFirst : 
    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes is : %d\n",iRet);

    //DeleteLast : 
    DeleteLast(&Head,&Tail);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes is : %d\n",iRet);

    //DeleteAtPos : 
    DeleteAtPos(&Head,&Tail,2);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes is : %d\n",iRet);

    return 0;
}