funciones no tienen direcciones


%{
int t,w,c_t,c_w,offset=0;
int stackoffset[50];
int spoffset=0;
%}

union
{
	char *id;
	struct
	{
		int type;
		int width;
	}tipo;
	struct
	{
		char* val;
		int type;
	}num;
}


%token INT FLOAT CHAR DOUBLE
%token<id> ID
%token COMA PC
%token<num> NUM

%nonassoc LPAR RPAR LCOR RCOR

%type<tipo> tipo base arreglo

%start program

%%


program: {offset = 0;
		push_symbol();//mete tabla sim en pila}
		push_type();//mete tabla tipps en pila
		} decl;
decl: decl tipo {c_w=$2.widht;c_t=$2.tipo;} list_var PC |;


tipo: base {t=$1.tipo;w=$1.widht;} arreglo {
		$$.tipo=$3.tipo;
		$$.widht=$3.widht;
}
