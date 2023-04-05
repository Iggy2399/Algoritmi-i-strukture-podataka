#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int povrh(int m, int n);
int main(){
    int n=10;
    int m = n/2;
    /*printf("Unesite n:");
    scanf("%d", &n);*/
    printf("%d",povrh(n,m));

}

int povrh(int n, int m){
    if(m == 0 || m == n || n ==1){
        return 1;
    }
    else{
        return povrh(n-1, m-1) + povrh(n-1, m);
    }
    
    
}
