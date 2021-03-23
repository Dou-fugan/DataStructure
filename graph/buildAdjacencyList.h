#pragma once
#include "struct.h"
#include <stdio.h>
//下面这两个文件别的源文件中会用到,所以要放在头文件中
int LocateVex(ALGraph g,char v);
void creatAdjList(ALGraph *g);
