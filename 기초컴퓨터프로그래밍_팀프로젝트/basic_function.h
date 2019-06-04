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

//6. 의자함수N
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_N(StairsID stairs, int x, int y, int z, int xlen, int ylen);

//7. 의자함수S
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_S(StairsID stairs, int x, int y, int z, int xlen, int ylen);

//8. 의자함수E
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_E(StairsID stair, int x, int y, int z, int zlen, int ylen);

//9. 의자함수W
//stairs x좌표, y좌표, z좌표, 의자너비, 의자높이를 받음
void chairs_W(StairsID stair, int x, int y, int z, int zlen, int ylen);

//10
void circle2(BlockID block, int x, int y, int z, int r);
//11
void soccerball(int x, int y, int z, int r);