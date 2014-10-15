#include<stdio.h>
void swap(int *a,int *b)
{
    int z;
    z=*a;
    *a=*b;
    *b=z;
}
void quicksort(int a[],int low,int high)
{
    if(low>high)
        return;
    int c,i;

    c=low;
    while(1)
    {
    for(i=high;i>c;i--)
      if(a[i]<a[c])
        {
            swap(&a[i],&a[c]);

            break;
        }
        if(i==c)
            break;
        else
            c=i;

    for(i=low;i<c;i++)
        if(a[i]>a[c])
        {
            swap(&a[i],&a[c]);

            break;
        }
        if(i==c)
            break;
        else
            c=i;
    }
    quicksort(a,low,c-1);
    quicksort(a,c+1,high);
}

int main()
{
    int a[100],n,i;
    printf("Enter N and then n numbers followed by space");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
