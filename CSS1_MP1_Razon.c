#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
/*Globals*/
#define HEIGHT 39
#define WIDTH 19
#define HEIGHT2 59
#define WIDTH2 59
#define ALIVE 1
#define DEAD 0
typedef int arrayTable[60][60];
int grid;
arrayTable tableprint;
char menuChoice;
int neighbor;

void randomCreature1(arrayTable table);
void randomCreature2(arrayTable table);
int GameOfLife();
void clearScreen();
int iLoveGameOfLife();
void setZero(arrayTable table);
void printTable1(arrayTable table);
void printTable2(arrayTable table);
int gridChoice(arrayTable tableprint);
int gridChoice2(arrayTable tableprint);
void loadPentomino1(arrayTable table);
void loadPentomino2(arrayTable table);
void loadOscillator1(arrayTable table);
void loadOscillator2(arrayTable table);
void loadStillLife1(arrayTable table);
void loadStillLife2(arrayTable table);
void calculate(arrayTable tableA, int grid);
void enterButton(arrayTable table, int grid);
void creatureChoice(char menuChoice, int grid);
int neighborValue(arrayTable table, int row, int col, int grid);
int countNeighbor(arrayTable table, int row, int col, int grid);
void chooseCreature();
int main()
{

	iLoveGameOfLife();
	return 0;
}

/*The rest of the functions here below */
int GameOfLife()
{
	int grid;
	arrayTable tableprint;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t        Choose your own specific 2-dimensional grid: \n\n");
	printf("\n\t\t\t\t\t\t\t\t\t      1 -- 40x20 grid\n\n\n\t\t\t\t\t\t\t\t\t      2 -- 60x60 grid\n\n");
	printf("\n\t\t\t\t\t\t\t\t\t      Enter here:");
	scanf("%d", &grid);

	clearScreen();
	switch (grid)
	{
		case 1: gridChoice(tableprint);
				chooseCreature();
				creatureChoice(menuChoice,grid);
				break;
		case 2: gridChoice2(tableprint);
				chooseCreature();
				creatureChoice(menuChoice,grid);
				break;
		default: break;
	}



	return grid;
}
void chooseCreature()
{
	printf("_________________________________________"); printf("\t\t\t\t    THIS IS YOUR GRID!\n");
	printf("You can choose one of the options below: |\n");
	printf("a) -- Random\t\t\t\t |\nb) -- Still life\t\t\t |\nc) -- Oscillators\t\t\t |\nd) -- R-pentomino\t\t\t |\n");
	printf("_________________________________________|");
	printf("Enter here:");
	
	scanf("\n%c", &menuChoice);
}
void creatureChoice(char menuChoice, int grid)
{
	arrayTable table;

	if(menuChoice == 'd' || menuChoice == 'D'){
		if(grid == 1)
		{
		setZero(table);
		clearScreen();
		loadPentomino1(table);
		printTable1(table);
		printf("\nPress any key to proceed to next generation (except X and R)\nPress X to exit\nPress R to go back to menu");
		enterButton(table,grid);
		}
		else if (grid == 2)
		{
		setZero(table);
		clearScreen();
		loadPentomino2(table);
		printTable2(table);
		printf("\nPress any key to proceed to next generation (except X and R)\nPress X to exit\nPress R to go back to menu");
		enterButton(table,grid);
		}
	}
	if(menuChoice == 'c' || menuChoice == 'C')
	{
		if(grid == 1)
		{
		setZero(table);
		clearScreen();
		loadOscillator1(table);
		printTable1(table);
		printf("\nPress any key to proceed to next generation (except X and R)\nPress X to exit\nPress R to go back to menu");
		enterButton(table,grid);
		} else if (grid == 2)
		{
		setZero(table);
		clearScreen();
		loadOscillator2(table);
		printTable2(table);
		printf("\nPress any key to proceed to next generation (except X and R)\nPress X to exit\nPress R to go back to menu");
		enterButton(table,grid);
		}
	}
	if(menuChoice == 'b' || menuChoice == 'B')
	{
		if(grid == 1)
		{
		setZero(table);
		clearScreen();
		loadStillLife1(table);
		printTable1(table);
		printf("\nPress any key to proceed to next generation (except X and R)\nPress X to exit\nPress R to go back to menu");
		enterButton(table,grid);
		} else if (grid == 2)
		{
		setZero(table);
		clearScreen();
		loadStillLife2(table);
		printTable2(table);
		printf("\nPress any key to proceed to next generation (except X and R)\nPress X to exit\nPress R to go back to menu");
		enterButton(table,grid);
		}
	}
	if(menuChoice == 'a' || menuChoice == 'A')
	{
		clearScreen();
		if(grid == 1)
		{
				setZero(table);
				clearScreen();
				randomCreature1(table);
				printTable1(table);
				printf("\nPress any key to proceed to next generation (except X and R)\nPress X to exit\nPress R to go back to menu");
				enterButton(table,grid);
			
		}
		else if (grid == 2)
		{
				setZero(table);
				clearScreen();
				randomCreature2(table);
				printTable2(table);
				printf("\nPress any key to proceed to next generation (except X and R)\nPress X to exit\nPress R to go back to menu");
			enterButton(table,grid);
		}
	}
}



int gridChoice(arrayTable tableprint)
{
	int height, width;
	arrayTable table;
	setZero(table);			

		for (height = 0; height <=HEIGHT; height++)
		{
			for (width = 0; width <=WIDTH; width++)
			{
				if(height<=40 && width == 0)
				{
					printf("\t\t\t\t\t\t\t\t\t  |");
				}
					printf(".");
				if (height<=40 && width == 19)
					printf("|");

			


				
			}
			printf("\n");
		}
		printf("\n");

	
return 0;
}

int gridChoice2(arrayTable tableprint)
{
	int height, width;
	arrayTable table;
	setZero(table);			

		for (height = 0; height <=HEIGHT2; height++)
		{
			for (width = 0; width <=WIDTH2; width++)
			{
				if(height<=60 && width == 0)
				{
					printf("\t\t\t\t\t\t        |");
				}


				printf(".");
				if (height<=60 && width == 59)
					printf("|");
				
			}
			printf("\n");
		}
		printf("\n");
return 0;
}

void clearScreen() {
system("@cls||clear");
}

void printTable1(arrayTable table) {
	int height, width;

	for (height = 0; height <=HEIGHT; height++) {
		for (width = 0; width <=WIDTH; width++)
		{
			if(height<=40 && width == 0)
				{
					printf("\t\t\t\t\t\t\t\t          |");
				}
			if (table[height][width] == ALIVE)
			{
				printf("*");
			} else {
				printf(" ");
			}
			if (height<=40 && width == 19)
					printf("|");
		}
			printf("\n");
	}
		printf("\n");
}

void printTable2(arrayTable table) {
	int height, width;

	for (height = 0; height <=HEIGHT2; height++) {
		for (width = 0; width <=WIDTH2; width++) {
			if(height<=60 && width == 0)
				{
					printf("\t\t\t\t\t\t        |");
				}
			if (table[height][width] == ALIVE) {
				printf("*");
			} else {
				printf(" ");
			}
			if (height<=60 && width == 59)
					printf("|");
		}
		printf("\n");
	}
	printf("\n");
}

int neighborValue(arrayTable table, int row, int col, int grid) {
		if (grid == 1)
	{
		if (row < 0 || row >= HEIGHT|| col < 0 || col >= WIDTH || table[row][col] != ALIVE)
			{
				return 0;
			}
			 else 
			{
				return 1;
			}
	}

	else if (grid ==2)
	{
		if (row < 0 || row >= HEIGHT2 || col < 0 || col >= WIDTH2 || table[row][col] != ALIVE)
	{
		return 0;
	} 
		else
		return 1;

	}
		return 0;
}
int countNeighbor(arrayTable table, int row, int col, int grid)
{
	int neighbor = 0;

	neighbor += neighborValue(table, row - 1, col - 1, grid);
	neighbor += neighborValue(table, row - 1, col,grid);
	neighbor += neighborValue(table, row - 1, col + 1,grid);
	neighbor += neighborValue(table, row, col - 1,grid);
	neighbor += neighborValue(table, row, col + 1,grid);
	neighbor += neighborValue(table, row + 1, col - 1,grid);
	neighbor += neighborValue(table, row + 1, col + 1,grid);
	neighbor += neighborValue(table, row + 1, col,grid);

	return neighbor;
}

void calculate(arrayTable tableA, int grid) {
	arrayTable tableB;
	int height, width;
	if (grid == 1){
	for (height = 0; height < HEIGHT; height++) {
		for (width = 0; width < WIDTH; width++) {
			neighbor = countNeighbor(tableA, height, width, grid);
			if (neighbor==3) {
				tableB[height][width] = ALIVE;
			} else if (neighbor == 2 && tableA[height][width] == ALIVE) {
				tableB[height][width] = ALIVE;
			} else {
				tableB[height][width] = DEAD;
			}
		}
	}

	for (height = 0; height < HEIGHT; height++) {
		for (width = 0; width < WIDTH; width++) {
			tableA[height][width] = tableB[height][width];
		}
	}
} else if (grid == 2)
{
	for (height = 0; height < HEIGHT2; height++) {
		for (width = 0; width < WIDTH2; width++) {
			neighbor = countNeighbor(tableA, height, width, grid);
			if (neighbor==3) {
				tableB[height][width] = ALIVE;
			} else if (neighbor == 2 && tableA[height][width] == ALIVE) {
				tableB[height][width] = ALIVE;
			} else {
				tableB[height][width] = DEAD;
			}
		}
	}
for (height = 0; height < HEIGHT2; height++) {
		for (width = 0; width < WIDTH2; width++) {
			tableA[height][width] = tableB[height][width];
		}
	}
}
}

void loadPentomino1(arrayTable table) {
	int x,y,z;
	int i,j;
	time_t t;
	srand((unsigned)time(&t));
	x = rand()%18;
	z = rand()%38;
	y = rand()%5;
	for(i=0; i<40; i++)
	{
		for(j=0; j<20; j++)
			{
				if(table[i][j] != ALIVE)
					{
						if(y > 3)
							{
							table[x][x] = ALIVE;
							table[x][x+1] = ALIVE;
							table[x+1][x-1] = ALIVE;
							table[x+1][x] = ALIVE;
							table[x+2][x] = ALIVE;
							} 
						else
							{
							table[z][x] = ALIVE;
							table[z][x+1] = ALIVE;
							table[z+1][x-1] = ALIVE;
							table[z+1][x] = ALIVE;
							table[z+2][x] = ALIVE;
							}
					}
}
}
}
void loadPentomino2(arrayTable table) {
	int x,i,j;
	time_t t;
	srand((unsigned)time(&t));
	x = rand()%58;
	for(i=0; i<60; i++)
	{
		for(j=0; j<60; j++)
			{
				if(table[i][j] != ALIVE)
					{
	table[x][x] = ALIVE;
	table[x][x+1] = ALIVE;
	table[x+1][x-1] = ALIVE;
	table[x+1][x] = ALIVE;
	table[x+2][x] = ALIVE;
}
}
}
}
void loadOscillator1(arrayTable table) {
	int x,y,z;
	int a,b;
	int i,j;

	srand((unsigned)time(NULL));
	x = rand()%18;
	z = rand()%38;
	a = rand()%18;
	b = rand()%38;
	y = rand()%20;

	for(i=0; i<40; i++)
	{
		for(j=0; j<20; j++)
			{
				if(table[i][j] != ALIVE )
					{
						if(y > 10)
						{
						table[x][x] = ALIVE;
						table[x][x+1] = ALIVE;
						table[x][x+2] = ALIVE;
						} else
						{
						table[z][x] = ALIVE;
						table[z+1][x] = ALIVE;
						table[z+2][x] = ALIVE;
						}
					}
			}
	}

for(i=0; i<40; i++)
	{
		for(j=0; j<20; j++)
			{
				if(table[i][j] != ALIVE)
					{
						if(y <= 5)
						{
							if(table[a][a-2])
								{
								table[a][a] = ALIVE;
								table[a][a+1] = ALIVE;
								table[a][a+2] = ALIVE;
								}		
						} else
						{
						table[b][a] = ALIVE;
						table[b+1][a] = ALIVE;
						table[b+2][a] = ALIVE;
						}
					}
			}
	}
}

void loadOscillator2(arrayTable table) {
	int x,y,z;
	int i,j;

	srand((unsigned)time(NULL));
	x = rand()%58;
	z = rand()%58;
	y = rand()%20;

	for(i=0; i<60; i++)
	{
		for(j=0; j<60; j++)
			{
				if(table[i][j] != ALIVE)
					{
						if(y > 10)
						{
						table[x][x] = ALIVE;
						table[x][x+1] = ALIVE;
						table[x][x+2] = ALIVE;
						} else
						{
						table[x][x] = ALIVE;
						table[x+1][x] = ALIVE;
						table[x+2][x] = ALIVE;
						}
					}
				}
			}

for(i=0; i<60; i++)
	{
		for(j=0; j<60; j++)
			{
				if(table[i][j] != ALIVE)
					{
						if(y <= 10)
						{
						table[z][z] = ALIVE;
						table[z][z+1] = ALIVE;
						table[z][z+2] = ALIVE;
						} else
						{
						table[z][z] = ALIVE;
						table[z+1][z] = ALIVE;
						table[z+2][z] = ALIVE;
						}
					}
				}
			}
}

void loadStillLife1(arrayTable table) {
	int x,y,z,q,e;
	int a,b,c,w,r;
	time_t t;
	srand((unsigned)time(&t));
	x = rand()%39;
	a = rand()%19;
	y = rand()%37;
	b = rand()%19;
	z = rand()%38;
	c = rand()%19;
	q = rand()%38;
	w = rand()%19;
	e = rand()%37;
	r = rand()%18;



	if(table[x][a+1] == 0 && table[x][a-1] == 0
	 && table[x][a-2] == 0 && table[x+1][a+2] == 0 && 
	 table[x+1][a+2] == 0 && table[x+1][a] == 0 && 
	 table[x-1][a] == 0 && table[x-1][a+1] == 0
	 && table[x][a+2] == 0)
		{
		table[x][a] = ALIVE;
		table[x][a+1] = ALIVE;
		table[x+1][a] = ALIVE;
		table[x+1][a+1] = ALIVE;
		}	else { 
			table[x][a] = ALIVE;
		table[x][a+1] = ALIVE;
		table[x+1][a] = ALIVE;
		table[x+1][a+1] = ALIVE;
		}
	if(table[y][b-2] == 0 && table[y+3][b+2] == 0 &&
		table[y][b+1] == 0 && table[y][b-1] == 0
	 && table[y][b-2] == 0 && table[y+1][b+2] == 0 && 
	 table[y+1][b+2] == 0 && table[y+1][b] == 0 && 
	 table[y-1][b] == 0)
		{
		table[y][b] = ALIVE;
		table[y+1][b-1] = ALIVE;
		table[y+1][b+1] = ALIVE;
		table[y+2][b-1] = ALIVE;
		table[y+2][b+1] = ALIVE;
		table[y+3][b] = ALIVE;
		} else {
		table[y][b] = ALIVE;
		table[y+1][b-1] = ALIVE;
		table[y+1][b+1] = ALIVE;
		table[y+2][b-1] = ALIVE;
		table[y+2][b+1] = ALIVE;
		table[y+3][b] = ALIVE;
		}
	if(table[z][c-2] == 0 && table[z+2][c+3] ==0 &&
		table[z][c+1] == 0 && table[z][c-1] == 0
	 && table[z][c-2] == 0 && table[z+1][c+2] == 0 && 
	 table[z+1][c+2] == 0 && table[z+1][c] == 0 && 
	 table[z-1][c] == 0 && table[z-1][c+1] == 0
	 && table[z][c+2] == 0)
		{			
		table[z][c] = ALIVE;
		table[z+1][c-1] = ALIVE;
	    table[z+1][c+1] = ALIVE;
		table[z+2][c] = ALIVE;
		table[z+2][c+1] = ALIVE;
		} else {			
		table[z][c] = ALIVE;
		table[z+1][c-1] = ALIVE;
	    table[z+1][c+1] = ALIVE;
		table[z+2][c] = ALIVE;
		table[z+2][c+1] = ALIVE;
		} 
	if(table[q][w-2] == 0 && table[q+2][w+3] == 0 &&
		table[q][w-2] == 0 && table[q+3][w+2] == 0 &&
		table[q][w+1] == 0 && table[q][w-1] == 0
	 && table[q][w-2] == 0 && table[q+1][w+2] == 0 && 
	 table[q+1][w+2] == 0 && table[q+1][w] == 0 && 
	 table[q-1][w] == 0)
		{
		table[q][w-1] = ALIVE;
		table[q][w] = ALIVE;
		table[q+1][w-1] = ALIVE;
		table[q+1][w+1] = ALIVE;
		table[q+2][w] = ALIVE;
		table[q+2][w+1] = ALIVE;						
		} else {
		table[q][w-1] = ALIVE;
		table[q][w] = ALIVE;
		table[q+1][w-1] = ALIVE;
		table[q+1][w+1] = ALIVE;
		table[q+2][w] = ALIVE;
		table[q+2][w+1] = ALIVE;						
		} 
	if(table[e][r-2] == 0 && table[e+3][r+2] == 0 &&
		table[e][r-2] == 0 && table[e+2][r+3] == 0 &&
		table[e][r-2] == 0 && table[e+3][r+2] == 0 &&
		table[e][r+1] == 0 && table[e][r-1] == 0
	 && table[e][r-2] == 0 && table[e+1][r+2] == 0 && 
	 table[e+1][r+2] == 0 && table[e+1][r] == 0 && 
	 table[e-1][r] == 0)
		{
		table[e][r] = ALIVE;
		table[e][r+1] = ALIVE;
		table[e+1][r-1] = ALIVE;
		table[e+1][r+2] = ALIVE;
		table[e+2][r] = ALIVE;
		table[e+2][r+2] = ALIVE;
		table[e+3][r+1] = ALIVE;
		} else {
		table[e][r] = ALIVE;
		table[e][r+1] = ALIVE;
		table[e+1][r-1] = ALIVE;
		table[e+1][r+2] = ALIVE;
		table[e+2][r] = ALIVE;
		table[e+2][r+2] = ALIVE;
		table[e+3][r+1] = ALIVE;
		}
				

}


void loadStillLife2(arrayTable table) {
	int x,y,z,q,e;
	int a,b,c,w,r;
	int i,j;
time_t t;
	srand((unsigned)time(&t));
	x = rand()%58;
	a = rand()%58;
	y = rand()%57;
	b = rand()%58;
	z = rand()%58;
	c = rand()%58;
	q = rand()%58;
	w = rand()%58;
	e = rand()%57;
	r = rand()%58;
					for(i=0; i<60; i++)
					{
						for(j=0; j<60; j++)
							{
								if(table[i][j] != ALIVE)
									{
										table[x][a] = ALIVE;
										table[x][a+1] = ALIVE;
										table[x+1][a] = ALIVE;
										table[x+1][a+1] = ALIVE;
									}
							}
					}
						for(i=0; i<60; i++)
						{
							for(j=0; j<60; j++)
								{
									if(table[i][j] != ALIVE)
										{
											table[y][b] = ALIVE;
											table[y+1][b-1] = ALIVE;
											table[y+1][b+1] = ALIVE;
											table[y+2][b-1] = ALIVE;
											table[y+2][b+1] = ALIVE;
											table[y+3][b] = ALIVE;
										}
								}
						}
						for(i=0; i<60; i++)
							{
								for(j=0; j<60; j++)
									{
										if(table[i][j] != ALIVE)
											{
												table[z][c] = ALIVE;
												table[z+1][c-1] = ALIVE;
												table[z+1][c+1] = ALIVE;
												table[z+2][c] = ALIVE;
												table[z+2][c+1] = ALIVE;
											}
									}
							}
						for(i=0; i<60; i++)
							{
								for(j=0; j<60; j++)
									{
										if(table[i][j] != ALIVE)
											{
												table[q][w-1] = ALIVE;
												table[q][w] = ALIVE;
												table[q+1][w-1] = ALIVE;
												table[q+1][w+1] = ALIVE;
												table[q+2][w] = ALIVE;
												table[q+2][w+1] = ALIVE;
											}
									}
							}
						for(i=0; i<60; i++)
							{
								for(j=0; j<60; j++)
									{
										if(table[i][j] != ALIVE)
											{
												table[e][r] = ALIVE;
												table[e][r+1] = ALIVE;
												table[e+1][r-1] = ALIVE;
												table[e+1][r+2] = ALIVE;
												table[e+2][r] = ALIVE;
												table[e+2][r+2] = ALIVE;
												table[e+3][r+1] = ALIVE;
											}
										}
									}

}

void setZero(arrayTable table) {
	int height, width;
	for (height = 0; height < 60; height++) {
		for (width = 0; width < 60; width++) {
			table[height][width] = DEAD;
	}
}

}

void enterButton(arrayTable table, int grid)
{
	int ch;
	int counter,generationum = 0;
	counter = 0;
		if(grid == 1)
		{
		while((ch = getch()) != EOF && ch !='X' && ch != 'x' && counter !=1)
			{
				if(ch != 'R' && ch != 'r')
					{
 				clearScreen();
 				calculate(table, grid);
 				printTable1(table);
 				printf("\nPress any key to proceed to next generation (except X and R)\nPress X to exit\nPress R to go back to menu");
 				generationum++;
 				printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tThis is generation %d", generationum);
 					}
 				else if (ch == 'R' || ch == 'r')
					{
						counter++;
						clearScreen();
						GameOfLife();
					}
		}
		}else if (grid == 2)
		{
			while((ch = getch()) != EOF && ch !='X' && ch != 'x' && counter != 1)
			{
				if(ch != 'R' && ch != 'r')
					{
 				clearScreen();
 				calculate(table, grid);
 				printTable2(table);
 				printf("\nPress any key to proceed to next generation (except X and R)\nPress X to exit\nPress R to go back to menu");
 				generationum++;
 				printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tThis is generation %d", generationum);
 					}
 				else if (ch == 'R' || ch == 'r')
					{
						counter++;
						clearScreen();
						GameOfLife();
					}

		}
		}
}
void randomCreature1(arrayTable table)
{
	int random;
	setZero(table);
	srand((unsigned)time(NULL));
	random = rand()%22;

	if(random == 14 || random == 20)
	{
		loadStillLife1(table);
		loadOscillator1(table);
		loadPentomino1(table);
	} else if(random == 8 || random == 10)
	{
		loadPentomino1(table);
	} else if(random < 10)
	{
		loadStillLife1(table);
		loadOscillator1(table);
	} else if(random > 10)
	{
		loadStillLife1(table);
		loadPentomino1(table);
	} else if(random == 1)
	{
		loadStillLife1(table);
	} else if(random == 5)
	{
	    loadOscillator2(table);
	}
}
void randomCreature2(arrayTable table)
{
	int random;
	setZero(table);
	srand((unsigned)time(NULL));
	random = rand()%22;

	if(random == 14 || random == 20)
	{
		loadStillLife2(table);
		loadOscillator2(table);
		loadPentomino2(table);
	} else if(random == 8 || random == 10)
	{
		loadPentomino2(table);
	} else if(random < 10)
	{
		loadStillLife2(table);
		loadOscillator2(table);
	} else if(random > 10)
	{
		loadStillLife2(table);
		loadPentomino2(table);
	} else if(random == 1)
	{
		loadStillLife2(table);
	} else if(random == 5)
	{
	    loadOscillator2(table);
	} 
}
int iLoveGameOfLife()
{
	int x;

		printf("This project was made by: Razon, Bermylle John U.\nSection PQ\nCMSC.11-Machine Problem: Game of life");
		printf("\t\t\t\t\t\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t     _____________________________________________________________________________");
		printf("\n\n\n\t\t\t\t\t\t\t       Welcome to the Game of Life by John Conway\n");
		printf("\n\t\t\t\t\t            \"Make sure to set the screen to full screen for optimal viewing\" ");
		printf("\n\n\n\t\t\t\t\t\t\t               Press any key to proceed");
		printf("\n\n\n\n\n\t\t\t\t\t\t\t ERROR HANDLING: You can only enter the keys indicated.\n \t\t\t\t\t\t\t     Failure to do so will cause the program to end");
		printf("\t\t\t\t\t\n\n\t\t\t\t\t     _____________________________________________________________________________");
		x = getch();
			if(x != 'r' || x != 'R')
			{
				clearScreen();
				GameOfLife();
			}
	return 0;
}

