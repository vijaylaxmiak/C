#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Bubble_sort(int arr[1000], int n);
void Selection_sort(int arr[1000], int n);
int findmax(int arr[1000], int n);
void swap(int arr[1000], int m, int k);
void merge(int arr[1000], int LB, int mid, int UB);
void Merge_sort(int arr[1000], int LB, int UB);
void print(int arr[],int n);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

int main()
{
    int n, i,upper,lower;
    FILE *fp;

    printf("Enter the number of elements: \n");
     scanf("%d", &n);
    printf("enter the upper limit:\n");
    scanf("%d",&upper);
              printf("enter the lower limit:\n");
    scanf("%d",&lower);

    int arr[n];
    clock_t start_b,end_b,start_s,end_s,start_m,end_m,start_h,end_h;
    fp=fopen("logs.txt","w");

    for (i=0; i<n; i++) {
        arr[i] = rand() % (upper - lower + 1) + lower;
        fprintf(fp,"%d\n",arr[i]);
    }
    printf("Unsorted array: ");
   print(arr,n);


           printf("Sorted array using bubble sort: ");
           start_b = clock();
    Bubble_sort(arr, n);
     print(arr,n);
     end_b = clock();
      double time_taken_b = (double)(end_b-start_b)/CLOCKS_PER_SEC;
      printf("The elapsed time is %f seconds\n", time_taken_b);
     fprintf(fp,"%f\n",time_taken_b);


    printf("Sorted array using selection sort: ");
    start_s = clock();
    Selection_sort(arr,n);
     print(arr,n);
      end_s = clock();
       double time_taken_s = (double)(end_s-start_s)/CLOCKS_PER_SEC;
       printf("The elapsed time is %f seconds\n", time_taken_s);
        fprintf(fp,"%f\n",time_taken_s);


        printf("Sorted array using merge sort: ");
        start_m = clock();
    Merge_sort(arr, 0, n - 1);
      print(arr,n);
       end_m = clock();
        double time_taken_m = (double)(end_m-start_m)/CLOCKS_PER_SEC;
        printf("The elapsed time is %f seconds\n", time_taken_m);
         fprintf(fp,"%f\n",time_taken_m);

         printf("Sorted array using heap sort: ");
         start_h = clock();
    heapSort(arr,n);
      print(arr,n);
       end_h = clock();
       double time_taken_h = (double)(end_h-start_h)/CLOCKS_PER_SEC;
       printf("The elapsed time is %f seconds\n", time_taken_h);
        fprintf(fp,"%f\n",time_taken_h);



    return 0;
}

void Bubble_sort(int arr[1000], int n)
{
    int i, j, temp, flag;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

}}

void Selection_sort(int arr[1000], int n)
{
    int m, i;
    for (i = 0; i < n; i++)
    {
        m = findmax(arr, n - i);
        swap(arr, m, n - i - 1);
    }
}

int findmax(int arr[1000], int n)
{
    int i, max = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[max] < arr[i])
        {
            max = i;
        }
    }
    return max;
}

void swap(int arr[1000], int m, int k)
{
    int temp;
    temp = arr[m];
    arr[m] = arr[k];
    arr[k] = temp;
}
void Merge_sort(int arr[1000], int LB, int UB)
{
    if (LB < UB)
    {
        int mid = (LB + UB) / 2;
        Merge_sort(arr, LB, mid);
        Merge_sort(arr, mid + 1, UB);
        merge(arr, LB, mid, UB);
    }
}

void merge(int a[1000], int LB, int mid, int UB)
{
    int b[1000];
    // int b[1000];
    int i, j, k;
    i = LB;
    j = mid + 1;
    k = LB;
    while (i <= mid && j <= UB)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= UB)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else if (j > UB)
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (int i = LB; i <= UB; i++)
    {
        a[i] = b[i];
    }
}


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void print(int arr[],int n)
{
     for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

