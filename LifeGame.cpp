#include "stdio.h"
#include "string.h"
#include "windows.h"
#include <iostream>
#include <time.h>
#define HIGH 20  //游戏尺寸
#define WIDTH 40
  
int CellsMap[HIGH][WIDTH]; //初始状态细胞地图 
int NewCellsMap[HIGH][WIDTH]; //下一代细胞地图
  
void RawDate()   //游戏数据初始化
{
     srand((unsigned)time(NULL)); //srand()就是给rand()提供种子seed 
     int i,j;
     for(i=0;i<HIGH+1;i++)
         for(j=0;j<WIDTH+1;j++)
            CellsMap[i][j]=rand()%2;   //细胞初始状态随机
 } 
 
void RunLifeGame()    //进行游戏
{
     int i,j,s=0;
     while(1)
     {   system("cls"); 
         for(i=1;i<HIGH;i++)  //打印初始状态细胞地图 
         {
             for(j=1;j<WIDTH;j++)
                 if(CellsMap[i][j]==1)
                     printf("■");
                 else if(CellsMap[i][j]==0)
                    printf("□");
             printf("\n");
         }
         for(i=1;i<HIGH;i++)
             for(j=1;j<WIDTH;j++)
             {     /*计算一个细胞周围8个格子内的活细胞总量*/ 
                 s=CellsMap[i-1][j-1]+CellsMap[i-1][j]+CellsMap[i-1][j+1]+CellsMap[i][j-1]+CellsMap[i][j+1]+CellsMap[i+1][j-1]+CellsMap[i+1][j]+CellsMap[i+1][j+1];
                   if(s==3)            //周围有3个活细胞时，该细胞下一代转为生细胞 
                      NewCellsMap[i][j]=1;
                  else if(s==2)       //周围有2个活细胞时，该细胞下一代状态不变
                      NewCellsMap[i][j]=CellsMap[i][j];
                  else
                      NewCellsMap[i][j]=0;  //其它情况时，该细胞下一代转为死细胞
             }
         for(i=1;i<HIGH;i++)  //打印新一轮细胞地图 
             for(j=1;j<WIDTH;j++)
                 CellsMap[i][j]=NewCellsMap[i][j];    
        Sleep(1000);  
     } 
}
 
int main()
{
    system("color f0");
    RawDate();
    RunLifeGame();
}
