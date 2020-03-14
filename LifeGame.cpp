#define High 20  //游戏尺寸
#define Width 40
int cellsmap[High][Width]; 
int newcellsmap[High][Width];   
void rawdate()  //游戏数据初始化
{
    int i,j;
    for(i=0;i<High+1;i++)
        for(j=0;j<Width+1;j++)
            cellsmap[i][j]=1;   //细胞初始化状态为活细胞 
}
void RunLifeGame()   //进行游戏
{
	int i,j,s=0;
    while(1)
    {
        for(i=1;i<High;i++)
        {
            for(j=1;j<Width;j++)
                if(cellsmap[i][j]==1)
                    printf("█");
                else if(cellsmap[i][j]==0)
                    printf("  ");
            printf("\n");
        }
        for(i=1;i<High;i++)
            for(j=1;j<Width;j++)
            {     /*计算一个细胞周围8个格子内的活细胞总量*/ 
                s=cellsmap[i-1][j-1]+cellsmap[i-1][j]+cellsmap[i-1][j+1]+cellsmap[i][j-1]+cellsmap[i][j+1]+cellsmap[i+1][j-1]+cellsmap[i+1][j]+cellsmap[i+1][j+1];
			}
	}
}
int main()
{
    
}



