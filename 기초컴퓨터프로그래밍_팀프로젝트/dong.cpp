#include "dong.h"
#include "basic_function.h"
#include <iostream>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

//�ʵ带 ������ ���δ� ���߼� �Լ� 
//�ʵ��� x�ʺ� y�ʺ� ���� ���� �׸��� ���� �ʵ��� �𼭸� �߿��� ���� ���� x y z ��
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


//ȭ�� ����� �Լ� 
//x��ǥ y��ǥ z��ǥ x����� z����̸� �޴´�.
void plant_flower (int x, int y, int z, int xlen, int zlen) {
	
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < zlen; j++) {
			FlowerID flower;

			//0~4������ ������ �����Ѵ�.
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

			//�����̸� ���������� for���� ���� ���� ���� ��µ� 
			delay(774);
		}
	}
}

//Ʈ���� ������ ����� �Լ�
//x��ǥ y��ǥ z��ǥ�� ����
void trophy(int x, int y, int z) {
	WoolID wool = createWool(COLOR_YELLOW);

	//Ʈ���� ������ ���� �κ� �����
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

	//Ʈ���� ������ �����
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

	//Ʈ�κ� ������ ���� �κ� ����� 
	//BlockID diamond = createBlock(BLOCK_DIAMOND);
	//BlockID air = createBlock(BLOCK_AIR);
	//soccerball(x, y + layer + 4, z, 5);
}