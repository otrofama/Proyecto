#include <stdio.h>
#include "symboltable.h"
#include "typetable.h"


int main(int argc, char const *argv[])
{
	symbol s,s1;
	params p;
	params p1;
	setParams("qwerty",p,0);
	setParams("sqwerty",p1,0);
	p=getParams("qwerty",0);
	p1=getParams("sqwerty",0);

	s = create_symbol("id",1,2,3,p);
	printf("%d\n",insert_symbol(0,s) );
	printf("%d\n",insert_symbol(0,s) );
	return 0;
}
