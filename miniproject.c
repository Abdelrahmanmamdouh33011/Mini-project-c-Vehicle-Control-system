#include <stdio.h>
#include <stdlib.h>
#define ON 1
#define OFF 0
#define engine_temper 1 // for #if and #endif

void print();
void turnedon();
void firstinputuser();
void printwhenturned();
void speed();
void roomtemperature();
void enginetemp();
void display();
void setvalue();


struct cardata // structure to to facilitate work
{
	int speed ;
	int roomtemperature ;
	int AC ;
	int engine_temp_controller ;
	int engine_temp ;
	int engine_state ;

}car;// making variable ( car ) structure

void setvalue() // set the initial value again when turned off
{
	car.AC = OFF; // set initial value
	car.engine_state = OFF;
	car.engine_temp = 90;
	car.engine_temp_controller = OFF;// set initial value
	car.roomtemperature = 35;
	car.speed = 0;// set initial value
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	void setvalue();
	print();// Ask the user

		return 0;
}

void print()
{
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");

	firstinputuser(); // call func to take input from user
	return;
}

void firstinputuser()
{
	    char input; // taken from user
		scanf(" %c",&input);
		if(input == 'c')
		{
			printf("\nc. Quit the system\n");
			return; // Quit program if user enter c
		}

		if (input == 'a')
		{
			return turnedon(); // call turned on func.
		}

		if (input == 'b')
		{
			printf("\nb. Turn off the vehicle engine\n\n");
			void setvalue(); // to set the initial value again when turned off
			return print();
		}


}

void printwhenturned()// While the engine is ON  always displayed and waits for an answer
{
	printf("\na. Turn off the engine\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
#if(engine_temper) // for #if bonus q
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
#endif
}


void turnedon()// this function to take the first selection from user
{
	car.engine_state = ON;

	printwhenturned();// While the engine is ON  always displayed and waits for an answer

	char input2;
	scanf(" %c",&input2);

	if(input2 == 'a') // if user choose turn of
	{
		printf("the vehicle is turned of \n");
	return print();// calling print func and display first option again

	}
	else if (input2 == 'b')
	{
		return speed();// for b calling speed function
	}
	else if(input2 == 'c')
	{
		return roomtemperature(); // for c calling roomtemp function
	}
#if (engine_temper) // for #if bonus q
	else if (input2 == 'd')
	{
		return enginetemp(); // calling engintemp function
	}
#endif // for #if bonus q

}


void speed()// this function to set speed and display to re input from user
{
	printwhenturned();

	printf("please enter required color \n");
	char speed;
	scanf(" %c",&speed);
	if (speed == 'g' || speed == 'G')
	{
		car.speed =100;
		return display(); // calling display function to display and re input from user
	}

	else if(speed == 'o' || speed == 'O')
	{
		car.speed = 30;
		car.AC = ON;
		car.roomtemperature = (car.roomtemperature*5/4) +1;
		return display(); // calling display function to display and re input from user
	}

	else if(speed == 'r' || speed == 'R')
	{
		car.speed = 0;
		return display(); // calling display function to display and re input from user
	}

}

void roomtemperature() // this function to set and control the room temperature
{
	printwhenturned();

	int temp;
	printf("please enter the temperature \n");
	scanf("%d",&temp);

	if(temp < 10)
	{
		car.AC = ON;
		car.roomtemperature = 20;
		return display(); // calling display function to display and re input from user
	}
	else if (temp > 30 )
	{
		car.roomtemperature = 20;
		car.AC = ON;
		return display(); // calling display function to display and re input from user
	}
	else
	{
		car.AC = OFF;
		return display(); // calling display function to display and re input from user
	}
}
void enginetemp() // this function to set and control the engine temperature and display it
{
	printwhenturned();

	printf("\nplease enter the engine temp \n");
	int entemp;
	scanf(" %d",&entemp);

	if (entemp<100)
	{
		car.engine_temp_controller = ON;
		car.engine_temp = 125;
		return display(); // calling display function to display and re input from user
	}
	else if(entemp > 150)
	{
		car.engine_temp_controller = ON;
		car.engine_temp = 125;
		return display(); // calling display function to display and re input from user
	}
	else
	{
		car.engine_temp_controller = OFF;
		return display(); // calling display function to display and re input from user
	}

}


void display() // function to display the state
{
	if (car.engine_state == ON)
	{
		printf("Engine state: is ON\n");
	}
	else
	{
		printf("Engine state: is OFF\n");
	}
	if(car.AC)
	{
		printf("AC: is ON\n");
	}
	else
	{
		printf("AC: is OFF\n");
	}

	printf("Vehicle Speed. = %d Km/Hr \n",car.speed);

	printf("Room Temperature = %d C\n",car.roomtemperature);

	if (car.engine_temp_controller)
	{
		printf("Engine Temperature Controller State. is ON \n");
	}

	else
	{
		printf("Engine Temperature Controller State. is OFF\n");
	}

#if(engine_temper) // for #if bonus q
	printf("Engine Temperature == %d C\n\n",car.engine_temp);

#endif // for #if bonus q

	return turnedon();

}
