

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<iomanip>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<ctime>
#include<cstdlib>
#include<stdlib.h>
#include<fstream>
using namespace std;

int time_lim = 3000;	// timer for 3 mins
 int score = 0;		//this variable stores the score of the player

string taxi_color , name; 	//variable to store the color for taxi and name of the player
bool var = false ;

bool flag_1 =false;	//this flag is created for passenger 1's location to check either he is picked
bool flag_1_ = false;	//this flag is created for passenger 1's location to check either he is dropped

bool flag_2 = false;	//this flag is created for passenger 2's location to check either he is picked
bool flag_2_ = false;	//this flag is created for passenger 2's location to check either he is dropped

bool flag_3 = false;	//this flag is created for passenger 3's location to check either he is picked
bool flag_3_ = false;	//this flag is created for passenger 3's location to check either he is dropped

bool flag_4 = false;	//this flag is created for passenger 4's location to check either he is picked
bool flag_4_ = false;	//this flag is created for passenger 4's location to check either he is dropped

bool flag_5 = false;	//this flag is created for passenger 5's location to check either he is picked
bool flag_5_ = false;	//this flag is created for passenger 5's location to check either he is dropped


bool var1 = false;	//variable checkes the status of passenger either picked to be picked
bool var2 = false;	//these varibles will help player drop and pick his passenger by checking their position
bool var3 = false;
bool var4 = false;
bool var5 = false;
int c = 650, _c = 130;		//initial loaction of car 1 ,2 ,3 ,4 ,5 and taxi respectivley
int c2 = 150, _c2 = 500;
int c3 = 350, _c3 = 650;
int c4 = 900, _c4 = 650;
int c5 = 1050, _c5 = 900;
int xI = 100, yI = 1000;

	//	******************************************************
	//	* 	BLACK BOXES: Building				*	      		     
	//	*	TRIANGLES: Obstacles				*		          
	//	*	CIRCLES: Passengers				*		          
	//	*	GREEN SQUARES: Destination			* 		  
	//	******************************************************	
	
void SetCanvasSize(int width, int height)	//here the sixe of canvas is set I left it by default
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void passenger ()	//this is function is called and passengers are drawn on board
{
	
	DrawCircle( 1030, 1000, 20, colors[DEEP_PINK] );	//passsenger location
	if ( var )					// true if being picked
	{	
	//drawing the circle to be white means that passnger is being picked i.e diapperead
		DrawCircle(1030, 1000, 20, colors[WHITE]);
		DrawSquare(900, 500, 50, colors[GREEN]);	//when picked drop off location generated
		
		if( ( ( xI >= (900 - 50) ) && (xI <= (900 + 50) ) ) && ( ( yI >= (500 - 50) ) && (yI <= (500 + 50) ) ) )
			
		flag_1= true;	//when taxi reaches the drop off location this variable goes true below in 
				// non printable keys function the passenger is drop when enter key is pressed
	}
	DrawCircle( 1020, 300, 20, colors[DEEP_PINK] );	//passsenger location
	
	if ( var1 )					// true if being picked
	{
		DrawCircle(1020, 300, 20, colors[WHITE]);
		DrawSquare(600, 200,50, colors[GREEN]);	//when picked drop off location generated
		if( ( ( xI >= (600 - 50) ) && (xI <= (600 + 50) ) ) && ( ( yI >= (200 - 50) ) && (yI <= (200 + 50) ) ) ) 
		flag_2 = true;
	}
	DrawCircle( 830, 220, 20, colors[DEEP_PINK] );	//passsenger location
	if ( var2 )
	{
		DrawCircle(830, 220, 20, colors[WHITE]);	
		DrawSquare(200, 500,50, colors[GREEN]);
		if( ( ( xI >= (200 - 50) ) && (xI <= (200 + 50) ) ) && ( ( yI >= (500 - 50) ) && (yI <= (500 + 50) ) ) ) 
		flag_3 = true;	//when taxi reaches the drop off location this variable goes true below in 
				// non printable keys function the passenger is drop when enter key is pressed
	}
	
	
	DrawCircle( 630, 620, 20, colors[DEEP_PINK] );
	if ( var3 )
	{
	DrawCircle( 630, 620, 20, colors[WHITE] );
	DrawSquare(300, 800, 50, colors[GREEN]);
		
		if( ( ( xI >= (300 - 50) ) && (xI <= (800 + 50) ) ) && ( ( yI >= (300 - 50) ) && (yI <= (800 + 50) ) ) )
		flag_4= true;	//when taxi reaches the drop off location this variable goes true below in 
				// non printable keys function the passenger is drop when enter key is pressed
	}	
	
	DrawCircle( 230, 850, 20, colors[DEEP_PINK] );
	if ( var4 )
	{
		DrawCircle(230, 850, 20, colors[WHITE]);
		DrawSquare(400, 200, 50, colors[GREEN]);
		
		if( ( ( xI >= (400 - 50) ) && (xI <= (400 + 50) ) ) && ( ( yI >= (200 - 50) ) && (yI <= (200 + 50) ) ) )
		flag_5= true;	//when taxi reaches the drop off location this variable goes true below in 
				// non printable keys function the passenger is drop when enter key is pressed
	}
	
}


void drawCar() 
{

	DrawSquare(c,  _c ,  50 , colors[MEDIUM_AQUA_MARINE]);	//this function draws the body square
	DrawCircle(c+10, _c-10 ,10,colors[RED]);			// this draws the wheels
	DrawCircle(c+40, _c-10 ,10,colors[RED]);
	glutPostRedisplay();
	
	DrawSquare(c2, _c2, 50, colors[MEDIUM_PURPLE]);	
	DrawCircle(c2+10,_c2-10,10,colors[RED]);	//function to draw the wheels of the car on the canvas
	DrawCircle(c2+40,_c2-10,10,colors[RED]);	
	glutPostRedisplay();	//this function is called do that everytime the axis of my car changes it will display the car
				// on the new axis.
	
	
	DrawSquare(c3, _c3, 50, colors[HOT_PINK]);	
	DrawCircle(c3+10,_c3-10,10,colors[RED]);	
	DrawCircle(c3+40,_c3-10,10,colors[RED]);
	glutPostRedisplay();	//this function is called do that everytime the axis of my car changes it will display the car
				// on the new axis.
	
	if ( taxi_color == "YELLOW" )	//here the condition is used to check the desired color of the player
	{

	DrawSquare(xI, yI, 50, colors[YELLOW]);	//Taxi
	DrawCircle(xI+10,yI-10,10,colors[RED]);
	DrawCircle(xI+40,yI-10,10,colors[RED]);
	glutPostRedisplay();	//this function is called do that everytime the axis of my car changes it will display the car
				// on the new axis.
	}
	
	if (taxi_color == "RED" )	//to check if the color of taxi chosen by player is red
	{
	
	DrawSquare(xI, yI, 50, colors[RED]);	//Taxi
	DrawCircle(xI+10,yI-10,10,colors[BLUE]);
	DrawCircle(xI+40,yI-10,10,colors[BLUE]);
	glutPostRedisplay();	//this function is called do that everytime the axis of my car changes it will display the car
				// on the new axis.
	}
	
	
	DrawSquare(c4 , _c4 , 50, colors[BLUE]);	//blue car
	DrawCircle(c4+10,_c4-10,10,colors[RED]);
	DrawCircle(c4+40,_c4-10,10,colors[RED]);
	glutPostRedisplay();	//this function is called do that everytime the axis of my car changes it will display the car
				// on the new axis.
	
	
	DrawSquare(c5 , _c5 , 50, colors[INDIGO]);	//blue car
	DrawCircle(c5+10,_c5-10,10,colors[RED]);
	DrawCircle(c5+40,_c5-10,10,colors[RED]);
	glutPostRedisplay();	//this function is called do that everytime the axis of my car changes it will display the car
				// on the new axis.
	
	
}

bool flag1 = true;
void moveCar1() {     	//this fucntion is defined to move the car1 on the board by changing it's x axis 
	
	if (c>10 && flag1)	//as it was default so I kept it as it is
	{
		c -= 10;	
		if(c < 650)	// and built the conditions here.
			flag1 = false;	//to restrict the car moving from more than 650 pixels in horzontal (left)
		
	}
	else if (c < 1010 && !flag1) 
	{
		c += 10;

		if (c > 900)	//to restrict the car moving from more than 650 pixels in horzontal (right)
			flag1 = true;
		
	}
	// here we are checking if the car collides with this particular car the score is decreased by 2
	
	if( ( ( xI >= (c - 50) ) && (xI <= (c + 50) ) ) && ( ( yI >= (_c - 50) ) && (yI <= (_c + 50) ) ) )	
	score -= 2;
	}


bool flag2 = true;
void moveCar2() {
	
	if (_c2 > 10 && flag2)
	{
		_c2 -= 10;	//making the car up and down
		
		if(_c2 < 100)	//to restrict the car moving from more than 100 pixels in vertical (down)
			
			flag2 = false;

	}
	else if (_c2 < 1010 && !flag2) 
	{
		
		_c2 += 10;
		if (_c2 > 900)	//to restrict the car moving from more than 900 pixels in vertical (up)
			flag2 = true;
	}
	// here we are checking if the car collides with this particular car the score is decreased by 2
	if( ( ( xI >= (c2 - 50) ) && (xI <= (c2 + 50) ) ) && ( ( yI >= (_c2 - 50) ) && (yI <= (_c2 + 50) ) ) )	
	score -= 2;
}

bool flag3 = true;
void moveCar3() 
{
	
	if (c3 >10 && flag3)	//keeping the conditions as they were provided
	{
		c3 -= 10;
		if(c3 < 100)	//to restrict the car moving from more than 400 pixels in horizontal (left)
			flag3 = false;
	}
	else if (c3 < 1010 && !flag3) //moving the car to the right in else part 
	{
		c3 += 10;

		if (c3 > 300)	//to restrict the car moving from more than 500 pixels in horizontal (right)
			flag3 = true;
		
	}
	// here we are checking if the car collides with this particular car the score is decreased by 2
	if( ( ( xI >= (c3 - 50) ) && (xI <= (c3 + 50) ) ) && ( ( yI >= (_c3 - 50) ) && (yI <= (_c3 + 50) ) ) )	
	score -= 2;
}
	
bool flag4 = true;
void moveCar4()
 {
	
	if (_c4 > 10 && flag4)		// the car is moving up and down automatically
	{				// we are restricting the boundries
		_c4 -= 10;
		
		if(_c4 < 500)	//restricting to move more than 550 pixels in y direction
			
			flag4 = false;

	}
	else if (_c4 < 1010 && !flag4) 	//restricting to move more than 850 pixels in y direction
	{	
		_c4 += 10;
		if (_c4 > 850)
			flag4 = true;
	}
	// here we are checking if the car collides with this particular car the score is decreased by 2
	if( ( ( xI >= (c4 - 50) ) && (xI <= (c4 + 50) ) ) && ( ( yI >= (_c4 - 50) ) && (yI <= (_c4 + 50) ) ) )	
	score -= 2;
}

bool flag5 = true;
void moveCar5() {
	
	if (_c5 > 10 && flag5)
	{			// the car is moving in y direction
		_c5 -= 10;
		
		if(_c5 < 100)	// restricting the boundries of car not more then 100 (downwards)
			
			flag5 = false;

	}
	else if (_c5 < 1010 && !flag5) 
	{
		
		_c5 += 10;	//restricting the pixels to 850 in y direction
		if (_c5 > 700)
			flag5 = true;
	}
	// here we are checking if the car collides with this particular car the score is decreased by 2
	if( ( ( xI >= (c5 - 50) ) && (xI <= (c5 + 50) ) ) && ( ( yI >= (_c5 - 50) ) && (yI <= (_c5 + 50) ) ) )	
	score -= 2;
}


void GameDisplay()
{
	//In this function we are actually displaying every single shape and funxtinality
	
	glClearColor(0, 0,0.0, 0 ); 	// Red==Green==Blue==1 --> White Colour
	
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	
	//setting the outer box to be white in color
	DrawSquare( 0 , 0 , 5000 , colors[WHITE]); 
	
	// drawing the grid lowest value of x-axis is 100 and maximum is 1100
	// max value of y-axis is 1050 and lowest is set to 10. 
	// width of the lines is 2
	DrawLine( 100 , 100 ,  100 , 1050 , 2 , colors[BLACK] );
	DrawLine( 150 , 100 ,  150 , 1050 , 2 , colors[BLACK] );
	DrawLine( 200 , 100 ,  200 , 1050 , 2 , colors[BLACK] );
	DrawLine( 250 , 100 ,  250 , 1050 , 2 , colors[BLACK] );
	DrawLine( 300 , 100 ,  300 , 1050 , 2 , colors[BLACK] );
	DrawLine( 350 , 100 ,  350 , 1050 , 2 , colors[BLACK] );
	DrawLine( 400 , 100 ,  400 , 1050 , 2 , colors[BLACK] );
	DrawLine( 450 , 100 ,  450 , 1050 , 2 , colors[BLACK] );
	DrawLine( 500 , 100 ,  500 , 1050 , 2 , colors[BLACK] );
	DrawLine( 550 , 100 ,  550 , 1050 , 2 , colors[BLACK] );
	DrawLine( 600 , 100 ,  600 , 1050 , 2 , colors[BLACK] );
	DrawLine( 650 , 100 ,  650 , 1050 , 2 , colors[BLACK] );
	DrawLine( 700 , 100 ,  700 , 1050 , 2 , colors[BLACK] );
	DrawLine( 750 , 100 ,  750 , 1050 , 2 , colors[BLACK] );
	DrawLine( 800 , 100 ,  800 , 1050 , 2 , colors[BLACK] );
	DrawLine( 850 , 100 ,  850 , 1050 , 2 , colors[BLACK] );
	DrawLine( 900 , 100 ,  900 , 1050 , 2 , colors[BLACK] );
	DrawLine( 950 , 100 ,  950 , 1050 , 2 , colors[BLACK] );
	DrawLine( 1000 ,100 , 1000 , 1050 , 2 , colors[BLACK] );
	DrawLine( 1050 , 100 , 1050 , 1050 , 2 ,colors[BLACK] );
	DrawLine( 1100 , 100 , 1100 , 1050 , 2 ,colors[BLACK] );
	
	DrawLine( 100 , 1050 , 1100 , 1050 , 2, colors[BLACK] );	//upper line
	DrawLine( 100 , 100 , 1100 , 100 , 2 ,  colors[BLACK] );	//lower line
	
	// here we are drawing the building blocks (black in color)
	DrawSquare(250, 300, 50, colors[BLACK]);
	DrawSquare(250, 350, 50, colors[BLACK]);
	DrawSquare(250, 400, 50, colors[BLACK]);
	
	DrawSquare(300, 500, 50, colors[BLACK]);
	DrawSquare(300, 550, 50, colors[BLACK]);

	DrawSquare(450, 750, 50, colors[BLACK]);
	DrawSquare(450, 800, 50, colors[BLACK]);
	DrawSquare(450, 850, 50, colors[BLACK]);
	
	 DrawSquare(500, 350, 50, colors[BLACK]);
	 DrawSquare(500, 550, 50, colors[BLACK]);
	 DrawSquare(500, 600, 50, colors[BLACK]);
	 DrawSquare(500, 650, 50, colors[BLACK]);
	
	 DrawSquare(550, 200, 50, colors[BLACK]);
	 DrawSquare(550, 150, 50, colors[BLACK]);
	 DrawSquare(550, 100, 50, colors[BLACK]);
	 
	 
	 DrawSquare(600, 350, 50, colors[BLACK]);
	
	 DrawSquare(650, 350, 50, colors[BLACK]);
	 DrawSquare(650, 400, 50, colors[BLACK]);
	 DrawSquare(650, 450, 50, colors[BLACK]);
	 
	
	   DrawSquare(750, 700, 50, colors[BLACK]);
	
	   DrawSquare(800, 350, 50, colors[BLACK]);
	   DrawSquare(800, 400, 50, colors[BLACK]);
	 
	   DrawSquare(850, 400, 50, colors[BLACK]);
	   
	    DrawSquare(1000, 850, 50, colors[BLACK]);
	   DrawSquare(1000, 800, 50, colors[BLACK]);  
	   DrawSquare(1000, 750, 50, colors[BLACK]);
	   DrawSquare(1000, 650, 50, colors[BLACK]);
	   
	   DrawSquare(1050, 800, 50, colors[BLACK]);  
	   
	   // this call displays the SCORE = in top left corner
	   DrawString(100 , 1150 , "Score = ", colors[RED]);
	   
	   // this function displays the current score of the player as it uses the function Num2str 
	   //wich converts our score to string and displays it
	   
	   DrawString(170 , 1150 , Num2Str(score), colors[RED]);
	  
	
	// Trianlge Vertices v1(300,250) , v2(500,350) , v3(400,250)
	// drawing triangles
	DrawTriangle( 200, 150 , 250 , 150 , 225 , 250, colors[BROWN] ); 
	DrawTriangle( 500, 750 , 550 , 750 , 525 , 850, colors[BROWN] ); 
	
	//since display function can only display the shapes. passanger function is called inside it
	
	passenger(); // to displsy the passenger
	
	
	
	// here these boolean flag and if statments are used to check that the passenger is being dropped on the desired location
	// so that the color of the position turns to the color of canvas as befor i.e white 
	// bool variable is being changed in NON PRINTABLE KEYS function
	if (flag_1_)
	{
	DrawSquare(900, 500, 50, colors[WHITE]); 
	
	}
	if(flag_2_){
	DrawSquare(600, 200,50, colors[WHITE]);
	
	}
 	
	if(flag_3_){
	DrawSquare(200, 500,50, colors[WHITE]);
	}
	
	if(flag_4_)
	{
	DrawSquare(300, 800,50, colors[WHITE]);
	
	}
	
	
	if(flag_5_)
	{
	DrawSquare(400, 200,50, colors[WHITE]);
	
	}
	
	//since display function can only display the shapes, drawCar function is called inside it
	drawCar();
	glutSwapBuffers(); // do not modify this line..
			
}	


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */
void NonPrintableKeys(int key, int x, int y)
{
	// here we have developed condition for restricting our taxi to pass the obstacles
	
	
	//if the axis of the taxi matches with the axis of obstacles 
	// and dedecting the pixels in left side we develop the following condition 
		if ( (key == GLUT_KEY_LEFT) && (xI<=100)
	
 	||(xI==250 && yI >= 150 && yI <= 225) //for the triangle
 	||(xI==550 && yI >= 525 && yI <= 750) //triangle
 	
 	||(xI==300 && yI >= 300 && yI <= 350)
 	|| (xI==300 && yI >=350 && yI <=400) 
 	||(xI==300 && yI >= 400 && yI <= 450)
 
	||(xI==350 && yI >= 500 && yI <= 550) 
	||(xI==350 && yI >= 550 && yI <= 600) 
	
	|(xI==500 && yI >= 750 && yI <= 800)
	||(xI==500 && yI >= 800 && yI <= 850)
	||(xI==500 && yI >= 850 && yI <= 900)

	||(xI==550 && yI >= 350 && yI <= 400)
	||(xI==550 && yI >= 550 && yI <= 600)
 	
 	||(xI==600 && yI >= 200 && yI <= 250)
 	||(xI==600 && yI >= 150 && yI <= 200)
 	||(xI==600 && yI >= 100 && yI <= 150)
  
 	 ||(xI==650 && yI >= 350 && yI <= 400)
 	
   
   	||(xI==700 && yI >= 350 && yI <= 400)
   	||(xI==700 && yI >= 400 && yI <= 450)
   	||(xI==700 && yI >= 450 && yI <= 500) 
     
    	||(xI==800 && yI >= 700 && yI <= 750)
     
     
      ||(xI==850 && yI >= 350 && yI <= 400)
      || (xI==850 && yI >= 400 && yI <= 450)
       
      ||(xI==900 && yI >= 400 && yI <= 450)
       
 
             
      || (xI==1050 && yI >= 800 && yI <= 850)||(xI==1050 && yI >= 850 && yI <= 900)
      || (xI==1050 && yI >= 650 && yI <= 700)||(xI==1050 && yI >= 750 && yI <= 800)
      
    )       
	// when taxi collides while moving left the score is deduced and pixels of the taxi are not changed 
	//as it does not moves from the obstacles
	score -= 2;
					
	//else there is no detection of obstacle while moving left side the car can move to left 
	//further by 10 					
	else 
	{
	if  (key == GLUT_KEY_LEFT )
		xI -= 10 ;
		
	}
	
			
	 if  ( (key == GLUT_KEY_RIGHT) && (xI>=1050) 
	 ||(xI==150 && yI >= 150 && yI <= 225) //for the triangle
 	||(xI==450 && yI >= 525 && yI <= 750)	//for triangle
 	
 	||(xI==200 && yI >= 300 && yI <= 350) || (xI==200 && yI >=350 && yI <=400) ||(xI==200 && yI >= 400 && yI <= 450)
 	
	||(xI==250 && yI >= 500 && yI <= 550) 
	||(xI==250 && yI >= 550 && yI <= 600) 

	 ||(xI==400 && yI >= 750 && yI <= 800)
	||(xI==400 && yI >= 800 && yI <= 850)
	||(xI==400 && yI >= 850 && yI <= 900)

	||(xI==450 && yI >= 350 && yI <= 400)
	||(xI==450 && yI >= 550 && yI <= 600)
 
 	||(xI==500 && yI >= 200 && yI <= 250)
 	||(xI==500 && yI >= 150 && yI <= 200)
 	||(xI==600 && yI >= 100 && yI <= 150)
  
 	 ||(xI==550 && yI >= 350 && yI <= 400)
 	
   
   	||(xI==600 && yI >= 350 && yI <= 400)
   	||(xI==600 && yI >= 400 && yI <= 450)
   	||(xI==600 && yI >= 450 && yI <= 500) 
 
   	 ||(xI==700 && yI >= 700 && yI <= 750)
   
     
	 ||(xI==750 && yI >= 350 && yI <= 400)
     	 ||(xI==750 && yI >= 400 && yI <= 450)
       
  	  ||(xI==800 && yI >= 400 && yI <= 450)
           
     || (xI==950 && yI >= 800 && yI <= 850)||(xI==950 && yI >= 850 && yI <= 900)
      || (xI==950 && yI >= 650 && yI <= 700)||(xI==950 && yI >= 750 && yI <= 800)
	 
	
     )
     // when taxi collides while moving right the score is deduced and pixels of the taxi are not changed
     // as it does not moves from the obstacles
		score -= 2;
	//else there is no detection of obstacle while moving right side the car can move to right
	//further by 10 	

	else 
	{
	if (key == GLUT_KEY_RIGHT )
		xI+=10;
		
		
	}
		
			
if ( (key == GLUT_KEY_DOWN) && (yI<=100)

  ||(yI==225 && xI >= 200 && yI <= 250) //for the triangle
 ||(yI==750 && yI >= 500 && yI <= 550) //triangle
  
  
 || (yI== 450  && xI >= 240 && xI <= 290)||(yI==350 && xI >= 240 && xI <= 290)
 || (yI == 400 && xI >= 240 && xI <= 290)
 
 
 ||(yI== 550 && xI >= 290 && xI <= 340) 
 ||(yI== 600 && xI >= 290 && xI <= 340)
 
  ||(yI==800 && xI >= 440 && xI <= 490) || (yI==850 && xI >= 440 && xI <= 490) || (yI==900 && xI >= 440 && xI <= 490)
 

  ||(yI==250 && xI >= 540 && xI <= 590) 
  ||(yI==200 && xI >= 540 && xI <= 590)
  ||(yI==150 && xI >= 540 && xI <= 590)
 
 ||(yI==400 && xI >= 590 && xI <= 640)


  ||(yI==400 && xI >= 640 && xI <= 690) || (yI==500 && xI >= 640 && xI <= 690)
  ||(yI==450 && xI >= 640 && xI <= 690) 
  

   ||(yI==800 && xI >= 740 && xI <= 790) 
     
   ||(yI==450 && xI >= 790 && xI <= 840) || (yI==400 && xI >= 790 && xI <= 840) 
  
   ||(yI==450 && xI >= 840 && xI <= 890)
  
   ||(yI==900 && xI >= 1000 && xI <= 1050) || (yI==850 && xI >= 1000 && xI <= 1050) 
   ||(yI==800 && xI >= 1000 && xI <= 1050) || (yI==700 && xI >= 1000 && xI <= 1050) 
             
   )
    // when taxi collides while moving down the score is deduced because collision is detected and pixels of the taxi are not changed
     // as it does not moves from the obstacles
	score -= 2;
 
	 //else there is no detection of obstacle while moving down the car can move to down
	//further by 10 
 	else 
 	{
 	if (key == GLUT_KEY_DOWN)
 		yI -= 10;
 		
 	}		
		
if ( (key == GLUT_KEY_UP) && (yI>=1000) 

	||(yI==200 && xI >= 200 && yI <= 250) //for the triangle
 	||(yI==850 && yI >= 500 && yI <= 550) //triangle
	
  || (yI== 350  && xI >= 250 && xI <= 300) ||(yI==250 && xI >= 250 && xI <= 300)
  || (yI == 300 && xI >= 250 && xI <= 300) 
 
 
 ||(yI== 450 && xI >= 290 && xI <= 340) 
 ||(yI== 500 && xI >= 290 && xI <= 340)
 
  ||(yI==700 && xI >= 440 && xI <= 490) || (yI==750 && xI >= 440 && xI <= 490) || (yI==800 && xI >= 440 && xI <= 490)
 

  ||(yI==150 && xI >= 540 && xI <= 590) 
  ||(yI==100 && xI >= 540 && xI <= 590)
  ||(yI==150 && xI >= 540 && xI <= 590)	
 
 ||(yI==300 && xI >= 590 && xI <= 640)


  ||(yI==300 && xI >= 640 && xI <= 690) || (yI==400 && xI >= 640 && xI <= 690)
  ||(yI==350 && xI >= 640 && xI <= 690) 
  

   ||(yI==700 && xI >= 740 && xI <= 790) 
     
   ||(yI==350 && xI >= 790 && xI <= 840) || (yI==300 && xI >= 790 && xI <= 840) 
  
   ||(yI==350 && xI >= 840 && xI <= 890)
  
   ||(yI==800 && xI >= 1000 && xI <= 1050) || (yI==750 && xI >= 1000 && xI <= 1050) 
   ||(yI==700 && xI >= 1000 && xI <= 1050) || (yI==600 && xI >= 1000 && xI <= 1050) )
   
   // when taxi collides while moving up the score is deduced because collision is detected and pixels of the taxi are not changed
     // as it does not moves from the obstacles
	score -= 2;
		
	//else there is no detection of obstacle while moving up the car can move to up
	//further by 10 
	else 
	{
		if (key == GLUT_KEY_UP)	
		yI += 10;
		
	}
   		
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}



/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
 



void PrintableKeys(unsigned char key, int x, int y)
 {
	
    	// ASCII code foe space bar is 32 and here if condition is used to check when it is pressed to proceed the further working
 if ( key == 32 )
 {
 	//when the enter key is pressed and taxi has reached the loaction of passenger then bool variable
 	// is becomes true which proceeds to "passenger" function where then desitantions are generated
 	
 	
 	 if( ( ( xI >= (1030 - 50) ) && (xI <= (1030 + 50) ) ) && ( ( yI >= (1000 - 50) ) && (yI <= (1000 + 50) ) ) )
 	{
 		var = true ;
 	}
 	if( ( ( xI >= (1020 - 50) ) && (xI <= (1020 + 50) ) ) && ( ( yI >= (300 - 50) ) && (yI <= (300 + 50) ) ) )
 	
 	{
 		var1 = true ;
 	}
 	
 	 if( ( ( xI >= (830 - 50) ) && (xI <= (830 + 50) ) ) && ( ( yI >= (220 - 50) ) && (yI <= (220 + 50) ) ) )
 	{
 		var2 = true ;
 	}
 	
 	 if( ( ( xI >= (630 - 50) ) && (xI <= (630 + 50) ) ) && ( ( yI >= (620 - 50) ) && (yI <= (620 + 50) ) ) )
 	{
 		var3 = true ;
 	}
 	 if( ( ( xI >= (230 - 50) ) && (xI <= (230 + 50) ) ) && ( ( yI >= (850 - 50) ) && (yI <= (850 + 50) ) ) )
 	{
 		var4 = true ;
 	}
 	
 	// flag_1 (and so on) is being changed as per conditions evaluation in function "passenger"
 	// it then changes the flag_1_ (so on..) which results are displayed in gameDisplay function 
 	if ( flag_1 )
 	{
 	flag_1_=true;
 	score += 10;	//as the passenger is being dropped at desired locations the score is increment by 10
 	}
 	if ( flag_2 )
 	{
 	flag_2_=true;
 	score += 10;
 	}
 	if ( flag_3 )
 	{
 	flag_3_=true;
 	score += 10;
 	}
 	if ( flag_4 )
 	{
 	flag_4_=true;
 	score += 10;
 	}
 	if ( flag_5 )
 	{
 	flag_5_=true;
 	score += 10;
 	}
 	
 		
 	
 }		
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
// int counter = 0;
void Timer(int m) {
	
	// timer function will move the car after every 1000.0/FPS milliseconds
	// which will show that cars are moving constantly (as function is called frequently times)
	moveCar1();

	moveCar2();

	moveCar3();

	moveCar4();

	moveCar5();
	time_lim -= 1 ; //every time this function is called the value is reduced by 1
	if( time_lim == 0) //when time reduced to 1
	exit (1);	//function exits
	
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(75, Timer, 0);
	
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	
	glutPostRedisplay();
}
void MouseMoved(int x, int y) 
{

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y)
 {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		//cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		//	cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) 
{
	int opt; // to ask user to start the game
	
	
	cout << setw(20)<< "*******************************************************"<<endl;
	cout << setw(20)<< "*                                                     *"<<endl;
	cout << setw(20)<< "*                 RUSH HOUR                           *"<<endl;
	cout << setw(20)<< "*                                                     *"<<endl;
	cout << setw(20)<< "*******************************************************"<<endl;
	
	cout << setw(20)<< "Enter the color for your taxi either RED or YELLOW. "<<endl;
	cin >> taxi_color;
	
	cout <<"Enter your name."<<endl;
	cin >> name;
	
	
	cout<< setw(20) <<"Enter 1 to start the game."<<endl;
	cin >>opt;
	
	if (opt==1)	//when user enters 1 means the game starts
	{
	int width = 1200, height = 1200; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);



	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}	
}
#endif /* RushHour_CPP_ */
