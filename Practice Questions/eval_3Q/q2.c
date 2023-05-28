#include <stdio.h>
#include <string.h>

int main(){

    char pattern[100];
    printf("Enter the patern to search :\n");
    scanf("%s", pattern);

    printf("Enter upto 10 lines of text");

    char lines[10][100];
    int line_count=0;
    
    while(line_count<10){
        if(fgets(lines[line_count], 100, stdin)==NULL){
            break;
        }else{
            line_count++;
        }
    }

    printf("Lines matching the pattern : \n");
    for(int i=0; i<line_count; i++){
        int j=0;
        int k=0;
        while(lines[i][j] != '\0'){
            if (lines[i][j]==pattern[k])
            {
                k++;
                if(pattern[k]=='\0'){
                    printf("%s", lines[i]);
                    break;
                }
            }else{
                k=0;
            }
            j++;
        }
    }
    return 0;
}