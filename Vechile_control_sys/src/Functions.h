/*
 * Functions.h
 * Author: Omar Ben Emad
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//==============================================================
//Definitions for enumerations and structures
enum state {
	OFF = 0 , ON = 1
};
typedef struct  {
	int vechile_speed  ;
	float room_temp ;
	float engine_temp  ;
	enum state Engine_Temperature_Controller_State ;
	enum state Engine_state ;
	enum state AC_state ;
}state;
state vechileState = {40 , 25 , 80  , OFF , OFF , OFF } ;
int true = 1 ;
//==============================================================
//Function declaration
void data_display();
void turn_on();

void start_up_menu(void){
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");
	printf("Enter your choice\n");
}
void sensor_menu(void){
	printf("a. Turn off the vehicle engine\n");
	printf("b. Set the traffic light color\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
	printf("Enter your choice\n");
	printf("\n");

}
void traffic_light (char x){
	vechileState.Engine_state= ON;
	if(x == 'G' || x == 'g' ){
		vechileState.vechile_speed = 100;
	}
	else if(x ==  'R'|| x == 'r'){
		vechileState.vechile_speed = 0;
	}

	else if (x =='O' || x == 'o'){
		vechileState.vechile_speed = 30;
		vechileState.AC_state = ON ;
		vechileState.Engine_Temperature_Controller_State = ON;
		vechileState.room_temp = (vechileState.room_temp * (float)1.25) -1;
	}
	else{
		printf("enter valid symbol");
	}
	 data_display();
}

void Room_temp_and_Ac(int temprature){
	vechileState.Engine_state= ON;
	if (temprature<10 || temprature>30){
		vechileState.room_temp = 20 ;
		vechileState.AC_state = ON ;
	}
	else{
		vechileState.AC_state = OFF ;
	}
	 data_display();
}
void engine_temp(int temprature){
	vechileState.Engine_state= ON;
	if(temprature<100 || temprature > 150){
		vechileState.engine_temp = 125 ;
		vechileState.Engine_Temperature_Controller_State= ON ;
	}
	else {
		vechileState.Engine_Temperature_Controller_State= OFF ;
	}
	 data_display();
}
void data_display(){
	if(	vechileState.Engine_state == ON){
	printf("Engine State : ON\n");
	}
	if(vechileState.AC_state == ON)
	{
		printf("AC : ON\n");
	}
	else {
		printf("AC : OFF\n");
	}
	printf("Vehicle Speed : %d\n",vechileState.vechile_speed);
	printf("Room Temperature : %g\n",vechileState.room_temp);
	if(vechileState.Engine_Temperature_Controller_State == ON)
	{
	printf("Engine Temperature Controller State : ON\n");
	}
	else{
	printf("Engine Temperature Controller State : OFF\n");
	}
	printf("Engine Temperature : %g\n",vechileState.engine_temp);
	printf("\n");
}
void turn_on(){
	int temp ;
	char y,x;
	sensor_menu();
	scanf(" %c",&x);
	switch (x){
	case'a':
		vechileState.Engine_state=OFF;
		break ;
	case'b':
		puts("Enter any of traffic light symbols (G , R ,O )");
		scanf(" %c",&y);
		traffic_light (y);
		break;
	case'c':
		puts("Enter the Temp");
		scanf("%d",&temp);
		Room_temp_and_Ac(temp);
		break;
	case'd':
		puts("enter the temp");
		scanf("%d",&temp);
		engine_temp(temp);
		break;
	default:
		printf("Enter valid choice \n");
	}

}
void start_menu (){
	char choice  ;
	start_up_menu();
	scanf(" %c",&choice);
	switch(choice){
	case'a':
		turn_on();
		break;
	case'b':
		vechileState.Engine_state = OFF;
		break;
	case'c':
		true = 0 ;
		printf("Quit the system\n");
		break;
	default:
		printf("Enter valid choice \n");
	}
}

#endif /* FUNCTIONS_H_ */
