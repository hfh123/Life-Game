#include "stdio.h"
#include "string.h"
#include "windows.h"
#define High 20  //��Ϸ�ߴ�
#define Width 40
int cellsmap[High][Width]; 
int newcellsmap[High][Width];   
void rawdate()  //��Ϸ���ݳ�ʼ��
{
    int i,j;
    for(i=0;i<High+1;i++)
        for(j=0;j<Width+1;j++)
            cellsmap[i][j]=1;   //ϸ����ʼ��״̬Ϊ��ϸ�� 
}
void RunLifeGame()   //������Ϸ
{
	int i,j,s=0;
    while(1)
    {
        for(i=1;i<High;i++)
        {
            for(j=1;j<Width;j++)
                if(cellsmap[i][j]==1)
                    printf("��");
                else if(cellsmap[i][j]==0)
                    printf("  ");
            printf("\n");
        }
        for(i=1;i<High;i++)
            for(j=1;j<Width;j++)
            {     /*����һ��ϸ����Χ8�������ڵĻ�ϸ������*/ 
                s=cellsmap[i-1][j-1]+cellsmap[i-1][j]+cellsmap[i-1][j+1]+cellsmap[i][j-1]+cellsmap[i][j+1]+cellsmap[i+1][j-1]+cellsmap[i+1][j]+cellsmap[i+1][j+1];
				if(cellsmap[i][j]==1)   //���ϸ��Ϊ�� 
                {
                    if(s<2)
                        newcellsmap[i][j]=0; //�����Χ��ϸ������2������ϸ����һ��תΪ��ϸ��
                    else if(s>3)
                        newcellsmap[i][j]=0; //�����Χ��ϸ������3������ϸ����һ��תΪ��ϸ��
                    else if(s==2||s==3)
                        newcellsmap[i][j]=1; //�����Χ��ϸ��Ϊ2����3������ϸ����һ��״̬���� 
                    }     
                else if(cellsmap[i][j]==0)  //���ϸ��Ϊ�� 
                {
                    if(s==3)
                        newcellsmap[i][j]=1;  //�����Χ��ϸ��Ϊ3������ϸ����һ��תΪ��ϸ��,�������״̬���� 
                    else
                        newcellsmap[i][j]=0;
                }
            }
		for(i=1;i<High;i++)
            for(j=1;j<Width;j++)
                cellsmap[i][j]=newcellsmap[i][j];	
	}
}
int main()
{
    system("color f0");
    rawdate();
    RunLifeGame();
}



