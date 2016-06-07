//Tabla de tipos
struct _type
{
	int type;
	int dim;
	int width;
	int base;
	//_type *next
}
typedef struct _type type;

struct _type_table
{
	type _type_table[100];//type *t;
	int cont;//sig localidad disponible
}

typedef struct _type_table Ttable;

Ttable Tstack[100];

int insert_type(Ttable *table, type t)
{
	table.t[cont] = t;
	table.cont++;
	return table.cont-1;
}


type create_type(int type, int dim, int width, int base)
{
	//
}


void create_type_table(Ttable *table)
{
	type t_char = create_type(0,-1,1,-1);
	insert_type(tabla,t_char);
	//
	//
	//
	//
	//
	//
}
/*int contadorPila;*/
int contTstack;
void push_type(Ttable table)
{
	Tstack[contTstack] = table;
	contTstack++;
}

void pop()
{
	Tstack[contTstack -1].cont = 0;
	contTstack--;
}

int getTypeBase(int i)
{
	return Tstack[contTstack-1].t[i].base;
}

int getWidthElement(int i)
{
	return Tstack[contTstack-1].t[i].width;
}

///////////////////////
///tabla de símbolos

struct _symbol
{
	char id[50];
	int type;
	int typeVar;
	int dir;
	params param;
};
typedef struct _symbol symbol;

struct _symbol_table
{
	symbol s[100];
	int cont;
};
typedef struct _symbol_table Stable;
Stable Sstack[10];
int contSstack;

int insert_symbol(symbol s)
{
	/*if existe en tabla....*/
	Sstack[contSstack-1].s[Sstack[contSstack-1].cont] =  s;
	Sstack[contSstack-1].cont++;
	return Sstack[contSstack-1].cont-1;

	return -1 // ya estaba en tabla de símbolos
}

int i;


//int get_Symbol(char *id)//contador para pila global
int get_Symbol(char *id,int table)//contador para pila global
{
	//for (i = 0; i < Sstack[contSstack-1].cont; i++)
	for (i = 0; i < Sstack[table].cont; i++)
	{
		if (Sstack[table].s[i].id==id)
			return i;
	}
	return -1;
}


// params
struct params
{
	int type[20];
	int cont;
}

params getParams(char* id)
{
	int i = get_Symbol(id,0);
	return Sstack[0].s[i].param;
}

void setParams(char* id,params p)
{
	int i = get_Symbol(id,0);
	Sstack[0].s[i].param = p;
}

int getTypeSymbol(char* id,int table)
{
	int i = get_Symbol(id,table);
	return Sstack[table].s[i].type;
}

int getTypeVar(char* id,int table)
{
	int i = get_Symbol(id,table);
	return Sstack[table].s[i].typevar;
}

void push_symbol()
{
	contSstack++;
}

void pop_symbol()
{
	Sstack[contSstack-1].cont = 0;
	contSstack--;
}

/*principios, técnicas aho*/

%union
{
	struct
	{
		int tipo;
		int ancho;
	}type;
	struct
	{
		char val[50];
		int type;
	}num;
}
%token<num> NUM
%type<type> tipo base arreglo

%%

t y w son variables globales

decl: decl tipo{c_w=$2.ancho;c_t=$2.tipo;} list_var PC
	|;

tipo: base {t= $1.tipo;w=$1.ancho;} arreglo {
	$$.tipo = $3.tipo;
	$$.ancho = $3.ancho;
};

base: INT {$$.tipo=1;$$.ancho=4;}
	| FLOAT {$$.tipo=2;$$.ancho=8;}
	| DOUBLE {$$.tipo=3;$$.ancho=16;}
	| CHAR {$$.tipo=0;$$.ancho=1;};

arreglo: {$$.tipo=t;$$.ancho=w;}
	| LPAR NUM RPAR arreglo {
		type t = create_type(5,atoi($2.val),atoi($2.val)*$4.ancho,$$.tipo);
		$$.tipo=insert_type(t,contTstack-1);
		$$.ancho = atoi($2.val)*$4.ancho;
	};
