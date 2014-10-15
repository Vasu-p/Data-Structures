#include<stdio.h>
#include<string.h>
int main()
{
    char s[100],s1[100],s2[100];
    int cnt[26]={0},i,j;
    scanf("%s",s);
    for(i=0,j=0;i<strlen(s);i++)
    {
        if(cnt[s[i]-'a']==0)
            s1[j++]=s[i];
        cnt[s[i]-'a']++;
    }
    s1[j]='\0';
    printf("%s\n",s1);
    int l;
    l=strlen(s1);
    int b;
    for(b=2;b<=strlen(s1);b++)
    for(i=0;i<l-1-b+2;i++)

    {
        strncpy(s2,s1+i,i+b);
        s2[b]='\0';
        printf("%s  ",s2);
    }
    return 0;
}
