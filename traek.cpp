#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
const float g = 9.8;
using namespace std;
struct Image
{
	int mx;
	int my;
	int* points;
};

void CreateImage(Image* img, int tmx, int tmy)
{
	img->mx = tmx;
	img->my = tmy;
	img->points = new int[tmx * tmy]{ 1 };
}

void SetPointImage(Image* img, int x, int y, int collor)
{
	img->points[(y * img->mx + x)] = collor;
}

int GetPointImage(Image* img, int x, int y)
{
	return img->points[(y * img->mx + x)];

}

void ShowImage(Image* img)
{
	for (int i = 0; i < img->my; i++)
	{
		for (int j = 0; j < img->mx; j++) 	cout << img->points[i * img->mx + j] << " ";

		cout << endl;
	}
}

void SaveToPnmFile(Image* img, string fileName)
{
	fstream out;
	out.open(fileName, fstream::out);
	out << "Image" << endl;
	out << img->mx << " " << img->my << endl;

	for (int i = 0; i < img->my; i++)
	{
		for (int j = 0; j < img->mx; j++)
		{
			out << img->points[i * img->mx + j] << " ";
		}
		out << endl;
	}
	out.close();
}



struct Ball {
  float h=100;
  float x=0;
  float y=h;

  float v0=0;
  float vy=0;
  float ax=0;
  float ay=-g;
  float m=0;

  Ball() {
  }
};


float t = 0;


void move(Ball* ball, float dt) {
	
	t=t+dt;
	ball->vy=ball->v0+ball->ay*t;
	ball->y=ball->h+ball->ay*0.5*t*t;
	if (ball->y <= 0) {
		ball->y = 0;
		ball->vy = 0;
	}
}


void show(Ball ball) {
	cout<<ball.y<<"		"<<abs(ball.vy)<<"		"<<abs(ball.ay)<<endl;
}

int main() {
	cout<<"t		y		vy		ay"<<endl;
	cout<<"==================================================="<<endl;
  float t = 0;
  Ball a;
  float deltaT = 1;
  for (int i=0; i<10; i++) {
  	 cout << t<<"		";
     move(&a, deltaT);     
     show(a);
     t = t + deltaT;           
  }
}
