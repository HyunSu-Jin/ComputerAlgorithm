//2012003738_ChaJeongMin_B

#include <stdio.h>
#include <stdlib.h>
#define inf 99999

void Merge(int arr[], int first, int mid, int last)
{
	int i=0,j=0,k=0;
	int a=first, b=mid, c=last;
	int n1 = b - a + 1;
	int n2 = c - b;

	int * Left, * Right;
	Left = (int*)malloc(sizeof(int)*(n1+1));
	Right = (int*)malloc(sizeof(int)*(n2+1));

	for(i=0; i<n1; i++){
		Left[i] = arr[a + i - 1]; 
	}
	for(i=0; i<n2; i++){
		Right[i] = arr[b + i];
	}
	Left[n1] = inf;
	Right[n2] = inf;
	i=0;
	j=0;

	for(k=a-1; k<c; k++)
	{
		if(Left[i] <= Right[j])
			arr[k] = Left[i++];
		else
			arr[k] = Right[j++];	
	}
}

void MergeSort(int arr[], int first, int last)
{
	if(first < last)			 // Terminal Condition!
	{
		int mid = (first + last)/2;
		MergeSort(arr, first, mid);
		MergeSort(arr, mid+1, last);
		Merge(arr, first, mid, last);
	}
}

void ReverseOrder(int arr[], int len)
{
	int tmp,i;

	int mid = len/2;

	for(i=0; i<mid; i++)
	{
		tmp = arr[i];
		arr[i] = arr[len-i-1];
		arr[len-i-1] = tmp;
	}
}

int main(void)
{
	int i; // for repetition
    int len;
    int * arr;

	/* Input */
    scanf("%d", &len);  // 길이 입력
    arr = (int*)malloc(sizeof(int)*(len+1)); // 그 길이에 맞춘 배열 생성
    for( int i=0; i < len; i++)
    {
        scanf("%d", &arr[i]); // 배열 원소들의 값들 입력받기
    }
 
    /* Output */
    MergeSort(arr,1,len);  // 삽입 정렬.
	ReverseOrder(arr, len);		// 내림차순 정렬.
    for(int i=0; i < len; i++)
    {
        printf("%d\n", arr[i]); // 각 값들 모두 출력하기
    }
	return 0;
}
