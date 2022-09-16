/*
 ============================================================================
 Name        : m.c
 Author      : Omar Ben Emad
 Description : Vehicle Control System
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
void turn_on();
void start_menu ();
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	while(true == 1){
	if(vechileState.Engine_state == OFF){
		start_menu();
	}
	else{
		turn_on();
	}
	}
	return EXIT_SUCCESS;
}
