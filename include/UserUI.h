#ifndef USERUI_H
#define USERUI_H

class UserUI
{

 public:

 enum Mode
 {
   VISUALIZE = 1,
   SORT = 2,
   GRAPH = 3
 };

 enum SortingMethod
 {
   BUBBLESORT = 1,
   SELECTIONSORT = 2,
   INSERTIONSORT = 3,
   BUCKETSORT = 4
 };

 UserUI();
 ~UserUI();
 void DispalyUI();
 void DispalyAlgorithm( const Mode mode );


 private:
 void ChoosenMode( const Mode mode, const SortingMethod method );

 template <class T>
 void PrintArray( T pNumArray, const int length );

 void ChooseAlgorithm( const Mode mode, const SortingMethod method );

 template <class T>
 void PopulateArray( T pNumArray, const int length );

 void ChoosenAlgorithm( int* pNumArray, const Mode mode, const SortingMethod method, const int length, const bool ascending = true );
 void ChoosenAlgorithm( float* pNumArray, const SortingMethod method, const int length, const bool ascending = true );
 void ChoosenAlgorithm( double* pNumArray, const SortingMethod method, const int length, const bool ascending = true );


};
// USERUI_H
#endif
