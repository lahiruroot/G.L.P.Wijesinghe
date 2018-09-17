#include<stdio.h>


int main()
{
    int park[2][2];
    int i, j;
    printf("Enter car number: \n");
    for(i=0; i<2; i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&park[i][j]);
        }
    }
    printf("\n");
    for(i=0; i<2; i++)
    {
        for(j=0;j<2;j++)
        {
            printf("\t%d",park[i][j]);
        }
    printf("\n");
    }
}
