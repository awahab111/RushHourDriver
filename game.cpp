#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
int  * spawn_cars(bool &);
int global_false = 0; 
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
//Outputs the coordinates of the 4 corners of any shape
int coordinate (int x1_min, int y1_min, int arr[], int width = 0,int height = 0, int index = 0){
	int x1_max = 0, y1_max = 0;
	arr[index] = x1_min;
	arr[index + 1] = y1_min;
	if (width > 0) {
		x1_max = x1_min + width;
		if(height == 0){ //if the shape is a square we will surely not require height as height will be equal to width
			y1_max = y1_min + width;
		}
		else if(height > 0){
			y1_max = y1_min + height;
		}
	}
	arr[index + 2]= x1_max;
	arr[index + 3] = y1_max;
	glutPostRedisplay();
}
//Takes an array which is then edited with values such as 0 or 1 to work as boolean
int is_collision (int x1_min , int x1_max, int y1_min, int y1_max, int x2_min, int x2_max, int y2_min, int y2_max, int collision_arr[]){
	if((y1_min < y2_max && y1_max > y2_min) ){
		if(x1_min == x2_max) //On the right side of the box
			collision_arr[0] =  1;
		else {collision_arr[0] = 0;}
		if(x1_max == x2_min) //On the left side of the box
			collision_arr[1] = 1;
		else {collision_arr[1] = 0;}
	}
	else if(x1_min < x2_max && x1_max > x2_min){
		if(y1_min == y2_max) //Below the box
			collision_arr[2] = 1;
		else {collision_arr[2] = 0;}
		if(y1_max == y2_min) //Above the box
			collision_arr[3] =1;
		else {collision_arr[3] = 0;}
	}
	else{
		for (int i = 0; i < 4; i++)
		{
			collision_arr[i] = 0;
		}
		
	}
}

int car[3] = {0, 800, 20}; //{xI, yI, width} already declared

void drawCar() {
	
	DrawSquare(car[0], car[1], car[2], colors[YELLOW]);
	glutPostRedisplay();
}

//Automatic Car Movement with collision
int flag = true;
void moveCar(int &auto_car_y , int &x_axis, int &car_no){
	bool const_false = false;
	int coordinate_car_arr[4];
	int auto_car_collision[4];
	int auto_cars[12];
	bool static flag_1 = true;
	bool collision_flag_1 = true, collision_flag_2 = true, collision_flag_3 = true ;
	coordinate(car[0], car[1], coordinate_car_arr,20);
	if(car_no == 1){
		
		coordinate((x_axis * 50)+10, auto_car_y,auto_cars, 20, 0 , 0);
		is_collision(coordinate_car_arr[0],coordinate_car_arr[2],coordinate_car_arr[1],coordinate_car_arr[3],auto_cars[0],auto_cars[2],auto_cars[1],auto_cars[3], auto_car_collision);
		if((auto_car_collision[0] && auto_car_collision[2]) || (auto_car_collision[1] && auto_car_collision[3])){
			collision_flag_1 = false;
		}
		while (collision_flag_1){
			if (auto_car_y > 0 && flag) {
				auto_car_y += 10;
				if(auto_car_y > 800)
					flag = false;
			}
			else if (auto_car_y > 100 && !flag) {
				auto_car_y -= 10;
				if (auto_car_y < 150)
					flag = true;
			}
			break;
		}
	}
	else if(car_no == 2){
		coordinate((x_axis *50)+10, auto_car_y, auto_cars, 20,0,4);
		
		is_collision(coordinate_car_arr[0],coordinate_car_arr[2],coordinate_car_arr[1],coordinate_car_arr[3],auto_cars[4],auto_cars[6],auto_cars[5],auto_cars[7], auto_car_collision);
		if((auto_car_collision[0] || auto_car_collision[2]) || (auto_car_collision[1] || auto_car_collision[3])){
			collision_flag_2 = false;
		}
		while (collision_flag_2){
			if (auto_car_y > 0 && flag) {
				auto_car_y += 10;
				if(auto_car_y > 800)
					flag = false;
			}
			else if (auto_car_y > 100 && !flag) {
				auto_car_y -= 10;
				if (auto_car_y < 150)
					flag = true;
			}
			break;
		}
	}
	else if (car_no == 3)
	{
		coordinate((x_axis *50)+10, auto_car_y, auto_cars, 20,0,8);
		is_collision(coordinate_car_arr[0],coordinate_car_arr[2],coordinate_car_arr[1],coordinate_car_arr[3],auto_cars[8],auto_cars[10],auto_cars[9],auto_cars[11], auto_car_collision);
		if((auto_car_collision[0] || auto_car_collision[2]) || (auto_car_collision[1] || auto_car_collision[3])) {
			collision_flag_3 = false;
		}
		while (collision_flag_3){
			if (auto_car_y > 0 && flag) {
				auto_car_y += 10;
				if(auto_car_y > 800)
					flag = false;
			}
			else if (auto_car_y > 100 && !flag) {
				auto_car_y -= 10;
				if (auto_car_y < 150)
					flag = true;
			}
			break;
			}
	}
	else{
	}
	
}
// Random Generation 
int * random_generation(){
	static int flag_1 = 0;
	int static building_arr[40];
	if(flag_1 == 0){
		for(int k = 0; k < 40; k+=2){
			building_arr[k] =  GetRandInRange(100, 700); //y axis
			building_arr[k+1] = GetRandInRange(80, 180);//height
			while((building_arr[k] % 10) || (building_arr[k+1] % 10)){
				building_arr[k] =  GetRandInRange(100, 700); //y axis
				building_arr[k+1] = GetRandInRange(80, 180);//height
			}
		}
		flag_1++;
		return building_arr;
	}
	else {
		return building_arr;
	}
}
int * spawn_cars(bool &flag){
	int static auto_car_y[3] = {200, 500, 400};
	int static flag_3 = 0;
	int static empty_roads[3];
	if (flag_3 == 0){
		empty_roads[0] = GetRandInRange(1, 5);
		empty_roads[1] = GetRandInRange(6, 11);
		empty_roads[2] = GetRandInRange(11, 20);
		flag_3++;
		return empty_roads;
	}
	else if(flag){
		return empty_roads;
	}
	DrawSquare(((empty_roads[0] *50)+10),auto_car_y[0],20,colors[CADET_BLUE]);
	DrawSquare(((empty_roads[1] *50)+10),auto_car_y[1],20,colors[CADET_BLUE]);
	DrawSquare(((empty_roads[2] *50)+10),auto_car_y[2],20,colors[CADET_BLUE]);
	glutPostRedisplay();
	return auto_car_y;
}
int * spawn_passengers(int &empty_1_road,int &empty_2_road, int &empty_3_road ){
	int *p;
	int buildings[80];
	int static passenger[10];
	int static flag_2 = 0;
	p = random_generation();
	for(int i = 0, j = 0, k = 0, l = 0; i < 20; i++, j+=51 , k+=2, l+=4){
		coordinate(j, *(p+k),buildings,51,*(p+(k+1)),l);
	}
	if(flag_2 == 0){
		for (int i = 0; i < 10; i+=2){
			passenger[i] = GetRandInRange(100 , 900); //X axis
			passenger[i + 1] = GetRandInRange(100 , 700); //y axis
			
			for (int k = 0; k < 80; k+=4){
				while (((passenger[i] + 5) + 10) > (buildings[k]) && ((passenger[i] - 5) - 10) < (buildings[k+2]) && ((passenger[i+1] + 5) + 10)> (buildings[k+1]) && ((passenger[i+1] - 5)-10)< (buildings[k+3]) ){
					if (passenger[i] - 5 > (empty_1_road * 51) && passenger[i] < (empty_1_road * 51) + 51 )
					{
						passenger[i] = GetRandInRange(100 , 900); //X axis
						passenger[i + 1] = GetRandInRange(100 , 700); //y axis
						i = 0;
					}
					else if (passenger[i] - 5 > (empty_1_road * 51) && passenger[i] < (empty_1_road * 51) + 51 )
					{
						passenger[i] = GetRandInRange(100 , 900); //X axis
						passenger[i + 1] = GetRandInRange(100 , 700); //y axis
					}
					else{
						k = 0;
						passenger[i + 1] = GetRandInRange(100 , 700);
						passenger[i] = GetRandInRange(100 , 900);
					}
					
				}
			}
		}
		flag_2++;
		return passenger;
	}
	else{
		return passenger;
	}
}
/*
 * Main Canvas drawing function.
 * */
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	bool const_false = false;
	int *p_1, *p_2, *p_3;
	int static flag_3 = 0;
	int static empty_road1, empty_road2, empty_road3;
	
	p_1 = random_generation();
	if (flag_3 == 0)
	{
		p_3 = spawn_cars(const_false);
		empty_road1 = *(p_3);
		empty_road2 = *(p_3 + 1); 
		empty_road3 = *(p_3 + 2);
		cout << empty_road1 <<" "<<empty_road2 << " " << empty_road3 <<endl;

	}
	flag_3++;
	p_2 = spawn_passengers(empty_road1, empty_road2, empty_road3);
	
	glClearColor(1/*Red Component*/, 1,	//148.1/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	//Display Score
	DrawString( 50, 800, "Score=0", colors[BLACK]);
	
	for (int i = 0 , j = 0, k = 0; i < 20; i++, j=j+50, k+=2)
	{
		DrawLine( j , 1 ,  j , 840 , 2 , colors[BLACK] );
		if( (j) == (empty_road1 * 50)){
			DrawRectangle(40000, *(p_1 + k), 51, *(p_1 + (k + 1)), colors[BLACK]);
		}
		else if( j == (empty_road2 * 50)){
			DrawRectangle(40000, *(p_1 + k), 51, *(p_1 + (k + 1)), colors[BLACK]);
		}
		else if( j == (empty_road3 * 50)){
			DrawRectangle(40000, *(p_1 + k), 51, *(p_1 + (k + 1)), colors[BLACK]);
		}
		else{
			DrawRectangle(j, *(p_1 + k), 50, *(p_1 + (k + 1)), colors[BLACK]);
		}

	}
	for (int i = 0; i < 10; i+=2)
	{
		DrawCircle(*(p_2 + i) , *( p_2 + (i + 1) ), 5, colors[RED]);
	}
	spawn_cars(const_false);
	
	// DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	// DrawCircle(50,670,10,colors[RED]);
	// DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);

	drawCar();
	glutSwapBuffers(); // do not modify this line..;
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

void NonPrintableKeys(int key, int x, int y) { 
	int coordinate_car_arr[4];
	int block_collision_arr[4];
	int auto_car_collision[4];
	int buildings[80] , auto_cars[8];
	bool static flag_4 = true;
	int static empty_road1 ,empty_road2, empty_road3;
	int *p, *p_1;

	p = random_generation();
	for (int i = 0; i < 4; i++){
			block_collision_arr[i] = 0;
	}
	if (flag_4)
	{
		p_1 = spawn_cars(flag_4);
		empty_road1 = *(p_1);
		empty_road2 = *(p_1 + 1); 
		empty_road3 = *(p_1 + 2); 
		flag_4 = false;
	}
	p_1 = spawn_cars(flag_4);

	coordinate (car[0],car[1], coordinate_car_arr, car[2]);
	for(int i = 0, j = 0, k = 0, l = 0; i < 20; i++, j+=50 , k+=2, l+=4){
			
			if( (i) == (empty_road1)){
				coordinate(40000, *(p+k),buildings,50,0,l);
			}
			else if(i == (empty_road2)){
				coordinate(40000, *(p+k),buildings,50,0,l);
			}
			else{
				coordinate(j, *(p+k),buildings,50,*(p+(k+1)),l);
			}
	}
	coordinate((empty_road1 * 50)+10, *(p_1),auto_cars, 20,0,0);
	coordinate((empty_road2 *50)+10, *(p_1+ 1), auto_cars, 20,0,4);
	coordinate((empty_road3*50)+10, *(p_1+ 2), auto_cars, 20,0,4);

	
	for(int i = 0; i < 80 ; i+=4){
		//cout << buildings[i] << " "<< buildings[i + 1] << " "<< buildings[i + 2] << " "<< buildings[i + 3] << endl;
		is_collision(coordinate_car_arr[0],coordinate_car_arr[2],coordinate_car_arr[1],coordinate_car_arr[3],buildings[i],buildings[i+2],buildings[i + 1],buildings[i + 3], block_collision_arr);
		if(block_collision_arr[0] || block_collision_arr[1] || block_collision_arr[2] || block_collision_arr[3]){
			break;
		}
	}
	if (key == GLUT_KEY_LEFT && (!block_collision_arr[0]) /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		car[0] -= 10;// what to do when left key is pressed...
	}
	else if (key == GLUT_KEY_RIGHT && (!block_collision_arr[1])) // && !collide_left /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{
		car[0] += 10;
	}
	else if (key == GLUT_KEY_UP && (!block_collision_arr[3] )) //&& !collide_bottom/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) 
	{
		car[1] += 10;
	}
	else if (key == GLUT_KEY_DOWN && (!block_collision_arr[2] )) //&& !collide_top/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) 
	{
		car[1] -= 10;
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
void PrintableKeys(unsigned char key, int x, int y) {
	int *p_1, *p_2;
	bool const_false = false;
	int coordinate_car_arr[4];
	int passenger_collision[4];
	bool static flag_5 = true;
	int static empty_road1, empty_road2, empty_road3;
	coordinate (car[0],car[1], coordinate_car_arr, car[2]);
	if (flag_5)
	{
		p_2 = spawn_cars(flag_5);
		empty_road1 = *(p_2);
		empty_road2 = *(p_2 + 1); 
		empty_road3 = *(p_2 + 2);
		flag_5 = false;
	}

	p_1 = spawn_passengers(empty_road1, empty_road2, empty_road3);

	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	for (int i = 0; i < 10; i+=2)
	{
		is_collision(coordinate_car_arr[0],coordinate_car_arr[2],coordinate_car_arr[1],coordinate_car_arr[3],*(p_1 + i) - 5,*( p_1 + i ) + 5,*(p_1 + i + 1) - 5,*(p_1 + i + 1) + 5, passenger_collision);
		if((passenger_collision[0] || passenger_collision[1] || passenger_collision[2] || passenger_collision[3]) && key == 32){
			cout << "Remove the Passenger"<<endl;
			break;
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
void Timer(int m) {
	int *p , *p_1;
	bool const_false = false;
	bool static flag_1 = true;
	int static empty_roads1, empty_roads2, empty_roads3;
	int car_1 = 1, car_2 = 2, car_3 = 3;
	p = spawn_cars(const_false);
	if(flag_1){
		p_1 = spawn_cars(flag_1);
		empty_roads1 = *(p_1);
		empty_roads2 = *(p_1 + 1);
		empty_roads3 = *(p_1 + 2);
		flag_1 = false;
	}
	
	moveCar(*(p) , empty_roads1, car_1);
	moveCar(*(p+1),empty_roads2, car_2);
	moveCar(*(p+2), empty_roads3, car_3);
	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(50, Timer, 0);
}


/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
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
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Abdul Wahab"); // set the title of our game window
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
#endif /* RushHour_CPP_ */
