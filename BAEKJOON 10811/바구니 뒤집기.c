#include <stdio.h>
#include <stdlib.h>


int arr_len = 0;
int try_change = 0;
int reverse_min = 0;
int reverse_max = 0;
void arr_len_and_try_change_input(arr_len, try_chage);
void arr_reset(int[]);
void reverse_interval(void);
void try_reverse(int[],int,int,int);



void arr_len_and_try_change_input(void)
{scanf_s("%d%d", &arr_len, &try_change);}

void arr_reset(int arr[])
{for (int i = 0; i < arr_len; i++)
{arr[i] = i + 1;}
}

void reverse_interval(void)
{scanf_s("%d%d", &reverse_min, &reverse_max);}

void try_reverse(int arr[],int element_count,int real_reverse_min_arr_index, int real_reverse_max_arr_index)
{int two_point = element_count / 2;
for (int j = 0; j < two_point; j++)
{int temporary_serve = arr[real_reverse_max_arr_index-j];
arr[real_reverse_max_arr_index - j] = arr[real_reverse_min_arr_index + j];
arr[real_reverse_min_arr_index + j] = temporary_serve;
}
}





int main(void)
{arr_len_and_try_change_input();
int* arr = malloc(sizeof(int) * arr_len);
arr_reset(arr);
reverse_interval();

int element_count = (reverse_max - reverse_min) + 1;
int real_reverse_min_arr_index = reverse_min - 1;
int real_reverse_max_arr_index = reverse_max - 1;


}