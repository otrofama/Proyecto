#include <stdio.h>
#include <stdlib.h>
int contSstack=0;
int contTstack;
#include "symboltable.h"
#include "typetable.h"
//
int main(int argc, char const *argv[])
{
	#if 0
	symbol s[4];
	params p[4];
	setParams("qwerty",p[0],0);
	setParams("sqwerty",p[1],0);
	setParams("1sqwerty",p[2],0);
	s[0] = create_symbol(":v",5,6,9,p[0]);
	s[1] = create_symbol(":'v",-5,-6,-9,p[1]);
	s[2] = create_symbol(":w",-51,-61,-91,p[2]);
	puts("");
	printf("Simbolo %d,id:%s,ty:%d,tyv:%d,dir:%d\n",12,s[0].id,s[0].type,s[0].typeVar,s[0].dir );
	printf("Simbolo %d,id:%s,ty:%d,tyv:%d,dir:%d\n",123,s[1].id,s[1].type,s[1].typeVar,s[1].dir );
	printf("Simbolo %d,id:%s,ty:%d,tyv:%d,dir:%d\n",-123,s[2].id,s[2].type,s[2].typeVar,s[2].dir );

	printf("%d\n",insert_symbol(0,s[0]) );
	printf("%d\n",insert_symbol(0,s[1]) );
	printf("%d\n",insert_symbol(2,s[2]) );
	printStack();
	#endif
	return 0;
}
