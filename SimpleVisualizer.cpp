#include <iostream>
#include <unistd.h>
#include <cmath>
#include "include/SimpleVisualizer.h"
#include "include/CoutColor.h"

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
SimpleVisualizer :: SimpleVisualizer() :m_iterationCount( 1 ),
m_numArrSize( 12 ),
m_bucketSize( 10 )
{

}

//! The destructor.
SimpleVisualizer :: ~SimpleVisualizer()
{

}

void SimpleVisualizer :: DrawArray( int* pNumArray, const int length, const int first, const int sorted, bool sortedFlag = false )
{
   int second = first+1;
   std::cout<< Color::FG_GREEN <<"Iteration: "<<m_iterationCount <<std::endl;
   m_iterationCount++;

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


void SimpleVisualizer :: SwapElements( int* first, int* second )
{
 //usleep(5000);
 int temp = *first;
 *first = *second;
 *second = temp;

}

// A function to implement bubble sort
void SimpleVisualizer :: BubbleSort( int* arr, const int length )
{
    int i, j;
    DrawArray( arr, length, 0, 10, false );
    for ( i = 0; i < length-1; i++ )
    {


    // Last i elements are already in place
        for ( j = 0; j < ( length-i-1 ); j++ )
        {

            if ( arr[j] > arr[j+1] )
            {
                 SwapElements( &arr[j], &arr[j+1] );
                 DrawArray( arr, length, j, ( length-i-1 ), false );
            }
        }
    }
    DrawArray( arr, length, j, ( length-i-1 ), true );
}

void SimpleVisualizer :: SelectionSort( int* arr, const int length )
{
   int index;
   int step;
   for( step = 0; step < (length - 1); step++ )
   {
       int MinIndex = step;

       for( index = (step + 1); index < length; index++ )
       {
          if( arr[index] < arr[MinIndex] )
          {
             MinIndex = index;

          }

       }

       SwapElements( &arr[MinIndex], &arr[step] );
       DrawArray( arr, length, index, ( length-step-1 ), false );

   }

   DrawArray( arr, length, index, ( length-step-1 ), true );

}

void SimpleVisualizer :: InsertionSort( int* arr,  const int length )
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

      DrawArray( arr, length, holePosition, ( length-i-1 ), false );
   }

   DrawArray( arr, length, holePosition, ( length-i-1 ), true );

}

void SimpleVisualizer :: BucketSort()
{
   const int numArr[] = { 22, 45, 12, 8, 10, 6, 72, 81, 33, 18, 50, 14 };
   int sortedArray[m_numArrSize] = { 0 };
   int maxVal = 0;
   int minVal = numArr[0];

   Node** bucket;
   bucket = new Node*[m_bucketSize];
   for( int i = 0; i < m_bucketSize; ++i )
   {
      bucket[i] = nullptr;
   }

   FindMaxAndMin( numArr, maxVal, minVal );
   const int divider = ceil( float( maxVal + 1 ) / m_bucketSize );

   DrawBucketSort( numArr, bucket, divider, 1 );

   AddToBucket( bucket, numArr, divider );
   BuildSortedArray( bucket, sortedArray );
   CleanMemory( bucket );
}

void SimpleVisualizer :: CleanMemory( Node** bucket )
{
   Node* head = nullptr;
   Node* previousNode = nullptr;
   for( int i = 0; i < m_bucketSize; ++i )
   {
      head = bucket[i];
      while( head != nullptr )
      {
         previousNode = head;
         head = head->next;
         delete previousNode;
      }
   }

   delete[] bucket;
   bucket = nullptr;
}

void SimpleVisualizer :: FindMaxAndMin( const int* numArr, int& maxVal, int& minVal )
{
   for( int i = 0; i < m_numArrSize; ++i )
   {
      if( maxVal < numArr[i] )
      {
         maxVal = numArr[i];
      }

      if( minVal > numArr[i] )
      {
         minVal = numArr[i];
      }
   }
}

void SimpleVisualizer :: AddToBucket( Node** bucket, const int* numArr, const int divider )
{
   int j = 0;
   m_iterationCount = 1;

   for( int i = 0; i < m_numArrSize; ++i )
   {
      usleep( 3000000 );
      std::cout<< Color::FG_GREEN <<"Iteration: "<<m_iterationCount <<std::endl;
      std::cout<< Color::FG_GREEN <<"j = floor( arr[ "<< i <<" ] / divider )"<<std::endl;
      std::cout<< Color::FG_GREEN <<"floor( "<< numArr[i] <<" / "<<divider<<" )" <<std::endl;
      std::cout<< Color::FG_GREEN <<"floor( "<< ( numArr[i]  / divider ) <<" )" <<std::endl;
      std::cout<< Color::FG_GREEN <<"j = "<<( numArr[i]  / divider )<<std::endl;

      m_iterationCount++;
      j = floor( numArr[i] / divider );
      AddNode( bucket, j, numArr[i] );
      ShowBucket( numArr, bucket );
   }
}

void SimpleVisualizer :: AddNode( Node** bucket, const int j, const int val )
{
   Node* newNode = new Node;
   newNode->value = val;
   newNode->next = nullptr;

   Node* previousNode = nullptr;
   Node* nodeItr = nullptr;
   Node* head = bucket[j];

   if( head == nullptr )
   {
      bucket[j] = newNode;
   }
   else
   {
      nodeItr = head;

      while( ( nodeItr != nullptr ) && ( nodeItr->value < val) )
      {
         previousNode = nodeItr;
         nodeItr = nodeItr->next;
      }

      if( previousNode == nullptr )
      {
         bucket[j] = newNode;
         newNode->next = nodeItr;
      }
      else
      {
         previousNode->next = newNode;
         newNode->next = nodeItr;
      }

   }

}

void SimpleVisualizer :: ShowBucket( const int* numArr, Node** bucket )
{
   Node* nodeItr = nullptr;
   for( int i = 0; i < m_bucketSize; ++i )
   {
      nodeItr = bucket[i];

      while ( nodeItr != nullptr )
      {
         std::cout<<Color::FG_DEFAULT<<"____";
         std::cout<<std::endl;
         std::cout<<Color::FG_DEFAULT<<"  "<<Color::FG_BLUE<< i <<Color::FG_DEFAULT<<" | --> | "<<Color::FG_GREEN<< nodeItr->value<<" |";
         std::cout<<std::endl;
         std::cout<<Color::FG_DEFAULT<<"----";
         std::cout<<std::endl;

         nodeItr = nodeItr->next;
      }
   }
}

void SimpleVisualizer :: BuildSortedArray( Node** bucket, int* sortedArray )
{
   int index = 0;
   Node* nodeItr = nullptr;

   for( int i = 0; i < m_bucketSize; ++i )
   {
      nodeItr = bucket[i];

      while( nodeItr != nullptr )
      {
         sortedArray[index] = nodeItr->value;
         nodeItr = nodeItr->next;
         ++index;
      }
   }
}

void SimpleVisualizer :: DrawBucketSort( const int* numArr, Node** bucket, const int divider, const int stage )
{
   m_iterationCount = 0;
   std::cout<< Color::FG_GREEN <<"Iteration: "<<m_iterationCount <<std::endl;
   m_iterationCount++;

   if( stage == 1 )
   {
      std::cout<< Color::FG_GREEN <<"Unsorted Array "<<std::endl;
      for( int i = 0; i < 82; i++ )
      {
         std::cout<< Color::FG_DEFAULT <<"_";
      }

      std::cout<<std::endl;

      for( int i = 0; i < m_numArrSize; ++i )
      {

         std::cout<<"  "<< Color::FG_MAGENTA <<numArr[i];
         std::cout<<Color::FG_DEFAULT<<"  |";
      }
      std::cout<<std::endl;

      for( int i = 0; i < 82; i++ )
      {
         std::cout<<"-";
      }
      std::cout<<std::endl;
    }
       DrawBucket();

}

void SimpleVisualizer :: DrawBucket()
{
      std::cout<<std::endl;
      std::cout<< Color::FG_GREEN <<" Creating a Bucket "<<std::endl;
      std::cout<<std::endl;

      for( int i = 0; i < m_bucketSize; ++i )
      {
         std::cout<<Color::FG_DEFAULT<<"____";
         std::cout<<std::endl;
         std::cout<<Color::FG_DEFAULT<<"  "<< i <<" | --> nullptr";
         std::cout<<std::endl;
         std::cout<<Color::FG_DEFAULT<<"----";
         std::cout<<std::endl;
      }
}
