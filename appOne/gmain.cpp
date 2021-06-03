#include"libOne.h"
void roundface(float px, float py) {
	strokeWeight(5);
	fill(255, 255, 0);
	circle(px, py, 300);
	fill(242, 177, 201);
	circle(px, py + 80, 80);
	fill(255);
	circle(px - 70, py - 50, 80);
	circle(px + 70, py - 50, 80);
	strokeWeight(20);
	point(px - 70, py - 50);
	point(px + 70, py - 50);

}

void gmain() {
	window(1920, 1080, full);
	//命
	/* //データ
	int life = 5;//命の数
	float px = 600;
	float py = 300;
	float r = 50;//円の大きさ
	float space = 100;//間隔
	while (notQuit) {
		clear(100);
		fill(255);
		print((let)"life=" + life);
		if (isTrigger(KEY_A)) { life--; }
		else if (isTrigger(KEY_D)) { life++; }
		//whileバージョン
		int i = 0;
		while (i < life) {
			float offsetX = space * i;
			strokeWeight(10);
			stroke(200);
			fill(255, 0, 0);
			circle(px + offsetX, py, r * 2);
			i++;
		}
		//forバージョン
		for (int i = 0; i < life; i++) {
			float offsetX = space * i;
			float offsetY = space * 2;
			strokeWeight(10);
			stroke(200);
			fill(0, 0, 255);
			circle(px + offsetX, py + offsetY, r * 2);
		}
	}
	*/
	//hpゲージ
	/*
	//データ
	float px = 760;
	float py = 200;
	float w = 500;
	float h = 100;
	float hp = 500;
	float vhp = 2;
	int R = 0;
	int G = 0;
	int B = 0;
	while (notQuit) {
		if (isTrigger(KEY_SPACE)) { hp = w; }
		if (hp > 150) {
			hp -= vhp;
			G = 255;
		}
		else if (hp > 50) {
			hp -= vhp;
			R = 255;
			G = 255;
		}
		else if (hp > 0) {
			hp -= vhp;
			R = 255;
			G = 0;
		}
		clear(100);
		if (hp == 0) {
		textSize(200);
		text("Game Over",600,500);
		}
		fill(50);
		rect(px, py, w, h);
		fill(R, G, B);
		rect(px, py, hp, h);
	}
	*/
	float px = width / 2;
	float py = height / 2;

	while (notQuit) {
		clear(60,120,240);
		roundface(0,540);
		rectMode(CENTER);
		strokeWeight(5);
		fill(255, 255, 0);
		rect(px, py, 300,300);
		fill(242, 177, 201);
		rect(px, py + 80, 80,80);
		fill(255);
		rect(px - 70, py - 50, 80,80);
		rect(px + 70, py - 50, 80,80);
		fill(0);
		rect(px - 70, py - 50, 10, 10);
		rect(px + 70, py - 50, 10, 10);



	}
}
