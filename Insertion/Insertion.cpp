// 2012003738_ChaJeongMin_B

#include <stdio.h>
#include <stdlib.h>
 
// ���̿� �迭�� �Է¹޽��ϴ�.
// ��°���� ���������Դϴ�.
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
    scanf("%d", &len);  // ���� �Է�
    arr = (int*)malloc(sizeof(int)*len); // �� ���̿� ���� �迭 ����
    for( int i=0; i < len; i++)
    {
        scanf("%d", &arr[i]); // �迭 ���ҵ��� ���� �Է¹ޱ�
    }
 
    /* Output */
    InsertionSort(len, arr);  // ���� ����.
    for(int i=0; i < len; i++)
    {
        printf("%d\n", arr[i]); // �� ���� ��� ����ϱ�
    }
    return 0;
}