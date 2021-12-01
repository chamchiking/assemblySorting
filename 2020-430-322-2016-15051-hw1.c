// This code is for 430.322 Project #1
// Student ID        : 2016-15051
// Student name      : mincheol cha
// Student email     : chamj61047@snu.ac.kr
// Compilation option:

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define nMAX 64
#define iMAX 1
#define rMAX 128

int asm_insert_ex(uint32_t count[], int n, int k);
int new_insert (uint32_t array[], int where, int amount, int num);
asm("	asm_insert_ex: \n\
		slli t1, a1, 2 \n\
		add  t1, a0, t1 \n\
		ld   t2, 0(t1) \n\
		addi t2, t2, 1 \n\
		sd   t2, 0(t1) \n\
		addi a0, a2, 1 \n\
		ret\n\
");


void your_sort(uint32_t array[])
{
 uint32_t count[rMAX+1] = { };
 int i=0, k=0;
 while(i<nMAX){
	 i = asm_insert_ex(count, array[i], i);
	 //++count[array[i++]];
 }
 for(i=0;i<rMAX+1;i++){
	for(int j=0;j<count[i];j++){
	 	array[k++] = i;
	}
 }
}
void bubble_sort(uint32_t array[])
{
  int i, j;
  uint32_t temp;
  for (i = 0; i < (nMAX - 1); i++)
  {
    for (j = 0; j < (nMAX - i - 1); j++)
    {
      if (array[j] > array[j + 1])
      {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void check(uint32_t array1[], uint32_t array2[])
{
  int i;
  uint32_t temp = 0;
  for (i = 0; i < nMAX; i++)
  {
    if (array1[i] != array2[i])
    {
      printf("Error : Wrong at array random_num[%d]\n",i);
      temp = 1;
    }
  }
  if (temp == 0)
  {
    printf("Success!\n");
  }
}

int main()
{
  int i, j;
  uint32_t random_nums[nMAX] = {0, };
  uint32_t your_nums[nMAX]   = {0, };

  srand(0);
  for (i = 0; i < iMAX; i++)
  {
    for (j = 0; j < nMAX; j++)
    {
      random_nums[j] = rand() % rMAX;
      your_nums[j] = random_nums[j];
   }
    bubble_sort(random_nums);

    //** run your function **//
    your_sort(your_nums);
    //***********************//

    check(random_nums, your_nums);
  }

  return 0;
}
