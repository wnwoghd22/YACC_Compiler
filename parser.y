%{
#include <stdio.h>
#include <stdlib.h>
#include "SymbolTable.h"

//typedef char* string;

Node IDENT;

extern int prag_source;
extern int prag_token;
extern int prag_parse;
extern int prag_tag;
extern int system_flag;
extern int lineNo;

int type = 0;

%}
%start Cmp_Stmt

%union{
	int intVal;
	double doubleVal;
	char charVal;
	char* stringVal;
	//struct symbol *sym;
}
%token VOID RETURN STRUCT
%token <intVal> iVal INT DOUBLE FLOAT CHAR STRING
%token <doubleVal> fVal
%token <charVal> cVal
%token <stringVal> sVal ID
%token KEY OP PUNC

%token NOT EQ NQ GQ LQ GT LT AND OR BAND BOR

%left '-' '+' 
%left '*' '/'
%nonassoc UMINUS INC DEC

%type <intVal> Stmt Expr E
%type <intVal> type assign_option
%type <stringVal> Define

%%
Cmp_Stmt : 
	 | Stmt Cmp_Stmt
	 ;
Stmt : Expr ';' { 
     		if( prag_parse == 1 )
     			printf("Line %d - result : %d \n", lineNo, $1);
		$$ = $1;
		}
     | Decl	{
		if( prag_parse == 1 )
			printf("\n"); 
		$$ = TRUE;
		}
     |  ';' {}
     ;
Expr :
     	{ if( prag_tag == 1 )
		printf("<Expr>"); }
     	E
	{ if( prag_tag == 1 )
		printf("</Expr>"); }
	;
E :	
	E
	'+' { if( prag_tag == 1) printf("+"); }
	E
	{ $$ = $1 + $4; } 
     | 
	E
	'-' { if( prag_tag == 1) printf("-"); }
	E
	{ $$ = $1 - $4; }
     |   
	E
	'*' { if(prag_tag == 1) printf("*"); }
	E
	{ $$ = $1 * $4; } 
     | 	
	E
	'/' { if(prag_tag == 1) printf("/"); }
	E   { if ($4 == 0)
		yyerror("zero division error");
	      else
		$$ = $1 / $4; } 
    | 
	'-' E %prec UMINUS { $$ = -$2; }
    | 
	'(' E ')'   { $$ = $2; }
    |
	 iVal	{ if( prag_tag == 1 )
			printf("<Expr>%d</Expr>", $1); }
    | 
	ID	{ $$ = GetValue($1); 
		  if( prag_tag == 1 )	
			printf("<Expr>%s</Expr>", $1); }
    ;
Decl : type
	{ type = $1;
		if( prag_parse == 1 )
			printf("Line %d - declare ", lineNo);
		if( prag_tag == 1 )
		{
			printf("<scalar_decl>");
			PrintType(type);
		}
	}
	
       Define
     ;
Define : ID
        {
		if( prag_parse == 1 )
			printf("%s ", $1);
		if( prag_tag == 1 )
			printf("%s", $1);
		Insert(type, $1, lineNo);
		IDENT = GetNode($1);
	}
	assign_option
	{
		IDENT->intVal = $3;
	}
	decl_option
	';'			{ printf(";</scalar_decl>");	}
      |	ID '[' iVal ']'		{ printf("<array_decl>");	}
	arr_assign_option
	decl_option
	';'			{ printf(";</array_decl>");	}
      | ID '(' type ID ')'	{ printf("<function_decl>");	}
	'{'
	{ PrintType(type); printf("%s(", $1);
	  PrintType($3); printf("%s){", $4); }
		Stmt
	'}'			{ printf("}</function_decl>"); }
      ;
assign_option :		 { $$ = 0; }
	      | '='	{ 
			if( prag_parse == 1 )
				printf("assign ");
			if( prag_tag == 1 )
				printf("="); }
		Expr
			{ $$ = $3; }
	      ;
arr_assign_option : {;}
		  | '=' '{'
			{ if( prag_tag == 1 )
				printf("={"); }
			iVal
			{ if( prag_tag == 1 )
				printf("<Expr>%d</Expr>", $4); } 
			arr_val_option
			'}'
			{ if( prag_tag == 1 )
				printf("}"); }
		  ;
arr_val_option : {;}
	       | ',' iVal
			{ if( prag_tag == 1 )
		 		printf(",<Expr>%d</Expr>", $2); } 
		 arr_val_option
	       ;
decl_option : {;}
	    | ',' 
		{ if( prag_parse == 1 ) printf(", "); 
		  if( prag_tag == 1) printf(",");	}
		Define
	    ;
type : INT	{ $$ = INT_TYPE;	}
     | DOUBLE   { $$ = DOUBLE_TYPE; 	}
     | CHAR	{ $$ = CHAR_TYPE;	}
     | FLOAT	{ $$ = FLOAT_TYPE;	}
     ;

%%

int main()
{	
	prag_source = 0;
	prag_token = 0;
	prag_parse = 0;
	prag_tag = 1;
	Table = (Node)malloc(sizeof(Node));
	Table->next = NULL;

	IDENT = (Node)malloc(sizeof(Node));

	yyparse();

}
void yyerror(char* msg)
{
	fprintf(stderr, "Error at line %d", lineNo);
	exit(1);
}
