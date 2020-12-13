#include "UserUI.h"

#include <iostream>
#include "Sorting.h"
#include "SimpleVisualizer.h"

UserUI :: UserUI()
{
  // Constructor
  // Nothing to do here for now. 
}

UserUI :: ~UserUI()
{
  // DeConstructor
  // Nothing to do here for now. 
}

void UserUI :: DispalyUI()
{

   int option = 0;
 
   do
   {
      std::cout<<"Please Select an Option"<<std::endl;
      std::cout<<"Press 1 to Visualize algorithem."<<std::endl;
      std::cout<<"Press 2 to Sort."<<std::endl;
      std::cout<<"Press 3 to Draw Graph. ( To be implemented )"<<std::endl;
      std::cin >> option;

   }while( option <= 0 || option > 3 );

   DispalyAlgorithm( static_cast<Mode>(option) );
   

}

void UserUI :: DispalyAlgorithm( const Mode mode )
{
   int method = 0;

   do
   {
      std::cout<<"Please Select an Algorithm to sort"<<std::endl;
      std::cout<<"Press 1 for BubbleSort"<<std::endl;
      std::cout<<"Press 2 for SelectionSort"<<std::endl;
      std::cout<<"Press 3 for InsertionSort"<<std::endl;
      std::cin >> method;

   }while( method <= 0 || method > 3 );

   ChooseAlgorithm( mode, static_cast<SortingMethod>(method) );

}

void UserUI :: ChooseAlgorithm( const Mode mode, const SortingMethod method )
{
   int arrayType = 0;
   int arraySize = 0;
   int orderBy = 1;
   bool ascending = true;

   if( mode == VISUALIZE )
   {
     
      // Create a simple unsorted Array.
      int numArray[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
      const int length = ( sizeof( numArray ) / sizeof( numArray[0] ) );

      ChoosenAlgorithm( numArray, mode, method, length, true );

   }
   else if( mode == SORT )
   {
      do
      {
         std::cout<<"Please select type of the array."<<std::endl;
         std::cout<<"Press 1 for Integer Array"<<std::endl;
         std::cout<<"Press 2 for Float Array"<<std::endl;
         std::cout<<"Press 3 for Double Array"<<std::endl;
         std::cin>>arrayType;

      }while( arrayType <= 0 || arrayType > 3 );

      std::cout<<"Press 1 for Ascending?"<<std::endl;
      std::cout<<"Press 2 for Descending?"<<std::endl;
      std::cin>>orderBy;

      if(orderBy == 1)
      {
         ascending = true;
      }
      else
      {
         ascending = false;
      }

      std::cout<<"Please select size of the array."<<std::endl;
      std::cin>>arraySize;

      if( arrayType == 1 && arraySize > 0 )
      {
         int numArray[arraySize];
         PopulateArray<int*>( numArray, arraySize );
         ChoosenAlgorithm( numArray, mode, method, arraySize, ascending );        
      }
      else if( arrayType == 2 && arraySize > 0 )
      {
         float numArray[arraySize];
         PopulateArray<float*>( numArray, arraySize );
         ChoosenAlgorithm( numArray, method, arraySize, ascending );      
      }
      else if( arrayType == 3 && arraySize > 0 )
      {
         double numArray[arraySize];
         PopulateArray<double*>( numArray, arraySize ); 
         ChoosenAlgorithm( numArray, method, arraySize, ascending );             
      }
 

   }


}

template <class T>
void UserUI :: PopulateArray( T pNumArray, const int length )
{

   for( int index = 0; index < length; index++ )
   {
      std::cout<<"Please enter index: "<< (index+1) <<std::endl;
      std::cin>>pNumArray[index];
   }

}

void UserUI :: ChoosenAlgorithm( int* pNumArray, const Mode mode, const SortingMethod method, const int length, const bool ascending )
{

   SimpleVisualizer mySimpleVisualizer;
   Sorting MySort;

   if( mode == VISUALIZE )
   {

      if( method == BUBBLESORT )
      {
         mySimpleVisualizer.bubbleSort( pNumArray, length );
      }
      else if( method == SELECTIONSORT )
      {         
         mySimpleVisualizer.selectionSort( pNumArray, length );
      }
      else if( method == INSERTIONSORT )
      {         
         mySimpleVisualizer.insertionSort( pNumArray, length );
      }

   } 
   else if( mode == SORT )
   {

      if( method == BUBBLESORT )
      {
        
         std::cout<<"Before Swapping"<<std::endl;
         PrintArray<int*>( pNumArray, length );

         MySort.BubbleSort<int*>( pNumArray, length, ascending );

         std::cout<<"After Swapping"<<std::endl;
         PrintArray<int*>( pNumArray, length );

      }
      else if( method == SELECTIONSORT )
      {
         std::cout<<"Before Swapping"<<std::endl;
         PrintArray<int*>( pNumArray, length );

         MySort.SelectionSort<int*>( pNumArray, length, ascending );

         std::cout<<"After Swapping"<<std::endl;
         PrintArray<int*>( pNumArray, length );
      }
      else if( method == INSERTIONSORT )
      {
         std::cout<<"Before Swapping"<<std::endl;
         PrintArray<int*>( pNumArray, length );

         MySort.InsertionSort<int*>( pNumArray, length, ascending );

         std::cout<<"After Swapping"<<std::endl;
         PrintArray<int*>( pNumArray, length );         
      }

   }

}

void UserUI :: ChoosenAlgorithm( float* pNumArray, const SortingMethod method, const int length, const bool ascending )
{   
   Sorting MySort;

      if( method == BUBBLESORT )
      {
        
         std::cout<<"Before Swapping"<<std::endl;
         PrintArray<float*>( pNumArray, length );

         MySort.BubbleSort<float*>( pNumArray, length, ascending );

         std::cout<<"After Swapping"<<std::endl;
         PrintArray<float*>( pNumArray, length );

      }
      else if( method == SELECTIONSORT )
      {
         std::cout<<"Before Swapping"<<std::endl;
         PrintArray<float*>( pNumArray, length );

         MySort.SelectionSort<float*>( pNumArray, length, ascending );

         std::cout<<"After Swapping"<<std::endl;
         PrintArray<float*>( pNumArray, length );
      }
      else if( method == INSERTIONSORT )
      {
         std::cout<<"Before Swapping"<<std::endl;
         PrintArray<float*>( pNumArray, length );

         MySort.InsertionSort<float*>( pNumArray, length, ascending );

         std::cout<<"After Swapping"<<std::endl;
         PrintArray<float*>( pNumArray, length );         
      }

}

void UserUI :: ChoosenAlgorithm( double* pNumArray, const SortingMethod method, const int length, const bool ascending )
{   
   Sorting MySort;

      if( method == BUBBLESORT )
      {
        
         std::cout<<"Before Swapping"<<std::endl;
         PrintArray<double*>( pNumArray, length );

         MySort.BubbleSort<double*>( pNumArray, length, ascending );

         std::cout<<"After Swapping"<<std::endl;
         PrintArray<double*>( pNumArray, length );

      }
      else if( method == SELECTIONSORT )
      {
         std::cout<<"Before Swapping"<<std::endl;
         PrintArray<double*>( pNumArray, length );

         MySort.SelectionSort<double*>( pNumArray, length, ascending );

         std::cout<<"After Swapping"<<std::endl;
         PrintArray<double*>( pNumArray, length );
      }
      else if( method == INSERTIONSORT )
      {
         std::cout<<"Before Swapping"<<std::endl;
         PrintArray<double*>( pNumArray, length );

         MySort.InsertionSort<double*>( pNumArray, length, ascending );

         std::cout<<"After Swapping"<<std::endl;
         PrintArray<double*>( pNumArray, length );         
      }

}

template <class T>
void UserUI :: PrintArray( T pNumArray, const int length )
{
   for( int index = 0; index < length; index++ )
   {
      std::cout<<"Array index "<<index<<" is "<<pNumArray[index]<<std::endl;
   }
  
}




