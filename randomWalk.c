/**
 This program randomly prints letters A to Z in a 2D array.
 @author Catherine Higgins 3101241
 Date: September 30, 2017
*/

#include <stdio.h>
#include <stdlib.h>

/**
 This recieves input for the size of the array n X n.
 @return int.
*/

int get_n();

void printArray(char *arr, int rows, int cols); 

int main() {

	int n = get_n();

	char arr[n][n]; /*Initialize char array with n size*/

	for (int d = 0; d < n; d++) { /*Insert initial values of . in array*/
		for(int j = 0; j <n; j++){
			arr[d][j] = '.';
		}
		printf("\n");
	}

	char alphabet = 'A'; 
	char *path = &arr[0][0];
	int row = 0;
	int col = 0;

	char *visited = &alphabet;  /*Set a path to increment the letters of the alphabet*/

	*(path + row + col) = *visited; /*Set alphabeth to follow path*/
	int checkA = 0;
	int checkB = 0;
	int checkC = 0;
	int checkD = 0;
	int c = 1;
	int end = 0;
	int maxlettercount = 0;
	int max = 0;
	if(n<=5){
		max = (n*n)-1 ;
	}else{
		max =25 ;
	}
	//Traverse path
	while(maxlettercount < max){

	int r = rand() % 4 +1; 	/*To dertermine travel directionality 1 to 4*/
		
		if( (checkA == 1 && checkB == 1 && checkC ==1 && checkD == 1)){

				int count = 60;
				int end_1 = 0;
				 while(end_1== 0){
						 row = rand() % n;
						 c = rand() % n + 1;
						 col = ((c-1)*n);
						 if(*(path + row + col) == '.'){
						 	*visited +=1;
						 	*(path + row + col) = '&';
						 	maxlettercount++;
							end_1 = 1;
							checkA = 0;
							checkB = 0;
							checkC=0;
							checkD=0;
						 }
				}
		 }
			else{
				if( r == 1){  /*Check to the right*/
						//printf("r1\n");
						if ((row +1) < n && ( *(path + (row+1) + col)  == '.' )){
							row++;
							*visited +=1;
							*(path + (row) + col) = *visited;
							maxlettercount++;
							checkA = 0;
							checkB = 0;
							checkC=0;
							checkD=0;
						}
						else if( (row == n-1) && (*(path + (0) + col) == '.' )){
							row = 0; 			
							*visited +=1;
							*(path + (row) + col) = *visited;
							maxlettercount++;	
							checkA = 0;
							checkB = 0;
							checkC=0;
							checkD=0;
							
						}else{
							checkA = 1;

						}	

					}
					else if ( r == 2){/*Check left*/
					//printf("r2\n");
						if ( row > 0 && ( *(path + (row-1) + col)  == '.' )){
							row--;
							*visited +=1;
							*(path + (row) + col) = *visited;
							maxlettercount++;
							checkA = 0;
							checkB = 0;
							checkC=0;
							checkD=0;
							
						}
						else if((row == 0) && (*(path + (n-1) + col) == '.' )){
							row = n-1; 			/*reset row to zero to wrap around*/
							*visited +=1;
							*(path + (row) + col) = *visited;
							maxlettercount++;
							checkA = 0;
							checkB = 0;
							checkC=0;
							checkD=0;
							
						}else{
							checkB = 1;
						}
					}
					else if (r == 3){/*Check the bottom*/
						
						if (c <= n && (*(path + row + (n*c) )  == '.' )){
							col +=n;
							c +=1;
							*visited +=1;
							*(path + (row) + (col)) = *visited;
							maxlettercount++;
							checkA = 0;
							checkB = 0;
							checkC=0;
							checkD=0;

							
						}
						 else if(c == n &&   ( *(path + row) == '.' )    ){
						    col =0;
						    c = 1;
							*visited +=1;
							*(path + (row) + (col)) = *visited;
							maxlettercount++;
							checkA = 0;
							checkB = 0;
							checkC=0;
							checkD=0;
							
						}else{
							checkC =1;
						}
						
					}
					else if (r == 4){/*Check up*/
					
						if (c == 1 && (*(path + row + (n*(n-1)) )  == '.' )){
							c = n;
							col += (c-1)*n;
							*visited +=1;
							*(path + (row) + (col)) = *visited;
							maxlettercount++;
							checkA = 0;
							checkB = 0;
							checkC=0;
							checkD=0;
							
						}
						else if(c > 1 && (*(path + row + (n*(c-2))) == '.' )  ){
						 	col -= n;
							c -= 1;
							*visited +=1;
							*(path + (row) + (col)) = *visited;
							maxlettercount++;
							checkA = 0;
							checkB = 0;
							checkC=0;
							checkD=0;
							
						}else{
							checkD = 1;
						}
					}
					else{
						printf("It got stuck");
						end = 1;
						return 1;
					}
			}

}
	printArray(path, n, n); 
	
	return 0;
}


void printArray(char *arr, int rows, int cols) { 
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			//*(arr + (i*cols) + j) = 'A';
		printf("%c ", *(arr + (i*cols) + j));
	}
	printf("\n"); }
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


