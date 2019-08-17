#include<cstdio>
#include<cstring>
const int MAX = 1000010;

int main()
{
    int a, b, c;
    scanf("%d%d", &a,&b);
    c = a + b;
    if(c < 0){
        printf("-");
        c = -c;
    }

    char result[MAX];
    sprintf(result, "%d\0", c);
    int len = strlen(result);
    for(int i = 0; result[i] != '\0'; i++){
        if((len-i-1)%3 == 0&&i != len-1) printf("%c,", result[i]);
        else printf("%c", result[i]);
    }
    
}