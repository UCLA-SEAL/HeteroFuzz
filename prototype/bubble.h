
#ifndef _BUBBLE_FUNC_H_
#define _BUBBLE_FUNC_H_

#define K 400
#include "ap_int.h"
void bubbleSort(ap_int<24> num[K]);
void swap(ap_int<24> arr[], ap_uint<9> i, ap_uint<9> j);
//void guard(int value,int size);
#endif
