#include "sorting.h"

/********************************************************************
*** FUNCTION <Sorting()> Default Constructor                      ***
*********************************************************************
*** DESCRIPTION : Initiate the program           .                ***
*** INPUT ARGS  : void                                            ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
Sorting :: Sorting()
{
    //To be implemented
    //std::cout<<"Hello From Constructor!"<<std::endl;
}

/********************************************************************
*** FUNCTION <Sorting()> Default Destructor                       ***
*********************************************************************
*** DESCRIPTION : Destructor                     .                ***
*** INPUT ARGS  : void                                            ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
Sorting :: ~Sorting()
{
    //To be implemented
    //std::cout<<"Hello From Deconstructor!"<<std::endl;
}

/********************************************************************
*** FUNCTION <SwapElements()> const                               ***
*********************************************************************
*** DESCRIPTION : Swap the n and n+1 elements.   .                ***
*** INPUT ARGS  : int* first, int* second                         ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: SwapElements(int* first, int* second) const
{
    int temp = *first;
    *first = *second;
    *second = temp;

    return;
}

/********************************************************************
*** FUNCTION <BubbleSortAsc()>                                    ***
*********************************************************************
*** DESCRIPTION : Use bubble sort algorithm to arrange numbers    ***
***               in ascending order.                             ***
*** INPUT ARGS  : int* pArray, const int length                   ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: BubbleSortAsc(int* pArray, const int length)
{
    for(int step = 0; step < (length -1); step++)
    {

        for(int index = 0; index < (length -step -1); index++)
        {
            if(pArray[index] > pArray[index+1])
            {
                SwapElements(&pArray[index], &pArray[index+1]);
            }
        }

    }

    return;
}

/********************************************************************
*** FUNCTION <BubbleSortDsc()>                                    ***
*********************************************************************
*** DESCRIPTION : Use bubble sort algorithm to arrange numbers    ***
***               in descending order.                            ***
*** INPUT ARGS  : int* pArray, const int length                   ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: BubbleSortDsc(int* pArray, const int length)
{
    for(int step = 0; step < (length -1); step++)
    {

        for(int index = 0; index < (length -step -1); index++)
        {
            if(pArray[index] < pArray[index+1])
            {
                SwapElements(&pArray[index], &pArray[index+1]);
            }
        }

    }

    return;
}
