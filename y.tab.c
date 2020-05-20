/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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


#line 89 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    IF = 285,
    ELSE = 286,
    SWITCH = 287,
    CASE = 288,
    DEFAULT = 289,
    UMINUS = 290,
    INC = 291,
    DEC = 292
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
#define IF 285
#define ELSE 286
#define SWITCH 287
#define CASE 288
#define DEFAULT 289
#define UMINUS 290
#define INC 291
#define DEC 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "parser.y" /* yacc.c:355  */

	int intVal;
	double doubleVal;
	char charVal;
	char* stringVal;

	struct _TreeNode* _node;
	//struct symbol *sym;

#line 213 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    45,    37,    36,    52,    35,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    43,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    57,    59,    66,    71,    74,    71,    76,
      76,    81,    83,    84,    86,    88,    91,    92,    93,    96,
     101,   125,   137,   149,   161,   176,   186,   196,   206,   219,
     236,   217,   244,   255,   242,   262,   271,   260,   276,   277,
     277,   285,   287,   290,   286,   297,   299,   298,   303,   305,
     308,   315,   304,   320,   324,   322,   329,   330,   331,   332
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "RETURN", "STRUCT", "iVal",
  "INT", "DOUBLE", "FLOAT", "CHAR", "STRING", "fVal", "cVal", "sVal", "ID",
  "KEY", "OP", "PUNC", "NOT", "EQ", "NQ", "GQ", "LQ", "GT", "LT", "AND",
  "OR", "BAND", "BOR", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "'-'",
  "'+'", "'*'", "'/'", "UMINUS", "INC", "DEC", "\"then\"", "';'", "'('",
  "')'", "'{'", "'}'", "':'", "'='", "'['", "']'", "','", "$accept",
  "Cmp_Stmt", "Stmt", "$@1", "$@2", "$@3", "C_Stmt", "if_option",
  "switch_stmt", "Expr", "E", "Decl", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", "assign_option", "$@10", "arr_assign_option", "$@11", "$@12",
  "arr_val_option", "$@13", "decl_option", "$@14", "$@15", "$@16",
  "arr_decl_option", "$@17", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    45,    43,    42,    47,   290,
     291,   292,   293,    59,    40,    41,   123,   125,    58,    61,
      91,    93,    44
};
# endif

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      29,   -72,   -72,   -72,   -72,   -72,   -39,   -26,   -23,    10,
     -72,    10,    28,    29,   -13,    46,   -72,    16,    10,   -72,
      19,   -72,   -72,    42,   -72,   -72,   -72,    10,    10,    10,
      10,   -35,    46,    11,     3,   -72,   -14,   -14,   -72,   -72,
     -72,   -72,   -16,     8,   -72,    81,    36,   -72,   -72,   -72,
      12,    45,     6,    11,    17,    -3,    18,    25,   -72,   -72,
     -72,    31,    29,   -72,    40,    70,    37,    47,    49,    43,
      78,   -72,    50,    -3,   -72,    48,    -3,   -72,   -72,    52,
      51,   -72,   -72,   -72,    -3,    18,    29,   -72,    84,    57,
     -16,    18,   -72,    54,    11,    55,   -72,   -72,   -72,   -72,
     -72,    96,    17,    56,    53,   -72,    11,    59,   -72,   -72,
     -72,    43,    56,    51,   -72,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    27,    56,    57,    59,    58,    28,     0,     0,     0,
      11,     0,     0,     2,     0,    19,     5,     0,     0,     6,
       0,    28,    25,     0,     1,     3,     4,     0,     0,     0,
       0,    29,    20,     0,     0,    26,    22,    21,    23,    24,
      35,    32,    38,     0,     9,     0,     0,    39,    30,     7,
       0,     0,     0,     0,    48,     0,    16,     0,    33,    40,
      49,     0,     2,    12,    14,     0,     0,     0,     0,    41,
       0,    31,     0,     0,     8,     0,     0,    10,    36,     0,
      53,    50,    13,    15,     0,    16,     0,    42,     0,     0,
      38,    16,    18,     0,     0,     0,    34,    51,    17,    37,
      43,     0,    48,    45,     0,    52,     0,     0,    54,    46,
      44,    41,    45,    53,    47,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -12,     0,   -72,   -72,   -72,   -65,   -72,   -71,   -31,
      38,   -72,   -72,   -72,   -72,   -72,   -72,   -72,    20,   -72,
      -4,   -72,   -72,    -1,   -72,     7,   -72,   -72,   -72,     1,
     -72,    67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    63,    33,    55,    50,    64,    74,    67,    14,
      15,    16,    42,    54,    46,    69,    45,    86,    48,    53,
      80,    94,   103,   107,   112,    61,    70,    90,   102,    89,
     111,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    25,    43,     1,     2,     3,     4,     5,    83,    40,
      18,    85,     6,    13,    92,    41,     1,     1,    19,    91,
      98,    20,    59,    29,    30,    21,     6,     7,    24,     8,
      26,    31,     9,    47,    34,     1,     2,     3,     4,     5,
      10,    11,    52,    62,     6,     9,     9,    22,    44,    23,
      72,    65,    66,    49,    11,    11,    32,    58,    56,     7,
      57,     8,    13,   100,     9,    36,    37,    38,    39,    60,
      68,    73,    10,    11,    71,   109,    75,    27,    28,    29,
      30,    27,    28,    29,    30,    76,    93,    35,     2,     3,
       4,     5,    79,    81,    77,    78,    84,    82,    87,    95,
      96,    99,   104,    88,   108,   101,   110,   113,   106,   105,
      97,   114,    51,     0,   115
};

static const yytype_int8 yycheck[] =
{
       0,    13,    33,     6,     7,     8,     9,    10,    73,    44,
      49,    76,    15,    13,    85,    50,     6,     6,    44,    84,
      91,    44,    53,    37,    38,    15,    15,    30,     0,    32,
      43,    15,    35,    49,    15,     6,     7,     8,     9,    10,
      43,    44,     6,    46,    15,    35,    35,     9,    45,    11,
      62,    33,    34,    45,    44,    44,    18,    51,    46,    30,
      15,    32,    62,    94,    35,    27,    28,    29,    30,    52,
      45,    31,    43,    44,    43,   106,     6,    35,    36,    37,
      38,    35,    36,    37,    38,    48,    86,    45,     7,     8,
       9,    10,    49,    15,    47,    46,    48,    47,    46,    15,
      43,    47,     6,    52,    51,    50,    47,   111,    52,   102,
      90,   112,    45,    -1,   113
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    15,    30,    32,    35,
      43,    44,    54,    55,    62,    63,    64,    84,    49,    44,
      44,    15,    63,    63,     0,    54,    43,    35,    36,    37,
      38,    15,    63,    56,    15,    45,    63,    63,    63,    63,
      44,    50,    65,    62,    45,    69,    67,    49,    71,    45,
      58,    84,     6,    72,    66,    57,    46,    15,    51,    62,
      52,    78,    46,    55,    59,    33,    34,    61,    45,    68,
      79,    43,    54,    31,    60,     6,    48,    47,    46,    49,
      73,    15,    47,    59,    48,    59,    70,    46,    52,    82,
      80,    59,    61,    55,    74,    15,    43,    71,    61,    47,
      62,    50,    81,    75,     6,    78,    52,    76,    51,    62,
      47,    83,    77,    73,    76,    82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    57,    55,    58,
      55,    55,    59,    59,    60,    60,    61,    61,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    65,
      66,    64,    67,    68,    64,    69,    70,    64,    71,    72,
      71,    73,    74,    75,    73,    76,    77,    76,    78,    79,
      80,    81,    78,    82,    83,    82,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     0,     0,     8,     0,
       8,     1,     1,     3,     0,     2,     0,     5,     4,     1,
       3,     3,     3,     3,     3,     2,     3,     1,     1,     0,
       0,     7,     0,     0,    10,     0,     0,    11,     0,     0,
       3,     0,     0,     0,     7,     0,     0,     4,     0,     0,
       0,     0,     7,     0,     0,     8,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 59 "parser.y" /* yacc.c:1646  */
    { 
     		if( prag_parse == 1 )
     			printf("Line %d - result : %d \n", lineNo, (yyvsp[-1].intVal));
		if( prag_tag == 1 )
			printf(";");
		(yyval.intVal) = (yyvsp[-1].intVal);
		}
#line 1395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "parser.y" /* yacc.c:1646  */
    {
		if( prag_parse == 1 )
			printf("\n"); 
		(yyval.intVal) = TRUE;
		}
#line 1405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 71 "parser.y" /* yacc.c:1646  */
    { if( prag_tag == 1 )
			printf("<stmt>if("); }
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 74 "parser.y" /* yacc.c:1646  */
    { if( prag_tag == 1)
			printf(")");}
#line 1419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = (yyvsp[-4].intVal); }
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 76 "parser.y" /* yacc.c:1646  */
    { if( prag_tag == 1)
			printf("<stmt>switch(%s)", (yyvsp[-1].stringVal)); }
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 80 "parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = 1; }
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 81 "parser.y" /* yacc.c:1646  */
    {}
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 86 "parser.y" /* yacc.c:1646  */
    { if( prag_tag == 1 )
	  				printf("</stmt>"); }
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "parser.y" /* yacc.c:1646  */
    { if( prag_tag == 1 )
					printf("</stmt>"); }
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 96 "parser.y" /* yacc.c:1646  */
    { Expression = (yyvsp[0]._node);
		(yyval.intVal) = (yyvsp[0]._node)->intVal;
		if( prag_tag == 1 )
			PrintTag(Expression); }
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 104 "parser.y" /* yacc.c:1646  */
    {	
		TreeNode* idNode = (TreeNode*)malloc(sizeof(TreeNode));
		idNode->left = NULL; idNode->right = NULL;
		strcpy(idNode->value, (yyvsp[-2].stringVal));
		idNode->intVal = (yyvsp[0]._node)->intVal;		

		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = idNode; temp->right = (yyvsp[0]._node);
		temp->value[0] = '=';
		temp->intVal = 1;
		
		Expression = temp;
		if( prag_tag == 1)
			PrintTag(Expression);

		(yyval.intVal) = 1;

		GetNode((yyvsp[-2].stringVal))->intVal = (yyvsp[0]._node)->intVal;
	}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 128 "parser.y" /* yacc.c:1646  */
    {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = (yyvsp[-2]._node);
		temp->value[0] = '+';
		temp->right = (yyvsp[0]._node);
		temp->intVal = temp->left->intVal + temp->right->intVal;
		(yyval._node) = temp;
	}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "parser.y" /* yacc.c:1646  */
    {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = (yyvsp[-2]._node);
		temp->value[0] = '-';
		temp->right = (yyvsp[0]._node);
		temp->intVal = temp->left->intVal - temp->right->intVal;
		(yyval._node) = temp;
	}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 152 "parser.y" /* yacc.c:1646  */
    {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = (yyvsp[-2]._node);
		temp->value[0] = '*';
		temp->right = (yyvsp[0]._node);
		temp->intVal = temp->left->intVal * temp->right->intVal;
		(yyval._node) = temp;
		}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 163 "parser.y" /* yacc.c:1646  */
    { if ((yyvsp[0]._node) == 0)
		yyerror("zero division error");
	      else
		  {
			TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
			temp->left = (yyvsp[-2]._node);
			temp->value[0] = '/';
			temp->right = (yyvsp[0]._node);
			temp->intVal = temp->left->intVal / temp->right->intVal;
			(yyval._node) = temp;
		  }
		}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 177 "parser.y" /* yacc.c:1646  */
    {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		temp->value[0] = '\0';
		temp->right = NULL;
		temp->intVal = -((yyvsp[0]._node)->intVal);
		(yyval._node) = temp;
	}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 187 "parser.y" /* yacc.c:1646  */
    {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = (yyvsp[-1]._node);
		temp->value[0] = '(';
		temp->right = NULL;
		temp->intVal = (yyvsp[-1]._node)->intVal;
		(yyval._node) = temp;
	}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 197 "parser.y" /* yacc.c:1646  */
    {	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		temp->value[0] = '\0';
		temp->right = NULL;
		temp->intVal = (yyvsp[0].intVal);
		(yyval._node) = temp;
	}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 207 "parser.y" /* yacc.c:1646  */
    { 
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->left = NULL;
		strcpy(temp->value, (yyvsp[0].stringVal));
		temp->right = NULL;
		temp->intVal = GetValue((yyvsp[0].stringVal));
		(yyval._node) = temp;
	}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 219 "parser.y" /* yacc.c:1646  */
    {
		type = (yyvsp[-1].intVal);
		if( prag_parse == 1 )
			printf("Line %d - declare ", lineNo);
		if( prag_tag == 1 )
		{
			printf("<scalar_decl>");
			PrintType(type);
		}
		if( prag_parse == 1 )
			printf("%s ", (yyvsp[0].stringVal));
		if( prag_tag == 1 )
			printf("%s", (yyvsp[0].stringVal));
		Insert(type, (yyvsp[0].stringVal), lineNo);
		IDENT = GetNode((yyvsp[0].stringVal));
	}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 236 "parser.y" /* yacc.c:1646  */
    {
		IDENT->intVal = (yyvsp[0].intVal);
	}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 240 "parser.y" /* yacc.c:1646  */
    { printf(";</scalar_decl>");	}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 244 "parser.y" /* yacc.c:1646  */
    {
	type = (yyvsp[-2].intVal);
		if( prag_parse == 1 )
			printf("Line %d - declare ", lineNo);
		if( prag_tag == 1 )
		{
			printf("<arr_decl>");
			PrintType(type);
		}
	}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 255 "parser.y" /* yacc.c:1646  */
    { printf("%s[%d]", (yyvsp[-4].stringVal), (yyvsp[-1].intVal)); }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 258 "parser.y" /* yacc.c:1646  */
    { printf(";</array_decl>");	}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 262 "parser.y" /* yacc.c:1646  */
    {
	  type = (yyvsp[-2].intVal);
		if( prag_parse == 1 )
			printf("Line %d - declare ", lineNo);
		if( prag_tag == 1 )
			printf("<function_decl>");	
		}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 271 "parser.y" /* yacc.c:1646  */
    { PrintType(type); printf("%s(", (yyvsp[-6].stringVal));
	  PrintType((yyvsp[-3].intVal)); printf("%s){", (yyvsp[-2].stringVal)); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 274 "parser.y" /* yacc.c:1646  */
    { printf("}</function_decl>"); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = 0; }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 277 "parser.y" /* yacc.c:1646  */
    { 
			if( prag_parse == 1 )
				printf("assign ");
			if( prag_tag == 1 )
				printf("="); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = (yyvsp[0].intVal); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 285 "parser.y" /* yacc.c:1646  */
    {;}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 287 "parser.y" /* yacc.c:1646  */
    { if( prag_tag == 1 )
				printf("={"); }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 290 "parser.y" /* yacc.c:1646  */
    { if( prag_tag == 1 )
				printf("<Expr>%d</Expr>", (yyvsp[0].intVal)); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 294 "parser.y" /* yacc.c:1646  */
    { if( prag_tag == 1 )
				printf("}"); }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 297 "parser.y" /* yacc.c:1646  */
    {;}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 299 "parser.y" /* yacc.c:1646  */
    { if( prag_tag == 1 )
		 		printf(",<Expr>%d</Expr>", (yyvsp[0].intVal)); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 303 "parser.y" /* yacc.c:1646  */
    {;}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 305 "parser.y" /* yacc.c:1646  */
    { if( prag_parse == 1 ) printf(", "); 
		  if( prag_tag == 1) printf(",");	}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 308 "parser.y" /* yacc.c:1646  */
    {
			if( prag_tag == 1 )
				printf("%s", (yyvsp[0].stringVal));
			Insert(type, (yyvsp[0].stringVal), lineNo);
			IDENT = GetNode((yyvsp[0].stringVal));
		}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 315 "parser.y" /* yacc.c:1646  */
    {
			IDENT->intVal = (yyvsp[0].intVal);
		}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 320 "parser.y" /* yacc.c:1646  */
    {;}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 324 "parser.y" /* yacc.c:1646  */
    {
		}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 329 "parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = INT_TYPE;	}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 330 "parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = DOUBLE_TYPE; 	}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 331 "parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = CHAR_TYPE;	}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 332 "parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = FLOAT_TYPE;	}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1820 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 335 "parser.y" /* yacc.c:1906  */


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
