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


/* Substitute the variable and function names.  */
#define yyparse         cool_yyparse
#define yylex           cool_yylex
#define yyerror         cool_yyerror
#define yydebug         cool_yydebug
#define yynerrs         cool_yynerrs

#define yylval          cool_yylval
#define yychar          cool_yychar
#define yylloc          cool_yylloc

/* Copy the first part of user declarations.  */
#line 6 "cool.y" /* yacc.c:339  */

  #include <iostream>
  #include "cool-tree.h"
  #include "stringtab.h"
  #include "utilities.h"
  
  extern char *curr_filename;
  
  
  /* Locations */
  #define YYLTYPE int              /* the type of locations */
  #define cool_yylloc curr_lineno  /* use the curr_lineno from the lexer
  for the location of tokens */
    
    extern int node_lineno;          /* set before constructing a tree node
    to whatever you want the line number
    for the tree node to be */
      
      
      #define YYLLOC_DEFAULT(Current, Rhs, N)         \
      Current = Rhs[1];                             \
      node_lineno = Current;
    
    
    #define SET_NODELOC(Current)  \
    node_lineno = Current;
    
    /* IMPORTANT NOTE ON LINE NUMBERS
    *********************************
    * The above definitions and macros cause every terminal in your grammar to 
    * have the line number supplied by the lexer. The only task you have to
    * implement for line numbers to work correctly, is to use SET_NODELOC()
    * before constructing any constructs from non-terminals in your grammar.
    * Example: Consider you are matching on the following very restrictive 
    * (fictional) construct that matches a plus between two integer constants. 
    * (SUCH A RULE SHOULD NOT BE  PART OF YOUR PARSER):
    
    plus_consts	: INT_CONST '+' INT_CONST 
    
    * where INT_CONST is a terminal for an integer constant. Now, a correct
    * action for this rule that attaches the correct line number to plus_const
    * would look like the following:
    
    plus_consts	: INT_CONST '+' INT_CONST 
    {
      // Set the line number of the current non-terminal:
      // ***********************************************
      // You can access the line numbers of the i'th item with @i, just
      // like you acess the value of the i'th exporession with $i.
      //
      // Here, we choose the line number of the last INT_CONST (@3) as the
      // line number of the resulting expression (@$). You are free to pick
      // any reasonable line as the line number of non-terminals. If you 
      // omit the statement @$=..., bison has default rules for deciding which 
      // line number to use. Check the manual for details if you are interested.
      @$ = @3;
      
      
      // Observe that we call SET_NODELOC(@3); this will set the global variable
      // node_lineno to @3. Since the constructor call "plus" uses the value of 
      // this global, the plus node will now have the correct line number.
      SET_NODELOC(@3);
      
      // construct the result node:
      $$ = plus(int_const($1), int_const($3));
    }
    
    */
    
    
    
    void yyerror(char *s);        /*  defined below; called for each parse error */
    extern int yylex();           /*  the entry point to the lexer  */
    
    /************************************************************************/
    /*                DONT CHANGE ANYTHING IN THIS SECTION                  */
    
    Program ast_root;	      /* the result of the parse  */
    Classes parse_results;        /* for use in semantic analysis */
    int omerrs = 0;               /* number of errors in lexing and parsing */
    

#line 158 "cool.tab.c" /* yacc.c:339  */

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
   by #include "cool.tab.h".  */
#ifndef YY_COOL_YY_COOL_TAB_H_INCLUDED
# define YY_COOL_YY_COOL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int cool_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    ELSE = 259,
    FI = 260,
    IF = 261,
    IN = 262,
    INHERITS = 263,
    LET = 264,
    LOOP = 265,
    POOL = 266,
    THEN = 267,
    WHILE = 268,
    CASE = 269,
    ESAC = 270,
    OF = 271,
    DARROW = 272,
    NEW = 273,
    ISVOID = 274,
    STR_CONST = 275,
    INT_CONST = 276,
    BOOL_CONST = 277,
    TYPEID = 278,
    OBJECTID = 279,
    ASSIGN = 280,
    NOT = 281,
    LE = 282,
    ERROR = 283
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
#define IN 262
#define INHERITS 263
#define LET 264
#define LOOP 265
#define POOL 266
#define THEN 267
#define WHILE 268
#define CASE 269
#define ESAC 270
#define OF 271
#define DARROW 272
#define NEW 273
#define ISVOID 274
#define STR_CONST 275
#define INT_CONST 276
#define BOOL_CONST 277
#define TYPEID 278
#define OBJECTID 279
#define ASSIGN 280
#define NOT 281
#define LE 282
#define ERROR 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 89 "cool.y" /* yacc.c:355  */

      Boolean boolean;
      Symbol symbol;
      Program program;
      Class_ class_;
      Classes classes;
      Feature feature;
      Features features;
      Formal formal;
      Formals formals;
      Case case_;
      Cases cases;
      Expression expression;
      Expressions expressions;
      char *error_msg;
    

#line 272 "cool.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE cool_yylval;
extern YYLTYPE cool_yylloc;
int cool_yyparse (void);

#endif /* !YY_COOL_YY_COOL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 303 "cool.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   492

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

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
      41,    42,    33,    31,    44,    32,    37,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    40,
      29,    30,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,    35,     2,     2,     2,
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
      25,    26,    27,    28,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   175,   180,   188,   193,   198,   202,   205,
     210,   218,   223,   228,   232,   240,   245,   250,   258,   261,
     267,   275,   283,   288,   293,   298,   303,   308,   313,   318,
     323,   328,   333,   338,   343,   348,   353,   358,   362,   367,
     372,   377,   382,   387,   392,   397,   405,   410,   415,   419,
     426,   431,   439,   447,   452,   460,   465,   470,   474,   477,
     485,   490,   495,   500,   505,   510,   515,   520,   525
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ELSE", "FI", "IF", "IN",
  "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", "OF",
  "DARROW", "NEW", "ISVOID", "STR_CONST", "INT_CONST", "BOOL_CONST",
  "TYPEID", "OBJECTID", "ASSIGN", "NOT", "LE", "ERROR", "'<'", "'='",
  "'+'", "'-'", "'*'", "'/'", "'~'", "'@'", "'.'", "'{'", "'}'", "';'",
  "'('", "')'", "':'", "','", "$accept", "program", "class_list", "class",
  "features", "feature", "method_declaration", "attribute_declaration",
  "formals", "formal", "expression", "block_expressions",
  "block_expression", "branches", "branch", "arguments_expressions",
  "let_expression", "let_assign", "dispatch_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   284,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    60,
      61,    43,    45,    42,    47,   126,    64,    46,   123,   125,
      59,    40,    41,    58,    44
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -9

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-9)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,   -31,   -10,    47,    78,  -126,  -126,    -5,  -126,  -126,
      30,     0,    17,    26,    -7,    11,  -126,    27,    28,     0,
    -126,    56,    60,    44,  -126,  -126,  -126,    24,    55,   -14,
    -126,    65,  -126,    54,    76,    57,    56,   216,  -126,  -126,
      80,  -126,   246,     3,   246,   246,    82,   246,  -126,  -126,
    -126,   -19,   246,   246,    51,   246,   444,  -126,    69,    51,
     310,    66,    68,  -126,   284,   322,  -126,     1,   246,    95,
     444,     1,    83,   395,   185,  -126,   381,   246,   246,   246,
     246,   246,   246,   246,    97,    94,   246,   409,   246,  -126,
      99,   246,   100,   444,  -126,   333,  -126,  -126,  -126,  -126,
    -126,  -126,   455,   455,   455,    25,    25,     1,     1,    88,
      85,   433,   259,   102,   297,    86,     5,  -126,  -126,   246,
      32,   104,   125,  -126,   246,   246,    12,  -126,   109,  -126,
    -126,   444,  -126,   246,   101,  -126,   349,   270,   444,   246,
       3,   118,   444,   155,  -126,    49,  -126,   444,  -126,   246,
    -126,   365,  -126,   421,  -126,    53,  -126,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     7,     0,     1,     4,
       0,     0,     0,     0,     0,     0,     9,     0,     0,     0,
      13,    18,     0,     0,    10,    11,    12,     0,     0,     0,
      19,    15,     5,     0,     0,     0,     0,     0,     6,    21,
       0,    20,     0,     0,     0,     0,     0,     0,    43,    42,
      44,    45,     0,     0,     0,     0,    17,    23,     0,     0,
       0,     0,     0,    24,     0,     0,    30,    31,     0,     0,
      37,    36,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,    22,    60,     0,    48,    16,    49,    28,
      47,    41,    38,    39,    40,    32,    33,    34,    35,     0,
       0,     0,    25,    58,     0,     0,     0,    50,    61,     0,
       0,     0,     0,    14,     0,     0,     0,    27,     0,    29,
      51,    53,    62,     0,     0,    63,     0,     0,    59,     0,
       0,     0,    54,     0,    64,     0,    26,    55,    56,     0,
      66,     0,    65,     0,    67,     0,    52,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,   136,   122,   -13,  -126,  -126,  -126,   112,
     -37,  -126,    79,  -126,    34,  -125,    14,  -126,  -126
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    15,    16,    17,    18,    29,    30,
      87,    74,    75,   116,   117,   120,    63,   126,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    13,    24,    10,    61,    60,    68,    64,    65,     6,
      67,   145,    13,     7,    24,    70,    71,    73,    76,   139,
     129,     1,    69,     2,    14,    13,   155,    62,    35,   115,
      36,    93,    95,    11,    21,    14,    22,    84,    85,    -8,
     102,   103,   104,   105,   106,   107,   108,     8,    14,   111,
      23,   112,    72,    12,   114,    19,   140,    42,    82,    83,
      43,    84,    85,    33,    44,    45,    20,    25,    26,    46,
      47,    48,    49,    50,   132,    51,   133,    52,    -2,     1,
      28,     2,   131,    31,    32,   136,    53,   137,   138,    59,
      37,   152,    55,   133,    38,   157,   142,   133,    34,    39,
      40,    42,   147,    58,    43,    66,   151,    86,    44,    45,
      89,    90,   153,    46,    47,    48,    49,    50,   110,    51,
     109,    52,   113,    96,   115,   121,   122,   125,   134,   128,
      53,    42,   141,    59,    43,   149,    55,    94,    44,    45,
       9,    27,   143,    46,    47,    48,    49,    50,    41,    51,
     130,    52,     0,   100,   148,     0,     0,     0,     0,     0,
      53,    42,     0,    59,    43,     0,    55,   135,    44,    45,
       0,     0,     0,    46,    47,    48,    49,    50,     0,    51,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    42,     0,    59,    43,     0,    55,   150,    44,    45,
       0,     0,     0,    46,    47,    48,    49,    50,     0,    51,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,    42,    59,    99,    43,    55,     0,     0,    44,
      45,     0,     0,     0,    46,    47,    48,    49,    50,     0,
      51,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    42,     0,    54,    43,     0,    55,     0,    44,
      45,     0,     0,   124,    46,    47,    48,    49,    50,     0,
      51,     0,    52,     0,     0,   146,     0,     0,     0,     0,
       0,    53,     0,     0,    59,     0,    77,    55,    78,    79,
      80,    81,    82,    83,    91,    84,    85,    77,     0,    78,
      79,    80,    81,    82,    83,     0,    84,    85,   127,     0,
       0,    77,     0,    78,    79,    80,    81,    82,    83,     0,
      84,    85,    88,     0,    77,     0,    78,    79,    80,    81,
      82,    83,     0,    84,    85,     0,     0,    77,    92,    78,
      79,    80,    81,    82,    83,     0,    84,    85,     0,    77,
       0,    78,    79,    80,    81,    82,    83,     0,    84,    85,
      77,     0,    78,    79,    80,    81,    82,    83,     0,    84,
      85,     0,     0,     0,     0,   118,    77,   119,    78,    79,
      80,    81,    82,    83,     0,    84,    85,     0,     0,     0,
       0,   144,    77,   119,    78,    79,    80,    81,    82,    83,
       0,    84,    85,     0,     0,     0,     0,   154,    77,   119,
      78,    79,    80,    81,    82,    83,     0,    84,    85,     0,
       0,     0,    77,   101,    78,    79,    80,    81,    82,    83,
       0,    84,    85,     0,    97,    98,    77,     0,    78,    79,
      80,    81,    82,    83,     0,    84,    85,     0,    77,    98,
      78,    79,    80,    81,    82,    83,     0,    84,    85,     0,
      77,   156,    78,    79,    80,    81,    82,    83,     0,    84,
      85,    77,   123,    78,    79,    80,    81,    82,    83,     0,
      84,    85,    -9,     0,    -9,    -9,    80,    81,    82,    83,
       0,    84,    85
};

static const yytype_int16 yycheck[] =
{
      37,     1,    15,     8,     1,    42,    25,    44,    45,    40,
      47,   136,     1,    23,    27,    52,    53,    54,    55,     7,
      15,     1,    41,     3,    24,     1,   151,    24,    42,    24,
      44,    68,    69,    38,    41,    24,    43,    36,    37,    39,
      77,    78,    79,    80,    81,    82,    83,     0,    24,    86,
      39,    88,     1,    23,    91,    38,    44,     6,    33,    34,
       9,    36,    37,    39,    13,    14,    40,    40,    40,    18,
      19,    20,    21,    22,    42,    24,    44,    26,     0,     1,
      24,     3,   119,    23,    40,   122,    35,   124,   125,    38,
      25,    42,    41,    44,    40,    42,   133,    44,    43,    23,
      43,     6,   139,    23,     9,    23,   143,    38,    13,    14,
      44,    43,   149,    18,    19,    20,    21,    22,    24,    24,
      23,    26,    23,    40,    24,    37,    41,    25,    24,    43,
      35,     6,    23,    38,     9,    17,    41,    42,    13,    14,
       4,    19,    41,    18,    19,    20,    21,    22,    36,    24,
     116,    26,    -1,    74,   140,    -1,    -1,    -1,    -1,    -1,
      35,     6,    -1,    38,     9,    -1,    41,    42,    13,    14,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,     6,    -1,    38,     9,    -1,    41,    42,    13,    14,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,     6,    38,    39,     9,    41,    -1,    -1,    13,
      14,    -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,     6,    -1,    38,     9,    -1,    41,    -1,    13,
      14,    -1,    -1,     4,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    38,    -1,    27,    41,    29,    30,
      31,    32,    33,    34,    10,    36,    37,    27,    -1,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    11,    -1,
      -1,    27,    -1,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    12,    -1,    27,    -1,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    -1,    -1,    27,    16,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    -1,    27,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    -1,    -1,    -1,    -1,    42,    27,    44,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    -1,    -1,    -1,
      -1,    42,    27,    44,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    -1,    -1,    -1,    -1,    42,    27,    44,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    -1,
      -1,    -1,    27,    42,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    -1,    39,    40,    27,    -1,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    -1,    27,    40,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    -1,
      27,    40,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    27,    39,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    27,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    46,    47,    48,    40,    23,     0,    48,
       8,    38,    23,     1,    24,    49,    50,    51,    52,    38,
      40,    41,    43,    39,    50,    40,    40,    49,    24,    53,
      54,    23,    40,    39,    43,    42,    44,    25,    40,    23,
      43,    54,     6,     9,    13,    14,    18,    19,    20,    21,
      22,    24,    26,    35,    38,    41,    55,    63,    23,    38,
      55,     1,    24,    61,    55,    55,    23,    55,    25,    41,
      55,    55,     1,    55,    56,    57,    55,    27,    29,    30,
      31,    32,    33,    34,    36,    37,    38,    55,    12,    44,
      43,    10,    16,    55,    42,    55,    40,    39,    40,    39,
      57,    42,    55,    55,    55,    55,    55,    55,    55,    23,
      24,    55,    55,    23,    55,    24,    58,    59,    42,    44,
      60,    37,    41,    39,     4,    25,    62,    11,    43,    15,
      59,    55,    42,    44,    24,    42,    55,    55,    55,     7,
      44,    23,    55,    41,    42,    60,     5,    55,    61,    17,
      42,    55,    42,    55,    42,    60,    40,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      49,    50,    50,    50,    51,    52,    52,    52,    53,    53,
      53,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    57,
      58,    58,    59,    60,    60,    61,    61,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     8,     2,     0,     1,
       2,     2,     2,     2,     9,     3,     7,     5,     0,     1,
       3,     3,     3,     1,     2,     4,     7,     5,     3,     5,
       2,     2,     3,     3,     3,     3,     2,     2,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     2,     6,     2,     3,     6,     6,     2,     0,     2,
       3,     4,     5,     5,     6,     7,     7,     8,     9
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 168 "cool.y" /* yacc.c:1646  */
    { 
              (yyloc) = (yylsp[0]); 
              ast_root = program((yyvsp[0].classes)); 
            }
#line 1644 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 176 "cool.y" /* yacc.c:1646  */
    { 
                  (yyloc) = (yylsp[0]); 
                  (yyval.classes) = single_Classes((yyvsp[0].class_));
                }
#line 1653 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 181 "cool.y" /* yacc.c:1646  */
    { 
                  (yyloc) = (yylsp[0]); 
                  (yyval.classes) = append_Classes((yyvsp[-1].classes),single_Classes((yyvsp[0].class_))); 
                }
#line 1662 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 189 "cool.y" /* yacc.c:1646  */
    {
            (yyloc) = (yylsp[0]);
            (yyval.class_) = class_((yyvsp[-4].symbol),idtable.add_string("Object"),(yyvsp[-2].features), stringtable.add_string(curr_filename)); 
          }
#line 1671 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 194 "cool.y" /* yacc.c:1646  */
    { 
              (yyloc) = (yylsp[0]);
              (yyval.class_) = class_((yyvsp[-6].symbol),(yyvsp[-4].symbol),(yyvsp[-2].features),stringtable.add_string(curr_filename)); 
            }
#line 1680 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 198 "cool.y" /* yacc.c:1646  */
    {  }
#line 1686 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 202 "cool.y" /* yacc.c:1646  */
    {
                (yyval.features) = nil_Features();
              }
#line 1694 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 206 "cool.y" /* yacc.c:1646  */
    {
                (yyloc) = (yylsp[0]); 
                (yyval.features) = single_Features((yyvsp[0].feature));
              }
#line 1703 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 211 "cool.y" /* yacc.c:1646  */
    {
                (yyloc) = (yylsp[0]); 
                (yyval.features) = append_Features((yyvsp[-1].features), single_Features((yyvsp[0].feature)));
              }
#line 1712 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 219 "cool.y" /* yacc.c:1646  */
    {
                (yyloc) = (yylsp[0]);
                (yyval.feature) = (yyvsp[-1].feature);
            }
#line 1721 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 224 "cool.y" /* yacc.c:1646  */
    {
              (yyloc) = (yylsp[0]);
              (yyval.feature) = (yyvsp[-1].feature);
            }
#line 1730 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 228 "cool.y" /* yacc.c:1646  */
    {  }
#line 1736 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 233 "cool.y" /* yacc.c:1646  */
    {
                          (yyloc) = (yylsp[0]);
                          (yyval.feature) = method((yyvsp[-8].symbol), (yyvsp[-6].formals), (yyvsp[-3].symbol), (yyvsp[-1].expression));
                        }
#line 1745 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 241 "cool.y" /* yacc.c:1646  */
    {
                            (yyloc) = (yylsp[0]);
                            (yyval.feature) = attr((yyvsp[-2].symbol), (yyvsp[0].symbol), no_expr());
                          }
#line 1754 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 246 "cool.y" /* yacc.c:1646  */
    {
                            (yyloc) = (yylsp[0]);
                            (yyval.feature) = attr((yyvsp[-6].symbol), (yyvsp[-4].symbol), (yyvsp[-1].expression));
                          }
#line 1763 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 251 "cool.y" /* yacc.c:1646  */
    {
                            (yyloc) = (yylsp[0]);
                            (yyval.feature) = attr((yyvsp[-4].symbol), (yyvsp[-2].symbol), (yyvsp[0].expression));
                          }
#line 1772 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 258 "cool.y" /* yacc.c:1646  */
    {
              (yyval.formals) = nil_Formals();
            }
#line 1780 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 262 "cool.y" /* yacc.c:1646  */
    {
              (yyloc) = (yylsp[0]);
              (yyval.formals) = single_Formals((yyvsp[0].formal));
            }
#line 1789 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 268 "cool.y" /* yacc.c:1646  */
    {
              (yyloc) = (yylsp[-1]); 
              (yyval.formals) = append_Formals((yyvsp[-2].formals),single_Formals((yyvsp[0].formal))); 
            }
#line 1798 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 276 "cool.y" /* yacc.c:1646  */
    {
              (yyloc) = (yylsp[0]);
              (yyval.formal) = formal((yyvsp[-2].symbol), (yyvsp[0].symbol));
            }
#line 1807 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 284 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = assign((yyvsp[-2].symbol), (yyvsp[0].expression));
                }
#line 1816 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 289 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = (yyvsp[0].expression);
                }
#line 1825 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 294 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = (yyvsp[0].expression);
                }
#line 1834 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 299 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = cond((yyvsp[-2].expression),(yyvsp[0].expression), no_expr());
                }
#line 1843 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 304 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[-3]);
                  (yyval.expression) = cond((yyvsp[-5].expression),(yyvsp[-3].expression),(yyvsp[-1].expression));
                }
#line 1852 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 309 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = loop((yyvsp[-3].expression), (yyvsp[-1].expression));
                }
#line 1861 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 314 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[-1]);
                  (yyval.expression) = block((yyvsp[-1].expressions));
                }
#line 1870 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 319 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = typcase((yyvsp[-3].expression), (yyvsp[-1].cases));
                }
#line 1879 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 324 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = new_((yyvsp[0].symbol));
                }
#line 1888 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 329 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = isvoid((yyvsp[0].expression));
                }
#line 1897 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 334 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = plus((yyvsp[-2].expression), (yyvsp[0].expression));
                }
#line 1906 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 339 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = sub((yyvsp[-2].expression), (yyvsp[0].expression));
                }
#line 1915 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 344 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = mul((yyvsp[-2].expression), (yyvsp[0].expression));
                }
#line 1924 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 349 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = divide((yyvsp[-2].expression), (yyvsp[0].expression));
                }
#line 1933 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 354 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = neg((yyvsp[0].expression));
                }
#line 1942 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 358 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = comp((yyvsp[0].expression));
                }
#line 1951 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 363 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = leq((yyvsp[-2].expression), (yyvsp[0].expression));
                }
#line 1960 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 368 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = lt((yyvsp[-2].expression), (yyvsp[0].expression));
                }
#line 1969 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 373 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = eq((yyvsp[-2].expression), (yyvsp[0].expression));
                }
#line 1978 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 378 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[-1]);
                  (yyval.expression) = (yyvsp[-1].expression);
                }
#line 1987 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 383 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = int_const((yyvsp[0].symbol));
                }
#line 1996 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 388 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = string_const((yyvsp[0].symbol));
                }
#line 2005 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 393 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = bool_const((yyvsp[0].boolean)); 
                }
#line 2014 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 398 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = object((yyvsp[0].symbol)); 
                }
#line 2023 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 406 "cool.y" /* yacc.c:1646  */
    {
                        (yyloc) = (yylsp[0]);
                        (yyval.expressions) = single_Expressions((yyvsp[0].expression));
                      }
#line 2032 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 411 "cool.y" /* yacc.c:1646  */
    {
                        (yyloc) = (yylsp[0]);
                        (yyval.expressions) = append_Expressions((yyvsp[-1].expressions),single_Expressions((yyvsp[0].expression)));
                      }
#line 2041 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 415 "cool.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2047 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 420 "cool.y" /* yacc.c:1646  */
    {
                        (yyval.expression) = (yyvsp[-1].expression);
                      }
#line 2055 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 427 "cool.y" /* yacc.c:1646  */
    {
                (yyloc) = (yylsp[0]);
                (yyval.cases) = single_Cases((yyvsp[0].case_));
              }
#line 2064 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 432 "cool.y" /* yacc.c:1646  */
    {
                (yyloc) = (yylsp[0]);
                (yyval.cases) = append_Cases((yyvsp[-1].cases), single_Cases((yyvsp[0].case_)));
              }
#line 2073 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 440 "cool.y" /* yacc.c:1646  */
    {
              (yyloc) = (yylsp[0]);
              (yyval.case_) = branch((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression));
            }
#line 2082 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 448 "cool.y" /* yacc.c:1646  */
    {
                            (yyloc) = (yylsp[-1]);
                            (yyval.expressions) = single_Expressions((yyvsp[0].expression));
                          }
#line 2091 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 453 "cool.y" /* yacc.c:1646  */
    {
                            (yyloc) = (yylsp[0]);
                            (yyval.expressions) = append_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[0].expression)));
                          }
#line 2100 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 461 "cool.y" /* yacc.c:1646  */
    {
                      (yyloc) = (yylsp[0]);
                      (yyval.expression) = let((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2109 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 466 "cool.y" /* yacc.c:1646  */
    {      
                      (yyloc) = (yylsp[0]);
                      (yyval.expression) = let((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-2].expression), (yyvsp[0].expression));
                    }
#line 2118 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 470 "cool.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2124 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 474 "cool.y" /* yacc.c:1646  */
    {
                  (yyval.expression) = no_expr();
                }
#line 2132 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 478 "cool.y" /* yacc.c:1646  */
    {
                  (yyloc) = (yylsp[0]);
                  (yyval.expression) = (yyvsp[0].expression);
                }
#line 2141 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 486 "cool.y" /* yacc.c:1646  */
    {
                          (yyloc) = (yylsp[0]);
                          (yyval.expression) = dispatch(object(idtable.add_string("self")), (yyvsp[-2].symbol), nil_Expressions());
                        }
#line 2150 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 491 "cool.y" /* yacc.c:1646  */
    {
                          (yyloc) = (yylsp[-1]);
                          (yyval.expression) = dispatch(object(idtable.add_string("self")), (yyvsp[-3].symbol), single_Expressions((yyvsp[-1].expression)));
                        }
#line 2159 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 496 "cool.y" /* yacc.c:1646  */
    {
                          (yyloc) = (yylsp[-2]);
                          (yyval.expression) = dispatch(object(idtable.add_string("self")), (yyvsp[-4].symbol), append_Expressions(single_Expressions((yyvsp[-2].expression)), (yyvsp[-1].expressions)));
                        }
#line 2168 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 501 "cool.y" /* yacc.c:1646  */
    { 
                          (yyloc) = (yylsp[0]);
                          (yyval.expression) = dispatch((yyvsp[-4].expression), (yyvsp[-2].symbol), nil_Expressions());
                        }
#line 2177 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 506 "cool.y" /* yacc.c:1646  */
    {
                          (yyloc) = (yylsp[0]);
                          (yyval.expression) = dispatch((yyvsp[-5].expression), (yyvsp[-3].symbol), single_Expressions((yyvsp[-1].expression)));
                        }
#line 2186 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 511 "cool.y" /* yacc.c:1646  */
    {
                          (yyloc) = (yylsp[0]);
                          (yyval.expression) = dispatch((yyvsp[-6].expression), (yyvsp[-4].symbol), append_Expressions(single_Expressions((yyvsp[-2].expression)), (yyvsp[-1].expressions)));
                        }
#line 2195 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 516 "cool.y" /* yacc.c:1646  */
    {
                          (yyloc) = (yylsp[0]);
                          (yyval.expression) = static_dispatch((yyvsp[-6].expression), (yyvsp[-4].symbol), (yyvsp[-2].symbol), nil_Expressions());
                        }
#line 2204 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 521 "cool.y" /* yacc.c:1646  */
    {
                          (yyloc) = (yylsp[0]);
                          (yyval.expression) = static_dispatch((yyvsp[-7].expression), (yyvsp[-5].symbol), (yyvsp[-3].symbol), single_Expressions((yyvsp[-1].expression)));
                        }
#line 2213 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 526 "cool.y" /* yacc.c:1646  */
    {
                          (yyloc) = (yylsp[0]);
                          (yyval.expression) = static_dispatch((yyvsp[-8].expression), (yyvsp[-6].symbol), (yyvsp[-4].symbol), append_Expressions(single_Expressions((yyvsp[-2].expression)), (yyvsp[-1].expressions)));
                        }
#line 2222 "cool.tab.c" /* yacc.c:1646  */
    break;


#line 2226 "cool.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 533 "cool.y" /* yacc.c:1906  */

    
    /* This function is called automatically when Bison detects a parse error. */
    void yyerror(char *s)
    {
      extern int curr_lineno;
      
      cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
      << s << " at or near ";
      print_cool_token(yychar);
      cerr << endl;
      omerrs++;
      
      if(omerrs>50) {fprintf(stdout, "More than 50 errors\n"); exit(1);}
    }
    
    
