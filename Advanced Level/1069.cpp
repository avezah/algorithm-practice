#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX = 4;

bool cmp(int a, int b){
    return a > b;
}

void num2array(int num, int array[]){
    for(int i = 0; i < MAX; i++){
        array[i] = num%10;
        num /= 10;
    }
}

void array2num(int &num, int array[]){
    num = 0;
    for(int i = 0; i < MAX; i++){
        num = num*10 + array[i];
    }
}

int main(){
    int num, array[MAX];
    scanf("%d", &num);
    int res = 1;
    while(res != 6174 && res){//crack point while input num = 6174
        num2array(num, array);
        sort(array, array+MAX, cmp);
        array2num(res, array);
        sort(array, array+MAX);
        array2num(num, array);
        printf("%04d - %04d = %04d\n", res, num, res-num);
        res -= num;
        num = res;
    }

    return 0;
}