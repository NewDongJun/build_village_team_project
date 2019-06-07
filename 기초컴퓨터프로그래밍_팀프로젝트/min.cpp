#include "min.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
#include "basic_function.h"

void min() {

	WoolID WHiteblock = createWool(BlockColor(COLOR_WHITE));
	BlockID pillar = createBlock(BLOCK_IRON);
	PlanksID DIY = createPlanks(PLANKS_JUNGLE);
	BlockID GLOW = createBlock(BLOCK_GLOWSTONE);
	




	soccerpillar(pillar, 35, 5, -7, 20, 10, 8);
	soccerpillar(pillar, 35, 5, 120, 20, 10, 8);

	airballoon(GLOW, DIY, WHiteblock, -7, 80, 40, 20, 20, 20);
	airballoon(GLOW, DIY, WHiteblock, -20, 140, 90, 24, 24, 24);

}

void soccerpillar(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen) {

	for (int i = 0; i <= ylen; i++) {

		locateBlock(block, x, y + i, z);
		locateBlock(block, x, y + i, z + zlen);
		locateBlock(block, x + xlen, y + i, z);
		locateBlock(block, x + xlen, y + i, z + zlen);
	}
	for (int i = 0; i <= xlen; i++) {
		locateBlock(block, x + i, y, z);
		locateBlock(block, x + i, y, z + zlen);
		locateBlock(block, x + i, y + ylen, z);
		locateBlock(block, x + i, y + ylen, z + zlen);
	}
	for (int i = 0; i <= zlen; i++) {
		locateBlock(block, x, y, z + i);
		locateBlock(block, x, y + ylen, z + i);
		locateBlock(block, x + xlen, y, z + i);
		locateBlock(block, x + xlen, y + ylen, z + i);
	}

}

void netR(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen) {

	for (int i = 0; i < xlen - 1; i++) {
		for (int j = 0; j < ylen - 1; j++) {
			for (int k = 0; k < zlen - 1; k++) {
				locateBlock(block, (x + 1) + i, (y + 1) + j, z);
				locateBlock(block, (x), (y + 1) + j, z + 1 + k);
				locateBlock(block, (x + 1) + i, (y + 1) + j, (z + zlen));
				locateBlock(block, (x + 1) + i, ylen + y, (z + 1) + k);

			}
		}
	}
}


void netL(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen)
{

	for (int i = 0; i < xlen - 1; i++) {
		for (int j = 0; j < ylen - 1; j++) {
			for (int k = 0; k < zlen - 1; k++) {
				locateBlock(block, (x + 1) + i, (y + 1) + j, z);
				locateBlock(block, (x + xlen), (y + 1) + j, z + 1 + k);
				locateBlock(block, (x + 1) + i, (y + 1) + j, (z + zlen));
				locateBlock(block, (x + 1) + i, ylen + y, (z + 1) + k);


			}
		}
	}
}


void pillar1(int block, int x, int y, int z, int ylen) {


	for (int i = 0; i < ylen; i++) {
		locateBlock(block, x, y + i, z);

	}
}


void airballoon(int cblock, int rblock, int pblock, int x, int y, int z, int xlen, int ylen, int zlen) {

	circle2(cblock, x + (xlen / 2), y + ylen + ylen + (ylen / 3), z + +(zlen / 2), ylen);
	pillar1(pblock, x + (xlen / 4), y + ylen, z + (zlen / 4), ylen);
	pillar1(pblock, x + (xlen / 4), y + ylen, z + zlen - (zlen / 4), ylen);
	pillar1(pblock, x + xlen - (xlen / 4), y + ylen, z + zlen - (zlen / 4), ylen);
	pillar1(pblock, x + xlen - (xlen / 4), y + ylen, z + (zlen / 4), ylen);
	rectangle(rblock, x, y, z, xlen, ylen, zlen);
}