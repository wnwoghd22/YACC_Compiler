%{
#include <stdio.h>
#include <stdlib.h>
#include "SymbolTable.h"

//typedef char* string;

Node* IDENT;

int yylex();
void yyerror(char* msg);

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

	struct _TreeNode* _node;
	//struct symbol *sym;
}
%token VOID RETURN STRUCT
%token <intVal> iVal INT DOUBLE FLOAT CHAR STRING
%token <doubleVal> fVal
%token <charVal> cVal
%token <stringVal> sVal ID
%token KEY OP PUNC

%token NOT EQ NQ GQ LQ GT LT AND OR BAND BOR

%token IF ELSE
%token SWITCH CASE DEFAULT

%left '-' '+' 
%left '*' '/'
%nonassoc UMINUS INC DEC
%right "then" ELSE

%type <intVal> Stmt Expr 
%type <_node> E
%type <intVal> type assign_option

%%
Cmp_Stmt : 
	 | Stmt Cmp_Stmt
	 ;
Stmt : Expr ';' { 
     		if( prag_parse == 1 )
     			printf("Line %d - result : %d \n", lineNo, $1);
		if( prag_tag == 1 )
			printf(";");
		$$ = $1;
		}
     | Decl	{
		if( prag_parse == 1 )
			printf("\n"); 
		$$ = TRUE;
		}
     |	IF '(' { if( prag_tag == 1 )
			printf("<stmt>if("); }
	Expr')'
		{ if( prag_tag == 1)
			printf(")");} C_Stmt if_option { $$ = $4; }
     | SWITCH '(' ID ')' { if( prag_tag == 1)
			printf("<stmt>switch(%s)", $3); }
	'{'
		switch_stmt
	'}' { $$ = 1; }
     |  ';' {}
     ;
C_Stmt : Stmt
       | '{' Cmp_Stmt '}'
       ;
if_option : %prec "then"	{ if( prag_tag == 1 )
	  				printf("</stmt>"); }
	  | ELSE C_Stmt		{ if( prag_tag == 1 )
					printf("</stmt>"); }
	  ;
switch_stmt : 
	    | CASE iVal ':' C_Stmt switch_stmt
	    | DEFAULT ':' C_Stmt switch_stmt
	    ;
Expr :     	
     	E  { Expression = $1;
		$$ = $1->intVal;
		if( prag_tag == 1 )
			PrintTag(Expression); }
	|
	ID
	'='
	E
	{	
		TreeNode* idNode = (TreeNode*)malloc(sizeof(TreeNode));
		idNode->left = NULL; idNode->right = NULL;
		strcpy(idNode->value, $1);
		idNode->intVal = $3->intVal;		

		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = idNode; temp->right = $3;
		temp->value[0] = '=';
		temp->intVal = 1;
		
		Expression = temp;
		if( prag_tag == 1)
			PrintTag(Expression);

		$$ = 1;

		GetNode($1)->intVal = $3->intVal;
	}
	;
E :
	E
	'+'
	E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '+';
		temp->right = $3;
		temp->intVal = temp->left->intVal + temp->right->intVal;
		$$ = temp;
	}
	| 
	E
	'-'
	E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '-';
		temp->right = $3;
		temp->intVal = temp->left->intVal - temp->right->intVal;
		$$ = temp;
	}
     |   
	E
	'*'
	E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '*';
		temp->right = $3;
		temp->intVal = temp->left->intVal * temp->right->intVal;
		$$ = temp;
		} 
     | 	
	E
	'/'
	E   { if ($3 == 0)
		yyerror("zero division error");
	      else
		  {
			TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
			temp->left = $1;
			temp->value[0] = '/';
			temp->right = $3;
			temp->intVal = temp->left->intVal / temp->right->intVal;
			$$ = temp;
		  }
		} 
    | 
	'-' E %prec UMINUS
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		temp->value[0] = '\0';
		temp->right = NULL;
		temp->intVal = -($2->intVal);
		$$ = temp;
	}
    | 
	'(' E ')'
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $2;
		temp->value[0] = '(';
		temp->right = NULL;
		temp->intVal = $2->intVal;
		$$ = temp;
	}
    |
	 iVal
	{	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		temp->value[0] = '\0';
		temp->right = NULL;
		temp->intVal = $1;
		$$ = temp;
	}
    | 
	
	ID
	{ 
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		strcpy(temp->value, $1);
		temp->right = NULL;
		temp->intVal = GetValue($1);
		$$ = temp;
	}
    ;

Decl : type
	 ID
        {
		type = $1;
		if( prag_parse == 1 )
			printf("Line %d - declare ", lineNo);
		if( prag_tag == 1 )
		{
			printf("<scalar_decl>");
			PrintType(type);
		}
		if( prag_parse == 1 )
			printf("%s ", $2);
		if( prag_tag == 1 )
			printf("%s", $2);
		Insert(type, $2, lineNo);
		IDENT = GetNode($2);
	}
	assign_option
	{
		IDENT->intVal = $4;
	}
	decl_option
	';'			{ printf(";</scalar_decl>");	}
      |	
	type
	ID '[' 
	{
	type = $1;
		if( prag_parse == 1 )
			printf("Line %d - declare ", lineNo);
		if( prag_tag == 1 )
		{
			printf("<arr_decl>");
			PrintType(type);
		}
	}
	iVal ']'
		{ printf("%s[%d]", $2, $5); }
	arr_assign_option
	arr_decl_option
	';'			{ printf(";</array_decl>");	}
      |
	  type
	  ID '(' 
	  {
	  type = $1;
		if( prag_parse == 1 )
			printf("Line %d - declare ", lineNo);
		if( prag_tag == 1 )
			printf("<function_decl>");	
		}
	  type ID ')'
	'{'
	{ PrintType(type); printf("%s(", $2);
	  PrintType($5); printf("%s){", $6); }
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
			Expr
			{ if( prag_tag == 1 )
				printf("<Expr>%d</Expr>", $4); } 
			arr_val_option
			'}'
			{ if( prag_tag == 1 )
				printf("}"); }
		  ;
arr_val_option : {;}
	       | ',' Expr
			{ if( prag_tag == 1 )
		 		printf(",<Expr>%d</Expr>", $2); } 
		 arr_val_option
	       ;
decl_option : {;}
	    | ',' 
		{ if( prag_parse == 1 ) printf(", "); 
		  if( prag_tag == 1) printf(",");	}
		ID
		{
			if( prag_tag == 1 )
				printf("%s", $3);
			Insert(type, $3, lineNo);
			IDENT = GetNode($3);
		}
		assign_option
		{
			IDENT->intVal = $5;
		}
		decl_option	
	    ;
arr_decl_option : {;}
		|
		','
		ID '[' iVal ']'
		{
		}
		arr_assign_option
		arr_decl_option
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
	prag_token = 1;
	prag_parse = 0;
	prag_tag = 0;
	
	Table = (Node*)malloc(sizeof(Node));
	Table->next = NULL;

	IDENT = (Node*)malloc(sizeof(Node));

	Expression = (TreeNode*)malloc(sizeof(TreeNode));

	yyparse();

}
void yyerror(char* msg)
{
	fprintf(stderr, "Error at line %d", lineNo);
	exit(1);
}
