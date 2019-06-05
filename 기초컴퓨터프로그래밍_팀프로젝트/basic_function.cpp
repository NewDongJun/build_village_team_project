#include "basic_function.h"
#include <math.h>
#include <stdlib.h> 
#include <time.h>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
/*
기본함수 10개 만들어야함 
1. 사각형 만드는 함수
2. 기둥을 만드는 함수
3. 원을 만드는 함수
4. 선그리는 함수
5. 0부터 n-1까지 개의 난수를 생성하는 함수
6. 의자함수N
7. 의자함수S
8. 의자함수E
9. 의자함수W
10. 딜레이함수


6. 골대 뼈대함수
7. 골대 망 함수

깃발 함수 
나무함수
*/


//1.사각형을 만드는 함수
//블록, x좌표, y좌표, z좌표, x너비, y너비, z너비 를 받음
void rectangle(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen) {
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < ylen; j++) {
			for (int k = 0; k < zlen; k++) {
				locateBlock(block, x + i, y + j, z + k);
			}
		}
	}
}

//2. 기둥을 만드는 함수 
//x좌표 y좌표, z좌표 y의 너비를 받음
void pillar(int x, int y, int z, int ylen) {
	BlockID iron = createBlock(BLOCK_IRON);
	for (int i = 0; i < ylen; i++) {
		locateBlock(iron, x + 1, y + i, z);
		locateBlock(iron, x - 1, y + i, z);
		locateBlock(iron, x, y + i, z + 1);
		locateBlock(iron, x, y + i, z - 1);
	}
}

//3. 원을 만드는 함수
//블록 x좌표 y좌표 z좌표 반지름을 받음 
//축구장 원만들때 쑬 수있지 않을까?
void circle(BlockID block, int x, int y, int z, int r) {
	
	double PI = 3.14159265358979323846;
	double radian = PI / 180;

	for (int i = 0; i < 360; i++) {
		double rx = r * cos(radian * i);
		double rz = r * sin(radian * i);
		locateBlock(block, x + rx, y, z + rz);
	}
}

//4. 선그리는 함수
//블록 x좌표 y좌표 z좌표 x너비 z너비를 받음
void line(BlockID block, int x, int y, int z, int xlen, int zlen) {
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < zlen; j++) {
			locateBlock(block, x + i, y, z + j);
		}
	}
}

//5. 0부터 n-1까지 개의 난수를 생성하는 함수
// n을 받음
int random(int n) {
	srand((unsigned)time(NULL));
	int rd = rand();

	return(rd % n);
}

//x좌표 증가가 동쪽 감소가 서쪽 
//z좌표 감소가 북쪽 증가가 남쪽

//6. 의자함수N
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_N (StairsID stairs, int x, int y, int z, int xlen, int ylen) {
	
	//의자 생성 
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < ylen; j++)
		{
			//z좌표 감소하는 쪽이 북쪽이므로 z-j가 맞음
			installStairs(stairs, x + i, y + j, z -j, FACING_NORTH);

		}
	}

	//의자뒤의 빈부분 채워주는 함수
	WoodID wood = createWood(WOOD_DARK_OAK);   //의자 빈부분을 뭘로 채울지 결정
	for (int i = 0; i < xlen; i++) {
		for (int j = 1; j < ylen; j++)
		{
			int high = j;
			while (high >= 1) {
				//z좌표 감소하는 쪽이 북쪽이므로 z-j가 맞음
				locateBlock(wood, x + i, y + high - 1, z - j);
				high--;
			}
		}
	}
}

//7. 의자함수S
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_S (StairsID stairs, int x, int y, int z, int xlen, int ylen) {
	
	//의자 생성 
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < ylen; j++)
		{
			//z좌표 감소하는 쪽이 남쪽이므로 z+j
			installStairs(stairs, x + i, y + j, z + j, FACING_SOUTH);

		}	
	}
	
	//의자뒤의 빈부분 채워주는 함수
	WoodID wood = createWood(WOOD_DARK_OAK);   //의자 빈부분을 뭘로 채울지 결정
	for (int i = 0; i < xlen; i++) {
		for (int j = 1; j < ylen; j++)
		{
			int high = j;
			while (high >= 1) {
				//z좌표 감소하는 쪽이 북쪽이므로 z+j가 맞음
				locateBlock(wood, x + i, y + high - 1, z + j);
				high--;
			}
		}
	}

}

//8. 의자함수E
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_E (StairsID stair, int x, int y, int z, int zlen, int ylen) {

	//의자생성
	for (int i = 0; i < zlen; i++) {
		for (int j = 0; j < ylen; j++) {

			installStairs(stair, x + j, y + j, z + i, FACING_EAST);
		}
	}

	//의자뒤 빈부분 채워줌
	WoodID wood = createWood(WOOD_DARK_OAK);   //의자 빈부분을 뭘로 채울지 결정 
	for (int i = 0; i < zlen; i++) {
		for (int j = 1; j < ylen; j++) {

			int high = j;
			while (high >= 1) {
				locateBlock(wood, x + j, y + high - 1, z + i);
				high--;
			}

		}
	}
}

//9. 의자함수W
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_W(StairsID stair, int x, int y, int z, int zlen, int ylen) {

	//의자생성
	for (int i = 0; i < zlen; i++) {
		for (int j = 0; j < ylen; j++) {

			installStairs(stair, x - j, y + j, z + i, FACING_WEST);
		}
	}

	//의자뒤 빈부분 채워줌
	WoodID wood = createWood(WOOD_DARK_OAK);   //의자 빈부분을 뭘로 채울지 결정 
	for (int i = 0; i < zlen; i++) {
		for (int j = 1; j < ylen; j++) {

			int high = j;
			while (high >= 1) {
				locateBlock(wood, x - j, y + high - 1, z + i);
				high--;
			}

		}
	}
}

//10. 딜레이 함수
//for문 반복횟수를 받는다.
void delay(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {

			}
		}
	}
}
//11. 구를 만드는 함수
//block, x좌표, y좌표, z좌표, 구의 반지름을 받음
void circle2(BlockID block, int x, int y, int z, int r) {

	double PI = 3.14159265358979323846;
	double radian = PI / 180;

	for (int i = 0; i < 360; i++) {
		double rx = r * cos(radian * i);
		double rz = r * sin(radian * i);

		//원을 만들면서 z축을 기준으로 회전시킴
		for (int j = 0; j < 360; j++) {
			double rx2 = rx * cos(radian * j);
			double ry2 = rx * sin(radian * j);
			locateBlock(block, x + rx2, y + ry2, z + rz);
		}
	}

}

//12.축구공 아직 미완성, 다듬을 필요가 있음
void soccerball(int x, int y, int z, int r) {

	WoolID a1 = createWool(BlockColor(COLOR_BLACK));
	WoolID a2 = createWool(BlockColor(COLOR_WHITE));
	double PI = 3.14159265358979323846;
	double radian = PI / 180;

	for (int i = 1; i < 360; i++) {
		double rx = r * cos(radian * i);
		double rz = r * sin(radian * i);

		//원을 만들면서 z축을 기준으로 회전시킴
		for (int j = 1; j < 360; j = j++) {
			double rx2 = rx * cos(radian * j);
			double ry2 = rx * sin(radian * j);
			locateBlock(a2, x + rx2, y + ry2, z + rz);
		}
	}
	for (int i = 0; i < 360; i = i + 4) {
		double rx = r * cos(radian * i);
		double rz = r * sin(radian * i);

		//원을 만들면서 z축을 기준으로 회전시킴
		for (int j = 0; j < 360; j = j + 4) {
			double rx2 = rx * cos(radian * j);
			double ry2 = rx * sin(radian * j);
			locateBlock(a1, x + rx2, y + ry2, z + rz);
		}
	}
