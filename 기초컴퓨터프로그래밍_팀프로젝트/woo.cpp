#include "woo.h"
#include "basic_function.h"
#include <iostream>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

void woo() {


	mainground();
	chair_woo();

}

void chair_woo() {


	StairsID Chair = createStairs(STAIRS_SPRUCE, true);
	chairs_N(Chair, -5, 5, -6, 112, 10);
	chairs_E(Chair, 97, 5, -14, 150, 10);
	chairs_S(Chair, -5, 5, 127, 112, 10);
		//StairsID stairs, int x, int y, int z, int xlen, int ylen)



}

void mainground() {

	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID whiteline = createWool(BlockColor(COLOR_WHITE));

	rectangle(grass, -3, 5, -3, 98, 1, 128);
	rectangle(grass, -7, 4, -7, 106, 1, 136);
		//BlockID block, int x, int y, int z, int xlen, int ylen, int zlen) {

	line(whiteline, 1, 5, 1, 90, 1);
	line(whiteline, 1, 5, 1, 1, 120);
	line(whiteline, 1, 5, 120, 90, 1);
	line(whiteline, 90, 5, 1, 1, 120);

	line(whiteline, 1, 5, 60, 90, 1);
		//BlockID block, int x, int y, int z, int xlen, int zlen)

	circle(whiteline, 45, 5, 60, 15);
		//BlockID block, int x, int y, int z, int r) {

	line(whiteline, 25, 5, 25, 41, 1);
	line(whiteline, 25, 5, 1, 1, 25);
	line(whiteline, 65, 5, 1, 1, 25);

	line(whiteline, 25, 5, 96, 41, 1);
	line(whiteline, 25, 5, 96, 1, 25);
	line(whiteline, 65, 5, 96, 1, 25);
	//운동장 선그림
	
}

