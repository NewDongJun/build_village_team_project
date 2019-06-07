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
	chairs_N(Chair, -5, 5, -16, 112, 10);//-6
	chairs_E(Chair, 97, 5, -24, 170, 10);
	chairs_S(Chair, -5, 5, 137, 112, 10);//127
	//StairsID stairs, int x, int y, int z, int xlen, int ylen)



}

void mainground() {

	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID whiteline = createWool(BlockColor(COLOR_WHITE));




	rectangle(grass, -23, 5, -23, 138, 1, 168);
	rectangle(grass, -27, 4, -27, 146, 1, 176);
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

//스포츠 센터를 만들어 보아요
void sportcenter() {

	WoolID Whiteblock = createWool(BlockColor(COLOR_WHITE));
	BlockID Glass = createBlock(BLOCK_STAINED_GLASS);
	BlockID Blank = createBlock(BLOCK_AIR);
	TerracottaID Bricks = createTerracotta(TERRACOTTA_GLAZED, BlockColor(COLOR_WHITE));
	PlanksID Bricks2 = createPlanks(PLANKS_OAK);

								
	circle_y(Whiteblock, -39, 7,60, 35);
	circle_y(Whiteblock, -39, 7,60, 36);
	circle_y(Whiteblock, -39, 7,60, 45);
	circle_y(Whiteblock, -39, 7,60, 46);
	circle_y(Whiteblock, -39, 7,60, 55);
	circle_y(Whiteblock, -39, 7,60, 56);
											//꾸미기

	rectangle(Bricks2, -41, 14, -7, 14, 1, 138); //중간난간

	rectangle(Bricks2, -39, 4, -5, 10, 20, 130); //가장큰건물
	rectangle(Blank, -38, 5, -4, 8, 18, 128);
	rectangle(Bricks2, -40, 24, -6, 12, 3, 132); //옥상 난간
	rectangle(Blank, -39, 25, -5, 10, 3, 130);

	rectangle(Bricks2, -50, 4, 29, 11, 10, 61); //앞쪽 건물
	rectangle(Blank, -49, 4, 30, 9, 9, 58);
	rectangle(Bricks2, -51, 14, 28, 13, 3, 63); //앞쪽 옥상난간
	rectangle(Blank, -50, 15, 29, 11, 3, 61);
	//BlockID block, int x, int y, int z, int xlen, int ylen, int zlen);


	for (int j = 1; j < 8; j = j + 5) {
		for (int i = 0; i < 58; i = i + 4) {
			locateBlock(Glass, -50, 5+j, 30 + i);
			locateBlock(Glass, -50, 5+j, 31 + i);
			locateBlock(Glass, -50, 5 + j, 32 + i);
			locateBlock(Glass, -50, 6 + j, 30 + i);
			locateBlock(Glass, -50, 6 + j, 31 + i);
			locateBlock(Glass, -50, 6 + j, 32 + i);
		}
	}

	for (int j = 1; j < 18; j = j + 5) {
		for (int i = 0; i < 126; i = i + 4) {
			locateBlock(Glass, -39, 5 + j, -4 + i);
			locateBlock(Glass, -39, 5 + j, -3 + i);
			locateBlock(Glass, -39, 5 + j, -2 + i);
			locateBlock(Glass, -39, 6 + j, -4 + i);
			locateBlock(Glass, -39, 6 + j, -3 + i);
			locateBlock(Glass, -39, 6 + j, -2 + i);
		}
	}

	//글씨 CAU SPORTS
	{int y = 14;  int z = 40;
		locateBlock(Whiteblock, -52,y+1,z+0);
		locateBlock(Whiteblock, -52,y+2,z+0);
		locateBlock(Whiteblock, -52,y+3,z+0);
		locateBlock(Whiteblock, -52,y+4,z+0);
		locateBlock(Whiteblock, -52,y+5,z+0);
		locateBlock(Whiteblock, -52,y+6,z+0);
		locateBlock(Whiteblock, -52,y+0,z+1);
		locateBlock(Whiteblock, -52,y+1,z+1);
		locateBlock(Whiteblock, -52,y+6,z+1);
		locateBlock(Whiteblock, -52,y+7,z+1);
		locateBlock(Whiteblock, -52,y+0,z+2);
		locateBlock(Whiteblock, -52,y+1,z+2);
		locateBlock(Whiteblock, -52,y+6,z+2);
		locateBlock(Whiteblock, -52,y+7,z+2);
		locateBlock(Whiteblock, -52,y+0,z+4);
		locateBlock(Whiteblock, -52,y+1,z+4);
		locateBlock(Whiteblock, -52,y+2,z+4);
		locateBlock(Whiteblock, -52,y+3,z+5);
		locateBlock(Whiteblock, -52,y+4,z+5);
		locateBlock(Whiteblock, -52,y+5,z+5);
		locateBlock(Whiteblock, -52,y+6,z+5);
		locateBlock(Whiteblock, -52,y+3,z+6);
		locateBlock(Whiteblock, -52,y+4,z+6);
		locateBlock(Whiteblock, -52,y+7,z+6);
		locateBlock(Whiteblock, -52,y+3,z+7);
		locateBlock(Whiteblock, -52,y+4,z+7);
		locateBlock(Whiteblock, -52,y+5,z+7);
		locateBlock(Whiteblock, -52,y+6,z+7);
		locateBlock(Whiteblock, -52,y+0,z+8);
		locateBlock(Whiteblock, -52,y+1,z+8);
		locateBlock(Whiteblock, -52,y+2,z+8);
		locateBlock(Whiteblock, -52,y+1,z+10);
		locateBlock(Whiteblock, -52,y+2,z+10);
		locateBlock(Whiteblock, -52,y+3,z+10);
		locateBlock(Whiteblock, -52,y+4,z+10);
		locateBlock(Whiteblock, -52,y+5,z+10);
		locateBlock(Whiteblock, -52,y+6,z+10);
		locateBlock(Whiteblock, -52,y+7,z+10);
		locateBlock(Whiteblock, -52,y+0,z+11);
		locateBlock(Whiteblock, -52,y+1,z+11);
		locateBlock(Whiteblock, -52,y+0,z+12);
		locateBlock(Whiteblock, -52,y+0,z+13);
		locateBlock(Whiteblock, -52,y+1,z+13);
		locateBlock(Whiteblock, -52,y+1,z+14);
		locateBlock(Whiteblock, -52,y+2,z+14);
		locateBlock(Whiteblock, -52,y+3,z+14);
		locateBlock(Whiteblock, -52,y+4,z+14);
		locateBlock(Whiteblock, -52,y+5,z+14);
		locateBlock(Whiteblock, -52,y+6,z+14);
		locateBlock(Whiteblock, -52,y+7,z+14);
		locateBlock(Whiteblock, -52,y+1,z+16);
		locateBlock(Whiteblock, -52,y+5,z+16);
		locateBlock(Whiteblock, -52,y+6,z+16);
		locateBlock(Whiteblock, -52,y+0,z+17);
		locateBlock(Whiteblock, -52,y+4,z+17);
		locateBlock(Whiteblock, -52,y+7,z+17);
		locateBlock(Whiteblock, -52,y+0,z+18);
		locateBlock(Whiteblock, -52,y+4,z+18);
		locateBlock(Whiteblock, -52,y+7,z+18);
		locateBlock(Whiteblock, -52,y+1,z+19);
		locateBlock(Whiteblock, -52,y+2,z+19);
		locateBlock(Whiteblock, -52,y+3,z+19);
		locateBlock(Whiteblock, -52,y+6,z+19);
		locateBlock(Whiteblock, -52,y+0,z+21);
		locateBlock(Whiteblock, -52,y+1,z+21);
		locateBlock(Whiteblock, -52,y+2,z+21);
		locateBlock(Whiteblock, -52,y+3,z+21);
		locateBlock(Whiteblock, -52,y+4,z+21);
		locateBlock(Whiteblock, -52,y+5,z+21);
		locateBlock(Whiteblock, -52,y+6,z+21);
		locateBlock(Whiteblock, -52,y+3,z+22);
		locateBlock(Whiteblock, -52,y+7,z+22);
		locateBlock(Whiteblock, -52,y+3,z+23);
		locateBlock(Whiteblock, -52,y+7,z+23);
		locateBlock(Whiteblock, -52,y+4,z+24);
		locateBlock(Whiteblock, -52,y+5,z+24);
		locateBlock(Whiteblock, -52,y+6,z+24);
		locateBlock(Whiteblock, -52,y+1,z+26);
		locateBlock(Whiteblock, -52,y+2,z+26);
		locateBlock(Whiteblock, -52,y+3,z+26);
		locateBlock(Whiteblock, -52,y+4,z+26);
		locateBlock(Whiteblock, -52,y+5,z+26);
		locateBlock(Whiteblock, -52,y+6,z+26);
		locateBlock(Whiteblock, -52,y+0,z+27);
		locateBlock(Whiteblock, -52,y+7,z+27);
		locateBlock(Whiteblock, -52,y+0,z+28);
		locateBlock(Whiteblock, -52,y+7,z+28);
		locateBlock(Whiteblock, -52,y+1,z+29);
		locateBlock(Whiteblock, -52,y+2,z+29);
		locateBlock(Whiteblock, -52,y+3,z+29);
		locateBlock(Whiteblock, -52,y+4,z+29);
		locateBlock(Whiteblock, -52,y+5,z+29);
		locateBlock(Whiteblock, -52,y+6,z+29);
		locateBlock(Whiteblock, -52,y+0,z+31);
		locateBlock(Whiteblock, -52,y+1,z+31);
		locateBlock(Whiteblock, -52,y+2,z+31);
		locateBlock(Whiteblock, -52,y+3,z+31);
		locateBlock(Whiteblock, -52,y+4,z+31);
		locateBlock(Whiteblock, -52,y+5,z+31);
		locateBlock(Whiteblock, -52,y+6,z+31);
		locateBlock(Whiteblock, -52,y+7,z+31);
		locateBlock(Whiteblock, -52,y+3,z+32);
		locateBlock(Whiteblock, -52,y+4,z+32);
		locateBlock(Whiteblock, -52,y+7,z+32);
		locateBlock(Whiteblock, -52,y+1,z+33);
		locateBlock(Whiteblock, -52,y+2,z+33);
		locateBlock(Whiteblock, -52,y+4,z+33);
		locateBlock(Whiteblock, -52,y+7,z+33);
		locateBlock(Whiteblock, -52,y+0,z+34);
		locateBlock(Whiteblock, -52,y+1,z+34);
		locateBlock(Whiteblock, -52,y+5,z+34);
		locateBlock(Whiteblock, -52,y+6,z+34);
		locateBlock(Whiteblock, -52,y+7,z+36);
		locateBlock(Whiteblock, -52,y+7,z+37);
		locateBlock(Whiteblock, -52,y+0,z+38);
		locateBlock(Whiteblock, -52,y+1,z+38);
		locateBlock(Whiteblock, -52,y+2,z+38);
		locateBlock(Whiteblock, -52,y+3,z+38);
		locateBlock(Whiteblock, -52,y+4,z+38);
		locateBlock(Whiteblock, -52,y+5,z+38);
		locateBlock(Whiteblock, -52,y+6,z+38);
		locateBlock(Whiteblock, -52,y+7,z+38);
		locateBlock(Whiteblock, -52,y+7,z+39);
		locateBlock(Whiteblock, -52,y+7,z+40);
	}
}
	/*
		for (int i = 0; i < xlen; i++) {
			for (int j = 0; j < ylen; j++) {
				for (int k = 0; k < zlen; k++) {
					locateBlock(block, x + i, y + j, z + k);
				}
			}
		}
	}

	*/