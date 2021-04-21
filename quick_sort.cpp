#include<bits/stdc++.h>
using namespace std;

int Partition(int arr[], int low, int high){
    int anchor = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j ++){
        if(arr[j] <= anchor){
            swap(arr[++i], arr[j]); // 将小于锚点的数放到左边
        }
    }
    swap(arr[i + 1], arr[high]); // 最后把锚点放到中间
    return i + 1; // 返回锚点位置
}

void quick_sort(int arr[], int low, int high){
    if(low < high){
        int anchor = Partition(arr, low, high);
        quick_sort(arr, low ,anchor - 1);
        quick_sort(arr, anchor + 1, high);
    }
}

int main()
{
    int a[10] = {13, 19, 5, 12, 8, 7, 4, 21, 6, 11};
    quick_sort(a, 0, 9);
    for(int i= 0; i < 10; i++){
        printf("%d ",a[i]);
    }
    // 1趟后（anchor=11）：5 8 7 4 6 11 12 21 19 13
    // 2趟：(1)（anchor=6）:5 4 6 8 7  (2)（anchor=13）:12 13 19 21
    // ... 
    system("pause");
    return 0;
}
