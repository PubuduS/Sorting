#include <iostream>
#include <unistd.h>
#include "SimpleVisualizer.h"
#include "CoutColor.h"

/*******************************************************************************
 * A brief history of JavaDoc-style (C-style) banner comments.
 *
 * This is the typical JavaDoc-style C-style "banner" comment. It starts with
 * a forward slash followed by some number, n, of asterisks, where n > 2. It's
 * written this way to be more "visible" to developers who are reading the
 * source code.
 *
 * Often, developers are unaware that this is not (by default) a valid Doxygen
 * comment block!
 *
 * However, as long as JAVADOC_BLOCK = YES is added to the Doxyfile, it will
 * work as expected.
 *
 * This style of commenting behaves well with clang-format.
 *
 * @param theory Even if there is only one possible unified theory. it is just a
 *               set of rules and equations.
 ******************************************************************************/
 
//! The constructor.
SimpleVisualizer :: SimpleVisualizer() :iterationCount(1)
{

}

//! The destructor.
SimpleVisualizer :: ~SimpleVisualizer()
{

}

//! A normal member taking two arguments and returning an integer value.
/*!
\param a an integer argument.
\param s a constant character pointer.
\return The test results
\sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
*/
void SimpleVisualizer :: drawArray( int* pNumArray, const int length, const int first, const int sorted, bool sortedFlag = false )
{
   int second = first+1;
   std::cout<< Color::FG_GREEN <<"Iteration: "<<iterationCount <<std::endl;
   iterationCount++;

   for( int i = 0; i < 60; i++ )
   {
      std::cout<< Color::FG_DEFAULT <<"_";
   }

   std::cout<<std::endl;
   for( int i = 0; i < length; i++ )
   {      
      usleep( 500000 );
      if(sortedFlag)
      {
         std::cout<<"  "<< Color::FG_GREEN <<pNumArray[i];
      }
      else if(i == first)
      {
         std::cout<<"  "<< Color::FG_MAGENTA <<pNumArray[i];
      }
      else if( i == second )
      {
         std::cout<<"  "<< Color::FG_CYAN <<pNumArray[i];
      }
      else if( i > sorted)
      {
         std::cout<<"  "<< Color::FG_GREEN <<pNumArray[i];
      }
      else
      {
         std::cout<<"  "<< Color::FG_DEFAULT <<pNumArray[i];

      }
      std::cout<<Color::FG_DEFAULT<<"  |";

   }

   std::cout<<std::endl;
   for( int i = 0; i < 60; i++ )
   {
      std::cout<<"-";
   }

   //index drawing
   std::cout<<std::endl;
   for( int i = 0; i < length; i++ )
   {
      if( i == 0 )
         std::cout<<"  "<< Color::FG_CYAN <<i;
      else
         std::cout<<"     "<< Color::FG_CYAN <<i;
   }

std::cout<<std::endl;

}


void SimpleVisualizer :: swapElements( int* first, int* second )
{
 //usleep(5000);
 int temp = *first;
 *first = *second;
 *second = temp;

}

// A function to implement bubble sort
void SimpleVisualizer :: bubbleSort(int* arr, int n)
{
    int i, j;
    drawArray( arr, n, 0, 10, false );
    for ( i = 0; i < n-1; i++ )
    {


    // Last i elements are already in place
        for ( j = 0; j < n-i-1; j++ )
        {

            if ( arr[j] > arr[j+1] )
            {
                swapElements(&arr[j], &arr[j+1]);
                 drawArray( arr, n, j, (n-i-1), false );
            }
        }
    }
    drawArray( arr, n, j, (n-i-1), true );
}

void SimpleVisualizer :: selectionSort( int* arr, int length )
{
   int index;
   int step;
   for( step = 0; step < (length - 1); step++ )
   {
       int MinIndex = step;
       int MaxIndex = step;

       for( index = (step + 1); index < length; index++ )
       {
          if( arr[index] < arr[MinIndex] )
          {
             MinIndex = index;
             
          }

       }
       
       swapElements( &arr[MinIndex], &arr[step] );
       drawArray( arr, length, index, (length-step-1), false );

   }
   
   drawArray( arr, length, index, (length-step-1), true );

}

void SimpleVisualizer :: insertionSort( int* arr, int length )
{
   int holePosition = 0;
   int i;

   for( i = 0; i < length; i++)
   {
      // Store the value that we need to be inserted.
      auto valueToInsert = arr[i];
      holePosition = i;

      // Mark first element as sorted. Locate hole position to the element to be inserted.
      while( (holePosition > 0) && (arr[holePosition-1] > valueToInsert) )
      {
         arr[holePosition] = arr[holePosition-1];
         holePosition--;
      }         
         
      // Put the value in correct position.
      arr[holePosition] = valueToInsert;
         
      drawArray( arr, length, holePosition, (length-i-1), false );
   }
   
   drawArray( arr, length, holePosition, (length-i-1), true );

}


