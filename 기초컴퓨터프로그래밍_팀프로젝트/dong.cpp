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
FlowerID white_tulip = createFlower(FLOWER_WHITE_TULIP);
FlowerID pink_tulip = createFlower(FLOWER_PINK_TULIP);
FlowerID oxeye_tulip = createFlower(FLOWER_OXEYE_TULIP);

FlowerID sunflower = createFlower(FLOWER_SUNFLOWER);


//ȭ�� ����� �Լ� 
//x��ǥ y��ǥ z��ǥ x����� z����̸� �޴´�.
void plant_flower (int x, int y, int z, int xlen, int zlen) {
	
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < zlen; j++) {
			FlowerID flower;

			int n = random(5);

			switch (n)
			{
			case 0:
				flower = orange_tulip;
				break;

			case 1:
				flower = white_tulip;
				break;

			case 2:
				flower = pink_tulip;
				break;

			case 3:
				flower = oxeye_tulip;
				break;

			case 4:
				flower = sunflower;
				break;
			}


			locateBlock(flower, x + i, y, z + j);
			printf("%d", n);

			//�����̸� ���������� for���� ���� ���� ���� ��µ� 
			delay(776);
		}
	}
}