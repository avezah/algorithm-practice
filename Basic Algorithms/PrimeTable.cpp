#include<cstdio>
#include<cmath>

//Method 1
bool isPrime(int n){
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0*n);
    for(int i = 2; i < sqr; i++)
        if(n%i == 0) return false;
    return true;
}

int FindPrime_1(int primeTable[], int n){
    int pNum = 0;
    for(int i = 0; i < n; i++)
        if(isPrime(i)) primeTable[pNum++] = i;
    return pNum;
}

//Method 2
int FindPrime_2(int primeTable[], int n){
    int pNum = 0;
    bool p[n]  = {0};
    for(int i = 2; i < n; i++){
        if(p[i] == false){// if p[i] is prime
            primeTable[pNum++] = i;
            for(int j = i + i; j < n; j+=i)
                p[j] = true;// mark p[j] isnt prime
        }
    }
    return pNum;
}

int main(){
    const int n = 500;
    int primeTable[n];
    int pNum = FindPrime_2(primeTable, n);
    for(int i = 0; i < pNum; i++)
        printf("%d ", primeTable[i]);
    return 0;
}