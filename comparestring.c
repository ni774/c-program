#include<stdio.h>
int strlength(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}
int main()
{
    char str1[10];
    char str2[10];
    int i=0;
    printf("enter first string\n");
    scanf("%s",str1);
    printf("enter second string\n");
    scanf("%s",str2);
    int l1=strlength(str1);
    int l2=strlength(str2);
    if(l1==l2)
    {
       while(i<l1){
          if(str1[i]==str2[i])
             i++;
          else {
             printf("string is not equal\n");
             break;
           }
          
        }
        if(i==l1)
            printf("string is equal");
    }
    else
    printf("string is not equal\n");

    
    

    return 0;
}