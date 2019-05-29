#include "basic_function.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
/*
�⺻�Լ� 10��
1. �簢�� ����� �Լ�
2. ����� ����� �Լ�
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

