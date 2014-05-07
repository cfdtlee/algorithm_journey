
#include<stdio.h>
#define full 100
#define N 5
int cost[N][full];
int knapsack(int m,int n);
int main()
{
    int m,n;int i,j;
    printf("%d",knapsack(m,n));
    printf("\n");
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            printf("%d ",cost[i][j]);
            
        }

}


int knapsack(int m,int n)
{
    int i,j,weight[N],value[N];
    
    value[0] = 20, value[1] = 30, value[2] = 65, value[3] = 40, value[4] = 60;
    weight[0] = 10, weight[1] = 20, weight[2] = 30, weight[3]= 40, weight[4] = 50;

    for(i=0;i<N;i++)
        for(j=0;j<full;j++)
            cost[i][j]=0;
    for(i=1;i<n+1;i++)
        for(j=1;j<m+1;j++)
        {
            if(weight[i]<=j){
                if(value[i]+cost[i-1][j-weight[i]]>cost[i-1][j])
                    cost[i][j]=value[i]+cost[i-1][j-weight[i]];
                else
                    cost[i][j]=cost[i-1][j];
            }else
                cost[i][j]=cost[i-1][j];
        }
    return(cost[n][m]);
}