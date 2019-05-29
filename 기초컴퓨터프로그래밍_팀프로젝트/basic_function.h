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