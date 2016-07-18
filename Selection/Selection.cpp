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
	scanf("%d %d", &len, &count); // ����(N)�� ����(M) �Է�.

    arr = ( int* )malloc( sizeof(int) * len ); // �� ���̿� ���� �迭 ����
    for( int i=0; i < len; i++ )
    {
        scanf("%d", &arr[i]); // �迭 ���ҵ��� ���� �Է¹ޱ�
    }
 
    /* Output */
    SelectionSort( arr, len, count );  // ���� ����.
    for(int i=0; i < len; i++)
    {
        printf("%d\n", arr[i]); // �� ���� ��� ����ϱ�
    }
	return 0;
}