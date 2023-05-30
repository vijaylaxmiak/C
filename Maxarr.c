//find the max num in an array
#include<stdio.h>
int main()
{
    int arr[7]={1,-2,300,4,9,8,60};
    int i;
    int max = arr[0];
    for(i=1;i<=6;i++)
    {


        if(max<arr[i])
    {
        max= arr[i];
    }
    }
    printf("%d",max);
    return 0;
}
