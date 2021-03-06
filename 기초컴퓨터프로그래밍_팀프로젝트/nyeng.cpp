#include "nyeng.h"
#include "basic_function.h"
#include "nyeng.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
BlockID OBSI = createBlock(BLOCK_OBSIDIAN);
BlockID AIR = createBlock(BLOCK_AIR);
BlockID GLASS = createBlock(BLOCK_GLASS);
BlockID GB = createBlock(BLOCK_GLOWSTONE);
// 숫자 만드는 함수(랜덤함수 추가하기)
void score(int sx, int sy, int sz) {
	int num;
	int i = 0;
	scanf_s("%d", &num);
	if (num == 0) {
		for (i; i < 5; i++) {
			locateBlock(GB, sx, sy + i, sz);
			locateBlock(GB, sx, sy + i, sz + 2);
		}
		locateBlock(GB, sx, sy + 4, sz + 1);
		locateBlock(GB, sx, sy, sz + 1);
	}
	if (num == 1) {
		for (i = 0; i < 5; i++)
			locateBlock(GB, sx, sy + i, sz + 1);
	}
	if (num == 2) {
		for (i; i < 5; i += 2) {
			locateBlock(GB, sx, sy + i, sz);
			locateBlock(GB, sx, sy + i, sz + 1);
			locateBlock(GB, sx, sy + i, sz + 2);
		}
		locateBlock(GB, sx, sy + 3, sz + 2);
		locateBlock(GB, sx, sy + 1, sz);
	}
	if (num == 3) {
		for (i; i < 5; i += 2) {
			locateBlock(GB, sx, sy + i, sz);
			locateBlock(GB, sx, sy + i, sz + 1);
			locateBlock(GB, sx, sy + i, sz + 2);
		}
		locateBlock(GB, sx, sy + 1, sz + 2);
		locateBlock(GB, sx, sy + 3, sz + 2);
	}
	if (num == 4) {
		for (i = 0; i < 5; i++)
			locateBlock(GB, sx, sy + i, sz + 2);
		locateBlock(GB, sx, sy + 2, sz + 1);
		locateBlock(GB, sx, sy + 2, sz);
		locateBlock(GB, sx, sy + 3, sz);
		locateBlock(GB, sx, sy + 4, sz);
	}
	if (num == 5) {
		for (i; i < 5; i += 2) {
			locateBlock(GB, sx, sy + i, sz);
			locateBlock(GB, sx, sy + i, sz + 2);
			locateBlock(GB, sx, sy + i, sz + 1);
		}
		locateBlock(GB, sx, sy + 3, sz);
		locateBlock(GB, sx, sy + 1, sz + 2);
	}
	if (num == 6) {
		for (i; i < 5; i += 2) {
			locateBlock(GB, sx, sy + i, sz);
			locateBlock(GB, sx, sy + i, sz + 1);
			locateBlock(GB, sx, sy + i, sz + 2);
		}
		locateBlock(GB, sx, sy + 3, sz);
		locateBlock(GB, sx, sy + 1, sz);
		locateBlock(GB, sx, sy + 1, sz + 2);
	}
	if (num == 7) {
		for (i = 0; i < 5; i++)
			locateBlock(GB, sx, sy + i, sz + 2);
		locateBlock(GB, sx, sy + 4, sz + 1);
		locateBlock(GB, sx, sy + 4, sz);
	}
	if (num == 8) {
		for (i; i < 5; i += 2) {
			locateBlock(GB, sx, sy + i, sz);
			locateBlock(GB, sx, sy + i, sz + 1);
			locateBlock(GB, sx, sy + i, sz + 2);
		}
		locateBlock(GB, sx, sy + 3, sz + 2);
		locateBlock(GB, sx, sy + 1, sz + 2);
		locateBlock(GB, sx, sy + 1, sz);
		locateBlock(GB, sx, sy + 3, sz);
	}
	if (num == 9) {
		for (i; i < 5; i += 2) {
			locateBlock(GB, sx, sy + i, sz);
			locateBlock(GB, sx, sy + i, sz + 2);
			locateBlock(GB, sx, sy + i, sz + 1);
		}
		locateBlock(GB, sx, sy + 3, sz + 2);
		locateBlock(GB, sx, sy + 1, sz + 2);
		locateBlock(GB, sx, sy + 3, sz);
	}
}
//전광판 만드는 함수
void scoreboard() {
	rectangle(OBSI, 106, 15, 49, 1, 11, 25);
	rectangle(GLASS, 106, 17, 51, 1, 7, 21);
	locateBlock(GB, 106, 19, 61);
	locateBlock(GB, 106, 21, 61);
}
//펜스 함수
void fence() {
	FenceID FENCE = createFence(FENCE_OAK);
	BlockID LL = createBlock(BLOCK_LAPIS_LAZULI);
	line(LL, -4, 6, -11, 100, 1);
	line(LL, 95, 6, -10, 1, 144);
	line(LL, -4, 6, 133, 99, 1);
	line(LL, -4, 6, -10, 1, 144);

	line(LL, -4, 7, -11, 100, 1);
	line(LL, 95, 7, -10, 1, 144);
	line(LL, -4, 7, 133, 99, 1);
	line(LL, -4, 7, -10, 1, 144);

	line(FENCE, -4, 8, -11, 100, 1);
	line(FENCE, 95, 8, -10, 1, 144);
	line(FENCE, -4, 8, 133, 99, 1);
	line(FENCE, -4, 8, -10, 1, 144);

}
//사람 함수{
void person1(int x, int y, int z) {
	WoolID RW = createWool(COLOR_RED);
	WoolID BW = createWool(COLOR_BLUE);
	WoolID WW = createWool(COLOR_WHITE);
	FenceID FENCE = createFence(FENCE_OAK);
	PlanksID FACE = createPlanks(PLANKS_OAK);
	JackOLanternID asd = createJackOLantern();
	locateFence(FENCE, x - 1, y, z);
	locateFence(FENCE, x + 1, y, z);
	locateFence(FENCE, x - 2, y + 2, z);
	locateFence(FENCE, x + 2, y + 2, z);
	locateWool(BW, x - 1, y + 1, z);
	locateWool(BW, x, y + 1, z);
	locateWool(BW, x + 1, y + 1, z);
	locateWool(RW, x - 1, y + 2, z);
	locateWool(RW, x, y + 2, z);
	locateWool(RW, x + 1, y + 2, z);
	locatePlanks(asd, x, y + 3, z);
}
void person2(int x, int y, int z) {
	WoolID RW = createWool(COLOR_RED);
	WoolID BW = createWool(COLOR_BLUE);
	WoolID WW = createWool(COLOR_WHITE);
	FenceID FENCE = createFence(FENCE_OAK);
	PlanksID FACE = createPlanks(PLANKS_OAK);
	JackOLanternID asd = createJackOLantern();
	locateFence(FENCE, x - 1, y, z);
	locateFence(FENCE, x + 1, y, z);
	locateFence(FENCE, x - 2, y + 2, z);
	locateFence(FENCE, x + 2, y + 2, z);
	locateWool(WW, x - 1, y + 1, z);
	locateWool(WW, x, y + 1, z);
	locateWool(WW, x + 1, y + 1, z);
	locateWool(BW, x - 1, y + 2, z);
	locateWool(BW, x, y + 2, z);
	locateWool(BW, x + 1, y + 2, z);
	locatePlanks(asd, x, y + 3, z);
}
//최종 함수
void nyeng() {
	scoreboard();
	score(106, 18, 52);
	score(106, 18, 56);
	score(106, 18, 64);
	score(106, 18, 68);
	fence();
	person1(20, 6, 40);
	person1(25, 6, 40);
	person1(40, 6, 40);
	person1(40, 6, 30);
	person1(40, 6, 35);
	person1(30, 6, 25);
	person2(20, 6, 100);
	person2(26, 6, 100);
	person2(36, 6, 100);
	person2(40, 6, 90);
	person2(35, 6, 110);
	person2(27, 6, 95);
}