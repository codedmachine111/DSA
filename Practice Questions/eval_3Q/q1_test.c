#include <stdio.h>

typedef struct txt{
    char str[100];
}text;

void read(text *tptr,int n)
{
    for(int i=0;i<n;i++)
    {
        gets(tptr->str);
        tptr++;
    }
}


void display(text *tptr, int n){
    for(int i=0; i<n; i++){
        printf("%s\n",tptr->str);
        tptr++;
    }
}

int count(char str[100]){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int longest(text *tptr, int n){
    int lengths[100];
    int c;
    for(int i=0; i<n; i++){
        c = count(tptr->str);
        lengths[i] = c;
        tptr++;
    }

    int max =0,m;
    for(int j=0; j<n; j++){
        if(lengths[j]>max){
            max=lengths[j];
            m=j;
        }
    }

    return m;
}

int main(){
    text *tptr;
    int num;
    printf("Enter the number of lines: \n");
    scanf("%d", &num);
    read(tptr, num);
    display(tptr,num);
    int m;
    m = longest(tptr,num);
    
    printf("The longest line is :\n\n");
    for(int k=0; k<m; k++){
        tptr++;
    }
    printf("%s", tptr->str);
    return 0;
}