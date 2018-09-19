
#include <iostream>
using namespace std;

/* 简单插入排序，start和end是数组下标，这里end是超尾 */
void Sort(int *a, int start, int end)
{
    int i, j;
    int tmp;

    for (i = start + 1; i < end; i++)
    {
        tmp = a[i];
        for (j = i; j > start && tmp < a[j - 1]; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

/* 简单交换 */
void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 打印数组 */
void Print(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void Next_permutation(int *a, int n)
{
    int i, j;
    
    while (1)
    {
        i = n - 1;
        /* 从右往左，找第一个左邻比右邻大的 */
        while (i--)
        {
            if (a[i] < a[i + 1])
                break;
        }
        /* 判断，若所有左边的数都比右边的数大，那么到达字典序的最大值 */
        if (i < 0)
            break;
        /* 找右边第一个比a[i]大的 */
        for (j = n; j > i && a[j] < a[i]; j--);
        /* 交换a[i]和a[j] */
        Swap(&a[i], &a[j]);
        /* 将a[i]右边升序排序 */
        Sort(a, i + 1, n);
        Print(a, 4);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    Next_permutation(arr, 4);
    return 1;
}
