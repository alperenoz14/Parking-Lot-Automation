#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{				//Car properties kept in 'struct'...
	char plate[20];
	char brand[20];																								////  Alperen ÖZ - Studying Software Engineering for 2 years
	char colour[20];
}Car;
void List_Cars(Car myCar[],int x , int y );
void Add_Car(Car myCar[] , int a , time_t time );
int main() {
int i , j , choice ,  again;
Car car[1000];  time_t t;  time(&t);
printf("*******************ALPEREN PARKING LOT*******************\n");
do{
menu:
printf("1.Add a new car to the parking lot\n");
printf("2.list cars added to parking lot\n");	
printf("3.EXIT\n\n");
printf("enter your choice...\n");	
scanf("%d",&choice);
if(choice == 1){
	add:
	Add_Car(car,i,t);					// Function which does adding process...
	i++;
	if(i == 1000){						// Checking the capacity of parking lot...		
	printf("The parking lot capacity is full!!!");
	}
	printf("To add new car to parking lot, press '1' and enter ,to list cars added, press '2' and enter , to return the main menu, press any number then enter... \n ");
	scanf("%d",&again);
	if(again == 1){
		goto add;
	}
	else if (again == 2){
	List_Cars(car,i,j); 			//Function which list cars been added...
	printf("To add car again, press '1' and enter, to return the main menu, press any number then enter...\n  ");
	scanf("%d",&again);
	if(again == 1){
		goto add;}
	}
	}
else if(choice == 2){				
	List_Cars(car,i,j);
	printf("To add car again, press '1' and enter, to return the main menu, press any number then enter...\n  ");
	scanf("%d",&again);
	if(again == 1){
		goto add;}
	}	
}while(choice != 3);
	
return 0;
}
void List_Cars( Car myCar[] , int x , int y ){
	printf("-------------------Cars in Parking Lot-------------------\n");         
	for(y = 0 ; y<x ; y++){
	printf("%d. car --> PLAT: %s  BRAND: %s  COLOUR: %s\n",y+1,myCar[y].plate,myCar[y].brand,myCar[y].colour);}
	printf("\n");
}
void Add_Car(Car myCar[] , int a , time_t time ){
	printf("----------------------Add Car SubMenu----------------------\n");				
	printf("Enter the lisance plat of car:\n");  
	fflush(stdin);
	gets(myCar[a].plate);
	printf("Enter the brand of car:\n");
	gets(myCar[a].brand);
	printf("Enter the colour of car:\n");
	gets(myCar[a].colour);
	printf("**Car registration is successful**\n\n");
	printf("PLAT = %s  BRAND = %s  COLOUR = %s\n",myCar[a].plate,myCar[a].brand,myCar[a].colour);
	printf("\n");
	printf("----> the moment of entry of the car with **%s** lisance plate: %s\n",myCar[a].plate,ctime(&time)); //catch of the moment of entry of car...
}
