/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Daryl Alex
	ID     : 143691202
	Email  : dalex4@myseneca.ca
	Section: ZBB
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define Maximum_life 10
#define Maximum_path_length 70
#define Minimum_path_length 10
#define Multiple 5
typedef struct Playerinfo {
	int number_of_lives;
	char symbol;
	int number_of_tresure;
	int enter_position[Maximum_path_length][Multiple];
}player_info;
typedef struct GameInfo {
	int maximum_moves;
	int path_length;
	int bombs[Maximum_path_length][Multiple];
	int tressure[Maximum_path_length][Multiple];
}game_info;
int main()
{
	player_info pi;
	game_info gi;
	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf("%c", &pi.symbol);
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &pi.number_of_lives);
		if (pi.number_of_lives < 1 || pi.number_of_lives > Maximum_life)
		{
			printf("     Must be between 1 and 10!\n");
		}
	} while (pi.number_of_lives < 1 || pi.number_of_lives > Maximum_life);
	printf("Player configuration set-up is complete\n\n");
	printf("GAME Configuration\n");
	printf("------------------\n");
	do
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &gi.path_length);
		if (gi.path_length < Minimum_path_length || gi.path_length > Maximum_path_length || gi.path_length % Multiple != 0)
		{
			printf("     Must be a multiple of %d and between %d-%d!!!\n",Multiple,Minimum_path_length,Maximum_path_length);
		}
	} while (gi.path_length < Minimum_path_length || gi.path_length > Maximum_path_length || gi.path_length % Multiple != 0);
	int Maximum_path_plays =(int) (0.75 * gi.path_length);
	do
	{ 

		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gi.maximum_moves);
		if (gi.maximum_moves < pi.number_of_lives || gi.maximum_moves>Maximum_path_plays)
		{
			printf("    Value must be between %d and %d\n",pi.number_of_lives,Maximum_path_plays);
		}
	} while (gi.maximum_moves < pi.number_of_lives || gi.maximum_moves>Maximum_path_plays);
	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
	int i;
	int j;
	for (i = 0; i < gi.path_length/5; i++)
	{
		printf("   Positions [%2d-%2d]: ",(i*5+1),(i+1)*5);
		for ( j = 0; j < 5; j++)
		{
			scanf("%d", &gi.bombs[i][j]);
		}
	}
	printf("BOMB placement set\n\n");
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",gi.path_length);
	for (i = 0; i < gi.path_length/5; i++)
	{
		printf("   Positions [%2d-%2d]: ", (i * 5 + 1), (i + 1) * 5);
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &gi.tressure[i][j]);
		}
	}
	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", pi.symbol);
	printf("   Lives      : %d\n", pi.number_of_lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", gi.path_length);
	printf("   Bombs      : ");
	for (i = 0; i < gi.path_length / 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d", gi.bombs[i][j]);
		}
	}
	printf("\n   Treasure   : ");
	for (i = 0; i < gi.path_length / 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d", gi.tressure[i][j]);
		}
	}
	printf("\n\n");
	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	return 0;
}