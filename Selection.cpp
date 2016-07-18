// 2012003738_ChaJeongMin_B

#include <stdio.h>
#include <stdlib.h>

// parameter:
// 'arr' is the array to sort.
// 'len' is the length of the array.
// 'count' means the steps of the selection sort.
void SelectionSort( int arr[], int len, int count )
{
	int i, j, minIdx, tmp;

	for( i=0; i<count; i++ )
	{
		minIdx = i;
		
		for( j=i+1; j<len; j++ )
		{
			if( arr[j] < arr[minIdx] )
				minIdx = j;
		}

		if( i != minIdx)
		{
			tmp = arr[minIdx];
			arr[minIdx] = arr[i];
			arr[i] = tmp;
		}
	}
}

int main( void )
{
	int i;	// for repetition
	int len, count;
	int * arr;

	/* Input */
	scanf("%d %d", &len, &count); // 길이(N)와 스텝(M) 입력.

    arr = ( int* )malloc( sizeof(int) * len ); // 그 길이에 맞춘 배열 생성
    for( int i=0; i < len; i++ )
    {
        scanf("%d", &arr[i]); // 배열 원소들의 값들 입력받기
    }
 
    /* Output */
    SelectionSort( arr, len, count );  // 선택 정렬.
    for(int i=0; i < len; i++)
    {
        printf("%d\n", arr[i]); // 각 값들 모두 출력하기
    }
	return 0;
}