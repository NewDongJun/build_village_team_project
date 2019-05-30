#include <iostream>
#include "dong.h"
#include "min.h"
#include "nyeng.h"
#include "woo.h"
#include "basic_function.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

int main()
{
	StairsID stair = createStairs(STAIRS_DARK_OAK, false);
	installStairs(stair, 0, 4, 0, FACING_EAST);
}

