#include "stdio.h"
#include "string.h"
#include "windows.h"
#include <iostream>
#include <time.h>
#define HIGH 20  //��Ϸ�ߴ�
#define WIDTH 40
  
int CellsMap[HIGH][WIDTH]; //��ʼ״̬ϸ����ͼ 
int NewCellsMap[HIGH][WIDTH]; //��һ��ϸ����ͼ
  
void RawDate()   //��Ϸ���ݳ�ʼ��
{
     srand((unsigned)time(NULL)); //srand()���Ǹ�rand()�ṩ����seed 
     int i,j;
     for(i=0;i<HIGH+1;i++)
         for(j=0;j<WIDTH+1;j++)
            CellsMap[i][j]=rand()%2;   //ϸ����ʼ״̬���
 } 
 
void RunLifeGame()    //������Ϸ
{
     int i,j,s=0;
     while(1)
     {   system("cls"); 
         for(i=1;i<HIGH;i++)  //��ӡ��ʼ״̬ϸ����ͼ 
         {
             for(j=1;j<WIDTH;j++)
                 if(CellsMap[i][j]==1)
                     printf("��");
                 else if(CellsMap[i][j]==0)
                    printf("��");
             printf("\n");
         }
         for(i=1;i<HIGH;i++)
             for(j=1;j<WIDTH;j++)
             {     /*����һ��ϸ����Χ8�������ڵĻ�ϸ������*/ 
                 s=CellsMap[i-1][j-1]+CellsMap[i-1][j]+CellsMap[i-1][j+1]+CellsMap[i][j-1]+CellsMap[i][j+1]+CellsMap[i+1][j-1]+CellsMap[i+1][j]+CellsMap[i+1][j+1];
                   if(s==3)            //��Χ��3����ϸ��ʱ����ϸ����һ��תΪ��ϸ�� 
                      NewCellsMap[i][j]=1;
                  else if(s==2)       //��Χ��2����ϸ��ʱ����ϸ����һ��״̬����
                      NewCellsMap[i][j]=CellsMap[i][j];
                  else
                      NewCellsMap[i][j]=0;  //�������ʱ����ϸ����һ��תΪ��ϸ��
             }
         for(i=1;i<HIGH;i++)  //��ӡ��һ��ϸ����ͼ 
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
