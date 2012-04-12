#include <stdio.h>

void Max_Heapify(int *a, int i, int n)
{
    int l = i,temp;
    
    if(2*i+1 <= n && a[2*i+1]>a[l])
    {
        l = 2*i+1;
    }
    if(2*i+2 <= n && a[2*i+2]>a[l])
    {
        l = 2*i+2;
    }
    if(l!=i)
    {
        temp = a[i];
        a[i] = a[l];
        a[l] = temp;
        Max_Heapify(a,l,n);
    }
}

void BuildMaxHeap(int *a, int n)
{
    int i;
    for (i=(n-2)/2;i>=0;i--)
    {
        Max_Heapify(a,i,n-1);
    }
}

void Heap_Sort(int *a, int n)
{
    BuildMaxHeap(a,n);
    
    int i;
    int temp = a[0];
        a[0] = a[n-1];
        a[n-1] = temp;
    for (i=n-2;i>0;i--)
    {
        Max_Heapify(a,0,i);
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
    }
}

int main()
{
    int a[100],n,i;
    scanf("%d",&n);
    
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    Heap_Sort(a,n);
    
    for (i=0;i<n;i++)
        printf("%d ",a[i]);
}
