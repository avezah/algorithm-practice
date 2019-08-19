#include<cstdio>

int Partition(int A[], int left, int right){
    int temp = A[left];
    while (left < right){
        while(left < right && A[right] > temp) right--;
        A[left] = A[right];
        while(left < right && A[left] <= temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}
void QuickSort(int A[], int left, int right){
    if(left < right){
        int pos = Partition(A, left, right);
        QuickSort(A, left, pos-1);
        QuickSort(A, pos+1, right);
        //position of A[pos] has been set
    }
}
int main(){
    int A[100] = {567,342,73,65,26,28,7,2358,4513};
    QuickSort(A, 0, 8);
    for(int i = 0; i < 9; i++)
        printf("%d ", A[i]);
    return 0;
}