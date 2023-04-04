#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*puni matricu random brojevima*/
void gen_array(int array[], int n, int dg, int gg);
int sekv(int array[], int n , int x);
void sortiranje(int array[], int n);




void gen_array(int array[], int n, int dg, int gg){
    for (int i = 0; i<n; i++){
        array[i] = (int)rand()%(int)(gg+1-dg)+dg;
    }
}
/*sekv pretrazivanje*/
int sekv(int array[], int n , int x){
    
    for(int i = 0; i<n; i++){
        if(array[i]==x){
            printf("%d",i);
            return i;
        }
    }
    printf("Broj nije u polju!\n");
    
    
}
/*sortiranje array-*/
void sortiranje(int array[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(array[j]<array[i]){
                int temp = array[i];
                array[i]=array[j];
                array[j] = temp;
                
            }
        }
    }
}

int bin_search( int array[], int x, int low, int high, int n){
    low = 0;
    high = n;
    
    while(low<=high){
        int mid = (high+low)/2;
        if(array[mid]==x){
            printf("Broj je na %d indexu\n",mid);
        }
        if (x>array[mid])
            low = mid +1;
        else
            high = mid -1;
    
    
    }
}
int main(){
    time_t t1,t2;
    int dg = 5;
    int gg = 8;
    int n = 10000;
    int low = 0;
    int high = n-1;
    int array[n];
    int *p;
    p = array;
    int x = 10;
    gen_array(p,n,dg,gg);
    t1=clock();
    sekv(p,n,x);
    t2=clock();
    printf("vrijeme izvodenja sekv pretrazivanja je: %ld ms\n",t2-t1);
    t1=clock();
    sortiranje(p,n);
    t2=clock();
    printf("vrijeme izvodenja sortiranje je: %ld ms\n",t2-t1);
    t1=clock();
    bin_search(p,x,low,high,n);
    t2=clock();
    printf("vrijeme izvodenja binarnog pretrazivanja je: %ld ms\n",t2-t1);
    /*for (int i =0; i<n; i++){
        printf("%d\t",array[i]);
    }*/
}