#pragma once
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
//1.�簢���� ����� �Լ�
//���, x��ǥ, y��ǥ, z��ǥ, x�ʺ�, y�ʺ�, z�ʺ� �� ����
void rectangle(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen);

//2. ����� ����� �Լ� 
//x��ǥ y��ǥ, z��ǥ y�� �ʺ� ����
void pillar(int x, int y, int z, int ylen);

//3. ���� ����� �Լ�
//��� x��ǥ y��ǥ z��ǥ �������� ���� 
//�౸�� �����鶧 �� ������ ������?
void circle(BlockID block, int x, int y, int z, int r);

//4. ���׸��� �Լ�
//��� x��ǥ y��ǥ z��ǥ x�ʺ� z�ʺ� ����
void line(BlockID block, int x, int y, int z, int xlen, int zlen);

//5. 0���� n-1���� ���� ������ �����ϴ� �Լ�
// n�� ����
int random(int n);

//6. �����Լ�N
//stairs x��ǥ, y��ǥ, z��ǥ, ���ڳʺ�, ���ڳ��̸� ����
void chairs_N(StairsID stairs, int x, int y, int z, int xlen, int ylen);

//7. �����Լ�S
//stairs x��ǥ, y��ǥ, z��ǥ, ���ڳʺ�, ���ڳ��̸� ����
void chairs_S(StairsID stairs, int x, int y, int z, int xlen, int ylen);

//8. �����Լ�E
//stairs x��ǥ, y��ǥ, z��ǥ, ���ڳʺ�, ���ڳ��̸� ����
void chairs_E(StairsID stair, int x, int y, int z, int zlen, int ylen);

//9. �����Լ�W
//stairs x��ǥ, y��ǥ, z��ǥ, ���ڳʺ�, ���ڳ��̸� ����
void chairs_W(StairsID stair, int x, int y, int z, int zlen, int ylen);

//10
void circle2(BlockID block, int x, int y, int z, int r);
//11
void soccerball(int x, int y, int z, int r);