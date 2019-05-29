#pragma once
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
//1.사각형을 만드는 함수
//블록, x좌표, y좌표, z좌표, x너비, y너비, z너비 를 받음
void rectangle(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen);

//2. 기둥을 만드는 함수 
//x좌표 y좌표, z좌표 y의 너비를 받음
void pillar(int x, int y, int z, int ylen);

//3. 원을 만드는 함수
//블록 x좌표 y좌표 z좌표 반지름을 받음 
//축구장 원만들때 쑬 수있지 않을까?
void circle(BlockID block, int x, int y, int z, int r);

//4. 선그리는 함수
//블록 x좌표 y좌표 z좌표 x너비 z너비를 받음
void line(BlockID block, int x, int y, int z, int xlen, int zlen);

//5. 0부터 n-1까지 개의 난수를 생성하는 함수
// n을 받음
int random(int n);