#include <stdio.h>
#include "CB_cbuffer.h"

struct mellon{
	int biji;
	char warna;
	int tebal;
	short berat;
};

typedef struct mellon MEL;

void addMellon(CB_HDL *nh){
	MEL mallun;
	int i = 2;
	while(!CB_isFull(nh)){
		mallun.berat = i;
		mallun.biji = i;
		mallun.tebal = i;
		mallun.warna = i;
		printf("add mallun: %d\n", i);
		CB_addElement(nh, &mallun);
		++i;
	}
}

void extMellon(CB_HDL *nh)
{
	MEL mallun;
	while(!CB_isEmpty(nh)){
		printf("size %d ",CB_curSize(nh));
		CB_getElement(nh, &mallun);
		printf("get mallun: %d\n",mallun.berat);
	}
}


int main(int argc, char **argv)
{
	CB_HDL hdl;
	hdl = CB_create(11, sizeof(MEL));
	addMellon(&hdl);
	extMellon(&hdl);
	CB_clear(&hdl);
	printf("hello world\n");
	return 0;
}
