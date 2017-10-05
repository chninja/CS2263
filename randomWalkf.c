/**
 This program randomly prints letters A to Z in a 2D array.
 @author Catherine Higgins 3101241
 Date: September 30, 2017
*/

#include <stdio.h>
#include <stdlib.h>

 /**
 This functions reset check values for example 
 if the path has recently moved the path 
 the checks for all 4 direction will restart.
 @param *A - The pointer for check right
 @param *B - The pointer for check left
 @param *C - The pointer for check up
 @param *D - The pointer for check down
*/

void resetChecks(int *A, int *B, int *C, int *D);


/**
 This recieves input for the size of the array n X n.
 @return int.
*/

int get_n();

/**
 This functions prints out an array.
 @param *arr - The array pointer
 @param rows - # number of rows 
 @param cols - # number of cols
*/

void printArray(char *arr, int rows, int cols); 

int main() {

	int n = get_n();

	char arr[n][n]; /*Initialize char array with n size*/

	for (int d = 0; d < n; d++) { /*Insert initial values '.'' in array*/
		for(int j = 0; j <n; j++){
			arr[d][j] = '.';
		}
		printf("\n");
	}

	char alphabet = 'A'; 
	char *path = &arr[0][0]; //Set the pointer to the start of the matrix
	int row = 0;
	int col = 0;
	int c = 1; /*Counter for the rows*/

	char *visited = &alphabet;  /*Set a path to increment the letters of the alphabet*/

	*(path + row + col) = *visited; /*Set first letter in the path*/

	int checkA = 0; //variables to check if right,left, top, bottom have been visited.
	int checkB = 0;
	int checkC = 0;
	int checkD = 0;

	int *A = &checkA;
	int *B = &checkB;
	int *C = &checkC;
	int *D = &checkD;

	int maxlettercount = 0; //Counters for max letter this will stop the array once Z is reached
	int max = 0;//Determine the stop value based on the size of the array
	if(n<=5){
		max = (n*n)-1 ;
	}else{
		max =25 ;
	}
	
	while(maxlettercount < max){//Traverse path

	int r = rand() % 4 +1; 	//To dertermine travel directionality 1 to 4
		
		if( (*A == 1 && *B == 1 && *C ==1 && *D == 1)){//If all 4 directions have been

				
				 int end_1 = 0;
				 while(end_1== 0){//Find new random seed and start the path again
						 row = rand() % n;
						 c = rand() % n + 1;
						 col = ((c-1)*n);
						 if(*(path + row + col) == '.'){
						 	*visited +=1;
						 	*(path + row + col) = *visited;
						 	maxlettercount++;
							end_1 = 1;
							resetChecks(A,B,C, D);
						 }
				}
		 }
			else{
				if( r == 1){  /*Check to the right*/
						
						if ((row +1) < n && ( *(path + (row+1) + col)  == '.' )){
							row++;
							*visited +=1;
							*(path + (row) + col) = *visited;
							maxlettercount++;
							resetChecks(A,B,C,D);
						}
						else if( (row == n-1) && (*(path + (0) + col) == '.' )){//This is for the wrap around
							row = 0; 			
							*visited +=1;
							*(path + (row) + col) = *visited;
							maxlettercount++;	
							resetChecks(A,B,C,D);
							
						}else{
							*A = 1;

						}	

					}
					else if ( r == 2){/*Check left*/
					
						if ( row > 0 && ( *(path + (row-1) + col)  == '.' )){
							row--;
							*visited +=1;
							*(path + (row) + col) = *visited;
							maxlettercount++;
							resetChecks(A,B,C,D);
							
						}
						else if((row == 0) && (*(path + (n-1) + col) == '.' )){//This is for the wrap around
							row = n-1; 			
							*visited +=1;
							*(path + (row) + col) = *visited;
							maxlettercount++;
							resetChecks(A,B,C,D);
							
						}else{
							*B = 1;
						}
					}
					else if (r == 3){/*Check the bottom*/
						
						if (c <= n && (*(path + row + (n*c) )  == '.' )){
							col +=n;
							c +=1;
							*visited +=1;
							*(path + (row) + (col)) = *visited;
							maxlettercount++;
							resetChecks(A,B,C, D);

							
						}
						 else if(c == n &&   ( *(path + row) == '.' )    ){//This is for the wrap around
						    col =0;
						    c = 1;
							*visited +=1;
							*(path + (row) + (col)) = *visited;
							maxlettercount++;
							resetChecks(A,B,C,D);
							
						}else{
							*C =1;
						}
						
					}
					else if (r == 4){/*Check up*/
					
						if (c == 1 && (*(path + row + (n*(n-1)) )  == '.' )){
							c = n;
							col += (c-1)*n;
							*visited +=1;
							*(path + (row) + (col)) = *visited;
							maxlettercount++;
							resetChecks(A,B,C,D);
							
						}
						else if(c > 1 && (*(path + row + (n*(c-2))) == '.' )  ){//This is for the wrap around
						 	col -= n;
							c -= 1;
							*visited +=1;
							*(path + (row) + (col)) = *visited;
							maxlettercount++;
							resetChecks(A,B,C,D);
							
						}else{
							*D = 1;
						}
					}
					else{
						return 1;//This should never happen
					}
			}

}
	printArray(path, n, n); 
	
	return 0;
}


void printArray(char *arr, int rows, int cols) { 
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
		printf("%c ", *(arr + (i*cols) + j));
		}
	printf("\n");
	}
}

void resetChecks(int *A, int *B, int *C, int *D){
		*A = 0;
		*B = 0;
		*C = 0;
		*D = 0;
}


int get_n() {
	
	printf("Enter the size of the array: ");
	int n = 0;
	if (scanf("%d", &n) != 1){
		return 1;
	}else{
		return n;
	}
		
	return n;
	
}


