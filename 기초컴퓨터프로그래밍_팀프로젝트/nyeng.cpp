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
//최종 함수
void nyeng() {
	scoreboard();
	score(106, 18, 52);
	score(106, 18, 56);
	score(106, 18, 64);
	score(106, 18, 68);
}