#include <stdio.h>
#include "symboltable.h"
#include "typetable.h"


int main(int argc, char const *argv[])
{
	symbol s;
	params p;
	setParams("qwerty",p,0);
	p=getParams("qwerty",0);

	s = create_symbol("id",1,2,3,p);
	return 0;
}
