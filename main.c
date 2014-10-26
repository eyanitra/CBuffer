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

void peekMellon(CB_HDL *pk)
{
	MEL mallun;
	int i;
	for(i = 13; i >= 0; --i){
		CB_peek(pk, i, &mallun);
		printf("peek mallun (%d): %d\n",i,mallun.berat);
	}
}


void korekMellon(CB_HDL *pk)
{
	if(!CB_isEmpty(pk)){
		printf("num of mallun: %d\n",CB_curSize(pk));
		CB_removeElements(pk);
		printf("num of mallun: %d\n",CB_curSize(pk));
		printf("%s mallun survive\n", CB_isEmpty(pk)?"none":"some");
	}
}


int main(int argc, char **argv)
{
	CB_HDL hdl;
	hdl = CB_create(11, sizeof(MEL));
	addMellon(&hdl);
	peekMellon(&hdl);
	extMellon(&hdl);
	printf("next\n");
	addMellon(&hdl);
	korekMellon(&hdl);
	CB_clear(&hdl);
	printf("end of test\n");
	return 0;
}
