#include<iostream>
using namespace std;

// 打印函数
void print_arr(int arr[], int n)
{
    for(int i =0; i< n; i++)
    {
        cout << arr[i]<< " ";
    }
    cout<<endl;
}

// 辅助函数，交换变量值
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 划分函数
int partition(int arr[], int low, int high)
{
    int i = low-1;
    int j = high;
    int pivot = arr[high];

    while(1)
    {
        while(arr[++i] < pivot);
        while(arr[--j] > pivot);
        if(i < j)
        {
            swap(&arr[i], &arr[j]);
        }else{
            break;
        }
    }
    // 把枢纽元素放到正确的位置上
    swap(&arr[i],&arr[high]);
    return i;
}

// 快速排序
void qsort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid = partition(arr,low,high);
        qsort(arr, low, mid-1);
        qsort(arr, mid+1, high);
    }
}

// 快速排序
void quick_sort(int arr[], int n)
{
    qsort(arr, 0, n-1);
}

int main()
{
    int arr[10] = {9, 5, 2, 11, 12, 4, 3, 1, 7, 15};
    int n = 10;
    print_arr(arr, n);
    quick_sort(arr, n);
    print_arr(arr, n);
    system("pause");
    return 0;
}