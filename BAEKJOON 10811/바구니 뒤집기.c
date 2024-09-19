#include <stdio.h>
#include <stdlib.h>


int arr_len = 0;
int try_change = 0;
int reverse_min = 0;
int reverse_max = 0;
void arr_len_and_try_change_input(arr_len, try_chage);
void arr_reset(int[]);




void arr_len_and_try_change_input(void)
{scanf_s("%d%d", &arr_len, &try_change);}

void arr_reset(int arr[])
{for (int i = 0; i < arr_len; i++)
{arr[i] = i + 1;}
}






int main(void)
{arr_len_and_try_change_input();
int* arr = malloc(sizeof(int) * arr_len);
arr_reset(arr);





}