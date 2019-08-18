#include<cstdio>
#include<cstring>
const int MAX = 100010;
const int MOD = 1000000007;

int main(){
    char s[MAX];
    scanf("%s", s);
    int len = strlen(s);

    int p[MAX];
    memset(p, 0, MAX);
    if(s[0] != 'P') p[0] = 0;
    else p[0] = 1;
    for(int i = 1; s[i] != '\0'; i++){//count number of 'P' on the left of s[i]
        if(s[i] == 'P') p[i] = p[i-1] + 1;
        else p[i] = p[i-1];
    }
    // for(int i = 0; i < len; i++) printf("%d", p[i]);
    // printf("\n");

    int n = 0;
    int t[MAX];
    memset(t, 0, MAX);
    if(s[len-1] == 'T') t[len-1] = 1;
    else t[len-1] = 0;
    for(int i = len-2; i >= 0; i--){//count number of 'T' on the right of s[i]
        if(s[i] == 'T') t[i] = t[i+1] + 1;
        else t[i] = t[i+1];
        if(s[i] == 'A') n = (n+t[i]*p[i])%MOD;
    }
    // for(int i = len-1; i >= 0; i--) printf("%d", t[i]);
    // printf("\n");
    printf("%d\n", n);
    return 0;
}