#include <stdio.h>
#include <string.h>

int read(char (*lines)[200], FILE *fp) {
    int n_lines = 0;
    while (fgets(lines[n_lines], 200, fp) != NULL) {
        n_lines++;
    }
    return n_lines;
}

void display(char (*lines)[200], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s", lines[i]);
    }
}

void replace(char *line, char *pattern1, char *pattern2, FILE *fp_out) {
    int i, j, k, found;

    i = 0;
    while (line[i] != '\0') {
        j = 0;
        found = 1;

        while (pattern1[j] != '\0') {
            if (line[i+j] != pattern1[j]) {
                found = 0;
                break;
            }
            j++;
        }

        if (found) {
            j = 0;
            while (pattern2[j] != '\0') {
                fputc(pattern2[j], fp_out);
                j++;
            }
            i += strlen(pattern1);
        } else {
            fputc(line[i], fp_out);
            i++;
        }
    }
}


int main(){
    FILE *fp;
    fp = fopen("lines.txt", "r+");
    FILE *fp1;
    fp1 = fopen("new.txt", "w");

    char pattern1[100];
    char pattern2[100];
    printf("Enter the pattern to search :\n");
    scanf("%s", pattern1);
    printf("Enter the pattern to replace with :\n");
    scanf("%s", pattern2);

    char lines[100][200];

    int n_lines, l;
    n_lines = read(lines,fp);

    display(lines,n_lines);
    printf("\n");
    printf("Lines matching the pattern : \n\n");
    for(int i=0; i<n_lines; i++){
        int j=0;
        int k=0;
        while(lines[i][j] != '\0'){
            if (lines[i][j]==pattern1[k])
            {
                k++;
                if(pattern1[k]=='\0'){
                    printf("%s", lines[i]);
                    replace(lines[i], pattern1, pattern2, fp1);
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