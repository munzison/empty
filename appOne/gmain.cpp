#define _円の当たり判定

#ifdef _円の当たり判定
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	struct CIRCLE {
		float x, y, r;  //半径...radius(ラディアス)
	};
	struct CIRCLE c1, c2;
	c1.x = width / 2;
	c1.y = height / 2;
	c1.r = 100;
	c2.x = 0;
	c2.y = 0;
	c2.r = 100;
	while (notQuit) {
		clear(140);
		c2.x = mouseX;
		c2.y = mouseY;
		float a = c1.x - c2.x;
		float b = c1.y - c2.y;
		float c = sqrt(a * a + b * b);
		if (c <= c1.r + c2.r) {
			fill(200, 0, 0, 128);
		}
		else fill(0, 100, 0);

		textSize(60);
		text(c, 0, 60);
		circle(c1.x, c1.y, c1.r * 2);
		circle(c2.x, c2.y, c2.r * 2);
		line(c1.x, c1.y, c2.x, c2.y);  //c
		line(c1.x, c1.y, c2.x, c1.y);  //a
		line(c2.x, c2.y, c2.x, c1.y);  //b
	}
}
#endif
#ifdef _三平方の定理
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	let a, b, c;
	while (notQuit) {
		clear(200);

		a = mathMouseX;
		b = mathMouseY;
		c = sqrt(a * a + b * b);

		mathAxis(4.1);
		stroke(0, 0, 250);

		mathLine(0, 0, a, b);  //斜辺
		mathLine(0, 0, a, 0);  //底辺
		mathLine(a, 0, a, b);  //高さ

		textSize(50);
		text("底辺=" + a, 0, 60);
		text("高さ=" + b, 0, 120);
		text("斜辺=" + c, 0, 180);
	}
}
#endif
#ifdef _ルート
#include"libOne.h"
void gmain() {
	window(1000, 1000);

	let area = 4;    //面積
	let renght = 0;  //一辺の長さ

	while (notQuit) {
		clear(200);

		if (isTrigger(KEY_D)) { ++area; }
		if (isTrigger(KEY_A)) { --area; }

		renght = sqrt(area);  //sqrt = √(ルート)   平方根...square root(スクエアルート)
		mathAxis(4.1);

		fill(0, 0, 255, 128);
		mathRect(0, 0, renght, -renght);

		textSize(50);
		text("面積 =" + area, 0, 60);
		text("√" + area + " = " + renght, 0, 120);
	}
}
#endif
#ifdef _15_HSV
#include"libOne.h"
void gmain() {
	window(1920, 1080,full);
	colorMode(HSV);
	angleMode(DEGREES);
	float hue = 0;      //角度
	float satu = 255;   //鮮やかさ
	float value = 255;  //明るさ
	while (notQuit) {
		if (isPress(KEY_Q)&&hue<360) { hue += 5; }
		if (isPress(KEY_W)&&hue>0) { hue -= 5; }
		if (isTrigger(KEY_A) && hue < 360) { hue += 5; }
		if (isTrigger(KEY_S) && hue > 0) { hue -= 5; }
		if (isPress(KEY_E) && satu < 360) { satu += 5; }
		if (isPress(KEY_R) && satu > 0) { satu -= 5; }
		if (isPress(KEY_D) && value < 360) { value += 5; }
		if (isPress(KEY_F) && value > 0) { value -= 5; }

		clear(0, 0, 0);
		fill(hue, satu, value);
		textSize(120);
		text((let)"hue=" + hue, 600, 400);
		text((let)"satu=" + satu, 600, 600);
		text((let)"value=" + value, 600, 800);
		//text((let)"Gameing" + hue, 600, 1000);

		int num = 12;
		float angle = hue / num;
		for (int i = 0; i < num; i++) {
			float px = cos(angle * i) * 200;
			float py = -sin(angle * i) * 200;
			fill(angle*i, satu, value);
			noStroke();
			circle(1500 + px, 540 + py, 50);
		}
	}
}
#endif
#ifdef _14_SORT
#include"libOne.h"
void gmain() {
	window(1100, 1000);
	const int num = 20;
	int score[num];
	int r, c; //r=基準となる添え字 c=比較対象となる添え字
	for (int i = 0; i < num; i++) {
		score[i] = random() % 1001;
	}
	while (notQuit) {
		clear(60);
		if (isTrigger(KEY_A)) {               //Aを押すとランダムな値を表示
			for (int i = 0; i < num; i++) {
				score[i] = random() % 1001;
			}
		}
		if (isTrigger(KEY_D)) {               //Dを押すと値を並び変える
			for (r = 0; r < num - 1; r++) {
				for (c = r + 1; c < num; c++) {
					if (score[r] < score[c]) {
						int w = score[r];
						score[r] = score[c];
						score[c] = w;
					}
				}
			}
		}
		for (int i = 0; i < num; i++) {
			print(score[i]);
			rect(100, 50 * i, score[i], 40);
		}
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
