#include "basic_function.h"
#include <math.h>
#include <stdlib.h> 
#include <time.h>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
/*
기본함수 10개
1. 사각형 만드는 함수
2. 기둥을 만드는 함수
3. 원을 만드는 함수
4. 선그리는 함수
5. 0부터 n-1까지 개의 난수를 생성하는 함수
6. 의자함수


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
	for (int i = 0; i < xlen; i++) {
		for (int j = 1; j < ylen; j++)
		{
			int high = j;
			while (high >= 1) {
				//z좌표 감소하는 쪽이 북쪽이므로 z-j가 맞음
				WoodID wood = createWood(WOOD_DARK_OAK);
				locateBlock(wood, x + i, y + high - 1, z - j);
				high--;
			}
		}
	}
}

//7. 의자함수S
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_S (StairsID stairs, int x, int y, int z, int xlen, int ylen) {
	

}

//8. 의자함수E
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_E (StairsID stair, int x, int y, int z, int zlen, int ylen) {

}

//9. 의자함수W
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_W(StairsID stair, int x, int y, int z, int zlen, int ylen) {

}