/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 29 "scannerparser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <glib.h>
#include <glib/gstdio.h>
#include "sourcescanner.h"
#include "scannerparser.h"

extern FILE *yyin;
extern int lineno;
extern char linebuf[2000];
extern char *yytext;

extern int yylex (GISourceScanner *scanner);
static void yyerror (GISourceScanner *scanner, const char *str);

extern void ctype_free (GISourceType * type);

static int last_enum_value = -1;
static gboolean is_bitfield;
static GHashTable *const_table = NULL;

/**
 * parse_c_string_literal:
 * @str: A string containing a C string literal
 *
 * Based on g_strcompress(), but also handles
 * hexadecimal escapes.
 */
static char *
parse_c_string_literal (const char *str)
{
  const gchar *p = str, *num;
  gchar *dest = g_malloc (strlen (str) + 1);
  gchar *q = dest;

  while (*p)
    {
      if (*p == '\\')
        {
          p++;
          switch (*p)
            {
            case '\0':
              g_warning ("parse_c_string_literal: trailing \\");
              goto out;
            case '0':  case '1':  case '2':  case '3':  case '4':
            case '5':  case '6':  case '7':
              *q = 0;
              num = p;
              while ((p < num + 3) && (*p >= '0') && (*p <= '7'))
                {
                  *q = (*q * 8) + (*p - '0');
                  p++;
                }
              q++;
              p--;
              break;
	    case 'x':
	      *q = 0;
	      p++;
	      num = p;
	      while ((p < num + 2) && (g_ascii_isxdigit(*p)))
		{
		  *q = (*q * 16) + g_ascii_xdigit_value(*p);
		  p++;
		}
              q++;
              p--;
	      break;
            case 'b':
              *q++ = '\b';
              break;
            case 'f':
              *q++ = '\f';
              break;
            case 'n':
              *q++ = '\n';
              break;
            case 'r':
              *q++ = '\r';
              break;
            case 't':
              *q++ = '\t';
              break;
            default:            /* Also handles \" and \\ */
              *q++ = *p;
              break;
            }
        }
      else
        *q++ = *p;
      p++;
    }
out:
  *q = 0;

  return dest;
}



/* Line 268 of yacc.c  */
#line 176 "scannerparser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     TYPEDEF_NAME = 259,
     INTEGER = 260,
     FLOATING = 261,
     CHARACTER = 262,
     STRING = 263,
     ELLIPSIS = 264,
     ADDEQ = 265,
     SUBEQ = 266,
     MULEQ = 267,
     DIVEQ = 268,
     MODEQ = 269,
     XOREQ = 270,
     ANDEQ = 271,
     OREQ = 272,
     SL = 273,
     SR = 274,
     SLEQ = 275,
     SREQ = 276,
     EQ = 277,
     NOTEQ = 278,
     LTEQ = 279,
     GTEQ = 280,
     ANDAND = 281,
     OROR = 282,
     PLUSPLUS = 283,
     MINUSMINUS = 284,
     ARROW = 285,
     AUTO = 286,
     BOOL = 287,
     BREAK = 288,
     CASE = 289,
     CHAR = 290,
     CONST = 291,
     CONTINUE = 292,
     DEFAULT = 293,
     DO = 294,
     DOUBLE = 295,
     ELSE = 296,
     ENUM = 297,
     EXTENSION = 298,
     EXTERN = 299,
     FLOAT = 300,
     FOR = 301,
     GOTO = 302,
     IF = 303,
     INLINE = 304,
     INT = 305,
     LONG = 306,
     REGISTER = 307,
     RESTRICT = 308,
     RETURN = 309,
     SHORT = 310,
     SIGNED = 311,
     SIZEOF = 312,
     STATIC = 313,
     STRUCT = 314,
     SWITCH = 315,
     TYPEDEF = 316,
     UNION = 317,
     UNSIGNED = 318,
     VOID = 319,
     VOLATILE = 320,
     WHILE = 321,
     FUNCTION_MACRO = 322,
     OBJECT_MACRO = 323
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define TYPEDEF_NAME 259
#define INTEGER 260
#define FLOATING 261
#define CHARACTER 262
#define STRING 263
#define ELLIPSIS 264
#define ADDEQ 265
#define SUBEQ 266
#define MULEQ 267
#define DIVEQ 268
#define MODEQ 269
#define XOREQ 270
#define ANDEQ 271
#define OREQ 272
#define SL 273
#define SR 274
#define SLEQ 275
#define SREQ 276
#define EQ 277
#define NOTEQ 278
#define LTEQ 279
#define GTEQ 280
#define ANDAND 281
#define OROR 282
#define PLUSPLUS 283
#define MINUSMINUS 284
#define ARROW 285
#define AUTO 286
#define BOOL 287
#define BREAK 288
#define CASE 289
#define CHAR 290
#define CONST 291
#define CONTINUE 292
#define DEFAULT 293
#define DO 294
#define DOUBLE 295
#define ELSE 296
#define ENUM 297
#define EXTENSION 298
#define EXTERN 299
#define FLOAT 300
#define FOR 301
#define GOTO 302
#define IF 303
#define INLINE 304
#define INT 305
#define LONG 306
#define REGISTER 307
#define RESTRICT 308
#define RETURN 309
#define SHORT 310
#define SIGNED 311
#define SIZEOF 312
#define STATIC 313
#define STRUCT 314
#define SWITCH 315
#define TYPEDEF 316
#define UNION 317
#define UNSIGNED 318
#define VOID 319
#define VOLATILE 320
#define WHILE 321
#define FUNCTION_MACRO 322
#define OBJECT_MACRO 323




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 134 "scannerparser.y"

  char *str;
  GList *list;
  GISourceSymbol *symbol;
  GISourceType *ctype;
  StorageClassSpecifier storage_class_specifier;
  TypeQualifier type_qualifier;
  FunctionSpecifier function_specifier;
  UnaryOperator unary_operator;



/* Line 293 of yacc.c  */
#line 361 "scannerparser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 373 "scannerparser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNRULES -- Number of states.  */
#define YYNSTATES  408

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,     2,     2,     2,    84,    77,     2,
      69,    70,    78,    79,    76,    80,    75,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    90,    92,
      85,    91,    86,    89,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    87,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    88,    72,    81,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    17,    24,
      26,    29,    31,    33,    35,    37,    42,    47,    51,    55,
      59,    62,    65,    67,    71,    73,    76,    79,    82,    85,
      90,    92,    94,    96,    98,   100,   102,   104,   109,   111,
     115,   119,   123,   125,   129,   133,   135,   139,   143,   145,
     149,   153,   157,   161,   163,   167,   171,   173,   177,   179,
     183,   185,   189,   191,   195,   197,   201,   203,   209,   211,
     215,   217,   219,   221,   223,   225,   227,   229,   231,   233,
     235,   237,   239,   243,   246,   248,   252,   255,   258,   260,
     263,   265,   268,   270,   273,   275,   277,   281,   283,   287,
     289,   291,   293,   295,   297,   299,   301,   303,   305,   307,
     309,   311,   313,   315,   317,   319,   321,   323,   329,   334,
     337,   339,   341,   343,   346,   350,   353,   355,   358,   360,
     362,   366,   367,   369,   372,   376,   382,   387,   394,   400,
     403,   405,   406,   409,   413,   415,   419,   421,   423,   425,
     427,   429,   432,   434,   436,   440,   445,   449,   454,   459,
     463,   466,   468,   472,   475,   477,   480,   482,   486,   489,
     492,   494,   496,   498,   502,   504,   507,   509,   511,   514,
     518,   521,   525,   529,   534,   537,   541,   545,   550,   552,
     554,   558,   563,   565,   569,   571,   573,   575,   577,   579,
     581,   585,   590,   594,   597,   601,   603,   606,   608,   610,
     612,   615,   621,   629,   635,   641,   649,   656,   664,   672,
     681,   689,   698,   707,   717,   721,   724,   727,   730,   734,
     736,   739,   741,   743,   745,   750,   754,   756,   759,   761,
     763,   768,   771,   773,   775
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     160,     0,    -1,    96,    -1,     5,    -1,     7,    -1,     6,
      -1,    95,    -1,    69,   116,    70,    -1,    43,    69,    71,
     154,    72,    70,    -1,     8,    -1,    95,     8,    -1,     3,
      -1,    96,    -1,   148,    -1,    94,    -1,    98,    73,   116,
      74,    -1,    98,    69,    99,    70,    -1,    98,    69,    70,
      -1,    98,    75,    97,    -1,    98,    30,    97,    -1,    98,
      28,    -1,    98,    29,    -1,   114,    -1,    99,    76,   114,
      -1,    98,    -1,    28,   100,    -1,    29,   100,    -1,   101,
     102,    -1,    57,   100,    -1,    57,    69,   145,    70,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,   100,    -1,    69,   145,    70,   102,    -1,   102,
      -1,   103,    78,   102,    -1,   103,    83,   102,    -1,   103,
      84,   102,    -1,   103,    -1,   104,    79,   103,    -1,   104,
      80,   103,    -1,   104,    -1,   105,    18,   104,    -1,   105,
      19,   104,    -1,   105,    -1,   106,    85,   105,    -1,   106,
      86,   105,    -1,   106,    24,   105,    -1,   106,    25,   105,
      -1,   106,    -1,   107,    22,   106,    -1,   107,    23,   106,
      -1,   107,    -1,   108,    77,   107,    -1,   108,    -1,   109,
      87,   108,    -1,   109,    -1,   110,    88,   109,    -1,   110,
      -1,   111,    26,   110,    -1,   111,    -1,   112,    27,   111,
      -1,   112,    -1,   112,    89,   116,    90,   113,    -1,   113,
      -1,   100,   115,   114,    -1,    91,    -1,    12,    -1,    13,
      -1,    14,    -1,    10,    -1,    11,    -1,    20,    -1,    21,
      -1,    16,    -1,    15,    -1,    17,    -1,   114,    -1,   116,
      76,   114,    -1,    43,   116,    -1,   113,    -1,   119,   120,
      92,    -1,   119,    92,    -1,   122,   119,    -1,   122,    -1,
     123,   119,    -1,   123,    -1,   136,   119,    -1,   136,    -1,
     137,   119,    -1,   137,    -1,   121,    -1,   120,    76,   121,
      -1,   138,    -1,   138,    91,   149,    -1,    61,    -1,    44,
      -1,    58,    -1,    31,    -1,    52,    -1,    64,    -1,    35,
      -1,    55,    -1,    50,    -1,    51,    -1,    45,    -1,    40,
      -1,    56,    -1,    63,    -1,    32,    -1,   124,    -1,   131,
      -1,   148,    -1,   125,    97,    71,   126,    72,    -1,   125,
      71,   126,    72,    -1,   125,    97,    -1,    59,    -1,    62,
      -1,   127,    -1,   126,   127,    -1,   128,   129,    92,    -1,
     123,   128,    -1,   123,    -1,   136,   128,    -1,   136,    -1,
     130,    -1,   129,    76,   130,    -1,    -1,   138,    -1,    90,
     117,    -1,   138,    90,   117,    -1,   132,    97,    71,   133,
      72,    -1,   132,    71,   133,    72,    -1,   132,    97,    71,
     133,    76,    72,    -1,   132,    71,   133,    76,    72,    -1,
     132,    97,    -1,    42,    -1,    -1,   134,   135,    -1,   133,
      76,   135,    -1,    96,    -1,    96,    91,   117,    -1,    36,
      -1,    53,    -1,    43,    -1,    65,    -1,    49,    -1,   140,
     139,    -1,   139,    -1,    96,    -1,    69,   138,    70,    -1,
     139,    73,   114,    74,    -1,   139,    73,    74,    -1,   139,
      69,   142,    70,    -1,   139,    69,   144,    70,    -1,   139,
      69,    70,    -1,    78,   141,    -1,    78,    -1,    78,   141,
     140,    -1,    78,   140,    -1,   136,    -1,   141,   136,    -1,
     143,    -1,   142,    76,   143,    -1,   119,   138,    -1,   119,
     146,    -1,   119,    -1,     9,    -1,    96,    -1,   144,    76,
      96,    -1,   128,    -1,   128,   146,    -1,   140,    -1,   147,
      -1,   140,   147,    -1,    69,   146,    70,    -1,    73,    74,
      -1,    73,   114,    74,    -1,   147,    73,    74,    -1,   147,
      73,   114,    74,    -1,    69,    70,    -1,    69,   142,    70,
      -1,   147,    69,    70,    -1,   147,    69,   142,    70,    -1,
       4,    -1,   114,    -1,    71,   150,    72,    -1,    71,   150,
      76,    72,    -1,   149,    -1,   150,    76,   149,    -1,   152,
      -1,   153,    -1,   156,    -1,   157,    -1,   158,    -1,   159,
      -1,    97,    90,   151,    -1,    34,   117,    90,   151,    -1,
      38,    90,   151,    -1,    71,    72,    -1,    71,   154,    72,
      -1,   155,    -1,   154,   155,    -1,   118,    -1,   151,    -1,
      92,    -1,   116,    92,    -1,    48,    69,   116,    70,   151,
      -1,    48,    69,   116,    70,   151,    41,   151,    -1,    60,
      69,   116,    70,   151,    -1,    66,    69,   116,    70,   151,
      -1,    39,   151,    66,    69,   116,    70,    92,    -1,    46,
      69,    92,    92,    70,   151,    -1,    46,    69,   116,    92,
      92,    70,   151,    -1,    46,    69,    92,   116,    92,    70,
     151,    -1,    46,    69,   116,    92,   116,    92,    70,   151,
      -1,    46,    69,    92,    92,   116,    70,   151,    -1,    46,
      69,   116,    92,    92,   116,    70,   151,    -1,    46,    69,
      92,   116,    92,   116,    70,   151,    -1,    46,    69,   116,
      92,   116,    92,   116,    70,   151,    -1,    47,    97,    92,
      -1,    37,    92,    -1,    33,    92,    -1,    54,    92,    -1,
      54,   116,    92,    -1,   161,    -1,   160,   161,    -1,   162,
      -1,   118,    -1,   168,    -1,   119,   138,   163,   153,    -1,
     119,   138,   153,    -1,   118,    -1,   163,   118,    -1,    67,
      -1,    68,    -1,   164,    69,   144,    70,    -1,   165,   117,
      -1,   166,    -1,   167,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   223,   223,   232,   244,   250,   257,   258,   262,   270,
     285,   299,   306,   307,   311,   312,   316,   320,   324,   328,
     332,   336,   343,   344,   348,   349,   353,   357,   380,   384,
     392,   396,   400,   404,   408,   412,   419,   420,   428,   429,
     435,   443,   454,   455,   461,   470,   471,   483,   492,   493,
     499,   505,   511,   520,   521,   527,   536,   537,   546,   547,
     556,   557,   566,   567,   578,   579,   590,   591,   598,   599,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   620,   621,   622,   629,   635,   653,   660,   665,   670,
     683,   684,   689,   694,   699,   707,   711,   718,   719,   723,
     727,   731,   735,   739,   746,   750,   754,   758,   762,   766,
     770,   774,   778,   782,   786,   787,   788,   796,   815,   820,
     828,   833,   841,   842,   849,   869,   874,   875,   880,   888,
     892,   900,   903,   904,   908,   919,   926,   933,   940,   947,
     954,   963,   963,   972,   980,   988,  1000,  1004,  1008,  1012,
    1019,  1026,  1031,  1035,  1040,  1044,  1049,  1054,  1064,  1071,
    1080,  1085,  1089,  1094,  1101,  1102,  1109,  1113,  1120,  1125,
    1130,  1135,  1142,  1148,  1157,  1158,  1162,  1167,  1168,  1176,
    1180,  1185,  1190,  1195,  1200,  1206,  1216,  1222,  1235,  1242,
    1243,  1244,  1248,  1249,  1255,  1256,  1257,  1258,  1259,  1260,
    1264,  1265,  1266,  1270,  1271,  1275,  1276,  1280,  1281,  1285,
    1286,  1290,  1291,  1292,  1296,  1297,  1298,  1299,  1300,  1301,
    1302,  1303,  1304,  1305,  1309,  1310,  1311,  1312,  1313,  1319,
    1320,  1324,  1325,  1326,  1330,  1331,  1335,  1336,  1342,  1349,
    1356,  1360,  1371,  1372,  1373
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"identifier\"", "\"typedef-name\"",
  "INTEGER", "FLOATING", "CHARACTER", "STRING", "ELLIPSIS", "ADDEQ",
  "SUBEQ", "MULEQ", "DIVEQ", "MODEQ", "XOREQ", "ANDEQ", "OREQ", "SL", "SR",
  "SLEQ", "SREQ", "EQ", "NOTEQ", "LTEQ", "GTEQ", "ANDAND", "OROR",
  "PLUSPLUS", "MINUSMINUS", "ARROW", "AUTO", "BOOL", "BREAK", "CASE",
  "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM",
  "EXTENSION", "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "INLINE", "INT",
  "LONG", "REGISTER", "RESTRICT", "RETURN", "SHORT", "SIGNED", "SIZEOF",
  "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID",
  "VOLATILE", "WHILE", "FUNCTION_MACRO", "OBJECT_MACRO", "'('", "')'",
  "'{'", "'}'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'",
  "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'",
  "'='", "';'", "$accept", "primary_expression", "strings", "identifier",
  "identifier_or_typedef_name", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enum_keyword", "enumerator_list",
  "$@1", "enumerator", "type_qualifier", "function_specifier",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "typedef_name", "initializer", "initializer_list", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list",
  "function_macro", "object_macro", "function_macro_define",
  "object_macro_define", "macro", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,    40,
      41,   123,   125,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   101,   101,   101,   102,   102,   103,   103,
     103,   103,   104,   104,   104,   105,   105,   105,   106,   106,
     106,   106,   106,   107,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   116,   117,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     125,   125,   126,   126,   127,   128,   128,   128,   128,   129,
     129,   130,   130,   130,   130,   131,   131,   131,   131,   131,
     132,   134,   133,   133,   135,   135,   136,   136,   136,   136,
     137,   138,   138,   139,   139,   139,   139,   139,   139,   139,
     140,   140,   140,   140,   141,   141,   142,   142,   143,   143,
     143,   143,   144,   144,   145,   145,   146,   146,   146,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   148,   149,
     149,   149,   150,   150,   151,   151,   151,   151,   151,   151,
     152,   152,   152,   153,   153,   154,   154,   155,   155,   156,
     156,   157,   157,   157,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   159,   159,   159,   159,   159,   160,
     160,   161,   161,   161,   162,   162,   163,   163,   164,   165,
     166,   167,   168,   168,   168
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     6,     1,
       2,     1,     1,     1,     1,     4,     4,     3,     3,     3,
       2,     2,     1,     3,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     3,     2,     2,     1,     2,
       1,     2,     1,     2,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     1,
       3,     0,     1,     2,     3,     5,     4,     6,     5,     2,
       1,     0,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       2,     1,     3,     2,     1,     2,     1,     3,     2,     2,
       1,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     1,     2,     1,     1,     1,
       2,     5,     7,     5,     5,     7,     6,     7,     7,     8,
       7,     8,     8,     9,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     1,     4,     3,     1,     2,     1,     1,
       4,     2,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   244,   188,   102,   113,   105,   146,   110,   140,   148,
     100,   109,   150,   107,   108,   103,   147,   106,   111,   101,
     120,    99,   121,   112,   104,   149,   238,   239,   232,     0,
      88,    90,   114,     0,   115,     0,    92,    94,   116,     0,
     229,   231,     0,     0,   242,   243,   233,    11,     0,   161,
      86,   153,     0,    95,    97,   152,     0,    87,    89,     0,
      12,   119,    13,   141,   139,    91,    93,     1,   230,     0,
       3,     5,     4,     9,     0,     0,     0,     0,     0,    30,
      31,    32,    33,    34,    35,    14,     6,     2,    24,    36,
       0,    38,    42,    45,    48,    53,    56,    58,    60,    62,
      64,    66,    84,   241,     0,   164,   163,   160,     0,    85,
       0,     0,   236,     0,   235,     0,     0,     0,   151,   126,
       0,   122,   131,   128,     0,     0,     0,   141,   172,     0,
       0,    25,    26,     0,     0,    28,   148,    36,    68,    81,
       0,   174,     0,    10,    20,    21,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   165,   162,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   209,     2,     0,
       0,   207,   116,   208,   194,   195,     0,   205,   196,   197,
     198,   199,     0,   189,    98,   237,   234,   171,   159,   170,
       0,   166,     0,   156,     0,   125,   118,   123,     0,     0,
     129,   132,   127,     0,   136,     0,   144,   142,     0,   240,
       0,     0,     0,     0,     0,    83,    74,    75,    71,    72,
      73,    79,    78,    80,    76,    77,    70,     0,     7,     0,
       0,     0,   176,   175,   177,     0,    19,    17,     0,    22,
       0,    18,    39,    40,    41,    43,    44,    46,    47,    51,
      52,    49,    50,    54,    55,    57,    59,    61,    63,    65,
       0,   226,     0,   225,     0,     0,     0,     0,     0,   227,
       0,     0,     0,     0,   210,   204,   206,   192,     0,     0,
     168,   176,   169,   157,     0,   158,   155,   133,   131,   124,
       0,   117,   138,   143,     0,   135,     0,   173,     0,    29,
      69,    82,   184,     0,     0,   180,     0,   178,     0,     0,
      37,    16,     0,    15,     0,     0,   202,     0,     0,     0,
     224,     0,   228,     0,     0,   200,   190,     0,   167,   130,
     134,   145,   137,     0,   185,   179,   181,   186,     0,   182,
       0,    23,    67,   201,     0,     0,     0,     0,     0,     0,
       0,   191,   193,     8,   187,   183,     0,     0,     0,     0,
       0,     0,   211,   213,   214,     0,   216,     0,     0,     0,
       0,     0,     0,     0,   215,   220,   218,     0,   217,     0,
       0,     0,   212,   222,   221,   219,     0,   223
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    85,    86,    87,   189,    88,   258,   137,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     138,   139,   247,   190,   103,   191,   113,    52,    53,    30,
      31,    32,    33,   120,   121,   122,   219,   220,    34,    35,
     125,   126,   313,    36,    37,   104,    55,    56,   107,   323,
     211,   129,   142,   324,   254,    38,   204,   298,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    39,    40,    41,
     115,    42,    43,    44,    45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -224
static const yytype_int16 yypact[] =
{
    1857,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,    20,
    2069,  2069,  -224,    59,  -224,    66,  2069,  2069,  -224,  1746,
    -224,  -224,   -38,  1451,  -224,  -224,  -224,  -224,    23,   151,
    -224,  -224,   -43,  -224,   970,   -17,    22,  -224,  -224,  2103,
    -224,   -16,  -224,  -224,    12,  -224,  -224,  -224,  -224,    39,
    -224,  -224,  -224,  -224,  1478,  1478,    40,  1508,  1119,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,   108,  -224,   161,  -224,
    1451,  -224,   129,    68,   255,    29,   198,    49,    42,    51,
     130,     1,  -224,  -224,   165,  -224,  -224,   151,    23,  -224,
     473,  1184,  -224,    20,  -224,  1960,  1923,  1217,   -17,  2103,
    1780,  -224,    71,  2103,  2103,     4,    39,  -224,  -224,    87,
    1535,  -224,  -224,   157,  1119,  -224,  1565,   472,  -224,  -224,
      95,   137,   167,  -224,  -224,  -224,   196,  1244,  1535,   196,
    -224,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1535,
    -224,  -224,  -224,  -224,   117,   160,  1451,   162,   159,   803,
     194,   196,   197,   819,   215,   217,  -224,  -224,   205,   214,
     -42,  -224,   218,  -224,  -224,  -224,   563,  -224,  -224,  -224,
    -224,  -224,  1184,  -224,  -224,  -224,  -224,  -224,  -224,   124,
     106,  -224,   109,  -224,   231,  -224,  -224,  -224,  1451,   -25,
    -224,   219,  -224,  1814,  -224,    32,   220,  -224,   133,  -224,
      39,  1565,   723,   240,  1039,   237,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  1451,  -224,  1451,
    1679,  1274,   158,  -224,   202,  1451,  -224,  -224,   122,  -224,
      -3,  -224,  -224,  -224,  -224,   129,   129,    68,    68,   255,
     255,   255,   255,    29,    29,   198,    49,    42,    51,   130,
     -44,  -224,   224,  -224,   803,   249,   884,   226,  1535,  -224,
      62,  1535,  1535,   803,  -224,  -224,  -224,  -224,   209,  1617,
    -224,    34,  -224,  -224,  2034,  -224,  -224,  -224,    71,  -224,
    1451,  -224,  -224,  -224,  1451,  -224,    33,  -224,   643,  -224,
    -224,  -224,  -224,   148,   251,  -224,   250,   202,  1997,  1301,
    -224,  -224,  1451,  -224,  1451,   803,  -224,   257,   900,    70,
    -224,   149,  -224,   169,   172,  -224,  -224,  1137,  -224,  -224,
    -224,  -224,  -224,   258,  -224,  -224,  -224,  -224,   177,  -224,
     253,  -224,  -224,  -224,  1535,  1331,    77,   916,   803,   803,
     803,  -224,  -224,  -224,  -224,  -224,   180,   803,   181,  1361,
    1391,    83,   288,  -224,  -224,   238,  -224,   803,   803,   189,
     803,   191,  1421,   803,  -224,  -224,  -224,   803,  -224,   803,
     803,   192,  -224,  -224,  -224,  -224,   803,  -224
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,  -224,   -29,   -21,  -224,  -224,   248,  -224,   -87,
     128,   136,   138,   139,   170,   168,   176,   178,   175,  -224,
     -34,  -106,  -224,   -48,  -159,    21,     8,  -224,   227,  -224,
      54,  -224,  -224,   223,  -113,   -62,  -224,    41,  -224,  -224,
     225,  -224,   230,    -1,  -224,   -14,   -55,   -39,  -224,  -114,
      46,   235,   229,   -98,  -223,   -15,  -189,  -224,    53,  -224,
     -30,   125,  -174,  -224,  -224,  -224,  -224,  -224,   321,  -224,
    -224,  -224,  -224,  -224,  -224,  -224
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -14
static const yytype_int16 yytable[] =
{
      51,   118,   210,   150,    60,   203,    60,   217,    29,   102,
     106,   214,    61,   297,    64,    54,   141,   282,    62,    51,
      62,    28,   296,    47,   114,    47,    47,    51,   168,   327,
     140,    69,   249,   108,   249,    47,    47,    47,    57,    58,
     128,   259,    47,   253,    65,    66,   334,    29,   105,   109,
     294,   308,   116,   158,   159,   124,   117,   215,   123,   307,
      28,   222,    47,     2,   262,   263,   264,   309,   172,    47,
       2,   333,   141,   249,    47,   112,   224,   123,   327,    51,
     225,   188,   140,   127,    51,   206,   140,   128,   235,    48,
     169,    48,    48,    51,   174,   192,   203,   226,    49,   174,
     260,    49,   252,   299,   312,   352,   171,   251,   221,   133,
     217,   302,    50,   119,   160,   161,   143,    60,   123,   123,
      60,   280,   123,   123,   209,   256,   164,    47,   261,   165,
      59,    62,   119,   123,    62,   290,   205,    63,   249,   166,
      48,   320,   102,   321,   296,   326,   249,   154,   155,    49,
     188,   350,    60,   249,   342,   351,   167,   229,   372,   249,
     287,   218,   367,   230,    62,   248,    62,   188,   330,   379,
     301,   249,   141,   119,   119,   392,   303,   119,   119,   305,
      51,   192,   304,   235,   102,   230,   140,     6,   119,   144,
     145,   146,   331,   299,     9,   300,   226,   251,   332,    47,
       2,   317,    49,   188,    16,   315,   250,   151,   111,   316,
     251,   252,   152,   153,   358,    49,    25,   192,   354,   368,
     162,   163,   123,   360,   304,   249,   361,   250,   232,    49,
     147,   251,   285,   123,   148,   170,   149,   255,   339,   369,
     341,   203,   370,   343,   344,   249,   118,   374,   249,   284,
     385,   387,   281,   304,   283,   188,   249,   249,   209,   397,
     301,   399,   406,   286,   188,   249,   288,   249,   249,    62,
      51,   328,    51,   156,   157,   329,   102,   119,    62,    51,
     102,   346,   265,   266,   291,   347,   292,   226,   119,   188,
     366,    89,   267,   268,   221,   -12,   269,   270,   271,   272,
     362,   273,   274,   192,   293,   306,   188,   209,   -13,   310,
     319,   314,   209,   249,   335,   337,   376,   378,   340,   381,
      62,   355,   131,   132,   356,   135,   364,   375,   373,   393,
     394,   389,   391,   276,   275,   173,   209,   336,    89,   188,
     188,   188,   277,   279,   401,   278,   345,   223,   188,   349,
     348,   212,   228,    62,    62,    62,   227,   318,   188,   188,
      68,   188,    62,   233,   188,     0,     0,     0,   188,     0,
     188,   188,    62,    62,     0,    62,     0,   188,    62,     0,
       0,     0,    62,     0,    62,    62,     0,     0,   363,     0,
       0,    62,     0,     0,     0,     0,     0,     0,     0,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,     0,     0,     0,
       0,   382,   383,   384,    89,     0,     0,     0,     0,     0,
     386,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     395,   396,     0,   398,     0,     0,   402,     0,     0,     0,
     403,     0,   404,   405,     0,     0,     0,     0,     0,   407,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     2,    70,    71,
      72,    73,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     0,   244,   245,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    89,     3,     4,   175,   176,     5,     6,
     177,   178,   179,     7,     0,     8,   136,    10,    11,   180,
     181,   182,    12,    13,    14,    15,    16,   183,    17,    18,
      77,    19,    20,   184,    21,    22,    23,    24,    25,   185,
       0,     0,    78,     0,   110,   186,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,     0,     0,    89,     0,
       0,     0,    89,   246,     0,   187,    47,     2,    70,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,     0,     3,     4,   175,   176,     5,     6,
     177,   178,   179,     7,     0,     8,   136,    10,    11,   180,
     181,   182,    12,    13,    14,    15,    16,   183,    17,    18,
      77,    19,    20,   184,    21,    22,    23,    24,    25,   185,
       0,     0,    78,     0,   110,   295,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    47,     2,    70,    71,
      72,    73,     0,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,     0,     3,     4,   175,   176,     5,     6,
     177,   178,   179,     7,     0,     8,   136,    10,    11,   180,
     181,   182,    12,    13,    14,    15,    16,   183,    17,    18,
      77,    19,    20,   184,    21,    22,    23,    24,    25,   185,
       0,     0,    78,     0,   110,   353,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    47,     2,    70,    71,
      72,    73,     0,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,     0,     3,     4,   175,   176,     5,     6,
     177,   178,   179,     7,     0,     8,   136,    10,    11,   180,
     181,   182,    12,    13,    14,    15,    16,   183,    17,    18,
      77,    19,    20,   184,    21,    22,    23,    24,    25,   185,
       0,     0,    78,     0,   110,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    47,     2,    70,    71,
      72,    73,     0,     0,     0,   187,     0,     0,     0,     0,
       0,     0,    47,     0,    70,    71,    72,    73,     0,     0,
       0,    74,    75,     0,     0,     0,   175,   176,     0,     0,
     177,   178,   179,     0,     0,     0,   231,    74,    75,   180,
     181,   182,     0,     0,     0,     0,     0,   183,     0,     0,
      77,     0,   231,   184,     0,     0,     0,     0,     0,   185,
       0,     0,    78,     0,   110,     0,    77,     0,     0,     0,
      79,    80,    81,    82,    83,    84,     0,    47,    78,    70,
      71,    72,    73,     0,     0,   187,    79,    80,    81,    82,
      83,    84,     0,    47,     0,    70,    71,    72,    73,     0,
       0,   289,    74,    75,     0,     0,     0,     0,     0,    47,
       0,    70,    71,    72,    73,     0,     0,   231,    74,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,   231,    74,    75,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,    77,     0,   231,
       0,    79,    80,    81,    82,    83,    84,     0,     0,    78,
       0,     0,     0,    77,     2,     0,   338,    79,    80,    81,
      82,    83,    84,     0,     0,    78,     0,     0,     0,     0,
       0,     0,   365,    79,    80,    81,    82,    83,    84,     0,
       0,     3,     4,     0,     0,     5,     6,     0,   380,     0,
       7,     0,     8,     9,    10,    11,     0,     0,     0,    12,
      13,    14,    15,    16,     0,    17,    18,     0,    19,    20,
       0,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,   110,    47,     2,    70,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,     0,     0,     0,    74,    75,     0,
       0,     4,     0,     0,     5,     6,     0,     0,     0,     7,
       0,     8,   136,     0,    11,     0,     0,     0,     0,    13,
      14,     0,    16,     0,    17,    18,    77,     0,    20,     0,
       0,    22,    23,    24,    25,     0,     0,     0,    78,     0,
     232,     0,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    47,     2,    70,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,    70,    71,    72,    73,     0,    74,    75,     0,
       0,     4,     0,     0,     5,     6,     0,     0,     0,     7,
       0,     8,   136,     0,    11,    74,    75,     0,     0,    13,
      14,     0,    16,     0,    17,    18,    77,     0,    20,     0,
      76,    22,    23,    24,    25,     0,     0,    47,    78,    70,
      71,    72,    73,     0,    77,     0,    79,    80,    81,    82,
      83,    84,     0,     0,     0,     0,    78,     0,   202,   371,
       0,     0,    74,    75,    79,    80,    81,    82,    83,    84,
      47,     0,    70,    71,    72,    73,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,    74,    75,    47,     0,    70,
      71,    72,    73,    78,     0,   202,     0,     0,     0,     0,
      76,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,    74,    75,    77,     0,     0,    47,     0,    70,
      71,    72,    73,     0,     0,     0,    78,    76,     0,     0,
       0,   213,     0,     0,    79,    80,    81,    82,    83,    84,
       0,    77,    74,    75,    47,     0,    70,    71,    72,    73,
       0,     0,     0,    78,   257,     0,     0,    76,     0,     0,
       0,    79,    80,    81,    82,    83,    84,     0,     0,    74,
      75,    77,     0,     0,    47,     0,    70,    71,    72,    73,
       0,     0,     0,    78,    76,     0,     0,     0,   325,     0,
       0,    79,    80,    81,    82,    83,    84,     0,    77,    74,
      75,     0,     0,     0,    47,     0,    70,    71,    72,    73,
      78,     0,     0,     0,   231,   359,     0,     0,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,    77,    74,
      75,     0,     0,     0,    47,     0,    70,    71,    72,    73,
      78,   377,     0,     0,   231,     0,     0,     0,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,    77,    74,
      75,     0,     0,     0,    47,     0,    70,    71,    72,    73,
      78,   388,     0,     0,   231,     0,     0,     0,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,    77,    74,
      75,     0,     0,     0,    47,     0,    70,    71,    72,    73,
      78,   390,     0,     0,   231,     0,     0,     0,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,    77,    74,
      75,    47,     0,    70,    71,    72,    73,     0,     0,     0,
      78,   400,     0,     0,    76,     0,     0,     0,    79,    80,
      81,    82,    83,    84,     0,     0,    74,    75,    77,     0,
       0,    47,     0,    70,    71,    72,    73,     0,     0,     0,
      78,    76,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,     0,    77,    74,    75,    47,     0,
      70,    71,    72,    73,     0,     0,     0,   130,     0,     0,
       0,    76,     0,     0,     0,    79,    80,    81,    82,    83,
      84,     0,     0,    74,    75,    77,     0,     0,    47,     0,
      70,    71,    72,    73,     0,     0,     0,   134,   231,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,     0,    77,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,   231,     0,
       0,     0,    79,    80,    81,    82,    83,    84,     0,     0,
      47,     2,    77,     0,     0,     0,   207,     0,     0,     0,
       0,     0,     0,     0,   234,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,     3,     4,
       0,     0,     5,     6,     0,     0,     0,     7,     0,     8,
       9,    10,    11,     0,     0,     0,    12,    13,    14,    15,
      16,     0,    17,    18,     0,    19,    20,     0,    21,    22,
      23,    24,    25,     2,     0,     0,   299,   322,   207,     0,
     251,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     0,     0,     5,     6,     0,     0,     0,     7,
       0,     8,     9,    10,    11,     0,     0,     0,    12,    13,
      14,    15,    16,     0,    17,    18,     0,    19,    20,     0,
      21,    22,    23,    24,    25,     0,    67,     1,   250,   322,
       2,     0,   251,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     0,
       0,     5,     6,     0,     2,     0,     7,     0,     8,     9,
      10,    11,     0,     0,     0,    12,    13,    14,    15,    16,
       0,    17,    18,     0,    19,    20,     0,    21,    22,    23,
      24,    25,     4,    26,    27,     5,     6,     0,     2,     0,
       7,     0,     8,     9,     0,    11,     0,     0,     0,     0,
      13,    14,     0,    16,     0,    17,    18,     0,     0,    20,
       0,     0,    22,    23,    24,    25,     4,     0,     0,     5,
       6,     0,   216,     0,     7,     0,     8,     9,     1,    11,
       0,     2,     0,     0,    13,    14,     0,    16,     0,    17,
      18,     0,     0,    20,     0,     0,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,   311,     0,     3,     4,
       0,     0,     5,     6,     0,     0,     0,     7,     0,     8,
       9,    10,    11,     0,     0,     0,    12,    13,    14,    15,
      16,     0,    17,    18,     0,    19,    20,     0,    21,    22,
      23,    24,    25,     0,    26,    27,    47,     2,     0,     0,
       0,     0,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     0,     5,     6,
       0,     0,     0,     7,     2,     8,     9,    10,    11,     0,
       0,     0,    12,    13,    14,    15,    16,     0,    17,    18,
       0,    19,    20,     0,    21,    22,    23,    24,    25,     0,
       0,     3,     4,   208,     0,     5,     6,     0,     0,     0,
       7,     2,     8,     9,    10,    11,   207,     0,     0,    12,
      13,    14,    15,    16,     0,    17,    18,     0,    19,    20,
       0,    21,    22,    23,    24,    25,     0,     0,     3,     4,
       0,   110,     5,     6,     0,     0,     0,     7,     2,     8,
       9,    10,    11,   207,     0,     0,    12,    13,    14,    15,
      16,     0,    17,    18,     0,    19,    20,     0,    21,    22,
      23,    24,    25,     0,     0,     3,     4,   357,     0,     5,
       6,     0,     0,     2,     7,     0,     8,     9,    10,    11,
       0,     0,     0,    12,    13,    14,    15,    16,     0,    17,
      18,     0,    19,    20,     0,    21,    22,    23,    24,    25,
       3,     4,     0,     0,     5,     6,     0,     2,     0,     7,
       0,     8,     9,    10,    11,     0,     0,     0,    12,    13,
      14,    15,    16,     0,    17,    18,     0,    19,    20,     0,
      21,    22,    23,    24,    25,     4,     0,     0,     5,     6,
       0,     0,     0,     7,     0,     8,     9,     0,    11,     0,
       0,     0,     0,    13,    14,     0,    16,     0,    17,    18,
       0,     0,    20,     0,     0,    22,    23,    24,    25
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-224))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      29,    56,   116,    90,    33,   111,    35,   120,     0,    43,
      49,   117,    33,   202,    35,    29,    78,   176,    33,    48,
      35,     0,   196,     3,    54,     3,     3,    56,    27,   252,
      78,    69,    76,    76,    76,     3,     3,     3,    30,    31,
      69,   147,     3,   141,    36,    37,    90,    39,    49,    92,
      92,    76,    69,    24,    25,    71,    73,   119,    59,   218,
      39,   123,     3,     4,   151,   152,   153,    92,   107,     3,
       4,    74,   134,    76,     3,    54,    72,    78,   301,   108,
      76,   110,   130,    71,   113,   115,   134,   116,   136,    69,
      89,    69,    69,   122,   108,   110,   202,   126,    78,   113,
     148,    78,   141,    69,    72,    72,   107,    73,   122,    69,
     223,   209,    92,    59,    85,    86,     8,   146,   119,   120,
     149,   169,   123,   124,   116,   146,    77,     3,   149,    87,
      71,   146,    78,   134,   149,   183,   115,    71,    76,    88,
      69,   247,   176,   249,   318,   251,    76,    79,    80,    78,
     179,   310,   181,    76,    92,   314,    26,    70,   347,    76,
     181,    90,    92,    76,   179,    70,   181,   196,   255,    92,
     209,    76,   234,   119,   120,    92,    70,   123,   124,    70,
     209,   196,    76,   231,   218,    76,   234,    36,   134,    28,
      29,    30,    70,    69,    43,   209,   225,    73,    76,     3,
       4,   230,    78,   232,    53,    72,    69,    78,    91,    76,
      73,   250,    83,    84,   328,    78,    65,   232,    70,    70,
      22,    23,   223,   329,    76,    76,   332,    69,    71,    78,
      69,    73,   179,   234,    73,    70,    75,    70,   286,    70,
     288,   347,    70,   291,   292,    76,   301,    70,    76,    90,
      70,    70,    92,    76,    92,   284,    76,    76,   250,    70,
     299,    70,    70,    69,   293,    76,    69,    76,    76,   284,
     299,    69,   301,    18,    19,    73,   310,   223,   293,   308,
     314,    72,   154,   155,    69,    76,    69,   316,   234,   318,
     338,    43,   156,   157,   308,    90,   158,   159,   160,   161,
     334,   162,   163,   318,    90,    74,   335,   299,    90,    90,
      70,    91,   304,    76,    90,    66,   364,   365,    92,   367,
     335,    70,    74,    75,    74,    77,    69,    74,    70,    41,
      92,   379,   380,   165,   164,   108,   328,   284,    90,   368,
     369,   370,   166,   168,   392,   167,   293,   124,   377,   308,
     304,   116,   127,   368,   369,   370,   126,   232,   387,   388,
      39,   390,   377,   134,   393,    -1,    -1,    -1,   397,    -1,
     399,   400,   387,   388,    -1,   390,    -1,   406,   393,    -1,
      -1,    -1,   397,    -1,   399,   400,    -1,    -1,   335,    -1,
      -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   368,   369,   370,   176,    -1,    -1,    -1,    -1,    -1,
     377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     387,   388,    -1,   390,    -1,    -1,   393,    -1,    -1,    -1,
     397,    -1,   399,   400,    -1,    -1,    -1,    -1,    -1,   406,
      -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,   255,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,    -1,    -1,   310,    -1,
      -1,    -1,   314,    91,    -1,    92,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    33,    34,    -1,    -1,
      37,    38,    39,    -1,    -1,    -1,    43,    28,    29,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      57,    -1,    43,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    69,    -1,    71,    -1,    57,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,    -1,     3,    69,     5,
       6,     7,     8,    -1,    -1,    92,    77,    78,    79,    80,
      81,    82,    -1,     3,    -1,     5,     6,     7,     8,    -1,
      -1,    92,    28,    29,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,    -1,    -1,    43,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    43,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    57,    -1,    43,
      -1,    77,    78,    79,    80,    81,    82,    -1,    -1,    69,
      -1,    -1,    -1,    57,     4,    -1,    92,    77,    78,    79,
      80,    81,    82,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    77,    78,    79,    80,    81,    82,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    -1,    92,    -1,
      40,    -1,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    71,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    40,
      -1,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,
      51,    -1,    53,    -1,    55,    56,    57,    -1,    59,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,    -1,    28,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    40,
      -1,    42,    43,    -1,    45,    28,    29,    -1,    -1,    50,
      51,    -1,    53,    -1,    55,    56,    57,    -1,    59,    -1,
      43,    62,    63,    64,    65,    -1,    -1,     3,    69,     5,
       6,     7,     8,    -1,    57,    -1,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    -1,    28,    29,    77,    78,    79,    80,    81,    82,
       3,    -1,     5,     6,     7,     8,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    28,    29,     3,    -1,     5,
       6,     7,     8,    69,    -1,    71,    -1,    -1,    -1,    -1,
      43,    77,    78,    79,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    28,    29,    57,    -1,    -1,     3,    -1,     5,
       6,     7,     8,    -1,    -1,    -1,    69,    43,    -1,    -1,
      -1,    74,    -1,    -1,    77,    78,    79,    80,    81,    82,
      -1,    57,    28,    29,     3,    -1,     5,     6,     7,     8,
      -1,    -1,    -1,    69,    70,    -1,    -1,    43,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    82,    -1,    -1,    28,
      29,    57,    -1,    -1,     3,    -1,     5,     6,     7,     8,
      -1,    -1,    -1,    69,    43,    -1,    -1,    -1,    74,    -1,
      -1,    77,    78,    79,    80,    81,    82,    -1,    57,    28,
      29,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
      69,    -1,    -1,    -1,    43,    74,    -1,    -1,    77,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,    57,    28,
      29,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
      69,    70,    -1,    -1,    43,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,    57,    28,
      29,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
      69,    70,    -1,    -1,    43,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,    57,    28,
      29,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
      69,    70,    -1,    -1,    43,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,    57,    28,
      29,     3,    -1,     5,     6,     7,     8,    -1,    -1,    -1,
      69,    70,    -1,    -1,    43,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    -1,    -1,    28,    29,    57,    -1,
      -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,    -1,
      69,    43,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    -1,    57,    28,    29,     3,    -1,
       5,     6,     7,     8,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      82,    -1,    -1,    28,    29,    57,    -1,    -1,     3,    -1,
       5,     6,     7,     8,    -1,    -1,    -1,    69,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      82,    -1,    57,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    82,    -1,    -1,
       3,     4,    57,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    82,    31,    32,
      -1,    -1,    35,    36,    -1,    -1,    -1,    40,    -1,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      63,    64,    65,     4,    -1,    -1,    69,    70,     9,    -1,
      73,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    40,
      -1,    42,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    63,    64,    65,    -1,     0,     1,    69,    70,
       4,    -1,    73,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    -1,     4,    -1,    40,    -1,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    -1,    61,    62,    63,
      64,    65,    32,    67,    68,    35,    36,    -1,     4,    -1,
      40,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,
      50,    51,    -1,    53,    -1,    55,    56,    -1,    -1,    59,
      -1,    -1,    62,    63,    64,    65,    32,    -1,    -1,    35,
      36,    -1,    72,    -1,    40,    -1,    42,    43,     1,    45,
      -1,     4,    -1,    -1,    50,    51,    -1,    53,    -1,    55,
      56,    -1,    -1,    59,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    31,    32,
      -1,    -1,    35,    36,    -1,    -1,    -1,    40,    -1,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      63,    64,    65,    -1,    67,    68,     3,     4,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
      -1,    -1,    -1,    40,     4,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    55,    56,
      -1,    58,    59,    -1,    61,    62,    63,    64,    65,    -1,
      -1,    31,    32,    70,    -1,    35,    36,    -1,    -1,    -1,
      40,     4,    42,    43,    44,    45,     9,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    31,    32,
      -1,    71,    35,    36,    -1,    -1,    -1,    40,     4,    42,
      43,    44,    45,     9,    -1,    -1,    49,    50,    51,    52,
      53,    -1,    55,    56,    -1,    58,    59,    -1,    61,    62,
      63,    64,    65,    -1,    -1,    31,    32,    70,    -1,    35,
      36,    -1,    -1,     4,    40,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    64,    65,
      31,    32,    -1,    -1,    35,    36,    -1,     4,    -1,    40,
      -1,    42,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    58,    59,    -1,
      61,    62,    63,    64,    65,    32,    -1,    -1,    35,    36,
      -1,    -1,    -1,    40,    -1,    42,    43,    -1,    45,    -1,
      -1,    -1,    -1,    50,    51,    -1,    53,    -1,    55,    56,
      -1,    -1,    59,    -1,    -1,    62,    63,    64,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,    31,    32,    35,    36,    40,    42,    43,
      44,    45,    49,    50,    51,    52,    53,    55,    56,    58,
      59,    61,    62,    63,    64,    65,    67,    68,   118,   119,
     122,   123,   124,   125,   131,   132,   136,   137,   148,   160,
     161,   162,   164,   165,   166,   167,   168,     3,    69,    78,
      92,    96,   120,   121,   138,   139,   140,   119,   119,    71,
      96,    97,   148,    71,    97,   119,   119,     0,   161,    69,
       5,     6,     7,     8,    28,    29,    43,    57,    69,    77,
      78,    79,    80,    81,    82,    94,    95,    96,    98,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   117,   138,   136,   140,   141,    76,    92,
      71,    91,   118,   119,   153,   163,    69,    73,   139,   123,
     126,   127,   128,   136,    71,   133,   134,    71,    96,   144,
      69,   100,   100,    69,    69,   100,    43,   100,   113,   114,
     116,   128,   145,     8,    28,    29,    30,    69,    73,    75,
     102,    78,    83,    84,    79,    80,    18,    19,    24,    25,
      85,    86,    22,    23,    77,    87,    88,    26,    27,    89,
      70,   136,   140,   121,   138,    33,    34,    37,    38,    39,
      46,    47,    48,    54,    60,    66,    72,    92,    96,    97,
     116,   118,   148,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    71,   114,   149,   118,   153,     9,    70,   119,
     142,   143,   144,    74,   114,   128,    72,   127,    90,   129,
     130,   138,   128,   126,    72,    76,    96,   135,   133,    70,
      76,    43,    71,   145,    69,   116,    10,    11,    12,    13,
      14,    15,    16,    17,    20,    21,    91,   115,    70,    76,
      69,    73,   140,   146,   147,    70,    97,    70,    99,   114,
     116,    97,   102,   102,   102,   103,   103,   104,   104,   105,
     105,   105,   105,   106,   106,   107,   108,   109,   110,   111,
     116,    92,   117,    92,    90,   151,    69,    97,    69,    92,
     116,    69,    69,    90,    92,    72,   155,   149,   150,    69,
     138,   140,   146,    70,    76,    70,    74,   117,    76,    92,
      90,    72,    72,   135,    91,    72,    76,    96,   154,    70,
     114,   114,    70,   142,   146,    74,   114,   147,    69,    73,
     102,    70,    76,    74,    90,    90,   151,    66,    92,   116,
      92,   116,    92,   116,   116,   151,    72,    76,   143,   130,
     117,   117,    72,    72,    70,    70,    74,    70,   142,    74,
     114,   114,   113,   151,    69,    92,   116,    92,    70,    70,
      70,    72,   149,    70,    70,    74,   116,    70,   116,    92,
      92,   116,   151,   151,   151,    70,   151,    70,    70,   116,
      70,   116,    92,    41,    92,   151,   151,    70,   151,    70,
      70,   116,   151,   151,   151,   151,    70,   151
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (scanner, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex (scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, GISourceScanner* scanner)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    GISourceScanner* scanner;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (scanner);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, GISourceScanner* scanner)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    GISourceScanner* scanner;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, GISourceScanner* scanner)
#else
static void
yy_reduce_print (yyvsp, yyrule, scanner)
    YYSTYPE *yyvsp;
    int yyrule;
    GISourceScanner* scanner;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, scanner); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, GISourceScanner* scanner)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, scanner)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    GISourceScanner* scanner;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (scanner);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (GISourceScanner* scanner);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (GISourceScanner* scanner)
#else
int
yyparse (scanner)
    GISourceScanner* scanner;
#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 224 "scannerparser.y"
    {
		(yyval.symbol) = g_hash_table_lookup (const_table, (yyvsp[(1) - (1)].str));
		if ((yyval.symbol) == NULL) {
			(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		} else {
			(yyval.symbol) = gi_source_symbol_ref ((yyval.symbol));
		}
	  }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 233 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		if (g_str_has_prefix (yytext, "0x") && strlen (yytext) > 2) {
			(yyval.symbol)->const_int = g_ascii_strtoll (yytext + 2, NULL, 16);
		} else if (g_str_has_prefix (yytext, "0") && strlen (yytext) > 1) {
			(yyval.symbol)->const_int = g_ascii_strtoll (yytext + 1, NULL, 8);
		} else {
			(yyval.symbol)->const_int = g_ascii_strtoll (yytext, NULL, 10);
		}
	  }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 245 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = g_utf8_get_char(yytext + 1);
	  }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 251 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_double_set = TRUE;
		(yyval.symbol)->const_double = 0.0;
        sscanf (yytext, "%lf", &((yyval.symbol)->const_double));
	  }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 259 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(2) - (3)].symbol);
	  }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 263 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 271 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		yytext[strlen (yytext) - 1] = '\0';
		(yyval.symbol)->const_string = parse_c_string_literal (yytext + 1);
                if (!g_utf8_validate ((yyval.symbol)->const_string, -1, NULL))
                  {
#if 0
                    g_warning ("Ignoring non-UTF-8 constant string \"%s\"", yytext + 1);
#endif
                    g_free((yyval.symbol)->const_string);
                    (yyval.symbol)->const_string = NULL;
                  }

	  }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 286 "scannerparser.y"
    {
		char *strings, *string2;
		(yyval.symbol) = (yyvsp[(1) - (2)].symbol);
		yytext[strlen (yytext) - 1] = '\0';
		string2 = parse_c_string_literal (yytext + 1);
		strings = g_strconcat ((yyval.symbol)->const_string, string2, NULL);
		g_free ((yyval.symbol)->const_string);
		g_free (string2);
		(yyval.symbol)->const_string = strings;
	  }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 300 "scannerparser.y"
    {
		(yyval.str) = g_strdup (yytext);
	  }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 313 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 317 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 321 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 325 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 329 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 333 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 337 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 350 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 354 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 358 "scannerparser.y"
    {
		switch ((yyvsp[(1) - (2)].unary_operator)) {
		case UNARY_PLUS:
			(yyval.symbol) = (yyvsp[(2) - (2)].symbol);
			break;
		case UNARY_MINUS:
			(yyval.symbol) = (yyvsp[(2) - (2)].symbol);
			(yyval.symbol)->const_int = -(yyvsp[(2) - (2)].symbol)->const_int;
			break;
		case UNARY_BITWISE_COMPLEMENT:
			(yyval.symbol) = (yyvsp[(2) - (2)].symbol);
			(yyval.symbol)->const_int = ~(yyvsp[(2) - (2)].symbol)->const_int;
			break;
		case UNARY_LOGICAL_NEGATION:
			(yyval.symbol) = (yyvsp[(2) - (2)].symbol);
			(yyval.symbol)->const_int = !gi_source_symbol_get_const_boolean ((yyvsp[(2) - (2)].symbol));
			break;
		default:
			(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
			break;
		}
	  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 381 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 385 "scannerparser.y"
    {
		ctype_free ((yyvsp[(3) - (4)].ctype));
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 393 "scannerparser.y"
    {
		(yyval.unary_operator) = UNARY_ADDRESS_OF;
	  }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 397 "scannerparser.y"
    {
		(yyval.unary_operator) = UNARY_POINTER_INDIRECTION;
	  }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 401 "scannerparser.y"
    {
		(yyval.unary_operator) = UNARY_PLUS;
	  }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 405 "scannerparser.y"
    {
		(yyval.unary_operator) = UNARY_MINUS;
	  }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 409 "scannerparser.y"
    {
		(yyval.unary_operator) = UNARY_BITWISE_COMPLEMENT;
	  }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 413 "scannerparser.y"
    {
		(yyval.unary_operator) = UNARY_LOGICAL_NEGATION;
	  }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 421 "scannerparser.y"
    {
		ctype_free ((yyvsp[(2) - (4)].ctype));
		(yyval.symbol) = (yyvsp[(4) - (4)].symbol);
	  }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 430 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int * (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 436 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		if ((yyvsp[(3) - (3)].symbol)->const_int != 0) {
			(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int / (yyvsp[(3) - (3)].symbol)->const_int;
		}
	  }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 444 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		if ((yyvsp[(3) - (3)].symbol)->const_int != 0) {
			(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int % (yyvsp[(3) - (3)].symbol)->const_int;
		}
	  }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 456 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int + (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 462 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int - (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 472 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int << (yyvsp[(3) - (3)].symbol)->const_int;

		/* assume this is a bitfield/flags declaration
		 * if a left shift operator is sued in an enum value
                 * This mimics the glib-mkenum behavior.
		 */
		is_bitfield = TRUE;
	  }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 484 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int >> (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 494 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int < (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 500 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int > (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 506 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int <= (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 512 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int >= (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 522 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int == (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 528 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int != (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 538 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int & (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 548 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int ^ (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 558 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(1) - (3)].symbol)->const_int | (yyvsp[(3) - (3)].symbol)->const_int;
	  }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 568 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int =
		  gi_source_symbol_get_const_boolean ((yyvsp[(1) - (3)].symbol)) &&
		  gi_source_symbol_get_const_boolean ((yyvsp[(3) - (3)].symbol));
	  }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 580 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_CONST, scanner->current_filename, lineno);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int =
		  gi_source_symbol_get_const_boolean ((yyvsp[(1) - (3)].symbol)) ||
		  gi_source_symbol_get_const_boolean ((yyvsp[(3) - (3)].symbol));
	  }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 592 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_get_const_boolean ((yyvsp[(1) - (5)].symbol)) ? (yyvsp[(3) - (5)].symbol) : (yyvsp[(5) - (5)].symbol);
	  }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 600 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 623 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 636 "scannerparser.y"
    {
		GList *l;
		for (l = (yyvsp[(2) - (3)].list); l != NULL; l = l->next) {
			GISourceSymbol *sym = l->data;
			gi_source_symbol_merge_type (sym, gi_source_type_copy ((yyvsp[(1) - (3)].ctype)));
			if ((yyvsp[(1) - (3)].ctype)->storage_class_specifier & STORAGE_CLASS_TYPEDEF) {
				sym->type = CSYMBOL_TYPE_TYPEDEF;
			} else if (sym->base_type->type == CTYPE_FUNCTION) {
				sym->type = CSYMBOL_TYPE_FUNCTION;
			} else {
				sym->type = CSYMBOL_TYPE_OBJECT;
			}
			gi_source_scanner_add_symbol (scanner, sym);
			gi_source_symbol_unref (sym);
		}
		ctype_free ((yyvsp[(1) - (3)].ctype));
	  }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 654 "scannerparser.y"
    {
		ctype_free ((yyvsp[(1) - (2)].ctype));
	  }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 661 "scannerparser.y"
    {
		(yyval.ctype) = (yyvsp[(2) - (2)].ctype);
		(yyval.ctype)->storage_class_specifier |= (yyvsp[(1) - (2)].storage_class_specifier);
	  }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 666 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_type_new (CTYPE_INVALID);
		(yyval.ctype)->storage_class_specifier |= (yyvsp[(1) - (1)].storage_class_specifier);
	  }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 671 "scannerparser.y"
    {
		(yyval.ctype) = (yyvsp[(1) - (2)].ctype);
		/* combine basic types like unsigned int and long long */
		if ((yyval.ctype)->type == CTYPE_BASIC_TYPE && (yyvsp[(2) - (2)].ctype)->type == CTYPE_BASIC_TYPE) {
			char *name = g_strdup_printf ("%s %s", (yyval.ctype)->name, (yyvsp[(2) - (2)].ctype)->name);
			g_free ((yyval.ctype)->name);
			(yyval.ctype)->name = name;
			ctype_free ((yyvsp[(2) - (2)].ctype));
		} else {
			(yyval.ctype)->base_type = (yyvsp[(2) - (2)].ctype);
		}
	  }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 685 "scannerparser.y"
    {
		(yyval.ctype) = (yyvsp[(2) - (2)].ctype);
		(yyval.ctype)->type_qualifier |= (yyvsp[(1) - (2)].type_qualifier);
	  }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 690 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_type_new (CTYPE_INVALID);
		(yyval.ctype)->type_qualifier |= (yyvsp[(1) - (1)].type_qualifier);
	  }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 695 "scannerparser.y"
    {
		(yyval.ctype) = (yyvsp[(2) - (2)].ctype);
		(yyval.ctype)->function_specifier |= (yyvsp[(1) - (2)].function_specifier);
	  }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 700 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_type_new (CTYPE_INVALID);
		(yyval.ctype)->function_specifier |= (yyvsp[(1) - (1)].function_specifier);
	  }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 708 "scannerparser.y"
    {
		(yyval.list) = g_list_append (NULL, (yyvsp[(1) - (1)].symbol));
	  }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 712 "scannerparser.y"
    {
		(yyval.list) = g_list_append ((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].symbol));
	  }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 724 "scannerparser.y"
    {
		(yyval.storage_class_specifier) = STORAGE_CLASS_TYPEDEF;
	  }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 728 "scannerparser.y"
    {
		(yyval.storage_class_specifier) = STORAGE_CLASS_EXTERN;
	  }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 732 "scannerparser.y"
    {
		(yyval.storage_class_specifier) = STORAGE_CLASS_STATIC;
	  }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 736 "scannerparser.y"
    {
		(yyval.storage_class_specifier) = STORAGE_CLASS_AUTO;
	  }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 740 "scannerparser.y"
    {
		(yyval.storage_class_specifier) = STORAGE_CLASS_REGISTER;
	  }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 747 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_type_new (CTYPE_VOID);
	  }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 751 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_basic_type_new ("char");
	  }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 755 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_basic_type_new ("short");
	  }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 759 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_basic_type_new ("int");
	  }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 763 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_basic_type_new ("long");
	  }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 767 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_basic_type_new ("float");
	  }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 771 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_basic_type_new ("double");
	  }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 775 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_basic_type_new ("signed");
	  }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 779 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_basic_type_new ("unsigned");
	  }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 783 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_basic_type_new ("bool");
	  }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 789 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_typedef_new ((yyvsp[(1) - (1)].str));
		g_free ((yyvsp[(1) - (1)].str));
	  }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 797 "scannerparser.y"
    {
		(yyval.ctype) = (yyvsp[(1) - (5)].ctype);
		(yyval.ctype)->name = (yyvsp[(2) - (5)].str);
		(yyval.ctype)->child_list = (yyvsp[(4) - (5)].list);

		GISourceSymbol *sym = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		if ((yyval.ctype)->type == CTYPE_STRUCT) {
			sym->type = CSYMBOL_TYPE_STRUCT;
		} else if ((yyval.ctype)->type == CTYPE_UNION) {
			sym->type = CSYMBOL_TYPE_UNION;
		} else {
			g_assert_not_reached ();
		}
		sym->ident = g_strdup ((yyval.ctype)->name);
		sym->base_type = gi_source_type_copy ((yyval.ctype));
		gi_source_scanner_add_symbol (scanner, sym);
		gi_source_symbol_unref (sym);
	  }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 816 "scannerparser.y"
    {
		(yyval.ctype) = (yyvsp[(1) - (4)].ctype);
		(yyval.ctype)->child_list = (yyvsp[(3) - (4)].list);
	  }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 821 "scannerparser.y"
    {
		(yyval.ctype) = (yyvsp[(1) - (2)].ctype);
		(yyval.ctype)->name = (yyvsp[(2) - (2)].str);
	  }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 829 "scannerparser.y"
    {
                scanner->private = FALSE;
		(yyval.ctype) = gi_source_struct_new (NULL);
	  }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 834 "scannerparser.y"
    {
                scanner->private = FALSE;
		(yyval.ctype) = gi_source_union_new (NULL);
	  }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 843 "scannerparser.y"
    {
		(yyval.list) = g_list_concat ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list));
	  }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 850 "scannerparser.y"
    {
	    GList *l;
	    (yyval.list) = NULL;
	    for (l = (yyvsp[(2) - (3)].list); l != NULL; l = l->next)
	      {
		GISourceSymbol *sym = l->data;
		if ((yyvsp[(1) - (3)].ctype)->storage_class_specifier & STORAGE_CLASS_TYPEDEF)
		    sym->type = CSYMBOL_TYPE_TYPEDEF;
		else
		    sym->type = CSYMBOL_TYPE_MEMBER;
		gi_source_symbol_merge_type (sym, gi_source_type_copy ((yyvsp[(1) - (3)].ctype)));
                sym->private = scanner->private;
                (yyval.list) = g_list_append ((yyval.list), sym);
	      }
	    ctype_free ((yyvsp[(1) - (3)].ctype));
	  }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 870 "scannerparser.y"
    {
		(yyval.ctype) = (yyvsp[(1) - (2)].ctype);
		(yyval.ctype)->base_type = (yyvsp[(2) - (2)].ctype);
	  }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 876 "scannerparser.y"
    {
		(yyval.ctype) = (yyvsp[(2) - (2)].ctype);
		(yyval.ctype)->type_qualifier |= (yyvsp[(1) - (2)].type_qualifier);
	  }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 881 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_type_new (CTYPE_INVALID);
		(yyval.ctype)->type_qualifier |= (yyvsp[(1) - (1)].type_qualifier);
	  }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 889 "scannerparser.y"
    {
		(yyval.list) = g_list_append (NULL, (yyvsp[(1) - (1)].symbol));
	  }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 893 "scannerparser.y"
    {
		(yyval.list) = g_list_append ((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].symbol));
	  }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 900 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 905 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
	  }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 909 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(1) - (3)].symbol);
		if ((yyvsp[(3) - (3)].symbol)->const_int_set) {
		  (yyval.symbol)->const_int_set = TRUE;
		  (yyval.symbol)->const_int = (yyvsp[(3) - (3)].symbol)->const_int;
		}
	  }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 920 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_enum_new ((yyvsp[(2) - (5)].str));
		(yyval.ctype)->child_list = (yyvsp[(4) - (5)].list);
		(yyval.ctype)->is_bitfield = is_bitfield || scanner->flags;
		last_enum_value = -1;
	  }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 927 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_enum_new (NULL);
		(yyval.ctype)->child_list = (yyvsp[(3) - (4)].list);
		(yyval.ctype)->is_bitfield = is_bitfield || scanner->flags;
		last_enum_value = -1;
	  }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 934 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_enum_new ((yyvsp[(2) - (6)].str));
		(yyval.ctype)->child_list = (yyvsp[(4) - (6)].list);
		(yyval.ctype)->is_bitfield = is_bitfield || scanner->flags;
		last_enum_value = -1;
	  }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 941 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_enum_new (NULL);
		(yyval.ctype)->child_list = (yyvsp[(3) - (5)].list);
		(yyval.ctype)->is_bitfield = is_bitfield || scanner->flags;
		last_enum_value = -1;
	  }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 948 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_enum_new ((yyvsp[(2) - (2)].str));
	  }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 955 "scannerparser.y"
    {
                scanner->flags = FALSE;
                scanner->private = FALSE;
          }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 963 "scannerparser.y"
    {
		/* reset flag before the first enum value */
		is_bitfield = FALSE;
	  }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 968 "scannerparser.y"
    {
            (yyvsp[(2) - (2)].symbol)->private = scanner->private;
            (yyval.list) = g_list_append (NULL, (yyvsp[(2) - (2)].symbol));
	  }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 973 "scannerparser.y"
    {
            (yyvsp[(3) - (3)].symbol)->private = scanner->private;
            (yyval.list) = g_list_append ((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].symbol));
	  }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 981 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_OBJECT, scanner->current_filename, lineno);
		(yyval.symbol)->ident = (yyvsp[(1) - (1)].str);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = ++last_enum_value;
		g_hash_table_insert (const_table, g_strdup ((yyval.symbol)->ident), gi_source_symbol_ref ((yyval.symbol)));
	  }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 989 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_OBJECT, scanner->current_filename, lineno);
		(yyval.symbol)->ident = (yyvsp[(1) - (3)].str);
		(yyval.symbol)->const_int_set = TRUE;
		(yyval.symbol)->const_int = (yyvsp[(3) - (3)].symbol)->const_int;
		last_enum_value = (yyval.symbol)->const_int;
		g_hash_table_insert (const_table, g_strdup ((yyval.symbol)->ident), gi_source_symbol_ref ((yyval.symbol)));
	  }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1001 "scannerparser.y"
    {
		(yyval.type_qualifier) = TYPE_QUALIFIER_CONST;
	  }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1005 "scannerparser.y"
    {
		(yyval.type_qualifier) = TYPE_QUALIFIER_RESTRICT;
	  }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1009 "scannerparser.y"
    {
		(yyval.type_qualifier) = TYPE_QUALIFIER_EXTENSION;
	  }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1013 "scannerparser.y"
    {
		(yyval.type_qualifier) = TYPE_QUALIFIER_VOLATILE;
	  }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1020 "scannerparser.y"
    {
		(yyval.function_specifier) = FUNCTION_INLINE;
	  }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1027 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(2) - (2)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), (yyvsp[(1) - (2)].ctype));
	  }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1036 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		(yyval.symbol)->ident = (yyvsp[(1) - (1)].str);
	  }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1041 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(2) - (3)].symbol);
	  }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1045 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(1) - (4)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), gi_source_array_new ((yyvsp[(3) - (4)].symbol)));
	  }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1050 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(1) - (3)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), gi_source_array_new (NULL));
	  }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1055 "scannerparser.y"
    {
		GISourceType *func = gi_source_function_new ();
		// ignore (void) parameter list
		if ((yyvsp[(3) - (4)].list) != NULL && ((yyvsp[(3) - (4)].list)->next != NULL || ((GISourceSymbol *) (yyvsp[(3) - (4)].list)->data)->base_type->type != CTYPE_VOID)) {
			func->child_list = (yyvsp[(3) - (4)].list);
		}
		(yyval.symbol) = (yyvsp[(1) - (4)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), func);
	  }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1065 "scannerparser.y"
    {
		GISourceType *func = gi_source_function_new ();
		func->child_list = (yyvsp[(3) - (4)].list);
		(yyval.symbol) = (yyvsp[(1) - (4)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), func);
	  }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1072 "scannerparser.y"
    {
		GISourceType *func = gi_source_function_new ();
		(yyval.symbol) = (yyvsp[(1) - (3)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), func);
	  }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1081 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_pointer_new (NULL);
		(yyval.ctype)->type_qualifier = (yyvsp[(2) - (2)].type_qualifier);
	  }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1086 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_pointer_new (NULL);
	  }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1090 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_pointer_new ((yyvsp[(3) - (3)].ctype));
		(yyval.ctype)->type_qualifier = (yyvsp[(2) - (3)].type_qualifier);
	  }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1095 "scannerparser.y"
    {
		(yyval.ctype) = gi_source_pointer_new ((yyvsp[(2) - (2)].ctype));
	  }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1103 "scannerparser.y"
    {
		(yyval.type_qualifier) = (yyvsp[(1) - (2)].type_qualifier) | (yyvsp[(2) - (2)].type_qualifier);
	  }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1110 "scannerparser.y"
    {
		(yyval.list) = g_list_append (NULL, (yyvsp[(1) - (1)].symbol));
	  }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1114 "scannerparser.y"
    {
		(yyval.list) = g_list_append ((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].symbol));
	  }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1121 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(2) - (2)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), (yyvsp[(1) - (2)].ctype));
	  }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1126 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(2) - (2)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), (yyvsp[(1) - (2)].ctype));
	  }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1131 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		(yyval.symbol)->base_type = (yyvsp[(1) - (1)].ctype);
	  }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1136 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_ELLIPSIS, scanner->current_filename, lineno);
	  }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1143 "scannerparser.y"
    {
		GISourceSymbol *sym = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		sym->ident = (yyvsp[(1) - (1)].str);
		(yyval.list) = g_list_append (NULL, sym);
	  }
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1149 "scannerparser.y"
    {
		GISourceSymbol *sym = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		sym->ident = (yyvsp[(3) - (3)].str);
		(yyval.list) = g_list_append ((yyvsp[(1) - (3)].list), sym);
	  }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1163 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		gi_source_symbol_merge_type ((yyval.symbol), (yyvsp[(1) - (1)].ctype));
	  }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1169 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(2) - (2)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), (yyvsp[(1) - (2)].ctype));
	  }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1177 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(2) - (3)].symbol);
	  }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1181 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		gi_source_symbol_merge_type ((yyval.symbol), gi_source_array_new (NULL));
	  }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1186 "scannerparser.y"
    {
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		gi_source_symbol_merge_type ((yyval.symbol), gi_source_array_new ((yyvsp[(2) - (3)].symbol)));
	  }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1191 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(1) - (3)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), gi_source_array_new (NULL));
	  }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1196 "scannerparser.y"
    {
		(yyval.symbol) = (yyvsp[(1) - (4)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), gi_source_array_new ((yyvsp[(3) - (4)].symbol)));
	  }
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1201 "scannerparser.y"
    {
		GISourceType *func = gi_source_function_new ();
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		gi_source_symbol_merge_type ((yyval.symbol), func);
	  }
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1207 "scannerparser.y"
    {
		GISourceType *func = gi_source_function_new ();
		// ignore (void) parameter list
		if ((yyvsp[(2) - (3)].list) != NULL && ((yyvsp[(2) - (3)].list)->next != NULL || ((GISourceSymbol *) (yyvsp[(2) - (3)].list)->data)->base_type->type != CTYPE_VOID)) {
			func->child_list = (yyvsp[(2) - (3)].list);
		}
		(yyval.symbol) = gi_source_symbol_new (CSYMBOL_TYPE_INVALID, scanner->current_filename, lineno);
		gi_source_symbol_merge_type ((yyval.symbol), func);
	  }
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1217 "scannerparser.y"
    {
		GISourceType *func = gi_source_function_new ();
		(yyval.symbol) = (yyvsp[(1) - (3)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), func);
	  }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1223 "scannerparser.y"
    {
		GISourceType *func = gi_source_function_new ();
		// ignore (void) parameter list
		if ((yyvsp[(3) - (4)].list) != NULL && ((yyvsp[(3) - (4)].list)->next != NULL || ((GISourceSymbol *) (yyvsp[(3) - (4)].list)->data)->base_type->type != CTYPE_VOID)) {
			func->child_list = (yyvsp[(3) - (4)].list);
		}
		(yyval.symbol) = (yyvsp[(1) - (4)].symbol);
		gi_source_symbol_merge_type ((yyval.symbol), func);
	  }
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1236 "scannerparser.y"
    {
		(yyval.str) = g_strdup (yytext);
	  }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 1343 "scannerparser.y"
    {
		(yyval.str) = g_strdup (yytext + strlen ("#define "));
	  }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 1350 "scannerparser.y"
    {
		(yyval.str) = g_strdup (yytext + strlen ("#define "));
	  }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 1361 "scannerparser.y"
    {
		if ((yyvsp[(2) - (2)].symbol)->const_int_set || (yyvsp[(2) - (2)].symbol)->const_double_set || (yyvsp[(2) - (2)].symbol)->const_string != NULL) {
			(yyvsp[(2) - (2)].symbol)->ident = (yyvsp[(1) - (2)].str);
			gi_source_scanner_add_symbol (scanner, (yyvsp[(2) - (2)].symbol));
			gi_source_symbol_unref ((yyvsp[(2) - (2)].symbol));
		}
	  }
    break;



/* Line 1806 of yacc.c  */
#line 3916 "scannerparser.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, YY_("syntax error"));
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
        yyerror (scanner, yymsgp);
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
		      yytoken, &yylval, scanner);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
		  yystos[yystate], yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, scanner);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 1376 "scannerparser.y"

static void
yyerror (GISourceScanner *scanner, const char *s)
{
  /* ignore errors while doing a macro scan as not all object macros
   * have valid expressions */
  if (!scanner->macro_scan)
    {
      fprintf(stderr, "%s:%d: %s in '%s' at '%s'\n",
	      scanner->current_filename, lineno, s, linebuf, yytext);
    }
}

static int
eat_hspace (FILE * f)
{
  int c;
  do
    {
      c = fgetc (f);
    }
  while (c == ' ' || c == '\t');
  return c;
}

static int
eat_line (FILE * f, int c)
{
  while (c != EOF && c != '\n')
    {
      c = fgetc (f);
    }
  if (c == '\n')
    {
      c = fgetc (f);
      if (c == ' ' || c == '\t')
        {
          c = eat_hspace (f);
        }
    }
  return c;
}

static int
read_identifier (FILE * f, int c, char **identifier)
{
  GString *id = g_string_new ("");
  while (g_ascii_isalnum (c) || c == '_')
    {
      g_string_append_c (id, c);
      c = fgetc (f);
    }
  *identifier = g_string_free (id, FALSE);
  return c;
}

void
gi_source_scanner_parse_macros (GISourceScanner *scanner, GList *filenames)
{
  GError *error = NULL;
  char *tmp_name = NULL;
  FILE *fmacros =
    fdopen (g_file_open_tmp ("gen-introspect-XXXXXX.h", &tmp_name, &error),
            "w+");
  g_unlink (tmp_name);

  GList *l;
  for (l = filenames; l != NULL; l = l->next)
    {
      FILE *f = fopen (l->data, "r");
      int line = 1;

      GString *define_line;
      char *str;
      gboolean error_line = FALSE;
      int c = eat_hspace (f);
      while (c != EOF)
        {
          if (c != '#')
            {
              /* ignore line */
              c = eat_line (f, c);
              line++;
              continue;
            }

          /* print current location */
          str = g_strescape (l->data, "");
          fprintf (fmacros, "# %d \"%s\"\n", line, str);
          g_free (str);

          c = eat_hspace (f);
          c = read_identifier (f, c, &str);
          if (strcmp (str, "define") != 0 || (c != ' ' && c != '\t'))
            {
              g_free (str);
              /* ignore line */
              c = eat_line (f, c);
              line++;
              continue;
            }
          g_free (str);
          c = eat_hspace (f);
          c = read_identifier (f, c, &str);
          if (strlen (str) == 0 || (c != ' ' && c != '\t' && c != '('))
            {
              g_free (str);
              /* ignore line */
              c = eat_line (f, c);
              line++;
              continue;
            }
          define_line = g_string_new ("#define ");
          g_string_append (define_line, str);
          g_free (str);
          if (c == '(')
            {
              while (c != ')')
                {
                  g_string_append_c (define_line, c);
                  c = fgetc (f);
                  if (c == EOF || c == '\n')
                    {
                      error_line = TRUE;
                      break;
                    }
                }
              if (error_line)
                {
                  g_string_free (define_line, TRUE);
                  /* ignore line */
                  c = eat_line (f, c);
                  line++;
                  continue;
                }

              g_assert (c == ')');
              g_string_append_c (define_line, c);
              c = fgetc (f);

              /* found function-like macro */
              fprintf (fmacros, "%s\n", define_line->str);

              g_string_free (define_line, TRUE);
              /* ignore rest of line */
              c = eat_line (f, c);
              line++;
              continue;
            }
          if (c != ' ' && c != '\t')
            {
              g_string_free (define_line, TRUE);
              /* ignore line */
              c = eat_line (f, c);
              line++;
              continue;
            }
          while (c != EOF && c != '\n')
            {
              g_string_append_c (define_line, c);
              c = fgetc (f);
              if (c == '\\')
                {
                  c = fgetc (f);
                  if (c == '\n')
                    {
                      /* fold lines when seeing backslash new-line sequence */
                      c = fgetc (f);
                    }
                  else
                    {
                      g_string_append_c (define_line, '\\');
                    }
                }
            }

          /* found object-like macro */
          fprintf (fmacros, "%s\n", define_line->str);

          c = eat_line (f, c);
          line++;
        }

      fclose (f);
    }

  rewind (fmacros);
  gi_source_scanner_parse_file (scanner, fmacros);
}

gboolean
gi_source_scanner_parse_file (GISourceScanner *scanner, FILE *file)
{
  g_return_val_if_fail (file != NULL, FALSE);

  const_table = g_hash_table_new_full (g_str_hash, g_str_equal,
				       g_free, (GDestroyNotify)gi_source_symbol_unref);

  lineno = 1;
  yyin = file;
  yyparse (scanner);

  g_hash_table_destroy (const_table);
  const_table = NULL;

  yyin = NULL;

  return TRUE;
}

gboolean
gi_source_scanner_lex_filename (GISourceScanner *scanner, const gchar *filename)
{
  lineno = 1;
  yyin = fopen (filename, "r");

  while (yylex (scanner) != YYEOF)
    ;

  fclose (yyin);

  return TRUE;
}

