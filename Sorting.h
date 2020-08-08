#ifndef SORTING_H
#define SORTING_H

class Sorting
{

public:
/********************************************************************
*** FUNCTION <Sorting()> Default Constructor                      ***
*********************************************************************
*** DESCRIPTION : Initiate the program           .                ***
*** INPUT ARGS  : void                                            ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/

    Sorting();

/********************************************************************
*** FUNCTION <Sorting()> Default Destructor                       ***
*********************************************************************
*** DESCRIPTION : Destructor                     .                ***
*** INPUT ARGS  : void                                            ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/

    ~Sorting();

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
    void BubbleSort(T pNumArray, const int length, const bool ascending = true);

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
    void SelectionSort(T pNumArray, const int length, const bool ascending = true);

private:

/********************************************************************
*** FUNCTION <SwapElements()> const                               ***
*********************************************************************
*** DESCRIPTION : Swap the n and n+1 elements.   .                ***
*** INPUT ARGS  : T1 , T2                                         ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/

    template <class T1, class T2>
    void SwapElements(T1  , T2 )const;


};
#endif
