#include "dong.h"
#include "basic_function.h"
#include <iostream>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

//필드를 완전히 감싸는 관중석 함수 
//필드의 x너비 y너비 의자 높이 그리고 가장 필드의 모서리 중에서 가장 작은 x y z 값
void DJ_stand(int xlen, int zlen, int high, int x, int y, int z) {
	StairsID chair = createStairs(STAIRS_DARK_OAK);

	chairs_N(chair, x, y, z - 1, xlen, high);
	chairs_S(chair, x, y, z + zlen, xlen, high);
	chairs_E(chair, x + xlen, y, z, zlen, high);
	chairs_W(chair, x - 1, y, z, zlen, high);
}


FlowerID orange_tulip = createFlower(FLOWER_OXEYE_TULIP);
FlowerID blue_orchid = createFlower(FLOWER_BLUE_ORCHID);
FlowerID pink_tulip = createFlower(FLOWER_PINK_TULIP);
FlowerID oxeye_tulip = createFlower(FLOWER_OXEYE_TULIP);
FlowerID poppy = createFlower(FLOWER_POPPY);


//화단 만드는 함수 
//x좌표 y좌표 z좌표 x축길이 z축길이를 받는다.
void plant_flower (int x, int y, int z, int xlen, int zlen) {
	
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < zlen; j++) {
			FlowerID flower;

			//0~4까지의 난수를 생성한다.
			int n = random(5);

			switch (n)
			{
			case 0:
				flower = orange_tulip;
				break;

			case 1:
				flower = blue_orchid;
				break;

			case 2:
				flower = pink_tulip;
				break;

			case 3:
				flower = oxeye_tulip;
				break;

			case 4:
				flower = poppy;
				break;
			}

			locateBlock(flower, x + i, y, z + j);
			printf("%d", n);

			//딜레이를 주지않으면 for문이 빨라서 같은 수만 출력됨 
			delay(774);
		}
	}
}

//트로피 조형물 만드는 함수
//x좌표 y좌표 z좌표를 받음
void trophy(int x, int y, int z) {
	WoolID wool = createWool(COLOR_YELLOW);

	//트로피 조형물 밑의 부분 만들기
	int layer = 0;

	for (int i = 5; i > 2; i--) {
		for (int j = 0; j < 2; j++) {

			circle(wool, x, y + layer, z, i);
			layer++;
		}
	}
	for (int i = 5; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			circle(wool, x, y + layer, z, i);
			layer++;
		}
	}	
	layer--;

	for (int i = 0; i < 7; i++) {
		circle(wool, x, y + layer, z, i);
	}

	//트로피 손잡이 만들기
	for (int i = 0; i < 20; i++) {
		locateBlock(wool, x, y + layer, z - 10 + i);
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		locateBlock(wool, x, y + layer - i, z - 11);
		locateBlock(wool, x, y + layer - i, z + 10);
		cnt++;
	}
	int fix = cnt;
	for (int i = 0; i < 2; i++) {
		locateBlock(wool, x, y + layer - fix - i, z - 10);
		locateBlock(wool, x, y + layer - fix - i, z + 9);
		cnt++;
	}
	for (int i = 0; i < 12; i++) {
		locateBlock(wool, x, y + layer - cnt, z - 9 + i);
		locateBlock(wool, x, y + layer - cnt, z + 8 - i);
		cnt++;
	}

	//트로비 조형물 위의 부분 만들기 
	//BlockID diamond = createBlock(BLOCK_DIAMOND);
	//BlockID air = createBlock(BLOCK_AIR);
	//soccerball(x, y + layer + 4, z, 5);
}