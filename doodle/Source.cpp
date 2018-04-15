// shake.cpp: определяет точку входа для консольного приложения.
//


#include <GL/glut.h> 
#include <GL/gl.h> 
#include <time.h> 
#include <random> 
#include <iostream>

#include "Person.h"
#include "Platform.h"
#include "PlatformBasic.h"
#include "PlatformToss.h"
#include "Coord.h"
#include "Game.h"

#define PLATFORMS 10

Person doodle;
Platform *platform[PLATFORMS];
Game game;

using namespace std;


int h = 250;
float dx = 0, dy = 0;

unsigned int Score = 0;


int i, j;
bool a;
static DWORD last_idle_time;

/* Через сколько секунд менять сцену */
#define ANIM_INTERVAL 0.005
int randX= 0;
void animate(){
	double dt;
	DWORD time_now;
	time_now = GetTickCount();  // Число миллисекунд с момента старта системы.
	dt = (double)(time_now - last_idle_time) / 1000.0;	// Число секунд с прошлой отрисовки анимации
	if (dt >= ANIM_INTERVAL) {
		game.Calculate();
		//dy += 0.2;
		//doodle.SetPositionY(doodle.GetPosition().y - dy);
		//

		//if (doodle.GetPosition().y > h) {
		//	for (i = 0; i < PLATFORMS; i++){
		//		
		//		doodle.SetPositionY(h);
		//		platform[i]->MovePositionY(dy);
		//		PA.MoveY(dy);///////////////////
		//		if (platform[i]->GetPosition().y < 0) {
		//			do {
		//				a = true;
		//				randX = rand() % 400;
		//				if (randX < 34) randX = 35 + rand() % 50;
		//				if (randX > (400 - 34)) randX = (400 - 35) - rand() % 50;
		//				if ((randX > platform[i]->GetPosition().y + 34 && randX < platform[i]->GetPosition().y - 34)) {
		//					a = false;
		//				}
		//				platform[i]->SetPosition(Coord(randX, 533));
		//				for (j = 0; j < PLATFORMS; j++) {
		//					if (platform[i]->GetPosition().x + 20 < platform[j]->GetPosition().y) {
		//						platform[i]->MovePositionY(20);
		//					}
		//					
		//				}
		//				
		//			} while (!a);
		//			
		//			Score++;
		//		}
		//		
		//	}
		//}
		//	

		//for (i = 0; i < PLATFORMS; i++) {
		//	int sizeD = 30;

		//	if ((doodle.GetPosition().x + sizeD >= platform[i]->GetPosition().x - 34 &&
		//		doodle.GetPosition().x - sizeD <= platform[i]->GetPosition().x + 34) &&
		//		(doodle.GetPosition().y >= platform[i]->GetPosition().y - 7 &&
		//			doodle.GetPosition().y - sizeD <= platform[i]->GetPosition().y + 7) &&
		//			(dy > 0)) {
		//		if (typeid(*platform[i]) == typeid(PlatformToss)) {
		//			dy = -15;
		//			cout << "chooooock" << endl;
		//		}
		//		else {
		//			dy = -8;
		//			cout << "chock" << endl;
		//		}
		//		
		//		
		//	}
		//	if (doodle.GetPosition().y < 0) {
		//		doodle.SetPositionY(300);
		//		cout << "fail" << endl;
		//	}
		//}
		//
		
		last_idle_time = time_now;
		glutPostRedisplay();
	}
	//glutPostRedisplay();
}


void Key(int key, int a, int b) // функция нажатия клавиш 
{
	switch (key) // используем оператор switch 
	{
	case GLUT_KEY_LEFT: 
		game.MoveLeft();
		//x -= 3; 
		doodle.MovePositionX(-7);
		doodle.LookLeft();
		break; // при нажатии клавиш, задаем направление змеи(вверх, вниз, влево, вправо) 
	case GLUT_KEY_RIGHT: 
		game.MoveRight();
		//x += 3;
		doodle.MovePositionX(7);
		doodle.LookRight();
		break;
	
	}
	if (doodle.GetPosition().x < 0) {
		//x = 400;
		doodle.SetPositionX(400);
	};
	if (doodle.GetPosition().x > 400) {
		//x = 0;
		doodle.SetPositionX(0);
	};
}


GLuint LoadTexture(const char * filename, int width, int height)
{
	GLuint texture;
	unsigned char * data;

	FILE * file;



	file = fopen(filename, "rb");
	if (file == NULL) return 0;
	data = (unsigned char *)malloc(width * height * 4);
	fread(data, width * height * 4, 1, file);
	fclose(file);
	
	unsigned char blue;

	for (int i = 0; i < width * height * 4; i += 4)
	{
		blue = data[i];
		data[i] = data[i + 2];
		data[i + 2] = blue;
	}


	

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
	//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);


	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	free(data);
	return texture;
}
GLuint LoadTexture2(const char * filename, int width, int height)
{
	GLuint texture;
	unsigned char * data;

	FILE * file;



	file = fopen(filename, "rb");
	if (file == NULL) return 0;
	data = (unsigned char *)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);
	
	unsigned char blue;

	for (int i = 0; i < width * height * 3; i += 3)
	{
	blue = data[i];
	data[i] = data[i + 2];
	data[i + 2] = blue;
	}

	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);



	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);
	return texture;
}
GLuint texture;
GLuint texture1;

char score[50];
void Display() //функция общий отрисовки 
{

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	glEnable(GL_TEXTURE_2D);

	game.Render();
	///doodle.Draw();
	//PA.Draw();

	for (size_t i = 0; i < PLATFORMS; i++){
		///platform[i]->Draw();
	}
	

	glColor3f(0.0f, 0.0f, 1.0f);
	glRasterPos2f(40, 20);
	sprintf(score,"score: %d",Score);
	for (int j = 0; j < strlen(score); j++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[j]);
	}
	
	glColor3f(1.0, 1.0, 1.0);


	//glFlush(); // выводим на экран все вышеописанное 
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv) // Главная функция 
{
	srand(time(NULL));

	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(400, 533);
	glutCreateWindow("OpenGL drawing");

	//glEnable(GL_TEXTURE_2D);
	glutReshapeFunc(reshape);

	glutDisplayFunc(Display); // ... и этой, она вызывает начальную функцию, в нашем случае это главная функция отрисовки - Display 
	glutSpecialFunc(Key);
	//glutKeyboardUpFunc();

	//glutTimerFunc(50, timer, 0); // ... Ну и в начале программы задаем рекурсивный таймер. 
	glutIdleFunc(animate);

	texture = LoadTexture2("doodle.bmp", 512, 512);
	
	////
	Coord coords;
	coords.x = 200;
	coords.y = 100;
	doodle = Person(coords, texture);

	//texture = LoadTexture("doodle_platform.bmp", 256, 256);
	//texture = LoadTexture2("doodle.bmp", 512, 512);
	game = Game(LoadTexture2("doodle_platform1.bmp", 256, 256));
	//game.SetTexture(texture);
	//game.SetPlatformTexture(LoadTexture2("doodle_platform.bmp", 256, 256));
	//PA = PlatformArrangement(texture);
	//PA.MoveY(1);
	
	for (int i = 0; i<PLATFORMS-2; i++){
		//platform[i] = new PlatformBasic(Coord(rand() % 400, rand() % 533), texture);
	}
	//platform[0]->SetPosition(Coord(200,20));
	//platform[8] = new PlatformToss(Coord(rand() % 400, rand() % 533), texture);
	//platform[9] = new PlatformToss(Coord(rand() % 400, rand() % 533), texture);
	
	////

	glutMainLoop();

	return 0;
}

