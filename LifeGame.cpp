#include "stdio.h"
#include "string.h"
#include "windows.h"
#include <iostream>
#include <time.h>
#define High 20  //游戏尺寸
#define Width 40
int cellsmap[High][Width]; 
int newcellsmap[High][Width];   
void rawdate()  //游戏数据初始化
{
	srand((unsigned)time(NULL)); //srand()就是给rand()提供种子seed 
    int i,j;
    for(i=0;i<High+1;i++)
        for(j=0;j<Width+1;j++)
           cellsmap[i][j]=rand()%2;   //细胞初始状态随机
} 
void RunLifeGame()   //进行游戏
{
	int i,j,s=0;
    while(1)
    {   system("cls"); 
        for(i=1;i<High;i++)
        {
            for(j=1;j<Width;j++)
                if(cellsmap[i][j]==1)
                    printf("■");
                else if(cellsmap[i][j]==0)
                    printf("□");
            printf("\n");
        }
        for(i=1;i<High;i++)
            for(j=1;j<Width;j++)
            {     /*计算一个细胞周围8个格子内的活细胞总量*/ 
                s=cellsmap[i-1][j-1]+cellsmap[i-1][j]+cellsmap[i-1][j+1]+cellsmap[i][j-1]+cellsmap[i][j+1]+cellsmap[i+1][j-1]+cellsmap[i+1][j]+cellsmap[i+1][j+1];
				if(cellsmap[i][j]==1)   //如果细胞为生 
                {
                    if(s<2)
                        newcellsmap[i][j]=0; //如果周围活细胞少于2个，该细胞下一代转为死细胞
                    else if(s>3)
                        newcellsmap[i][j]=0; //如果周围活细胞超过3个，该细胞下一代转为死细胞
                    else if(s==2||s==3)
                        newcellsmap[i][j]=1; //如果周围活细胞为2个或3个，该细胞下一代状态不变 
                    }     
                else if(cellsmap[i][j]==0)  //如果细胞为死 
                {
                    if(s==3)
                        newcellsmap[i][j]=1;  //如果周围活细胞为3个，该细胞下一代转为活细胞,其它情况状态不变 
                    else
                        newcellsmap[i][j]=0;
                }
            }
		for(i=1;i<High;i++)
            for(j=1;j<Width;j++)
                cellsmap[i][j]=newcellsmap[i][j];	
	   Sleep(1000);  
    } 
}
int main()
{
    system("color f0");
    rawdate();
    RunLifeGame();
}



