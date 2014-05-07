#include "stdio.h"
#define MAX 99999
#define Num 5
int dijkstra(int argc, _TCHAR* argv[])
{
 int G[Num][Num]=
 {
 {MAX,－1, 3 ,MAX,MAX},
 {MAX,MAX, 3 , 2 , 2},
 {MAX,MAX,MAX,MAX,MAX},
 {MAX, 1 , 5 ,MAX,MAX},
 {MAX,MAX,MAX,－3,MAX},
 };
 int P[6][6];
 int D[6];
 int final[6];
 int v;
 int w;
 //int G[6][6]={1000,};
 for(int v=0;v<6;++v)
 {
  final[v] = false;
        D[v] = G[0][v];
        for(w = 0; w < 6; ++w)
        P[v][w] = false;
        if(D[v] < MAX)
  {

   P[v][0] = true;
   P[v][v] = true;
  } 
 } 
 D[0] = 0;
 final[0] = true;   
 for(int i = 1; i < 6; ++ i)
 {
  int min = MAX; 
  for(w = 0; w < 6; ++ w)
   if(!final[w])
    if(D[w] < min)
    {
     v = w; 
     min = D[w];
    }
    final[v] = true; 

    for(w = 0; w < 6; ++ w)
     if(!final[w] && (min + G[v][w] < D[w]))
     {
      D[w] = min + G[v][w] ;
      P[w][0] = P[v][0];
      P[w][w] = true;
     } 
 } 

  
   
    for(int i=0;i<6;i++)
    {
        printf("0到顶点%d的最短路径为:\n",i);
        for(int j=0;j<6;j++)
            printf("%d ",P[i][j]);
        printf("代价为:%d\n",D[i]);
        printf("\n");
    }
 return 0;
}