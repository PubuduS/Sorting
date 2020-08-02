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
*** INPUT ARGS  : int*, const int, const bool                     ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
    void BubbleSort(int*, const int, const bool);

/********************************************************************
*** FUNCTION <BubbleSort()> (Overloaded)                          ***
*********************************************************************
*** DESCRIPTION : Use bubble sort algorithm to arrange numbers    ***
***               in ascending order.                             ***
*** INPUT ARGS  : float*, const int, const bool                   ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
    void BubbleSort(float*, const int, const bool);

/********************************************************************
*** FUNCTION <BubbleSortAsc()> (Overloaded)                       ***
*********************************************************************
*** DESCRIPTION : Use bubble sort algorithm to arrange numbers    ***
***               in ascending order.                             ***
*** INPUT ARGS  : double*, const int, const bool                  ***
*** OUTPUT ARGS : void                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
    void BubbleSort(double*, const int, const bool);

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
    void SelectionSort(int*, const int, const bool);

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
    void SelectionSort(float*, const int, const bool);

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
    void SelectionSort(double*, const int, const bool);

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

/********************************************************************
*** FUNCTION <SwapElements()> const (Overloaded)                  ***
*********************************************************************
*** DESCRIPTION : Swap the n and n+1 elements.   .                ***
*** INPUT ARGS  : float*, float*                                  ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
    void SwapElements(float* , float*)const;

/********************************************************************
*** FUNCTION <SwapElements()> const (Overloaded)                  ***
*********************************************************************
*** DESCRIPTION : Swap the n and n+1 elements.   .                ***
*** INPUT ARGS  : double*, double*                                ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN      : NONE                                            ***
********************************************************************/
    void SwapElements(double* , double*)const;







};
#endif
