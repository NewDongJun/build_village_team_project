#include "basic_function.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
/*
기본함수 10개
1. 사각형 만드는 함수
2. 기둥을 만드는 함수
3. 선그리는함수(필드에 그리는선)
4. 의자함수
 필드 만드는 함수( 함수하나 만들고 선그리는거랑 같이 쓰면 기본함수로 취급가능)
6. 골대 뼈대함수
7. 골대 망 함수
8. 벽함수(경기장에 서리하는거)


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

