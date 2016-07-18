// 2012003738 _ Â÷Á¤¹Î _ B

#include <stdio.h>

void array_swap(int * arr, int a, int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void Heapify(int * arr, int parent_position, int heap_size)
{
	int left, right, largest;
	left=2*parent_position+1;
	right=2*parent_position+2;

	if((left<heap_size)&&(arr[left]>arr[parent_position]))
		largest = left;
	else
		largest = parent_position;

	if((right<heap_size)&&(arr[right]>arr[largest]))
		largest = right;

	if(largest != parent_position)
	{
		array_swap(arr, parent_position, largest);
		Heapify(arr, largest, heap_size);
	}
}

void Build_Heap(int * arr, int length)
{
	int parent_position;

	for(parent_position=length/2-1; parent_position>=0; parent_position--)
		Heapify(arr, parent_position, length);
}

void Heap_Sort(int * arr, int length, int k)
{
	Build_Heap(arr, length);
	int last_row;
	int count = 0;

	for(last_row = length-1; last_row>0; last_row--)
	{
		if(count == k)
			break;
		array_swap(arr, 0, last_row);
		length--;
		count ++;

		Heapify(arr, 0, length);
	}
}

int main(void)
{
	int arr[100000];
	int length = 10;
	int N, k, i;

	// input
	scanf("%d %d", &N, &k);
	for(i=0; i<N; i++)
	{
		scanf("%d", &arr[i]);
	}
	Heap_Sort(arr, N, k);

	// output
	for(i=N-1; i>(N-1)-k; i--)
		printf("%d ", arr[i]);

	printf("\n");
	for(i=0; i<=(N-1)-k; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}