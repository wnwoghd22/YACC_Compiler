%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	struct _parameter* _par;
	//struct symbol *sym;
}
%token VOID RETURN STRUCT CONST
%token <intVal> iVal INT DOUBLE FLOAT CHAR STRING
%token <doubleVal> fVal
%token <charVal> cVal
%token <stringVal> sVal ID
%token KEY OP PUNC

%token NOT EQ NQ GQ LQ GT LT AND OR BAND BOR

%token IF ELSE
%token SWITCH CASE DEFAULT BREAK
%token WHILE DO FOR CONTINUE

%left OR
%left AND
%left BOR
%left BAND
%left EQ NQ
%left GQ LQ GT LT
%left '-' '+' 
%left '*' '/' '%'
%nonassoc UMINUS INC DEC NOT
%right "then" ELSE

%type <intVal> Stmt Expr 
%type <_node> E arr_option
%type <_par> parameter para_option
%type <intVal> type assign_option return_option

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
     | SWITCH '(' ID ')'
	'{'
		{ if( prag_tag == 1)
			printf("<stmt>switch(%s){", $3); }
		switch_stmt
	'}' { $$ = 1; }
     | WHILE '('
		{ if( prag_tag == 1 )
			printf("<stmt>while("); }
	Expr ')'
		{ if( prag_tag == 1 )
			printf(")"); }
	loop_stmt	{ if( prag_tag == 1 )
			printf("</stmt>");
			$$ = 1; }
     |	DO
		{ if( prag_tag == 1 )
			printf("<stmt>do"); } 
	loop_stmt
	WHILE '('
		{ if( prag_tag == 1 )
			printf("while("); }
	Expr
	')' ';' { if( prag_tag == 1 )
			printf(");</stmt>"); $$ = 1; }
     |	FOR '('
		{ if( prag_tag == 1 )
			printf("<stmt>for("); }
	Expr ';' { if( prag_tag == 1 ) printf(";"); }
	Expr ';' { if( prag_tag == 1 ) printf(";"); }
	Expr ')' { if( prag_tag == 1 ) printf(")"); }
	loop_stmt { $$ = 1; }
     |	RETURN		{ if( prag_tag == 1 ) printf("<stmt>return"); }
	return_option ';' { $$ = $3; if( prag_tag == 1 )
					printf("</stmt>"); }
     |  ';' { $$ = 0; }
     ;
C_Stmt : Stmt
       | '{' { printf("<stmt>{"); } Cmp_Stmt '}' { printf("}</stmt>"); }
       ;
if_option : %prec "then"	{ if( prag_tag == 1 )
	  				printf("</stmt>"); }
	  | ELSE C_Stmt		{ if( prag_tag == 1 )
					printf("</stmt>"); }
	  ;
switch_stmt : 
	    | CASE iVal ':' Sw_Stmt switch_stmt
	    | DEFAULT ':' Sw_Stmt switch_stmt
	    ;
Sw_Stmt :
	| BREAK ';' { if( prag_tag == 1 ) printf("<stmt>break;</stmt>"); }
	| Stmt Sw_Stmt
	;
loop_stmt : L_Stmt
	  | '{' loop_C '}'
	  ;
loop_C : L_Stmt loop_C
       |
       ;
L_Stmt : BREAK ';'
       | CONTINUE ';'
       | Stmt
       ;
return_option :		{ $$ = 0;	}
	      | Expr	{ $$ = $1;	}
		;

Expr :     	
     	E  { Expression = $1;
		$$ = $1->intVal;
		if( prag_tag == 1 )
			PrintTag(Expression); }
	|
	ID arr_option
	'='
	Expr
	{	
		TreeNode* idNode = (TreeNode*)malloc(sizeof(TreeNode));
		idNode->left = NULL; idNode->right = $2;
		strcpy(idNode->value, $1);
		idNode->intVal = $4;		

		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = idNode; 
		temp->right = NULL; /*temp->right = $4;*/
		temp->value[0] = '=';
		temp->intVal = 1;
		
		Expression = temp;
		if( prag_tag == 1)
			PrintTag(Expression);

		$$ = 1;

		/*GetNode($1)->intVal = $4;*/
	}
	;
E :
	E OR E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '|';
		temp->value[1] = '|';
		temp->right = $3;
		temp->intVal = (temp->left->intVal || temp->right->intVal);
		$$ = temp;
	}
  	|
	E AND E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '&';
		temp->value[1] = '&';
		temp->right = $3;
		temp->intVal = (temp->left->intVal && temp->right->intVal);
		$$ = temp;
	}
  	|
	E BOR E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '|';
		temp->right = $3;
		temp->intVal = (temp->left->intVal | temp->right->intVal);
		$$ = temp;
	}
  	|
	E BAND E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '&';
		temp->right = $3;
		temp->intVal = (temp->left->intVal & temp->right->intVal);
		$$ = temp;
	}
  	|
  	E EQ E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '=';
		temp->value[1] = '=';
		temp->right = $3;
		temp->intVal = (temp->left->intVal == temp->right->intVal);
		$$ = temp;
	}
  	|
	E NQ E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '!';
		temp->value[1] = '=';
		temp->right = $3;
		temp->intVal = (temp->left->intVal != temp->right->intVal);
		$$ = temp;
	}
	|
	E GQ E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '<';
		temp->value[1] = '=';
		temp->right = $3;
		temp->intVal = (temp->left->intVal <= temp->right->intVal);
		$$ = temp;
	}
	|
	E LQ E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '>';
		temp->value[1] = '=';
		temp->right = $3;
		temp->intVal = (temp->left->intVal >= temp->right->intVal);
		$$ = temp;
	}
	|
	E GT E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '>';
		temp->right = $3;
		temp->intVal = (temp->left->intVal > temp->right->intVal);
		$$ = temp;
	}
	|
	E LT E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '<';
		temp->right = $3;
		temp->intVal = (temp->left->intVal < temp->right->intVal);
		$$ = temp;
	}
	|
	E '+' E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '+';
		temp->right = $3;
		temp->intVal = temp->left->intVal + temp->right->intVal;
		$$ = temp;
	}
	| 
	E '-' E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '-';
		temp->right = $3;
		temp->intVal = temp->left->intVal - temp->right->intVal;
		$$ = temp;
	}
     |   
	E '*' E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '*';
		temp->right = $3;
		temp->intVal = temp->left->intVal * temp->right->intVal;
		$$ = temp;
		} 
     | 	
	E '/' E
	{ if ($3 == 0)
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
	E '%' E
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = $1;
		temp->value[0] = '%';
		temp->right = $3;
		temp->intVal = temp->left->intVal % temp->right->intVal;
		$$ = temp;
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
	'!' E %prec NOT
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		temp->value[0] = '!';
		temp->right = NULL;
		temp->intVal = !($2->intVal);
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
		/*temp->intVal = GetValue($1);*/
		temp->intVal = 0;
		$$ = temp;
	}
	|
	ID '[' E ']' arr_option
	{
		TreeNode* per = (TreeNode*)malloc(sizeof(TreeNode));
		per->left = $3;
		per->value[0] = '[';
		per->right = $5;
		
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		strcpy(temp->value, $1);
		temp->right = per;
		/*temp->intVal = GetValue($1);*/
		temp->intVal = 0;
		$$ = temp;
	}
	|
	ID '(' para_call ')'
	{
		TreeNode* per = (TreeNode*)malloc(sizeof(TreeNode));
		per->left = $3;
		per->value[0] = '(';
		per->right = NULL;
		
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		strcpy(temp->value, $1);
		temp->right = per;
		/*temp->intVal = GetValue($1);*/
		temp->intVal = 0;
		$$ = temp;
	}
	| INC ID
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		strcpy(temp->value, "++");
		strcat(temp->value, $2);
		temp->right = NULL;
		/*temp->intVal = GetValue($2) + 1;*/
		temp->intVal = 1;
		$$ = temp;
	}
	| DEC ID
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		strcpy(temp->value, "--");
		strcat(temp->value, $2);
		temp->right = NULL;
		/*temp->intVal = GetValue($2) - 1;*/
		temp->intVal = -1;
		$$ = temp;
	}
	| ID INC
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		strcpy(temp->value, $1);
		strcat(temp->value, "++");
		temp->right = NULL;
		$$ = temp;
		/*temp->intVal = GetValue($1) + 1;*/
		temp->intVal = 1;		
	}
	| ID DEC
	{
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		strcpy(temp->value, $1);
		strcat(temp->value, "--");
		temp->right = NULL;
		$$ = temp;
		/*temp->intVal = GetValue($1) - 1;*/
		temp->intVal = -1;
	}
	;
arr_option : { $$ = NULL; }
		|	'[' E ']' arr_option
		{
			TreeNode* per = (TreeNode*)malloc(sizeof(TreeNode));
			per->left = $2;
			per->value[0] = '[';
			per->right = $4;
		
			$$ = per;
		}
    ;
para_call : { $$ = NULL; }
		| E //////////////////////////////////////////////////////////////////

Decl :	type
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
		/*Insert(type, $2, lineNo);*/
		/*IDENT = GetNode($2);*/
	}
	assign_option
	{
		/*IDENT->intVal = $4;*/
	}
	decl_option
	';'			{ if( prag_tag == 1 )
					printf(";</scalar_decl>");	}
	|
	CONST
	type
	ID
	'='
	{	type = $2;	
		if( prag_tag == 1 )
		{
			printf("<const_decl>");
			PrintType(type);
			printf("%s=", $3);
		}
	}
	Expr
	';'	{ if( prag_tag == 1 )
			printf("</const_decl>"); }
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
	arr_dem_option
	arr_assign_option
	arr_decl_option
	';'			{ printf(";</array_decl>");	}
      |
 	  type ID '(' parameter ')' ';'
	{
		type = $1;
		if( prag_parse == 1 )
			printf("Line %d - declare ", lineNo);
		if( prag_tag == 1 )
			printf("<func_decl>");	
		PrintType(type); printf("%s(", $2);
		PrintParameter(parameter); printf(");</func_decl>");
	}
	|
	type ID '(' parameter ')' '{'
	{
		type = $1;
		if( prag_parse == 1 )
			printf("Line %d - declare ", lineNo);
		if( prag_tag == 1 )
			printf("<func_def>");	
		PrintType(type); printf("%s(", $2);
		PrintParameter(parameter); printf("){");
	}
	Stmt '}'
				{ if( prag_tag == 1 )
				printf("}</func_def>"); }
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
			/*Insert(type, $3, lineNo);
			IDENT = GetNode($3);*/
		}
		assign_option
		{
			/*IDENT->intVal = $5;*/
		}
		decl_option	
	    ;
arr_dem_option :
	       | '[' iVal ']'	{ if( prag_tag == 1 )
					printf("[%d]", $2); }
		 arr_dem_option
	       ;
arr_decl_option : {;}
		|
		','
		ID '[' iVal ']'
		{
			if( prag_tag == 1)
				printf(",%s[%d]", $2, $4);
		}
		arr_dem_option
		arr_assign_option
		arr_decl_option
		;
parameter :	{ $$ = NULL; parameter = NULL; }
	  | type ID para_option
		{
			Parameter* temp = (Parameter*)malloc(sizeof(Parameter));
			temp->type = $1;
			strcpy(temp->name, $2);
			temp->next = $3;
			$$ = temp;
			parameter = temp;
		}
	  ;
para_option : {	$$ = NULL; }
	    | ',' type ID para_option
		{
			Parameter* temp = (Parameter*)malloc(sizeof(Parameter));
			temp->type = $2;
			strcpy(temp->name, $3);
			temp->next = $4;
			$$ = temp;
		}
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
	
	Table = (Node*)malloc(sizeof(Node));
	Table->next = NULL;

	IDENT = (Node*)malloc(sizeof(Node));

	Expression = (TreeNode*)malloc(sizeof(TreeNode));
	parameter = (Parameter*)malloc(sizeof(Parameter));

	yyparse();

}
void yyerror(char* msg)
{
	fprintf(stderr, "Error at Line %d", lineNo);
	exit(1);
}
