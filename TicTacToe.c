#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h> 


//no input validation for other types rather than integer.

int arr[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
char gameGUI[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char humanChar= ' ';
char compChar= ' ';
int counter = 0;

void printGame(){
	
	system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player (%c)  vs  Computer (%c)\n\n\n",humanChar, compChar);


    printf("         |     |     \n");
    printf("      %c  |  %c  |  %c \n", gameGUI[0][0], gameGUI[0][1], gameGUI[0][2]);

    printf("    _____|_____|_____\n");
    printf("         |     |     \n");

    printf("      %c  |  %c  |  %c \n", gameGUI[1][0], gameGUI[1][1], gameGUI[1][2]);

    printf("    _____|_____|_____\n");
    printf("         |     |     \n");

    printf("      %c  |  %c  |  %c \n", gameGUI[2][0], gameGUI[2][1], gameGUI[2][2]);

    printf("         |     |     \n\n");
}

void isWinner(int comp){
	
	if(counter<9){
		
		struct Situation{
			char robotWon[50];
			char youWon[50];
		};
		
		struct Situation game;
		strcpy( game.robotWon, "My Robot Won You!\n");
   		strcpy( game.youWon, "Hm, Good Job, You Won!\n"); 
		
		int i;
		//check for horizontal
		for(i=0;i<3;i++){
			if(arr[i][0]!=0 && arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2]){
			if(arr[i][0]==comp){
				printf("%s",game.robotWon);
			}
			else{
				printf("%s",game.youWon);
			}
			exit(0);
			}
		}
		//check for vertical
		for(i=0;i<3;i++){
			if(arr[0][i]!=0 && arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i]){
			if(arr[0][i]==comp){
				printf("%s",game.robotWon);
			}
			else{
				printf("%s",game.youWon);
			}
			exit(0);
			}
		}
	
		//for diagonal
		if(arr[0][0]!=0 && arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2]){
			if(arr[0][0]==comp){
				printf("%s",game.robotWon);
			}
			else{
				printf("%s",game.youWon);
			}
			exit(0);
		}
		if(arr[2][0]!=0 && arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2]){
			if(arr[2][0]==comp){
				printf("%s",game.robotWon);
			}
			else{
				printf("%s",game.youWon);
			}
			exit(0);
		}
		
		counter++;
	}
	else{
		printf("Non, or Both of your Won :-)\n");
		exit(0);
	}
}


int generate_random(){
	//works
	int rand_num = (rand() % (2 - 0 + 1)) + 0;
    return rand_num;
}

void equalize(int comp, int human){
	//works
	int i,j;
	for(i=0; i<3; i++){
		for(j =0; j<3;j++){
			if(arr[i][j]==comp){
				gameGUI[i][j]=compChar;
			}
			if(arr[i][j]==human){
				gameGUI[i][j]=humanChar;
			}
		}
	}
}

void generate(int comp){
	//works, but with random which is bad
	srand(time(0));
	while(true){
		int n = generate_random();
		if(arr[n][0]==0 || arr[n][1]==0 ||arr[n][2]==0 ){
			int m = (rand() % (2 - 0 + 1)) + 0; 
			if(arr[n][m]==0){
				arr[n][m]=comp; //this is for the computer 
				break;
			}
		}
	}
}

bool validate(int num1, int num2){
	if ((num1==1 || num1==2 || num1==3) && (num2==1 || num2==2 || num2==3)){
		return true;
	}
	else{
		
		return false;
	}
}


int main(){
	//driver
	srand(time(0));
	int temp1 = (rand() % (2 - 1 + 1)) + 1;
	const int comp = temp1; //Each time human and robot sign choses randomly
	
	if(comp==2){
		temp1 =1;
	} 
	else{
		temp1 = 2;
	}
	const int human= temp1;
	if(comp==1){
		compChar = 'O';
		humanChar = 'X';
	}
	else{
		compChar = 'X';
		humanChar = 'O';
	}

	//game starts
	int x=0,y=0;
	bool checkForRobot=true; //X will always make a first move

	printGame();
	while(true){
		if(comp==2 && checkForRobot ){ 
			generate(comp);
			equalize(comp,human);
			checkForRobot=false;
			
			printGame();
			isWinner(comp);
		}
		while(true){
			printf("Your move: ");


			scanf("%d",&y);	
			scanf("%d",&x);
			
			
			if(validate(x,y)){

				y--;
				x--;

				if(arr[x][y]==0){
					arr[x][y]=human;
					break;
				}
				printf("Wrong Input, please re-enter\n");
			}
			else{
				printf("Wrong Input, please re-enter\n");
			}
			
	
		}
		equalize(comp,human);
		printGame();

		isWinner(comp);
		printf("Robot is thinking...\n");
		sleep(1); //this feature is lit!
		
		generate(comp);
		equalize(comp,human);

		printGame();
		isWinner(comp);
		
		
	}
	return 0;
}

