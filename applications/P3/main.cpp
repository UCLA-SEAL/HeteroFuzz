#include<iostream>
#include<fstream>
#include<string.h>

#include "acc_kernel.h"

using namespace std;

int main(int argc, char *argv[])
{
    int result;
    int numbers[K];
    int numbers[K];
    int i=0;
    for (i=0; i<K; i++)
    {
        fscanf(f, "%d\n", &n);
        numbers[i]=n;    
    }
    fclose(f);
    result = acc_kernel(numbers);
    printf("%d\n", result);
    return 0;
}
