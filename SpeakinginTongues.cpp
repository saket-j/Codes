#include <stdio.h>
#include <string.h>

char s[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
    char st[102];
    int t,i,j;
    scanf("%d",&t);
    gets(st);
    for(i=1;i<=t;i++)
    {
        gets(st);
        st[strlen(st)]='\0';
        printf("Case #%d: ",i);
        for(j=0;st[j]!='\0';j++)
        {
            if(st[j]==' ')
                printf(" ");
            else printf("%c",s[st[j]-'a']);
        }
        printf("\n");
    }
}
