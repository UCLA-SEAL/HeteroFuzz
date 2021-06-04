
#include "acc_kernel.h"

int kernel(ap_uint<24> arr[]){
    ap_uint<24> numbers[];
    int i=0;
    for (i=0; i<K; i++)
    {
      #pragma HLS unroll
        numbers[i] = (ap_uint<24>)arr[i];    
    }
  
    ap_uint<24> result;
    for (i=0; i<K; i++)
    {
        result += numbers[i];    
    }
    result = (int)result;
    return result;
}

