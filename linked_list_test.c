#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int A[ 5 ] = { 1, 4, -1, 2, 3 };

typedef struct list_item {

   int    arrayValue;
   void   *next; 

} LIST_ITEM;

int solution( int A[], int N )
{
LIST_ITEM   *listArray = (LIST_ITEM *)malloc( (sizeof( LIST_ITEM ) * (N / sizeof( int ))) );
struct list_item   *tmpEntry;
int         cnt = 1;
int         tmpValue;

    printf( "Array Count = %ld\n", (N / sizeof( int )) );

    printf( "Array Addresses\n" );
    printf( "Allocated %ld bytes\n", (sizeof( LIST_ITEM ) * (N / sizeof( int ))) );
    for( cnt = 0; cnt < N; cnt++ ) {
	printf( "0x%016LX\n", (long long unsigned int)&listArray[ cnt ] );
    }

    tmpEntry = &listArray[ 0 ];
    tmpEntry->arrayValue = A[ 0 ];

    while( tmpEntry->arrayValue > 0 ) {
        tmpValue = tmpEntry->arrayValue;
	printf( "tmpValue = %d\n", tmpValue );
	tmpEntry->next = (LIST_ITEM *)&listArray[ tmpValue ];
	printf( "tmpEntry->next = 0x%016LX\n", (long long unsigned int)tmpEntry->next );
	tmpEntry = tmpEntry->next;
        tmpEntry->arrayValue = A[ tmpValue ];
	cnt++;
    }
    tmpEntry->next = NULL;

    printf( "Final List Assembled\n" );
    tmpEntry = &listArray[ 0 ];
    while( tmpEntry->next ) {
	printf( "tmpEntry = 0x%016LX\n", (long long unsigned int)tmpEntry );
	printf( "tmpEntry->next = 0x%016LX\n", (long long unsigned int)tmpEntry->next );
	printf( "tmpEntry->arrayValue = %d\n", tmpEntry->arrayValue );
	tmpEntry = tmpEntry->next;

    }
 
    return( cnt );
}

int main()
{
    printf( "%d\n", solution( A, sizeof( A ) ) );
    return( 0 );
}

