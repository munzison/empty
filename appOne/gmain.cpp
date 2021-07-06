#define _�x�N�g��_14


#ifdef _�x�N�g��_14
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	while (notQuit) {
	}
}
#endif

#ifdef _�x�N�g��_13
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	angleMode(DEGREES);
	float x, y, angle;
	while (notQuit) {
		clear(0, 50, 0);
		mathAxis(5.1f, 255);

		x = mathMouseX;
		y = mathMouseY;
		angle = atan2(y, x);

		strokeWeight(5);
		stroke(128);
		mathArrow(0, 0, x, y);
		mathArc(0, angle, 0.5f);
		textSize(50);
		fill(160);
		text((let)"x=" + x, 0, 50);
		text((let)"y=" + y, 0, 100);
		fill(100, 100, 200);

		text((let)"atan2 = (y,x)" + angle, 0, 150);

		float r = sqrt(x * x + y * y);
		fill(160);
		text((let)"asin = (y/r)" + asin(y / r), 0, 200);//asin�͍�������p�x�����߂�
		text((let)"acos = (x/r)" + acos(x / r), 0, 250);
		text((let)"atan = (y/x)" + atan(y / x), 0, 300);
	}
}
#endif



#ifdef _�x�N�g��_12
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	angleMode(DEGREES);
	float x, y, angle;
	while (notQuit) {
		clear(0, 50, 0);
		mathAxis(5.1f, 255);

		x = mathMouseX;
		y = mathMouseY;
		angle = atan2(y, x);//?

		strokeWeight(5);
		stroke(128);
		mathArrow(0, 0, x, y);
		mathArc(0, angle, 0.5f);
		textSize(50);
		fill(160);
		text((let)"x=" + x, 0, 50);
		text((let)"y=" + y, 0, 100);
		fill(100,100,200);

		text((let)"atan2 = (y,x)" + angle, 0, 150);

		float r = sqrt(x * x + y * y);
		fill(160);
		text((let)"asin = (y/r)" + asin(y / r), 0, 200);//asin�͍�������p�x�����߂�
		text((let)"acos = (x/r)" + acos(x / r), 0, 250);
		text((let)"atan = (y/x)" + atan(y / x), 0, 300);
	}
}
#endif

#ifdef _�x�N�g��_11
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	float x, y, r;
	float s, c, t;
	float tx, ty;
	while (notQuit) {
		clear(0, 50, 0);
		mathAxis(3.1f, 255);
		x = mathMouseX;
		y = mathMouseY;
		r = sqrt(x * x + y * y);//�O�����̒藝
		c = x / r;
		s = y / r;
		t = y / x;
		tx = s * t;
		ty = -c * t;
		strokeWeight(5);
		mathArrow(0, 0, x, y);//�Ε�
		fill(0, 0, 0, 0);//�l�Ԗڂ͓����x
		mathCircle(0, 0, 2);  //�P�ʉ~
		stroke(0, 0, 255);
		//���K���x�N�g��
		mathArrow(0, 0, c, s);//���K�����ꂽ�Ε�
		stroke(0, 255, 0);
		mathLine(0, 0, c, 0);//cos��
		stroke(255, 0, 0);
		mathLine(c, 0, c, s);//sin��
		stroke(255, 0, 255);
		mathArrow(c, s, c + tx, s + ty);//tan��
	}
}
#endif

#ifdef _�x�N�g��_10
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	float x, y, r;
	float s, c;
	while (notQuit) {
		clear(0,50,0);
		mathAxis(3.1f,255);
		x = mathMouseX;
		y = mathMouseY;
		r = sqrt(x * x + y * y);//�O�����̒藝
		c = x / r;
		s =	y / r;
		strokeWeight(5);
		mathArrow(0, 0, x, y);
		fill(0, 0, 0, 0);//�l�Ԗڂ͓����x
		mathCircle(0, 0, 2);  //�P�ʉ~
		stroke(0,0,255);
		//���K���x�N�g��
		mathArrow(0, 0, c, s);
		stroke(0, 255, 0);
		mathLine(0, 0, c, 0);
		stroke(255, 0, 0);
		mathLine(c, 0, c, s);
	}
}
#endif

#ifdef _�x�N�g��_07
#include<libOne.h>
void gmain() {
	window(1000, 1000);
	float rx = 5, ry = 5;
	float bx = 7, by = 7;
	while (notQuit) {
		bx = mathMouseX;
		by = mathMouseY;
		float vx = bx - rx;
		float vy = by - ry;
		float mag = sqrt(vx * vx + vy * vy);
		//float nmag = mag / mag;
		float nvx = vx / mag;
		float nvy = vy / mag;
		float nmag = sqrt(nvx * nvx + nvy * nvy);
		rx += nvx * 0.1f;
		ry += nvy * 0.1f;


		clear(200);
		mathAxis(9.1f);
		strokeWeight(5);

		stroke(255, 0, 0);
		mathLine(0, 0, vx, 0);

		stroke(0, 0, 255);
	    mathLine(vx, 0, vx, vy);

		stroke(0, 255, 0);
		mathArrow(0, 0, vx, vy);

		stroke(0);
		mathLine(0, 0, nvx, 0);//���K�����ꂽx

		mathLine(nvx, 0, nvx, nvy);//���K�����ꂽy

		mathArrow(0, 0, nvx, nvy);//���K�����ꂽ�x�N�g��

		strokeWeight(20);
		stroke(255,0,0);
		mathPoint(rx, ry);

		stroke(0,0,255);
		mathPoint(bx, by);
		
		textSize(50);
		text((let)"vec(" + vx + "," + vy + ")", 0, 50);
		text((let)"mag = " + mag, 0, 100);
		text((let)"nvec(" + nvx + "," + nvy + ")", 0, 150);
		text((let)"nmag = " + nmag, 0, 200);
	}
}
#endif

#ifdef _�x�N�g��_06
#include<libOne.h>
void gmain() {
	window(1000, 1000);
	while (notQuit) {
		float vx = mathMouseX;
		float vy = mathMouseY;
		float mag = sqrt(vx * vx + vy * vy);
		//float nmag = mag / mag;
		float nvx = vx / mag;
		float nvy = vy / mag;
		//float nmag = sqrt(nvx * nvx + nvy * nvy);
		clear(200);
		mathAxis(6.1f);

		strokeWeight(5);
		stroke(255, 0, 0);
		mathLine(0, 0, vx, 0);

		stroke(0, 0, 255);
		mathLine(vx, 0, vx, vy);

		stroke(0, 255, 0);
		mathArrow(0, 0, vx, vy);

		stroke(0);
		mathLine(0, 0, nvx, 0);//���K�����ꂽx

		stroke(0);
		mathLine(nvx, 0, nvx, nvy);//���K�����ꂽy

		stroke(0);
		mathArrow(0, 0, nvx, nvy);//���K�����ꂽ�x�N�g��

		//stroke(0);
		//mathArrow(0, 0, mag, mag);

		textSize(50);
		text((let)"vec(" + vx + "," + vy + ")", 0, 50);
		text((let)"vx = " + vx, 0, 100);
		text((let)"vy = " + vy, 0, 150);
		text((let)"mag = " + mag, 0, 200);
		text((let)"nvec(" + nvx + "," + nvy + ")", 0, 250);
		text((let)"nvx = " + nvx, 0, 300);
		text((let)"nvy = " + nvy, 0, 350);
		//text((let)"nmag = " + nmag, 0, 250);
	}
}
#endif

#ifdef _�x�N�g��_05
#include<libOne.h>
void gmain() {
	window(1000, 1000);
	while (notQuit) {
		float vx = mathMouseX;
		float vy = mathMouseY;
		float mag = sqrt(vx * vx + vy * vy);
		clear(200);
		mathAxis(6.1f);

		strokeWeight(5);
		stroke(255, 0, 0);
		mathLine(0, 0, vx, 0);

		stroke(0, 0, 255);
		mathLine(vx, 0, vx, vy);

		stroke(0, 255, 0);
		mathArrow(0, 0, vx, vy);

		textSize(50);
		text((let)"vec(" + vx + "," + vy + ")", 0, 50);
		text((let)"vx = " + vx, 0, 100);
		text((let)"vy = " + vy, 0, 150);
		text((let)"mag = "+mag, 0, 200);
	}
}
#endif

#ifdef _�x�N�g��_04
#include<libOne.h>
void gmain() {
	window(1000, 1000);
	float rx = 5;
	float bx = 9;
	while (notQuit) {
		float vx = rx - bx;//�I�_ - �n�_
		//float vx = mathMouseX;
		float mag = vx < 0 ? -vx : vx;//�O�����Z�q
		float nvx = vx / mag;
		bx += nvx * 0.01f;
		clear(200);
		mathAxis(9.1f);

		strokeWeight(5);
		stroke(255, 0, 0);
		mathArrow(0, 0, vx, 0);
		stroke(0, 0, 255);
		mathArrow(0, 0, nvx, 0);//���K�� 

		strokeWeight(20);
		stroke(255, 0, 0);
		mathPoint(rx, 0);
		stroke(0, 0, 255);
		mathPoint(bx, 0);

		textSize(50);
		text(vx, 0, 50);
		text(mag, 0, 100);
	}
}
#endif

#ifdef _�x�N�g��_03
#include<libOne.h>
void gmain() {
	window(1000, 1000);
	while (notQuit) {
		//float vx = -3;
		float vx = mathMouseX;
		float mag = vx < 0 ? -vx : vx;//�O�����Z�q
		float nvx = vx / mag;
		clear(200);
		mathAxis(5.1f);
		strokeWeight(5);
		stroke(0, 0, 255);
		mathArrow(0, 0, vx, 0);
		stroke(255, 0, 0);
		mathArrow(0, 0, nvx, 0);//���K��
		textSize(50);
		text(vx, 0, 50);
		text(mag, 0, 100);
	}
}
#endif

#ifdef _�x�N�g��_02
#include<libOne.h>
void gmain() {
	window(1000, 1000);
	while (notQuit) {
		float vx = -3;
		float mag = vx < 0 ? -vx : vx;//�O�����Z�q
		//if (vx < 0) { mag = -vx; }
		//else mag = vx;
		clear(200);
		mathAxis(5.1f);
		strokeWeight(5);
		stroke(0, 0, 255);
		mathArrow(0, 0, vx, 0);
		textSize(50);
		text(vx, 0, 50);
		text(mag, 0, 100);
	}
}
#endif

#ifdef _�x�N�g��_01
#include<libOne.h>
void gmain() {
	window(1000, 1000);
	while (notQuit) {
		float vx = -3;
		clear(200);
		mathAxis(5.1f);
		strokeWeight(5);
		stroke(0, 0, 255);
		mathArrow(0, 0, vx, 0);//�n�_��0,0�̏ꍇ�A���_���n�_�ƂȂ�
	}
}

#endif

#ifdef _�O�p�֐�_11
#include"libOne.h"
void gmain() {
	window(1920, 1080,full);
	struct POS{
		float x, y, z;
	};
	const int num = 1000;
	struct POS p[num];
	for (int i = 0; i < num; i++) {
		p[i].x = random(-1.0f, 1.0f);
		p[i].y = random(-0.5f, 0.5f);
		p[i].z = random(0.0f, 1.0f);

	}
	while (notQuit) {
		for (int i = 0; i < num; i++) {
			p[i].z -= 0.01f;
			if (p[i].z <= 0.0f) {//z����0�ɂȂ�����1�ɖ߂�
				p[i].z = 1.0f;
			}
		}
		fill(0, 0, 0, 80);
		strokeWeight(0);
		rect(0, 0, width, height);
		mathAxis(1.0f);
		for (int i = 0; i < num; i++) {
			stroke(255);
			float size = (1.0f - p[i].z) * 20.0f;
			strokeWeight(size);
			mathPoint(p[i].x/ p[i].z, p[i].y/ p[i].z);
			//mathPoint( p[i].z, p[i].y / p[i].z);//�����
		}
	}
}
#endif

#ifdef _�O�p�֐�_10
#include"libOne.h"
//���_�ʒu�̍\����
struct POS {
	float x, y, z;
};
//�Q�[�����C��
void gmain() {
	window(1000, 1000);
	//���_�̐�
	int numcorners = 20;
	int numrings = numcorners / 2 + 1;
	int num = numcorners * numrings;
	float deg = 360.0f / numcorners;
	angleMode(DEGREES);
	//���̒��_�ʒu
	struct POS* op = new POS[num];
	for (int j = 0; j < numrings; j++) {
		float r = sin(deg * j);
		float z = cos(deg * j);
		for (int i = 0; i < numcorners; i++) {//���_��p�ӂ���
			int k = j * numcorners + i;
			op[k].x = cos(deg * i)* r;
			op[k].y = sin(deg * i)* r;
			op[k].z = z;// 1.0f - 2.0f / (numrings - 1) * j;
		}
	}
	//�ύX��̒��_�ʒu�̓��ꕨ
	struct POS* p = new POS[num];
	//���̒��_�ʒu����]������p�x
	deg = 0;
	//����state��0�̎�Y���A1�̎�X����]����
	int state = 0;
	//���C�����[�v
	while (notQuit) {
		//���炩����sin,cos���v�Z���Ă���
		float s = sin(deg);
		float c = cos(deg);
		deg++;
		//state�̕ύX
		if (deg > 360) {
			deg = 0;
			++state %= 2;
		}
		for (int i = 0; i < num; i++) {
			if (state == 0) {
				p[i].x = op[i].x * c + op[i].z * -s;
				p[i].y = op[i].y;
				p[i].z = op[i].x * s + op[i].z * c;
			}
			else {
				p[i].x = op[i].x;
				p[i].y = op[i].y * c + op[i].z * -s;
				p[i].z = op[i].y * s + op[i].z * c;
			}
			p[i].z += 3;//���s

			p[i].x /= p[i].z;
			p[i].y /= p[i].z;
		}
		clear(200);
		mathAxis(0.8);
		stroke(0, 0, 200);
		for (int i = 0; i < num; i++) {
			//strokeWeight(5);
			//mathPoint(p[i].x, p[i].y);
			int j = i + 1;
			if (j % numcorners == 0)j -= numcorners;
			strokeWeight(3);
			mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
			if (i < num - numcorners) {
				j = numcorners + i;
			}
			mathLine(p[i].x, p[i].y, p[j].x, p[j].y);

		}
	}
	delete[]op;
	delete[]p;
}

#endif

#ifdef _�O�p�֐�_09//������
#include"libOne.h"
//���_�ʒu�̍\����
struct POS {
	float x, y, z;
};
//�Q�[�����C��
void gmain(){
	window(1000, 1000);
	//���_�̐�
	const int num = 8;
	angleMode(DEGREES);
	//���̒��_�ʒu
	struct POS op[num] = {
		-1,1,-1,
		-1,-1,-1,
		1,-1,-1,
		1,1,-1,
		-1,1,1,
		-1,-1,1,
		1,-1,1,
		1,1,1,
	};
	//�ύX��̒��_�ʒu�̓��ꕨ
	struct POS p [num];
	//���̒��_�ʒu����]������p�x
	float deg = 0;
	//����state��0�̎�Y���A1�̎�X����]����
	int state = 0;
	//���C�����[�v
	while (notQuit) {
		//���炩����sin,cos���v�Z���Ă���
		float s = sin(deg);
		float c = cos(deg);
		deg++;
		//state�̕ύX
		if (deg > 360) {
			deg = 0;
			++state %= 2;
		}
		for (int i = 0; i < num; i++) {
			if (state == 0) {
				p[i].x = op[i].x * c + op[i].z * -s;
				p[i].y = op[i].y;
				p[i].z = op[i].x * s + op[i].z * c;
			}
			else {
				p[i].x = op[i].x;
				p[i].y = op[i].y * c + op[i].z * -s;
				p[i].z = op[i].y * s + op[i].z * c;
			}
			p[i].z += 3;//���s

			p[i].x /= p[i].z;
			p[i].y /= p[i].z;
		}
		clear(200);
		mathAxis(1.2);//�N���A�F�Ɠ����Ŏ��͌����Ȃ����K�v�Ȗ���
		stroke(0, 0, 200);
		strokeWeight(10);
		for (int i = 0; i < 4; i++) {
			int j = (i + 1) % 4;
			//��O�̎l�p�`�̐�
			mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
			//���̎l�p�`�̐�
			mathLine(p[i+4].x, p[i+4].y, p[j+4].x, p[j+4].y);
			//�O������Ԑ�
			mathLine(p[i].x, p[i].y, p[i+4].x, p[i+4].y);


		}
	}
}
#endif

#ifdef _�O�p�֐�_08//���T�[�W���Ȑ����ǂ�
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	let x, y, deg = 0;
	float ax = 2;//x�̐U����
	float by = 3;//y�̐U����
	angleMode(DEGREES);
	while (notQuit) {
		//if (deg > 360) {
			//deg = -360;
			//clear(200);
		//}
		//clear(200);
		deg += 0.5;
		x = cos(deg*ax);    //cos��1����n�܂�
		y = sin(deg*by);      //sin��0����n�܂�
		mathAxis(3);  //x,y����\��
		strokeWeight(10);
		stroke(0, 0, 200);
		//mathPoint(deg, y);
		stroke(0, 0, 200);
		mathPoint(x, y);
	}
}

#endif

#ifdef _�O�p�֐�_07//�n�[�g
#include"libOne.h"
int createtriangle() {
	struct SHAPE_VERTEX vertices[3];
	vertices[0].x = 0;
	vertices[0].y = -1;
	vertices[1].x = 1;
	vertices[1].y = 1;
	vertices[2].x = -1;
	vertices[2].y = 1;
	return createShape(vertices, 3); //3�̒��_
}
int createpolygon() {
	//���p�`�̃v���O����
	const int NUM = 4;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		vertices[i].x = sin(deg * i);
		vertices[i].y = -cos(deg * i);
	}
	return createShape(vertices, NUM); //���p�`�̒��_
}
int createstar() {
	//���̃v���O����
	const int NUM = 10;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		float r = 0.5f + 0.5f * (i % 2);
		vertices[i].x = sin(deg * i) * r;
		vertices[i].y = cos(deg * i) * r;
	}
	return createShape(vertices, NUM); //���p�`�̒��_
}
int createheart() {
	//�n�[�g�̃v���O����
	const int NUM = 100;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		float t = deg * i;
		vertices[i].x =
			16 * pow(sin(t), 3);
		vertices[i].y = -(
			13 * cos(t) -
			5 * cos(2 * t) -
			2 * cos(3 * t) -
			1 * cos(4 * t));
	}
	return createShape(vertices, NUM); //���p�`�̒��_
}

void gmain() {
	window(1000, 1000);
	int idx = createheart();
	float deg = 0;
	while (notQuit) {
		//deg++;
		clear(200);
		angleMode(DEGREES);
		fill(200, 0, 0);
		shape(idx, 500, 500, deg, 20); //�Ԃ�l�Cx���W�Cy���W�C��]�p�x�C�g��̒l
	}
}

#endif

#ifdef _�O�p�֐�_06
#include"libOne.h"
int createtriangle() {
	struct SHAPE_VERTEX vertices[3];
	vertices[0].x = 0;
	vertices[0].y = -1;
	vertices[1].x = 1;
	vertices[1].y = 1;
	vertices[2].x = -1;
	vertices[2].y = 1;
	return createShape(vertices, 3); //3�̒��_
}
int createpolygon() {
	//���p�`�̃v���O����
	const int NUM = 4;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		vertices[i].x = sin(deg * i);
		vertices[i].y = -cos(deg * i);
	}
	return createShape(vertices, NUM); //���p�`�̒��_
}
int createstar() {
	//���̃v���O����
	const int NUM = 10;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		float r = 0.5f + 0.5f * (i % 2);
		vertices[i].x = sin(deg * i) * r;
		vertices[i].y = cos(deg * i) * r;
	}
	return createShape(vertices, NUM); //���p�`�̒��_
}

void gmain() {
	window(1000, 1000);
	int idx = createstar();
	float deg = 0;
	while (notQuit) {
		//deg++;
		clear(200);
		angleMode(DEGREES);
		fill(0, 0, 100);
		shape(idx, 500, 500, deg, 200); //�Ԃ�l�Cx���W�Cy���W�C��]�p�x�C�g��̒l
	}
}

#endif

#ifdef _�O�p�֐�_05//���p�`
#include"libOne.h"
int createtriangle() {
	struct SHAPE_VERTEX vertices[3];
	vertices[0].x = 0;
	vertices[0].y = -1;
	vertices[1].x = 1;
	vertices[1].y = 1;
	vertices[2].x = -1;
	vertices[2].y = 1;
	return createShape(vertices, 3); //3�̒��_
}
int createpolygon() {
	//���p�`�̃v���O����
	const int NUM = 3;
	struct SHAPE_VERTEX vertices[NUM];
	float deg = 360.0f / NUM;
	angleMode(DEGREES);
	for (int i = 0; i < NUM; i++) {
		vertices[i].x = sin(deg * i);
		vertices[i].y = -cos(deg * i);//0�̒��_����ɗ���悤�ɂ���
	}
	return createShape(vertices, NUM); //���p�`�̒��_
}

void gmain() {
	window(1000, 1000);
	int idx = createpolygon();
	float deg = 0;
	while (notQuit) {
		//deg++;
		clear(200);
		angleMode(DEGREES);
		fill(0, 0, 100);
		shape(idx, 500, 500, deg, 200); //�Ԃ�l�Cx���W�Cy���W�C��]�p�x�C�g��̒l
	}
}

#endif

#ifdef _�O�p�֐�_04//�O�p�`
#include"libOne.h"
int createtriangle() {
	//�O�p�`�̃v���O����
	struct SHAPE_VERTEX vertices[3];
	vertices[0].x = 0;
	vertices[0].y = -1;
	vertices[1].x = 1;
	vertices[1].y = 1;
	vertices[2].x = -1;
	vertices[2].y = 1;
	return createShape(vertices, 3); //3�̒��_
}
void gmain() {
	window(1000, 1000);
	int idx = createtriangle();
	float deg = 0;
	while (notQuit) {
		deg++;
		clear(200);
		angleMode(DEGREES);
		fill(0, 0, 100);
		shape(idx, 500, 500, deg, 100); //�Ԃ�l�Cx���W�Cy���W�C��]�p�x�C�g��̒l
	}
}
#endif

#ifdef _�O�p�֐�_03_���v
#include"libOne.h"
#include<time.h>
void gmain() {
	window(1000, 1000);
	let x, y, deg = 0;
	float second = 0; float minute = 0; float hour = 0;
	angleMode(DEGREES);
	time_t stdTime;
	struct tm local;
	while (notQuit) {
		time(&stdTime);
		localtime_s(&local, &stdTime);
		second = local.tm_sec;
		minute = local.tm_min;
		hour = local.tm_hour;

		//if (second >= 60) { minute++; second = 0; }
		//if (minute >= 60) { hour++; minute = 0; }
		//second += 20;
		clear(200);
		//���j
		deg = 30 * hour + 30 * minute / 60;
		x = sin(deg) * 300;
		y = -cos(deg) * 300;
		strokeWeight(20);
		line(500, 500, 500 + x, 500 + y);
		//���j
		deg = 6 * minute + 6 * second / 60;
		x = sin(deg) * 400;
		y = -cos(deg)*400;
		strokeWeight(10);
		line(500, 500, 500 + x, 500 + y);
		//�b�j
		deg = 6 * second;
		x = sin(deg) * 400;
		y = -cos(deg) * 400;
		strokeWeight(5);
		line(500, 500, 500 + x, 500 + y);
	}
}
#endif

#ifdef _�O�p�֐�_02//sin,cos�̓���
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	let x, y, deg = -360;
	angleMode(DEGREES);
    while (notQuit) {
		if (deg > 360) {
			deg = -360;
			clear(0);
		}
		deg+=1;//�p�x��1������
		x = cos(deg)*100;    //cos��1����n�܂�   cos�̔��a*100
		y = sin(deg) * 100;      //sin��0����n�܂�   sin�̔��a*100
		mathAxis(360);  //x,y����\��
		strokeWeight(20);//���̑傫����20
		stroke(0, 0, 200);//���̐F
		mathPoint(deg, y);//x���W��1�������Ă����Cy�ɂ�
		stroke(200, 0, 0);
		mathPoint(deg, x);
	}
}
#endif

#ifdef _�O�p�֐�_01
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	let x, y, c, deg = 0;
	angleMode(DEGREES);
	while (notQuit) {
		if (isPress(KEY_W)) { deg++; }
		if (isPress(KEY_S)) { deg--; }
		if (isTrigger(KEY_A)) { deg += 30; }
		if (isTrigger(KEY_D)) { deg -= 30; }
		x = cos(deg);
		y = sin(deg);
		c = sqrt(x * x + y * y);
		clear(128);
		mathAxis(1.2);  //x,y����\��
		textSize(40);
		stroke(0,0,100);
		strokeWeight(10);
		mathLine(0, 0, x, y);
		stroke(0, 100, 0);
		mathLine(0, 0, x, 0);
		stroke(100, 0, 0);
		mathLine(x, 0, x, y);

		fill(0, 100, 0);
		text("���=cos(" + deg + ")=" + x, 0, 40);
		fill(100, 0, 0);
		text("����=sin(" + deg + ")=" + y, 0, 80);
		fill(0, 0, 100);
		text("�Ε�(���a)="+c, 0, 120);
	}
}
#endif

#ifdef _�~�̓����蔻��
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	struct CIRCLE {
		float x, y, r;  //���a...radius(���f�B�A�X)
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

#ifdef _�O�����̒藝
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

		mathLine(0, 0, a, b);  //�Ε�
		mathLine(0, 0, a, 0);  //���
		mathLine(a, 0, a, b);  //����

		textSize(50);
		text("���=" + a, 0, 60);
		text("����=" + b, 0, 120);
		text("�Ε�=" + c, 0, 180);
	}
}
#endif

#ifdef _���[�g
#include"libOne.h"
void gmain() {
	window(1000, 1000);

	let area = 4;    //�ʐ�
	let renght = 0;  //��ӂ̒���

	while (notQuit) {
		clear(200);

		if (isTrigger(KEY_D)) { ++area; }
		if (isTrigger(KEY_A)) { --area; }

		renght = sqrt(area);  //sqrt = ��(���[�g)   ������...square root(�X�N�G�A���[�g)
		mathAxis(4.1);

		fill(0, 0, 255, 128);
		mathRect(0, 0, renght, -renght);

		textSize(50);
		text("�ʐ� =" + area, 0, 60);
		text("��" + area + " = " + renght, 0, 120);
	}
}
#endif

#ifdef _15_HSV
#include"libOne.h"
void gmain() {
	window(1920, 1080,full);
	colorMode(HSV);
	angleMode(DEGREES);
	float hue = 0;      //�p�x
	float satu = 255;   //�N�₩��
	float value = 255;  //���邳
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
	int r, c; //r=��ƂȂ�Y���� c=��r�ΏۂƂȂ�Y����
	for (int i = 0; i < num; i++) {
		score[i] = random() % 1001;
	}
	while (notQuit) {
		clear(60);
		if (isTrigger(KEY_A)) {               //A�������ƃ����_���Ȓl��\��
			for (int i = 0; i < num; i++) {
				score[i] = random() % 1001;
			}
		}
		if (isTrigger(KEY_D)) {               //D�������ƒl����ѕς���
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

#ifdef _13_�e
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
	//�f�[�^
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
		if (isPress(KEY_A) && p.px > 50) {//���Ɉړ�
			p.px -= p.vx;
		}
		if (isPress(KEY_D) && p.px < 1870) {//�E�Ɉړ�
			p.px += p.vx;
		}
		if (isTrigger(KEY_SPACE)) {//�e�𔭎�
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
				//�E�B���h�E�̊O�ɏo����HP��0�ɂ���
				if (b[i].py < -p.ofsY) {
					b[i].hp = 0;
				}
			}
		}
		rect(p.px, p.py, p.w, p.h);//�v���C���[
		for (int i = 0; i < numBullets; i++) {
			if (b[i].hp > 0) {
				rect(b[i].px, b[i].py, b[i].w, b[i].h);//�e
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
//hp�Q�[�W
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	//�f�[�^
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
	//�f�[�^
	int life = 5;//���̐�
	float px = 600;
	float py = 300;
	float r = 50;//�~�̑傫��
	float space = 100;//�Ԋu
	while (notQuit) {
		clear(100);
		fill(255);
		print((let)"life=" + life);
		if (isTrigger(KEY_A)) { life--; }
		else if (isTrigger(KEY_D)) { life++; }
		//while�o�[�W����
		int i = 0;
		while (i < life) {
			float offsetX = space * i;
			strokeWeight(10);
			stroke(200);
			fill(255, 0, 0);
			circle(px + offsetX, py, r * 2);
			i++;
		}
		//for�o�[�W����
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

#ifdef _07_�}�`
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
