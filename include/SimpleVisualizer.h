#ifndef SIMPLEVISUALIZER_H
#define SIMPLEVISUALIZER_H

class SimpleVisualizer
{

public:
   SimpleVisualizer();
   ~SimpleVisualizer();
   void bubbleSort( int*, int );
   void selectionSort( int*, int );
   void insertionSort( int*, int );

private:
   void drawArray( int*, const int, const int, const  int, bool);
   void swapElements( int*, int* );
   int iterationCount;



};
// SIMPLEVISUALIZER_H
#endif 
