//problem 5.4 part e

//e) Write one OpenMP program for each of the loops that you determined could 
//be parallelized. You may find the single directive useful - when a block of
//code is being executed in parallel and a sub-block should be executed by only
//one thread, the sub-block can be modified by a #pragma omp single directive.
//The threads in the executing team will block at the end of the directive until
//all of the threads have completed it.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int n = 3;




int main(){
  int x[n];
  int b[n];
  int A[n][n];
  int i;
  srand(time(NULL));
  /*for(i = 0; i < n; i++)
    b[i] = rand();
  t = 0;
  for(i = 0; i < n; i++)
    for(t = 0; t < n ; t++)
      A[i][t] = rand();
  */

  b[0] = 3;
  b[1] = 1;
  b[2] = 0;
  
  A[0][0] = 2;
  A[1][0] = 0;
  A[2][0] = 0;

  A[0][1] = -3;
  A[1][1] = 1;
  A[2][1] = 0;

  A[0][2] = 0;
  A[1][2] = 1;
  A[2][2] = -5;
  
  int col;
  int row;
  for(row = n-1; row >= 0; row--){
    x[row] = b[row];
    for(col=row+1; col < n; col++)
      x[row] -= A[row][col]*x[col];
    x[row] /= A[row][row];
  }
  
  for(i = 0; i < n; i++)
    printf("%d ", x[i]);
  printf("\n");
}





/*
int column_orient(){
  int col;
  int row;
  for(row = 0; row < n; row++)
    x[row] = b[row];
  for(col = n-1; col >= 0; col--){
    x[col] /= A[col][col];
    for(row = 0; row < col; row++)
      x[row] -= A[row][col]*x[col];

  }

  return 0;

  }*/




