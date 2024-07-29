#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE First, PNODE Last)
{
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
    newn ->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
        *Last = newn;
    }
    else 
    {
        newn ->next = *First;
        *First = newn;
        newn ->prev = *Last;
    }
    (*First) ->prev = *Last;
    (*Last) ->next = *First;
}

void InsertLast(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = No;
    newn ->next = NULL;
    newn ->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
        *Last = newn;
    }
    else 
    {
        (*Last) ->next = newn;
        newn ->prev = *Last;
        *Last = newn;
    }
    (*First) ->prev = *Last;
    (*Last) ->next = *First;
}


void InsertAtPos(PPNODE First, PPNODE Last, int No, int iPos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int i = 0;
    int iLength = 0;
    iLength = Count(*First,*Last);
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn ->data = No;
    newn ->prev = NULL;
    newn ->next = NULL;

    if(iPos == 1)
    {
        InsertFirst(First,Last,No);
    }
    else if(iPos == (iLength+1))
    {
        InsertLast(First,Last,No);
    }
    else 
    {
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

void DeleteFirst(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        printf("Linked List is empty...\n");
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else 
    {
        *First = (*First) ->next;
        free((*Last) ->next);
        (*Last) ->next = *First;
        (*First) ->prev = *Last;
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        printf("Linked List is empty...\n");
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else 
    {
        *Last = (*Last) ->prev;
        free((*Last) ->next);
        (*First) ->prev = *Last;
        (*Last) ->next = *First;
    }
}

void DeleteAtPos(PPNODE First, PPNODE Last, int iPos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    int i = 0;
    int iLength = 0;
    iLength = Count(*First,*Last);

    if(iPos == 1)
    {
        DeleteFirst(First,Last);
    }
    else if(iPos == (iLength+1))
    {
        DeleteLast(First,Last);
    }
    else 
    {
        temp1 = *First;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp1 = temp1 ->next;
        }

        temp2 = temp1 ->next->next;
        temp1 ->next = temp2;
        free(temp2->prev);
        temp2 ->prev = temp1;
    }
}

int main()
{
    int iRet = 0;

    PNODE Head = NULL;
    PNODE Tail = NULL;

    printf("--------------Implimentation of Doubly Circular Linked List--------------\n");

    //InsertFirst : 
    InsertFirst(&Head,&Tail,41);
    InsertFirst(&Head,&Tail,31);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes in the LL is : %d\n",iRet);

    //InsertLast : 
    InsertLast(&Head,&Tail,51);
    InsertLast(&Head,&Tail,61);
    InsertLast(&Head,&Tail,71);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes in the LL is : %d\n",iRet);

    //InsertAtPos : 
    InsertAtPos(&Head,&Tail,25,3);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes in the LL is : %d\n",iRet);

    //DeleteFirst : 
    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes in the LL is : %d\n",iRet);

    //DeleteLast : 
    DeleteLast(&Head,&Tail);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes in the LL is : %d\n",iRet);

    //DeleteAtPos : 
    DeleteAtPos(&Head,&Tail,4);
    Display(Head,Tail);
    iRet = Count(Head,Tail);
    printf("Number of nodes in the LL is : %d\n",iRet);


    return 0;
}