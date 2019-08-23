#include<cstdio>

const int MAXN = 100;

void Merge(int A[], int L1, int R1, int L2, int R2){
    int i = L1, j = L2;
    int temp[MAXN], index = 0;
    while(i <= R1 && j <= R2){
        if(A[i] <= A[j]) temp[index++] = A[i++];
        else temp[index++] = A[j++];
    } 
    while(i <= R1) temp[index++] = A[i++];
    while(j <= R2) temp[index++] = A[j++];
    for(int k = 0; k < index; k++)
        A[L1+k] = temp[k];
}

void MergeSort(int A[], int L, int R){
    if(L < R){
        int mid = (L+R)/2;
        MergeSort(A, L, mid);
        MergeSort(A, mid+1, R);
        Merge(A, L, mid, mid+1, R);
    }
}

int main(){
    int A[100] = {567,342,73,65,26,28,7,2358,4513};
    MergeSort(A, 0, 8);
    for(int i = 0; i < 9; i++)
        printf("%d ", A[i]);
    return 0;
}