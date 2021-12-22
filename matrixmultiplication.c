#include<stdio.h>

int main()
{
    int m1,n1,m2,n2;
    printf("enter row and column of first matrix");
    scanf("%d %d",&m1,&n1);
    printf("enter row and column of second matrix");
    scanf("%d %d",&m2,&n2);
    int a[m1][n1],b[m2][n2];
    int c[m1][n2],i,j,k;
    if(n1==m2){
       // element of first matrix
       printf("element of first matrix\n");
       for(i=0;i<m1;i++)
       {
         for(j=0;j<n1;j++)
            scanf("%d",&a[i][j]);
       }
       printf("enter element of second matrix\n");
       for(i=0;i<m2;i++)
      {
        for(j = 0; j < n2; j++)
           scanf("%d",&b[i][j]);     
      }     
        
        
      

    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            c[i][j]=0;
            for(k=0;k<m2;k++)
              c[i][j]+=a[i][k]*b[k][j];
        }
        
    }
   printf("first matrix-->\n");
   for(i=0;i<m1;i++)
   {
      for(j=0;j<n1;j++)
          printf("%d ",a[i][j]);
        printf("\n");
   }
   printf("second matrix-->\n");
   for(i=0;i<m2;i++)
   {
       for(j=0;j<n2;j++)
          printf("%d ",b[i][j]);
        printf("\n");
          
       
   }
   printf("multiplication-->\n");
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
          printf("%d ",c[i][j]);
        printf("\n");
    }
    }
    else
       printf("multiplication not posssible");
     


   return 0;
    
}