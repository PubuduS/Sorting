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
*** FUNCTION <BubbleSortAsc()>                                    ***
*********************************************************************
*** DESCRIPTION : Use bubble sort algorithm to arrange numbers    ***
***               in ascending order.                             ***
*** INPUT ARGS  : int*, const int                                 ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
    void BubbleSortAsc(int*, const int);

/********************************************************************
*** FUNCTION <BubbleSortDsc()>                                    ***
*********************************************************************
*** DESCRIPTION : Use bubble sort algorithm to arrange numbers    ***
***               in descending order.                            ***
*** INPUT ARGS  : int*, const int                                 ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
    void BubbleSortDsc(int*, const int);

private:

/********************************************************************
*** FUNCTION <SwapElements()> const                               ***
*********************************************************************
*** DESCRIPTION : Swap the n and n+1 elements.   .                ***
*** INPUT ARGS  : int*, int*                                      ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
    void SwapElements(int* , int*)const;







};
#endif
