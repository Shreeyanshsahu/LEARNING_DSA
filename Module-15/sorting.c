#include <stdio.h>

int main()
{
    int arr[] = {1, 3, 4, 2, 5};
    // for (int i = 0; i < sizeof(arr)/sizeof(arr[0])-1; i++)
    // {
    //     for (int j = 0; j < sizeof(arr)/sizeof(arr[0])-i-1; j++)
    //     {
    //         int temp = 0;
    //         if(arr[j]>arr[j+1]){
    //             temp=arr[j];
    //             arr[j]=arr[j+1];
    //             arr[j+1]=temp;
    //         }
    //     }
    // }
    int cur;
    int prev;
    // for (int i = 1; i <=sizeof(arr)/sizeof(arr[0])-1; i++)
    // {
    //     cur = arr[i];
    //      prev=i-1;
    //     while (arr[prev]>cur && prev>=0)
    //     {
    //         arr[prev+1]=arr[prev];
    //         prev--;
    //     }
    //     arr[prev+1] = cur;
    // }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
    {
        int small = i;
        int temp=0;
        for (int j = i + 1; j < sizeof(arr) / sizeof(arr[0]); j++)
        {
            if (arr[small] > arr[j])
            {
                small=j;
            }
        }
        temp = arr[i];
        arr[i] = arr[small];
        arr[small]= temp;
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
}