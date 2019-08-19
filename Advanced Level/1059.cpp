#include<cstdio>
#include<cmath>

const int MAX = 100010;//sizeof(int) ~ 2*10^9; 10^5 > sqrt(2*10^9)

struct Factor
{
    int x;
    int cnt;
}fac[10];//2*3*5*7*11*13*17*19*23*29 > sizeof(int)


int FindPrime(int prime[], int n){
    int pNum = 0;
    int p[n] = {0};
    for(int i = 2; i < n; i++)
        if(p[i] == false){
            prime[pNum++] = i;
            for(int j = i+i; j < n; j+=i)
                p[j] = true;
        }
    return pNum;
}

int main(){
    
    int prime[MAX];
    int pNum = FindPrime(prime, MAX);
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("1=1\n");
        return 0;
    }
    else printf("%d=", n);

    int sqr = (int)sqrt(1.0*n), num = 0;
    for(int i = 0; i < pNum && prime[i] < sqr; i++){
        if(n%prime[i] == 0){
            fac[num].x = prime[i];
            fac[num].cnt = 0;
            while(n%prime[i] == 0){
                n = n/prime[i];
                fac[num].cnt++;
            }
            num++;
        }
    }
    if(n != 1){
        fac[num].x = n;
        fac[num].cnt = 1;
        num++;
    }
    for(int i = 0; i < num; i++){
        if(i>0) printf("*");
        printf("%d",fac[i].x);
        if(fac[i].cnt > 1) printf("^%d", fac[i].cnt);
    }
        
    return 0;
}