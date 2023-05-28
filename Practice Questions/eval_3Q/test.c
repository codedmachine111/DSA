#include<stdio.h>
#include<string.h>
char sub[100];
int substring(char sub[100],char str[100])
{

    int i=0,c=0,j=0,k,l,m;
    l=strlen(sub);
    m=strlen(str);
    for(int i=0; i<=m-l; i++)
    {
        k=i;
        for(j=0; j<l; j++)
        {

            if(str[k]!=sub[j])
            {
                break;
            }
            k++;
        }
        if(j==strlen(sub))
            return k-j;

    }


    return -1;
}
void replace1(char rep[10],int x,char str[100])
{
    int n=strlen(rep);
    FILE*fpr=fopen("lines2.txt","w");
    while(n!=0)
    {
        str[x]=rep[x];
        x++;
        n--;
    }
    for(int i=0;i<=strlen(str);i++)
    {
        fprintf(fpr,"%c",str[i]);
    }

}
int main()
{
    FILE* fp;
    fp=fopen("lines.txt","r");

    int a,x=0;

    char rep[30];

    char str[100],sub[100];
    fscanf(fp,"%s",sub);

        fscanf(fp,"%s",str);
        x=substring(sub,str);
        if(x==-1)
        {
            printf("NOT PRESENT\n");
        }
     else{
    fscanf(fp,"%s",rep);
    replace1(rep,x,str);
}
}