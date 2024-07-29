//Function : InsertFirst() , InsertLast() , InsertAtPos() , DeleteFirst() , DeleteLast() ,  Display() , Count() : 

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

//  InsertFirst() : 
void InsertFirst(PPNODE First, int No)
{
    //step 1 : pointer of new node : 
    PNODE newn = NULL;

    //step 2 : Dynamic memory Allocation for newn : 
    newn = (PNODE)malloc(sizeof(NODE));

    //step 3 : intialize newn : 
    newn->data = No;
    newn->next = NULL;

    //step 4 : If zero node is present : 
    if(*First == NULL)
    {
        *First = newn;
    }
    else // step 5 : If more than one node is present : 
    {
        newn->next = *First;
        *First = newn;
    }
}

//  InsertLast() : 
void InsertLast(PPNODE First, int No)
{
    //step 1 : pointer of newn and temp  : 
    PNODE newn = NULL;
    PNODE temp = NULL;

    //step 2 : Dynamic memory Allocation for newn : 
    newn = (PNODE)malloc(sizeof(NODE));

    //step 3 : intialize newn : 
    newn->data = No;
    newn->next = NULL;

    //step 4 : If zero node is present : 
    if(*First == NULL)
    {
        *First = newn;
    }
    else // step 5 : If more than one node is present : 
    {
        temp = *First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}
//  InsertAtPos() : 
void InsertAtPos(PPNODE First , int No , int iPos)
{
    int i = 0;

    // step 1 : count the length of LL : 
    int iLength = 0;
    iLength = Count(*First);

    //  step 2 : declare the newn and temp pointer : 
    PNODE newn = NULL;
    PNODE temp = NULL;

    //  step 3 : if position is not valid : 
    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position\n");
        return;
    }

    //  step 4 : Insert at First location : 
    if(iPos == 1)
    {
        InsertFirst(First , No);
    }
    //  step 5 : Insert at last location : 
    else if(iPos == (iLength + 1))
    {
        InsertLast(First, No);
    }
    //  step 5 : Insert any where in the LL except first and last : 
    else 
    {
        temp = *First;

        newn = (PNODE)malloc(sizeof(NODE));
        newn ->data = No;
        newn ->next = NULL;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp ->next;
        }

        newn ->next = temp ->next;
        temp ->next = newn;
    }
}

//  DeleteFirst() : 
void DeleteFirst(PPNODE First)
{
    //  step1 : create one temp pointer : 
    PNODE temp = NULL;

    if(*First == NULL) //   step 2 : zero node is present : 
    {
        printf("Zero node is present this operation is not possible : \n");
    }
    else if((*First) ->next == NULL) // step 3 : one node is present : 
    {
        free(*First);
        *First = NULL;
    }
    else // step 4 : more than one node is present : 
    {
        temp = *First;
        *First = (*First) -> next;
        free(temp);
    }
}

//  DeleteLast() : 
void DeleteLast(PPNODE First)
{
    //  step1 : create one temp pointer : 
    PNODE temp = NULL;

    if(*First == NULL) //   step 2 : zero node is present : 
    {
        printf("Zero node is present this operation is not possible : \n");
    }
    else if((*First) ->next == NULL) // step 3 : one node is present : 
    {
        free(*First);
        *First = NULL;
    }
    else // step 4 : more than one node is present : 
    {
        temp = *First;

        while(temp ->next ->next != NULL)
        {
            temp = temp ->next;
        }
        free(temp ->next);
        temp ->next = NULL;
    }
}

//  Display() : 
void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("|%ld|->",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

//  Count() : 
int Count(PNODE First)
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    printf("-------------Implimentation of Singly Linear Linked List-------------\n");

    //InsertFirst : 
    InsertFirst(&Head,101);
    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);

    Display(Head);

    iRet = Count(Head);
    printf("Count is : %d \n",iRet);

    //InsertLast() :
    printf("InsertLast : \n"); 
    InsertLast(&Head,151);
    InsertLast(&Head,201);
    InsertLast(&Head,251);

    Display(Head);

    iRet = Count(Head);
    printf("Count is : %d \n",iRet);

    //DeleteFirst() : 
    printf("DeleteFirst : \n"); 
    DeleteFirst(&Head);
    
    Display(Head);

    iRet = Count(Head);
    printf("Count is : %d \n",iRet);

    //DeleteLast() :
    printf("DeleteLast : \n"); 
    DeleteLast(&Head);

    Display(Head);

    iRet = Count(Head);
    printf("Count is : %d \n",iRet);

    // InsertAtPos() : 
    printf("InsertAtPos : \n");
    InsertAtPos(&Head,71,3);

    Display(Head);

    iRet = Count(Head);
    printf("Count is : %d \n",iRet);


    return 0;
}