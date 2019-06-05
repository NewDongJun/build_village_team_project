#pragma once

#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

//필드를 완전히 감싸는 관중석 함수 
//필드의 x너비 y너비 의자 높이 그리고 가장 필드의 모서리 중에서 가장 작은 x y z 값
void DJ_stand(int xlen, int zlen, int high, int x, int y, int z);

//화단 만드는 함수 
//x좌표 y좌표 z좌표 x축길이 z축길이를 받는다.
void plant_flower(int x, int y, int z, int xlen, int zlen);

//트로피 조형물 만드는 함수
//x좌표 y좌표 z좌표를 받음
void trophy(int x, int y, int z);