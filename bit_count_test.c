#include <stdio.h>
#include <stdlib.h>

int solution( int A, int B )
{
int tmp;
int i;
int bitCnt = 0;

    tmp = (A * B);

    for( i = 0; i < (sizeof( int ) * 8); i++ ) {
        if( tmp & 0x00000001 ) {
            bitCnt++;
        }

        tmp = (tmp >> 1);
    }

    return( bitCnt );
}



int solutionA( int A, int B )
{
unsigned int n;

    n = (unsigned int)(A * B);
    n = ((0xaaaaaaaa & n) >> 1) + (0x55555555 & n);
    n = ((0xcccccccc & n) >> 2) + (0x33333333 & n);
    n = ((0xf0f0f0f0 & n) >> 4) + (0x0f0f0f0f & n);
    n = ((0xff00ff00 & n) >> 8) + (0x00ff00ff & n);
    n = ((0xffff0000 & n) >> 16) + (0x0000ffff & n);

    return( n );
}

int solutionB( int A, int B )
{
unsigned int n;

    n = (unsigned int)(A * B);

    unsigned int count = 0;
    while( n ) {
        count += (n & 1);
        n >>= 1;
    }
    return( count );
}

int solutionB64( int A, int B )
{
unsigned long int n;

    n = (unsigned long int)((unsigned long int)A * (unsigned long int)B);

    unsigned int count = 0;
    while( n ) {
        count += (n & 1);
        n >>= 1;
    }
    return( count );
}

int solutionC( int A, int B )
{
unsigned int n;

    n = (unsigned int)(A * B);

    return( __builtin_popcount( n ) );
}

int solutionC64( int A, int B )
{
unsigned long int n;

    n = (unsigned long int)((unsigned long int)A * (unsigned long int)B);

    /* Note that testing shows this only works on 32 bits.
     */
    return( __builtin_popcount( n ) );
}

int solutionD( int A, int B )
{
unsigned int i;

    i = (unsigned int)(A * B);

    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main()
{
    
    /*  These results all due to 32 bit integer, which is why
     *  the test failed.
     * 
     *  Test Description (which I failed to note LONG INTEGER):
     * 
     *     2. BitcountInProduct
     *     Count 1s in binary representation of long integer.
     *
     *   For example, for the input (131071, 131073) the solution
     *   returned a wrong answer (got 32 expected 34).
     */
    printf( "solution() %d\n", solution( 131071, 131073 ) );
    printf( "solutionA() %d\n", solutionA( 131071, 131073 ) );
    printf( "solutionB() %d\n", solutionB( 131071, 131073 ) );
    printf( "solutionC() %d\n", solutionC( 131071, 131073 ) );
    printf( "solutionD() %d\n", solutionD( 131071, 131073 ) );

    printf( "solutionB64() %d\n", solutionB64( 131071, 131073 ) );
    printf( "solutionC63() %d\n", solutionC64( 131071, 131073 ) );

    return( 0 );
}

