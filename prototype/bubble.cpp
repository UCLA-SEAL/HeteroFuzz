#include "bubble.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int c, d, swap, retval=0;
    int n;
    FILE* f = fopen(argv[1], "r");

    ap_int<24> numbers[K];
    int i=0;

    for (i=0; i<K; i++)
    {
    	fscanf(f, "%d\n", &n);
    	numbers[i]=n;
    }
    fclose(f);

    ap_int<24> array[K];
    for (c = 0; c < K; c++)
    {
	array[c] = numbers[c];
    }
    printf("Begin sort!\n");

    bubbleSort(array);

//    FILE* fw = fopen("1.dat", "w");
//    for (int cnt=0; cnt<K; cnt++)
//    {
//    	fprintf(fw, "%d\n", array[cnt].to_int());
//    }
//    fclose(fw);

    return retval;

}
