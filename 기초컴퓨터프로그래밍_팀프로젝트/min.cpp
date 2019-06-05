#include "min.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
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