#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack{
    char data[SIZE];
    int top;
};
void push(struct stack* sptr,char letter){
    if(sptr->top == SIZE-1){
        printf("Stack overflow");
    }
    else{
        sptr->top++;
        sptr->data[sptr->top]=letter;
    }
}
void pop(struct stack* sptr){
    if(sptr->top == -1){
        printf("Stack underflow\n");
    }
    else{
        sptr->top--;
    }
}
void check_add(struct stack* sptr,struct stack* vptr,struct stack* cptr){
    int v_count=0, c_count=0;
    for(int i=(sptr->top); i>=0; i--){
        if(sptr->data[i] == 'A' || sptr->data[i] == 'E' || sptr->data[i] == 'I' || sptr->data[i] == 'O' || sptr->data[i] == 'U'){
          push(vptr,sptr->data[i]);
          v_count++;
        }
        else{
            push(cptr,sptr->data[i]);
            c_count++;
        }
    }
    printf("%d %d\n", v_count, c_count);
}
void display(struct stack* sptr){
    if(sptr->top ==-1){
        printf("Empty stack\n");
    }
    else{
        for(int i= sptr->top; i>=0; i--)
        {
            printf("%c ",sptr->data[i]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    struct stack* sptr;
    struct stack s[SIZE];
    struct stack* vptr;
    struct stack v[SIZE];
    struct stack* cptr;
    struct stack c[SIZE];
    sptr = &s;
    cptr = &c;
    vptr = &v;
    sptr->top = -1;
    cptr->top = -1;
    vptr->top = -1;

    char d;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%s",&d);
        push(sptr,d);
    }
    check_add(sptr,vptr,cptr);
    display(vptr);
    display(cptr);
}
