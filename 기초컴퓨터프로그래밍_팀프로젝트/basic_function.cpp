#include "basic_function.h"
#include <math.h>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
/*
�⺻�Լ� 10��
1. �簢�� ����� �Լ�
2. ����� ����� �Լ�
3. ���� ����� �Լ�
4. ���׸��� �Լ�
5. 0���� n-1���� ���� ������ �����ϴ� �Լ�

3. ���׸����Լ�(�ʵ忡 �׸��¼�)
4. �����Լ�
    �ʵ� ����� �Լ�( �Լ��ϳ� ����� ���׸��°Ŷ� ���� ���� �⺻�Լ��� ��ް���)
6. ��� �����Լ�
7. ��� �� �Լ�
8. ���Լ�(����忡 �����ϴ°�)


��� �Լ� 
�����Լ�

*/


//1.�簢���� ����� �Լ�
//���, x��ǥ, y��ǥ, z��ǥ, x�ʺ�, y�ʺ�, z�ʺ� �� ����
void rectangle(BlockID block, int x, int y, int z, int xlen, int ylen, int zlen) {
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < ylen; j++) {
			for (int k = 0; k < zlen; k++) {
				locateBlock(block, x + i, y + j, z + k);
			}
		}
	}
}

//2. ����� ����� �Լ� 
//x��ǥ y��ǥ, z��ǥ y�� �ʺ� ����
void pillar(int x, int y, int z, int ylen) {
	BlockID iron = createBlock(BLOCK_IRON);
	for (int i = 0; i < ylen; i++) {
		locateBlock(iron, x + 1, y + i, z);
		locateBlock(iron, x - 1, y + i, z);
		locateBlock(iron, x, y + i, z + 1);
		locateBlock(iron, x, y + i, z - 1);
	}
}

//3. ���� ����� �Լ�
//��� x��ǥ y��ǥ z��ǥ �������� ���� 
//�౸�� �����鶧 �� ������ ������?
void circle(BlockID block, int x, int y, int z, int r) {
	
	double PI = 3.14159265358979323846;
	double radian = PI / 180;

	for (int i = 0; i < 360; i++) {
		double rx = r * cos(radian * i);
		double rz = r * sin(radian * i);
		locateBlock(block, x + rx, y, z + rz);
	}
}

//4. ���׸��� �Լ�
//��� x��ǥ y��ǥ z��ǥ x�ʺ� z�ʺ� ����
void line(BlockID block, int x, int y, int z, int xlen, int zlen) {
	for (int i = 0; i < xlen; i++) {
		for (int j = 0; j < zlen; j++) {
			locateBlock(block, x + i, y, z + j);
		}
	}
}

//5. 0���� n-1���� ���� ������ �����ϴ� �Լ�
int random()