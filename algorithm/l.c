#include<malloc.h>
#include<stdio.h>
int lis( int* a, int N ) {
   int *best, *prev, i, j, max = 0;
   best = (int*) malloc ( sizeof( int ) * N );
   prev = (int*) malloc ( sizeof( int ) * N );

   for ( i = 0; i < N; i++ ) best[i] = 1, prev[i] = i;

   for ( i = 1; i < N; i++ )
      for ( j = 0; j < i; j++ )
         if ( a[i] > a[j] && best[i] < best[j] + 1 )
            best[i] = best[j] + 1, prev[i] = j;  // prev[] is for backtracking the subsequence

   for ( i = 0; i < N; i++ )
      if ( max < best[i] )
         max = best[i];

   free( best );
   free( prev );

   return max;
}

// Sample usage.
int main(){
  int b[] = { 1, 3, 2, 4, 3, 5, 4, 6 };
  // the longest increasing subsequence = 13456?
  // the length would be 5, as well lcs(b,8) will return.
  printf("%d\n", lis( b, 8 ) );
}
