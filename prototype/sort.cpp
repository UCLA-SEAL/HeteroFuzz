#include "bubble.h"
#include "stdio.h"

void swap(ap_int<24> arr[], ap_uint<9> i, ap_uint<9> j)
{
	ap_int<24> temp;
	if(i == j)
	{
		return;
	}
	temp = arr[i]; // swap elements
	arr[i] = arr[j];
	arr[j] = temp;

}

void bubbleSort(ap_int<24> num[K])
{
	ap_uint<9> i, j, q;
	ap_int<24> num_l[K];

//	if(K==0)
//	{
//		return;
//	}

	for(q=0;q< K;q++)
	{
		num_l[q] =  num[q];
	}

  	for(i = 0; i < K -1 ; i++)
	{
    		for(j = 0; j < K -1 -i ; j++)
		{
			    //printf("%d\n",num_l[j]);
      			if(num_l[j] > num_l[j+1])
      			{
				swap(num_l, j, j+1);
			}
    		}
  	}

	for(q =0; q< K; q++)
	{
        	num[q] =  num_l[q];
	}
	return; //arrays are passed to functions by address; nothing is returned
}
