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




void plant_wood(int x, int y, int z) {
	int n = random(6);
	switch (n)
	{

	case 0:
		break;

	case 1:
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		break;
	}

}