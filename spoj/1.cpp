///merge sort................
#include<stdio.h>
#include<iostream>
void mergesort(long int *, int, int);
void merge(long int *, int, int, int);
int main()
{
                int n;
                int t;
                scanf("%d ",&t);
                 int k;
                while(t--)
                {
                                scanf("%d",&n);

                                long int arr[n];
                                int i;
                                for(i=0;i<n;i++)
                                scanf("%ld",&arr[i]);
                                if(n==1)
                                {
                                                printf("0\n");continue;
                                }
                                mergesort(arr,0,n-1);
                                k=(n/2);
                               int max;
                                i=n-2;
                                max=n-1;
                                while(1)
                                {
                                                if(arr[max]>arr[i])break;
                                                i--;
                                }
                                k=i+2-k;
                                printf("%d\n",k);



                }
                /*for(i=0;i<n;i++)
                printf("%d  ",arr[i]);*/
                return 0;
}
void mergesort(long int *arr, int left, int right)
{
                 int mid;
                mid=(left+right)/2;
                if(left<right)
                {
                                mergesort(arr,left,mid);
                                mergesort(arr,mid+1,right);
                                merge(arr,left,mid,right);
                }

}
void merge(long int *arr, int left, int mid, int right)
{
                long int temparr[left-right+1];
                int pos=0;
                int lpos,rpos;
                lpos=left;rpos=mid+1;
                while(lpos <= mid && rpos <= right)
                {
                                if(arr[lpos] < arr[rpos])
                                {
                                temparr[pos++] = arr[lpos++];
                                }
                                else
                                {
                                temparr[pos++] = arr[rpos++];
                                }
                }
        while(lpos <= mid)  temparr[pos++] = arr[lpos++];
        while(rpos <= right)temparr[pos++] = arr[rpos++];
         int iter;
        for(iter = 0;iter < pos; iter++)     ///copy back temparr to original array........
        {
                arr[iter+left] = temparr[iter];
        }
}
