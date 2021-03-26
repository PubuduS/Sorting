#ifndef SIMPLEVISUALIZER_H
#define SIMPLEVISUALIZER_H

class SimpleVisualizer
{

private:

   //! This is used to keep count of iterations
   int m_iterationCount;

   //! This is used to define the size of number array (12)
   //! used to illustrate bucket sort algorithm
   //! DO NOT CHANGE
   int m_numArrSize;

   //! This is used to define bucket size which is 10 for this illustration.
   //! DO NOT CHANGE
   const int m_bucketSize;

   //! Define an int array with 12 elements to illustrate bucket sort algorithem.
   int m_numArr[];

   //! This is used to create a chained hash map. ( sort of )
   //! There are easier eays to do this using STL container
   //! I just did this way for practise.
   struct Node
   {
     int value;
     Node* next;
   };

   //! Draws sorting process for algorithms that doesn't require additional space.
   //! Eg: BubbleSort, SelectionSort and InsertionSort.
   void DrawArray( int*, const int, const int, const  int, bool);

   //! Draw the original unsorted array for the bucket sort.
   void DrawBucketSort( const int* numArr, Node** bucket, const int divider, const int stage );

   //! Draw the bucket.
   void DrawBucket( );

   //! Swap two elements.
   void SwapElements( int*, int* );


 public:

    //! Constructor. Use for initilization
    SimpleVisualizer();

    //! DeConstructor.
    ~SimpleVisualizer();

    //! Define BubbleSort.
    void BubbleSort( int* arr , const int length );

    //! Define SelectionSort.
    void SelectionSort( int* arr, const int length );

    //! Define InsertionSort.
    void InsertionSort( int* arr, const int length );

    //! Define BucketSort.
    void BucketSort();

    //! Deallocate memory used for hash chaining.
    //! First destroy the all the nodes of each bucket.
    //! Then Deallocate the bucket itself.
    void CleanMemory( Node** bucket );

    //! Find max and min values used for calculations.
    void FindMaxAndMin( const int* numArr, int& maxVal, int& minVal );

    //! Add element to the bucket.
    void AddToBucket( Node** bucket, const int* numArr, const int divider );

    //! Add nodes to each list in each bucket.
    void AddNode( Node** bucket, const int j, const int val );

    //! Draw the list in each buckert.
    //! Need to improve this in future.
    void ShowBucket( const int* numArr, Node** bucket );

    //! Build a sorted version of array.
    void BuildSortedArray( Node** bucket, int* sortedArray );


};
// SIMPLEVISUALIZER_H
#endif
