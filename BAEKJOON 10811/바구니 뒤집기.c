#include <stdio.h>
#include <stdlib.h>


int arr_len = 0;//배열의 길이를 담는 변수
int try_change = 0;//역순 작업을 몇번 할지 담는 변수
int reverse_min = 0;//역순시 가장 왼쪽 바구니 번호
int reverse_max = 0;//역순시 가장 오른쪽 바구니 번호
void arr_len_and_try_change_input(void);//배열의 길이와 작업 횟수를 입력 받는 함수
void arr_reset(int[]);//배열 내 원소를 1,2,3...으로 초기화 시키는 함수
void reverse_interval_input(void);//역 순 시킬 구간을 입력하는 함수
void try_reverse(int[],int,int,int);//two point방식으로 구간 내 원소를 역순 시키는 함수
void output_arr(int []);//역순한 작업을 모두 끝낸 결과를 출력하는 함수


void arr_len_and_try_change_input(void)
{scanf_s("%d%d", &arr_len, &try_change);}//배열의 길이와 작업 횟수를 입력

void arr_reset(int arr[])
{for (int i = 0; i < arr_len; i++)
{arr[i] = i + 1;}//배열 내 원소를 1,2,3...으로 초기화
}

void reverse_interval_input(void)
{scanf_s("%d%d", &reverse_min, &reverse_max);}//역 순 시킬 구간을 입력


void try_reverse(int arr[],int element_count,int real_reverse_min_arr_index, int real_reverse_max_arr_index)
{int two_point = element_count / 2;
for (int j = 0; j < two_point; j++)
{int temporary_serve = arr[real_reverse_max_arr_index-j];//맨 끝값-j를 임시저장
arr[real_reverse_max_arr_index - j] = arr[real_reverse_min_arr_index + j];//맨 끝값-j로 앞으로 오는 방식을 이용해 맨 끝 번호-j와 맨 처음번호+j값을 교환
arr[real_reverse_min_arr_index + j] = temporary_serve;}//초기화 전 맨 끝값-j 임시 저장한 값을  맨 처음번호+j에게 줌
}

void output_arr(int arr[])
{for (int i = 0; i < arr_len; i++)
{printf("%d ", arr[i]);}
}





int main(void)
{arr_len_and_try_change_input();
int* arr = (int *)malloc(sizeof(int) * arr_len);
arr_reset(arr);

for (int i = 0; i < try_change; i++)
{reverse_interval_input();
int element_count = (reverse_max - reverse_min) + 1;
int real_reverse_min_arr_index = reverse_min - 1;//배열은 0부터 시작하므로 입력 받은 구간에서 1을 빼야 실제 배열내 위치로 갈 수 있음
int real_reverse_max_arr_index = reverse_max - 1;
try_reverse(arr, element_count, real_reverse_min_arr_index, real_reverse_max_arr_index);}
output_arr(arr);
free(arr);
}
