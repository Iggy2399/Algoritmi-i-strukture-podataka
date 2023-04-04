#include<stdio.h>
#include<time.h>
typedef struct stack{
    int data[100];
    int sp;
}STACK;

int clearStack(STACK *s){
    s->sp=-1;
    return 1;
}
int isEmpty(STACK *s){
    int result;
    if(s->sp==-1){
        result = 1;
    }else{
        result = 0;
    }
    return result;
}
int isFull (STACK *s){
    int result;
    if(s->sp == 99){
        result =1 ;
    } 
    else{
        result = 0;
    }
    return result;
}
int Push(STACK *s, int data){
    s->sp++;
    s->data[s->sp]=data;
    return 1;
}
int Pop(STACK *s){
    int result = s->data[s->sp];
    s->sp--;
    return result;
}
int PrintStack(STACK *s){
    int i;
    printf("\n");
    for(i=0; i<=s->sp; i++){
        printf("%d",s->data[i]);
    }
    printf("\n");
    return 1;
}
int main(){
    time_t t1, t2;
    STACK S1, S2;
    int n = 37;
    int m = n/2;
    clearStack(&S1);
    clearStack(&S2);
    t1=clock();
    int over = 0;
    if(!isFull(&S1)) Push(&S1, n);
    if(!isFull(&S2)) Push(&S2, m);
    do {
        if(!isEmpty(&S1)) m = Pop(&S1);
        if(!isEmpty(&S2)) n = Pop(&S2);
        if(m == n || n == 0) {
            over++;
        }
        else {
            if(!isFull(&S1)) Push(&S1, m - 1);
            if(!isFull(&S1)) Push(&S1, m - 1);
            if(!isFull(&S2)) Push(&S2, n - 1);
            if(!isFull(&S2)) Push(&S2, n);
        }
    }while(!isEmpty(&S1));
    t2=clock();
    printf("Result: %d\n", over);
    printf("vrijeme racunanja je: %d ms",t2-t1);
    return 0;

}