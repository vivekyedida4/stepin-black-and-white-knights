#include<stdio.h>
#include<stdlib.h>
#define 	RESET 0
int sudokusolver();
int findemptycell();
int isvalid();
void printgrid();
void inputgrid();
int grid[9][9]={
{0,5,4,0,0,0,0,8,0},
{0,0,0,8,4,0,0,2,6},
{0,8,0,0,0,0,4,0,0},
{0,0,6,3,0,0,5,0,0},
{1,0,0,0,0,0,0,0,3},
{0,0,8,0,0,2,9,0,0},
{0,0,3,0,0,0,0,1,0},
{8,2,0,0,7,1,0,0,0},
{0,4,0,0,0,0,6,5,0},
};
int row,col;
//this variable was used just to keep track of number of recursive calls
long int totalnumofcalls=0;
void main()
{
int i,j,solution=0;
char ch;
printf("you can change the puzzle before running the programme \nby changing the values in the \"grid\"array\n\n");
printf("the entered sudoko puzzle is :\n");
printgrid();
printf("press 'c' to confirm and solve, or 'e' to exit : ");
ch=getchar();
if(ch=='e')
exit(0);
else if(ch=='c')
{
solution=sudokosolver();
if(solution)
{
printf("\nThe solved sudoko is : \n\n");
printgrid();
}
else
print("\nNo possible solution!!\n\n");
}
}
int findemptycell()
{
int i,j;
for(i=row;i<=8;i++)
for(j=0;j<=8;j++)
{
if(grid[i][j]==0)
{
row=i;col=j;
return 1;
}
}
return 0;
}
int isvalid(int cellrow,int cellcol,int num)
{
int i,j,trow,tcol,trow1,tcol1;
int rowstart=(cellrow/3)*3;
int colstart=(cellcol/3)*3;
//to check the presence of the number in row and colum
for(j=0;j<=8;j++)
{
if(grid[cellrow][j]==num)
return 0;
if(grid[j])
if(grid[j][cellcol]==num)
return 0;
}
//to check the presence of number in 3x3 box
for(i=rowstart;i<=rowstart+2;i++)
for(j=colstart;j<=colstart+2;j++)
if(grid[i][j]==num)
return 0;
return 1;
}
int sudokusolver()
{
int digit;
int prevrow,prevcol;
//for backtracking
totalnumofcalls++;
if(!findemptycell())
return 1;
for(digit=1;digit<=9;digit++)
{
if(isvalid(row,col,digit))
{
grid[row][col]=digit;
prevrow=row;prevcol=col;
if (sudokusolver())
return 1;
//while backtracking assigning previous values to row and column
row=prevrow;
col=prevcol;
grid[row][col]=RESET;
}

return 0;
}
void printgrid()
{
int i,j;
printf("\t----------------\n");
for(i=0;i<9;i++)
{
printf("\t");
for(j=0;j<9;j++)
{
if(j==0)
printf("| ");
if(grid[i][j]==0)
printf(". ");
else
printf("%d",grid[i][j]);
if((j+1)%3==0)
printf("| ");
}
if((i+1)%3==0)
{
printf("\n\t--------------------");
printf("\n");
}
}
}


