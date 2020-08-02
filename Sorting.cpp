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
*** FUNCTION <SwapElements()> const (Overloaded)                  ***
*********************************************************************
*** DESCRIPTION : Swap the n and n+1 elements.   .                ***
*** INPUT ARGS  : float* first, float* second                     ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: SwapElements(float* first, float* second) const
{
    float temp = *first;
    *first = *second;
    *second = temp;

    return;
}

/********************************************************************
*** FUNCTION <SwapElements()> const (Overloaded)                  ***
*********************************************************************
*** DESCRIPTION : Swap the n and n+1 elements.   .                ***
*** INPUT ARGS  : double* first, double* second                   ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: SwapElements(double* first, double* second) const
{
    double temp = *first;
    *first = *second;
    *second = temp;

    return;
}

/********************************************************************
*** FUNCTION <BubbleSort()>                                       ***
*********************************************************************
*** DESCRIPTION : Use bubble sort algorithm to arrange numbers    ***
***               in ascending order.                             ***
*** INPUT ARGS  : int* pArray, const int length, const bool       ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: BubbleSort(int* pArray, const int length, const bool ascending = true)
{
    //Best Case Time Complexity O(n)
    //Average Case Time Complexity O(n^2)
    //Word Case Time Complexity O(n^2)
    //Space Complexity O(1)

    /***
        Bubble sort is used in the following cases where
            (1) the complexity of the code does not matter.
            (2) a short code is preferred.
    ***/

    //This Loop is used to stepping through the Array
    for(int step = 0; step < (length -1); step++)
    {
        //After each iteration rightmost digit has the largest or smallest number
        //if ascending or descending order. Therefore we don't have to check right
        //most number
        for(int index = 0; index < (length -step -1); index++)
        {
            if(ascending)
            {
                if( pArray[index] > pArray[index+1] )
                {
                    SwapElements( &pArray[index], &pArray[index+1] );
                }
            }
            else
            {
                if( pArray[index] < pArray[index+1] )
                {
                    SwapElements( &pArray[index], &pArray[index+1] );
                }
            }

        }
    }

    return;
}

/********************************************************************
*** FUNCTION <BubbleSort()> (Overloaded)                          ***
*********************************************************************
*** DESCRIPTION : Use bubble sort algorithm to arrange numbers    ***
***               in ascending order.                             ***
*** INPUT ARGS  : float* pArray, const int length, const bool     ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: BubbleSort(float* pArray, const int length, const bool ascending = true)
{
    for(int step = 0; step < (length -1); step++)
    {
        for(int index = 0; index < (length -step -1); index++)
        {
            if(ascending)
            {
                if( pArray[index] > pArray[index+1] )
                {
                    SwapElements( &pArray[index], &pArray[index+1] );
                }
            }
            else
            {
                if( pArray[index] < pArray[index+1] )
                {
                    SwapElements( &pArray[index], &pArray[index+1] );
                }
            }

        }
    }

    return;
}

/********************************************************************
*** FUNCTION <BubbleSort()> (Overloaded)                          ***
*********************************************************************
*** DESCRIPTION : Use bubble sort algorithm to arrange numbers    ***
***               in ascending order.                             ***
*** INPUT ARGS  : double* pArray, const int length, const bool    ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: BubbleSort(double* pArray, const int length, const bool ascending = true)
{
    for(int step = 0; step < (length -1); step++)
    {
        for(int index = 0; index < (length -step -1); index++)
        {
            if(ascending)
            {
                if( pArray[index] > pArray[index+1] )
                {
                    SwapElements( &pArray[index], &pArray[index+1] );
                }
            }
            else
            {
                if( pArray[index] < pArray[index+1] )
                {
                    SwapElements( &pArray[index], &pArray[index+1] );
                }
            }

        }
    }

    return;
}

/********************************************************************
*** FUNCTION <SelectionSort()>                                    ***
*********************************************************************
*** DESCRIPTION : Use Selection sort algorithm to arrange numbers ***
***               in ascending order.                             ***
*** INPUT ARGS  : int*, const int, const bool                     ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: SelectionSort(int* NumArray, const int length, const bool ascending = true)
{
    //Worst Case Time Complexity: O(n^2)
    //Best Case Time Complexity: O(n^2)
    //Average Case Time Complexity: O(n^2)
    //Space Complexity: O(1)

    /***
    The selection sort is used when:
        (1) a small list is to be sorted
        (2) cost of swapping does not matter
        (3) checking of all the elements is compulsory
        (4) cost of writing to a memory matters like in flash memory (number of writes/swaps is O(n) as compared to O(n2) of bubble sort)

    ***/

    for(int step = 0; step < (length - 1); step++)
    {
        int MinIndex = step;
        int MaxIndex = step;

        for(int index = (step + 1); index < length; index++)
        {
            if(ascending)
            {
                if( NumArray[index] < NumArray[MinIndex] )
                {
                    MinIndex = index;
                }
            }
            else
            {
                if( NumArray[index] > NumArray[MaxIndex] )
                {
                    MaxIndex = index;
                }
            }
        }

        if(ascending)
        {
            SwapElements( &NumArray[MinIndex], &NumArray[step] );
        }
        else
        {
            SwapElements( &NumArray[MaxIndex], &NumArray[step] );
        }

    }

}

/********************************************************************
*** FUNCTION <SelectionSort()> (Overloaded)                       ***
*********************************************************************
*** DESCRIPTION : Use Selection sort algorithm to arrange numbers ***
***               in ascending order.                             ***
*** INPUT ARGS  : float*, const int, const bool                   ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: SelectionSort(float* NumArray, const int length, const bool ascending = true)
{
    for(int step = 0; step < (length - 1); step++)
    {
        int MinIndex = step;
        int MaxIndex = step;

        for(int index = (step + 1); index < length; index++)
        {
            if(ascending)
            {
                if(NumArray[index] < NumArray[MinIndex])
                {
                    MinIndex = index;
                }
            }
            else
            {
                if(NumArray[index] > NumArray[MaxIndex])
                {
                    MaxIndex = index;
                }
            }
        }

        if(ascending)
        {
            SwapElements(&NumArray[MinIndex], &NumArray[step]);
        }
        else
        {
            SwapElements(&NumArray[MaxIndex], &NumArray[step]);
        }

    }

}

/********************************************************************
*** FUNCTION <SelectionSort()> (Overloaded)                       ***
*********************************************************************
*** DESCRIPTION : Use Selection sort algorithm to arrange numbers ***
***               in ascending order.                             ***
*** INPUT ARGS  : double*, const int, const bool                  ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
void Sorting :: SelectionSort(double* NumArray, const int length, const bool ascending = true)
{
    for(int step = 0; step < (length - 1); step++)
    {
        int MinIndex = step;
        int MaxIndex = step;

        for(int index = (step + 1); index < length; index++)
        {
            if(ascending)
            {
                if(NumArray[index] < NumArray[MinIndex])
                {
                    MinIndex = index;
                }
            }
            else
            {
                if(NumArray[index] > NumArray[MaxIndex])
                {
                    MaxIndex = index;
                }
            }
        }

        if(ascending)
        {
            SwapElements(&NumArray[MinIndex], &NumArray[step]);
        }
        else
        {
            SwapElements(&NumArray[MaxIndex], &NumArray[step]);
        }

    }

}
