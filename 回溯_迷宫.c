#include <stdio.h>

typedef enum
{
    false,
    true
} bool;

#define ROW 5
#define COL 5

//假设当前迷宫中没有起点到终点的路线
bool find = false;

//输出行走路线
void printmaze(char maze[ROW][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

//判断 (row,col) 区域是否可以移动
//判断 (row,col) 区域是否可以移动
bool canMove(char maze[ROW][COL], int row, int col)
{
    //如果目标区域位于地图内，不是黑色区域，且尚未行走过，返回 true：反之，返回 false
    return (row >= 0 && row <= ROW - 1) && (col >= 0 && col <= COL - 1) && (maze[row][col] != '0' && maze[row][col] != 'Y');
}

//回溯算法查找可行路线
//(row,col) 表示起点，(outrow,outcol)表示终点
void maze_puzzle(char maze[ROW][COL], int row, int col, int outrow, int outcol)
{
    maze[row][col] = 'Y'; // 将各个走过的区域标记为 Y
    //如果行走至终点，表明有从起点到终点的路线
    if (row == outrow && col == outcol)
    {
        find = true;
        printf("成功走出迷宫,路线图为：\n");
        printmaze(maze);
        return;
    }
    //尝试向上移动
    if (canMove(maze, row - 1, col))
    {
        maze_puzzle(maze, row - 1, col, outrow, outcol);
        //如果程序不结束，表明此路不通，恢复该区域的标记
        maze[row - 1][col] = '1';
    }
    //尝试向左移动
    if (canMove(maze, row, col - 1))
    {
        maze_puzzle(maze, row, col - 1, outrow, outcol);
        //如果程序不结束，表明此路不通，恢复该区域的标记
        maze[row][col - 1] = '1';
    }
    //尝试向下移动
    if (canMove(maze, row + 1, col))
    {
        maze_puzzle(maze, row + 1, col, outrow, outcol);
        //如果程序不结束，表明此路不通，恢复该区域的标记
        maze[row + 1][col] = '1';
    }
    //尝试向右移动
    if (canMove(maze, row, col + 1))
    {
        maze_puzzle(maze, row, col + 1, outrow, outcol);
        //如果程序不结束，表明此路不通，恢复该区域的标记
        maze[row][col + 1] = '1';
    }
}

int main()
{
    char maze[ROW][COL] = {
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'1', '0', '0', '1', '0'},
        {'1', '0', '0', '1', '1'}};

    maze_puzzle(maze, 0, 0, ROW - 1, COL - 1);

    if (find == false)
    {
        printf("未找到可行线路");
    }

    return 0;
}