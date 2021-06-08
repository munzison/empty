#define _14_SORT


#ifdef _14_SORT
#include"libOne.h"
void gmain() {
	window(1100, 1000, full);
	const int num = 20;
	int score[num];
	for (int i = 0; i < num; i++) {
		score[i] = random() % 101;
	}
	while (notQuit) {
		clear(60);
	}
}
#endif

#ifdef _13_弾
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	struct PLAYER {
		float px, py, w, h, vx, ofsY;
	};
	struct BULLET {
		float px, py, w, h, vy;
		int hp = 0;
	};
	//データ
	struct PLAYER p;
	p.px = 1920 / 2;
	p.py = 1000;
	p.w = 100;
	p.h = 100;
	p.vx = 30;
	p.ofsY = 50;
	const int numBullets = 10;
	struct BULLET b[numBullets];
	for (int i = 0; i < numBullets; i++) {
		b[i].px = p.px;
		b[i].py = p.py;
		b[i].w = 20;
		b[i].h = 20;
		b[i].vy = 10;
	}
	while (notQuit) {
		clear(0);
		rectMode(CENTER);
		if (isPress(KEY_A) && p.px > 50) {//左に移動
			p.px -= p.vx;
		}
		if (isPress(KEY_D) && p.px < 1870) {//右に移動
			p.px += p.vx;
		}
		if (isTrigger(KEY_SPACE)) {//弾を発射
			for (int i = 0; i < numBullets; i++){
				if (b[i].hp == 0) {
					b[i].hp = 1;
					b[i].px = p.px;
					b[i].py = p.py - p.ofsY;
					i = numBullets;
				}
			}
		}
		for (int i = 0; i < numBullets; i++) {
			if (b[i].hp > 0) {
				b[i].py -= b[i].vy;
				//ウィンドウの外に出たらHPを0にする
				if (b[i].py < -p.ofsY) {
					b[i].hp = 0;
				}
			}
		}
		rect(p.px, p.py, p.w, p.h);//プレイヤー
		for (int i = 0; i < numBullets; i++) {
			if (b[i].hp > 0) {
				rect(b[i].px, b[i].py, b[i].w, b[i].h);//弾
			}
		}
	}
}


#endif
#ifdef _10_FACE
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
void rectface(float px, float py,float angle) {
	rectMode(CENTER);
	strokeWeight(5);
	fill(255, 255, 0);
	rect(px, py, 300, 300, angle);
	fill(242, 177, 201);
	rect(px, py + 80, 80, 80, angle);
	fill(255);
	rect(px - 70, py - 50, 80, 80, angle);
	rect(px + 70, py - 50, 80, 80, angle);
	fill(0);
	rect(px - 70, py - 50, 10, 10, angle);
	rect(px + 70, py - 50, 10, 10, angle);

 }
void gmain() {
	window(1920, 1080, full);
	float px = width / 2;
	float py = height / 2;
	float angle = 0;
	float anglespeed = 0.003f;
	float osfX = 100;
	float osfY = 100;
	int sw = 1;
	while (notQuit) {
		osfX = width / 2 - mouseX;
		osfY = height / 2 - mouseY;

		clear(60, 120, 240);
		if (isTrigger(KEY_SPACE)) { sw = 1 - sw; }
		for (int i = -5; i < 5; i++) {
			if (sw == 1) {
				roundface(px + osfX * i, py + osfY * i);
			}
			else {
				angle += anglespeed;
				rectface(px + osfX * i, py + osfY * i, angle);
			}
		}

	}
}
#endif
#ifdef _09_HP
//hpゲージ
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
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
			text("Game Over", 600, 500);
		}
		fill(50);
		rect(px, py, w, h);
		fill(R, G, B);
		rect(px, py, hp, h);
	}
}
#endif
#ifdef _08_LIFE
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	//データ
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
}
#endif
#ifdef _07_図形
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	float px = 1920 / 2;
	float py = 1080 / 2;
	float vx = 10;
	float radius = 150;
	float len = radius / 1.4142 * 2;
	float sw = radius / 8;
	float angle = 0;
	float angleSpeed = 0.03f;
	while (notQuit) {
		px += vx;
		angle += angleSpeed;
		if (px < 0 || px > 1920) { 
			vx = -vx; 
			angleSpeed = -angleSpeed;
		}
		clear(60);
		strokeWeight(sw);
		stroke(255, 0, 0);
		circle(px, py, radius * 2);
		rectMode(CENTER);
		rect(px, py, len, len,angle);
		strokeWeight(50);
		point(px, py);
		strokeWeight(sw);
		line(1920 / 2, 0, px, py);
	}
}
#endif
