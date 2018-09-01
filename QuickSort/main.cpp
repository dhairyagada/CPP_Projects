#include <iostream>
using namespace std;
void Swap(int *a,int* b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
    return;
}
int Partition(int *A,int start,int end)
{
    int pivot=A[end];
    int pindex=start;
    for(int i=start;i<end;i++)
    {
        if(pivot>=A[i])
        {
            Swap(&A[i],&A[pindex]);
            pindex++;

        }
    }
    Swap(&A[pindex],&A[end]);
    return  pindex;
}
void QuickSort(int *A,int start,int end)
{
    if(start>=end)return;
    int pindex;
    pindex=Partition(A,start,end);
    QuickSort(A,start,pindex-1);
    QuickSort(A,pindex+1,end);
    return;
}
int main() {
    int A[10]={9,1,5,6,3,2,8,4,10,7};
    QuickSort(A,0,9);
    for(int i=0;i<10;i++)
        cout<<A[i]<<"  ";
    return 0;
}