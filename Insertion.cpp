// 2012003738_ChaJeongMin_B

#include <stdio.h>
#include <stdlib.h>
 
// 길이와 배열을 입력받습니다.
// 출력결과는 내림차순입니다.
void InsertionSort(int len, int arr[])
{
    int i=0, j=0;
    int tmp=0;
 
    for( j=1; j < len; j++ )
    {
        tmp = arr[j];
        i=j-1;
         
        while( i>=0 && arr[i] < tmp )
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = tmp;
    }
}
 
int main(void)
{
    int i; // for repetition
    int len;
    int * arr;
 
    /* Input */
    scanf("%d", &len);  // 길이 입력
    arr = (int*)malloc(sizeof(int)*len); // 그 길이에 맞춘 배열 생성
    for( int i=0; i < len; i++)
    {
        scanf("%d", &arr[i]); // 배열 원소들의 값들 입력받기
    }
 
    /* Output */
    InsertionSort(len, arr);  // 삽입 정렬.
    for(int i=0; i < len; i++)
    {
        printf("%d\n", arr[i]); // 각 값들 모두 출력하기
    }
    return 0;
}