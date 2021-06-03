#include"libOne.h"
void gmain(){
	window(1920, 1080,full);
	float px = 1920 / 2;
	float py = 1080 / 2;
	float vx = 10;
	float r = 150;
	float len = r / 1.4142f * 2;
	float sw = r / 8;
	float angle = 0;          
	float angles = 0.03f;  //angleSpeed
	while (notQuit) {
		px += vx;
		angle += angles;
		if (px > 1920 || px < 0) {
			vx = -vx;      //-(-10)
			angles = -angles;
		}

		clear(200);
		strokeWeight(sw);
		stroke(255, 0, 0);
		circle(px, py, r * 2);
		rectMode(CENTER);
		rect(px, py, len, len,angle);
		strokeWeight(sw * 4);
		point(px,py);
		strokeWeight(sw);
		line(1920/2, 0, px, py);
	}
}
