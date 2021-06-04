#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    //srand((unsigned)time(NULL)); 
    srand(time(0) + rand());
    printf("haha!\n\n\n");
    int retval=(rand() % (10-1))+ 1;
    int n;
    FILE* f = fopen(argv[1], "r");
    FILE* fw = fopen("0.dat", "w");
    int i=0;
    int K = 400;

    for (i=0; i < K; i++)
    {
    	fscanf(f, "%d\n", &n);
//        fprintf(fw, "%d\n", n);
    }
    fclose(f);
    fclose(fw);

    printf("invoke the kernel");
    system("vivado_hls -f run_hls_csim.tcl");
    
//    int median = num[K/2];
    

//    FILE* fr = fopen("1.dat", "r");
//    for (i=0; i<400; i++)
//    {
//    	fscanf(fr, "%d\n", &n);
//        printf("%d\n", n);
//    }
//    fclose(f);
    
    return 0;

}
