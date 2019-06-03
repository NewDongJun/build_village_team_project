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
FlowerID white_tulip = createFlower(FLOWER_WHITE_TULIP);
FlowerID pink_tulip = createFlower(FLOWER_PINK_TULIP);
FlowerID oxeye_tulip = createFlower(FLOWER_OXEYE_TULIP);

FlowerID sunflower = createFlower(FLOWER_SUNFLOWER);


//화단 만드는 함수 
//x좌표 y좌표 z좌표 x축길이 z축길이를 받는다.
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

			//딜레이를 주지않으면 for문이 빨라서 같은 수만 출력됨 
			delay(776);
		}
	}
}