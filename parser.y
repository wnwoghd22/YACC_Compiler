%{
#include <stdio.h>
#include <stdlib.h>
#include "SymbolTable.h"
//#typedef char* string

struct Node* IDENT;

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
%type <stringVal> Decl

%%
Cmp_Stmt : 
	 | Stmt Cmp_Stmt
	 ;
Stmt : Expr ';' { printf("Line %d - result : %d \n", lineNo, $1); $$ = $1; }
     | Decl ';' { printf("Line %d - declare %d \n", lineNo, type); $$ = TRUE; }
     |  ';' {}
     ;
Expr : E { $$ = $1; }
     ;
E : E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { if ($3 == 0)
		yyerror("zero division error");
	      else
		$$ = $1 / $3; }
  | '-' E %prec UMINUS { $$ = -$2; }
  | '(' E ')'   { $$ = $2; }
  | iVal
  | ID		{ $$ = GetValue($1); }
  ;
Decl : type Define { type = $1; }
     ;
Define: ID assign_option decl_option
        {
		Insert(type, $1, lineNo);
		IDENT = GetNode($1);
		IDENT->intVal = $2;
	}
      ;
assign_option :		 { $$ = 0; }
	      | '=' Expr { printf("assign \n"); $$ = $2; }
	      ;
decl_option : {}
	    | ',' Define
	    ;
type : INT
     | DOUBLE
     | CHAR
     ;

%%

int main()
{	
	Table = (struct Node*)malloc(sizeof(struct Node*));
	Table->next = NULL;

	IDENT = (struct Node*)malloc(sizeof(struct Node*));

	yyparse();

}
void yyerror(char* msg)
{
	fprintf(stderr, "Error at line %d", lineNo);
	exit(1);
}
