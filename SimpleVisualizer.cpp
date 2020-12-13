#include <iostream>
#include <unistd.h>
#include "SimpleVisualizer.h"
#include "CoutColor.h"


//Constructor
SimpleVisualizer :: SimpleVisualizer() :iterationCount(1)
{

}

//De-constructor
SimpleVisualizer :: ~SimpleVisualizer()
{

}

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


