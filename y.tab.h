/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    RETURN = 259,
    STRUCT = 260,
    iVal = 261,
    INT = 262,
    DOUBLE = 263,
    FLOAT = 264,
    CHAR = 265,
    STRING = 266,
    fVal = 267,
    cVal = 268,
    sVal = 269,
    ID = 270,
    KEY = 271,
    OP = 272,
    PUNC = 273,
    NOT = 274,
    EQ = 275,
    NQ = 276,
    GQ = 277,
    LQ = 278,
    GT = 279,
    LT = 280,
    AND = 281,
    OR = 282,
    BAND = 283,
    BOR = 284,
    UMINUS = 285,
    INC = 286,
    DEC = 287
  };
#endif
/* Tokens.  */
#define VOID 258
#define RETURN 259
#define STRUCT 260
#define iVal 261
#define INT 262
#define DOUBLE 263
#define FLOAT 264
#define CHAR 265
#define STRING 266
#define fVal 267
#define cVal 268
#define sVal 269
#define ID 270
#define KEY 271
#define OP 272
#define PUNC 273
#define NOT 274
#define EQ 275
#define NQ 276
#define GQ 277
#define LQ 278
#define GT 279
#define LT 280
#define AND 281
#define OR 282
#define BAND 283
#define BOR 284
#define UMINUS 285
#define INC 286
#define DEC 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "parser.y" /* yacc.c:1909  */

	int intVal;
	double doubleVal;
	char charVal;
	char* stringVal;
	//struct symbol *sym;

#line 126 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
