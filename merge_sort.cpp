#include <iostream>
#include "malloc.h"
using namespace std;

// 归并
void merge(int arr[], int temparr[], int left, int mid, int right)
{
    // 标记左边未排序部分第一个元素
    int l = left;
    // 标记右边未排序部分第一个元素
    int r = mid + 1;
    // 标记临时数组的下标
    int pos = left;
    // 当左边和右边都还有元素时，进行合并
    while (l <= mid && r <= right)
    {
        // 当左边第一个剩余元素小于右边第一个剩余元素
        if (arr[l] < arr[r])
            temparr[pos++] = arr[l++]; // 将左边第一个剩余元素复制到temparr
        else                           // 当右边第一个剩余元素小于左边第一个剩余元素
            temparr[pos++] = arr[r++]; // 将右边第一个剩余元素复制到temparr
    }
    // 左边还有元素剩余，直接将左边剩余部分复制到temparr
    while (l <= mid)
    {
        temparr[pos++] = arr[l++];
    }
    // 右边还有元素剩余，直接将右边剩余部分复制到temparr
    while (r <= right)
    {
        temparr[pos++] = arr[r++];
    }
    // 将临时数组合并后的元素,复制回原来的数组
    while (left <= right)
    {
        arr[left] = temparr[left];
        left++;
    }
}

// 归并排序
void msort(int arr[], int temparr[], int left, int right)
{
    // 找中间点
    int mid = (left + right) / 2;
    // 当只有一个元素时，就不需要进行划分
    // 只有一个元素的区域，本身就是有序的，只需被归并即可
    if (left < right)
    {
        // 递归排序左边
        msort(arr, temparr, left, mid);
        // 递归排序右边
        msort(arr, temparr, mid + 1, right);
        // 归并排序完成后的两个序列
        merge(arr, temparr, left, mid, right);
    }
}

// 归并排序入口
void merge_sort(int arr[], int n)
{
    // 分配一个数组
    int *temparr = (int *)malloc(n * sizeof(int));
    if (temparr) // 数组分配成功
    {
        msort(arr, temparr, 0, n - 1);
        free(temparr);
    }
    else
    {
        cout << "Error:failed to allocate memory!";
    }
}

int main()
{
    int arr[10] = {1, 5, 9, 7, 2, 3, 8, 4, 10, 6};
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << arr[i] << endl;
        else
            cout << arr[i] << " ";
    }
    merge_sort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << arr[i] << endl;
        else
            cout << arr[i] << " ";
    }
    system("pause");
    return 0;
}
