#include "Sorting.h"

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
*** INPUT ARGS  : class T1, class T2                              ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/

template <class T1, class T2>
void Sorting :: SwapElements(T1 first, T2 second)
{
    auto temp = *first;
    *first = *second;
    *second = temp;

    return;
}

// This is done to avoid linking error. Please refer here for more details.
// https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
template void Sorting :: SwapElements<int*, int*>(int*, int*);
template void Sorting :: SwapElements<float*, float*>(float*, float*);
template void Sorting :: SwapElements<double*, double*>(double*, double*);

/********************************************************************
*** FUNCTION <BubbleSort()>                                       ***
*********************************************************************
*** DESCRIPTION : Use bubble sort algorithm to arrange numbers    ***
***               in ascending order.                             ***
*** INPUT ARGS  : T, const int, const bool = true                 ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/

template <class T>
void Sorting :: BubbleSort(T pNumArray, const int length, const bool ascending)
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
                if( pNumArray[index] > pNumArray[index+1] )
                {
                    SwapElements( &pNumArray[index], &pNumArray[index+1] );
                }
            }
            else
            {
                if( pNumArray[index] < pNumArray[index+1] )
                {
                    SwapElements( &pNumArray[index], &pNumArray[index+1] );
                }
            }

        }
    }

    return;
}

// This is done to avoid linking error. Please refer here for more details.
// https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
template void Sorting :: BubbleSort<int*>(int*, const int, const bool);
template void Sorting :: BubbleSort<float*>(float*, const int, const bool);
template void Sorting :: BubbleSort<double*>(double*, const int, const bool);

/********************************************************************
*** FUNCTION <SelectionSort()>                                    ***
*********************************************************************
*** DESCRIPTION : Use Selection sort algorithm to arrange numbers ***
***               in ascending order.                             ***
*** INPUT ARGS  : T, const int, const bool = true                 ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/

template <class T>
void Sorting :: SelectionSort(T pNumArray, const int length, const bool ascending)
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
                if( pNumArray[index] < pNumArray[MinIndex] )
                {
                    MinIndex = index;
                }
            }
            else
            {
                if( pNumArray[index] > pNumArray[MaxIndex] )
                {
                    MaxIndex = index;
                }
            }
        }

        if(ascending)
        {
            SwapElements( &pNumArray[MinIndex], &pNumArray[step] );
        }
        else
        {
            SwapElements( &pNumArray[MaxIndex], &pNumArray[step] );
        }

    }

    return;
}

// This is done to avoid linking error. Please refer here for more details.
// https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
template void Sorting :: SelectionSort<int*>(int*, const int, const bool);
template void Sorting :: SelectionSort<float*>(float*, const int, const bool);
template void Sorting :: SelectionSort<double*>(double*, const int, const bool);
