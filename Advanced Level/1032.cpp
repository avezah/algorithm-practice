#include<cstdio>
using namespace std;

const int MAX = 100010;

struct Node
{
    char c;
    int next;
    bool flag;
}node[MAX];

int main(){
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int a,b,n;
    scanf("%d%d%d", &a, &b, &n);
    int here, next;
    char temp;
    for(int i = 0; i < n; i++){
        scanf("%d %c %d", &here, &temp, &next);
        node[here].c = temp;
        node[here].next = next;
        node[here].flag = false;
    }
    int res = -1;
    while(a != -1){//do while format incurs tle
        node[a].flag = true;
        a = node[a].next;
    }
    while(b != -1){
        if(node[b].flag == true){
            res = b;
            break;
        }
        b = node[b].next;
    }
    
    if(res == -1) printf("-1\n");
    else printf("%05d", res);
    return 0;
}