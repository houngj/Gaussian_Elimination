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
#include <omp.h>

int n = 3;

int column_orient(int A[n][n], int b[n], int x[n], int thread_count){
  int col;
  int row;
  int d = 0;
  while(d < 10){
    for(row = 0; row < n; row++)
      x[row] = b[row];

    for(col = n-1; col >= 0; col--){
      x[col] /= A[col][col];
#pragma omp parallel for num_threads(thread_count)
      for(row = 0; row < col; row++)
	x[row] -= A[row][col]*x[col];
      
    }
    
    
    int z;
    for(z = 0; z < n; z++)
      printf("%d ", x[z]);
    printf("\n");
    d++;
    
  }
  return 0;
}

int row_orient(int A[n][n], int b[n], int x[n], int thread_count){
  
  int col;
  int row;
  int d = 0;
  while(d < 10){
    
    for(row = n-1; row >= 0; row--){
      x[row] = b[row];
      
      #pragma omp parallel for num_threads(thread_count)
      for(col=row+1; col < n; col++){
	x[row] -= A[row][col]*x[col];

      }
      x[row] /= A[row][row];
    }
    int z;
    for(z = 0; z < n; z++)
      printf("%d ", x[z]);
    printf("\n");
    d++;
  }   
      return 0;
}



int main(int argc, char *argv[]){
  int x[n];
  int b[n];
  int A[n][n];
  int i;
  int t;
  srand(time(NULL));
  int r;
  for(i = 0; i < n; i++){
      r = rand() ; 
      b[i] = r;
  }
  for(i = 0; i < n; i++){
    for(t = 0; t < n ; t++){
      r = rand();
      A[i][t] = r;
    }
  }
  

  
  
  
  int thread_count = strtol(argv[1], NULL, 10);
  if(row_orient(A, b, x, thread_count) == 0)
    printf("ROW ORIENT IS DONE\n");

  if(column_orient(A, b, x, thread_count) == 0)
    printf("COLUMN ORIENT IS DONE\n");

  return 0;
}











