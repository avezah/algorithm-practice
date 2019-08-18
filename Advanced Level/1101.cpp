#include<cstdio>
#include<cstring>

const int MAX = 100010;

int num[MAX];
int small[MAX];//the smallest number on the right
int big[MAX];//the biggest number on the left
int res[MAX];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    if(n == 0){
        printf("0\n");
        return 0;
    }

    small[n-1] = num[n-1];
    for(int i = n-2; i >= 0; i--){
        if(num[i] < small[i+1]) small[i] = num[i];
        else small[i] = small[i+1];
    }

    big[0] = num[0];
    for(int i = 0; i < n; i++){
        if(num[i] > big[i-1]) big[i] = num[i];
        else big[i] = big[i-1];
    }

    int cnt = 0;
    memset(res, 0, MAX);
    for(int i = 0; i < n; i++){
        if(num[i] >= big[i] && num[i] <= small[i]){
            res[i] = 1;
            cnt++;
        }
    }

    // for(int i = 0; i < n; i++) printf("%d ", res[i]);
    printf("%d\n", cnt);
    if(cnt == 0) printf("\n"); //while 0 element can be pivot, print endline
    for(int i = 0; i < n; i++){
        if(res[i]) {
            cnt--;
            printf("%d", num[i]);
            if(cnt!=0) printf(" ");
            else printf("\n");
        }
    }

    return 0;
}