#include "merge.h"
#include <stdio.h>
#include <stdlib.h>

//using namespace std;

int main(int argc, char* argv[])
{
	int c, d, swap, retval=0;
	int n;
	int fallback;
        FILE* f = fopen(argv[1], "r");
    	ap_uint<4> numbers[K];
    	int i=0;

    	for (i=0; i<K; i++)
    	{
    		fscanf(f, "%d\n", &n);
    		numbers[i]=n;
//    		printf("%d, %d\n",i, numbers[i]);
    	}

    	fclose(f);
	ap_uint<4> array[K];
	for (c = 0; c < K; c++)
	{
		array[c] = numbers[c];
	}
	printf("Begin sort!\n");
        process_top(K, array, numbers, fallback);

    	for (int cnt=0; cnt<K; cnt++)
    	{
    		printf("%d %d\n", cnt, array[cnt]);
    	}

    	return retval;
}
