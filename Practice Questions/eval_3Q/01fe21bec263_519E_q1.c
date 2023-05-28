#include <stdio.h>

typedef struct txt
{
    char str[100];
}text;

int read_from_file(text *tptr, FILE *fp){
    int n_lines=0;
    while(!feof(fp)){
        fgets(tptr->str, 100, fp);
        tptr++;
        n_lines++;
    }
    return n_lines;
}

int display_lines(text *tptr, int n){
    for(int i=0; i<n; i++){
        printf("%s\n", tptr->str);
        tptr++;
    }
}

int count(char str[100]){
    int i;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int longest_line(text *tptr, int num){
    int lengths[10];
    int c;
    for(int i=0; i<num; i++){
        c = count(tptr->str);
        lengths[i]=c;
    }
    int max=0, m;
    for(int j=0; j<num; j++){
        if(lengths[j]>max){
            max=lengths[j];
            m = j;
        }
    }
    return m;
}

int main(){
    text *tptr;
    FILE *fp;
    fp = fopen("lines.txt", "r+");
    int n_lines;
    n_lines = read_from_file(tptr,fp);
    display_lines(tptr, n_lines);
    int m;
    m = longest_line(tptr, n_lines);
    printf("Longest line is : \n");
    for(int i=0; i<m; i++){
        tptr++;
    }
    printf("%s", tptr->str);
    return 0;
}