/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "microC.y"

    #define _GNU_SOURCE
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <assert.h>
    #include "listaSimbolos.h"
    #include "listaCodigo.h"

    extern int yylex();
    extern int yylineno;
    extern int errores;
    int numCadena = 1;
    int contador_etiq = 1;
    void yyerror(const char *msg);
    void comprobar_division(ListaC expre);
    // Lista de simbolos
    Lista l;
    void declarar_id(char *id, Tipo t);
    void imprimirLS(Lista l);
    void declarar_cadena(char *cadena, Tipo t);
    void verificar_id(char *id);
    // Variable para determinar si el id es VAR o CONST
    Tipo t;
    // Lista de codigo
    ListaC codigoTotal;
    bool registros[10];
    void inicializarRegs();
    char *obtenerReg();
    void liberarReg(char *reg);
    ListaC expresion_num(char *num);
    ListaC expresion_id(char *id);
    ListaC expresion_bin(char *op, ListaC expr1, ListaC expr2);
    ListaC expresion_neg(ListaC expr);
    char *nuevaEtiqueta();
    void imprimirLC(ListaC codigo);
    ListaC statement_while(ListaC expr, ListaC stat);
    


#line 113 "microC.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "microC.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PYC = 3,                        /* ";"  */
  YYSYMBOL_IDE = 4,                        /* "identifier"  */
  YYSYMBOL_IGU = 5,                        /* "="  */
  YYSYMBOL_SUM = 6,                        /* "+"  */
  YYSYMBOL_RES = 7,                        /* "-"  */
  YYSYMBOL_COI = 8,                        /* "{"  */
  YYSYMBOL_COD = 9,                        /* "}"  */
  YYSYMBOL_PAI = 10,                       /* "("  */
  YYSYMBOL_PAD = 11,                       /* ")"  */
  YYSYMBOL_PRI = 12,                       /* "print"  */
  YYSYMBOL_COM = 13,                       /* ","  */
  YYSYMBOL_CAD = 14,                       /* "cadena"  */
  YYSYMBOL_MUL = 15,                       /* "*"  */
  YYSYMBOL_VOI = 16,                       /* "void"  */
  YYSYMBOL_VAR = 17,                       /* "var"  */
  YYSYMBOL_CON = 18,                       /* "const"  */
  YYSYMBOL_INT = 19,                       /* "int"  */
  YYSYMBOL_IFF = 20,                       /* "if"  */
  YYSYMBOL_ELS = 21,                       /* "else"  */
  YYSYMBOL_DO = 22,                        /* "do"  */
  YYSYMBOL_WHI = 23,                       /* "while"  */
  YYSYMBOL_REA = 24,                       /* "read"  */
  YYSYMBOL_DIV = 25,                       /* "/"  */
  YYSYMBOL_MNR = 26,                       /* "<"  */
  YYSYMBOL_MYR = 27,                       /* ">"  */
  YYSYMBOL_MNI = 28,                       /* "<="  */
  YYSYMBOL_MYI = 29,                       /* ">="  */
  YYSYMBOL_IG2 = 30,                       /* "=="  */
  YYSYMBOL_DES = 31,                       /* "!="  */
  YYSYMBOL_NUM = 32,                       /* "number"  */
  YYSYMBOL_SIGNO = 33,                     /* SIGNO  */
  YYSYMBOL_NOELSE = 34,                    /* NOELSE  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_38_2 = 38,                      /* $@2  */
  YYSYMBOL_body = 39,                      /* body  */
  YYSYMBOL_declaration = 40,               /* declaration  */
  YYSYMBOL_41_3 = 41,                      /* $@3  */
  YYSYMBOL_42_4 = 42,                      /* $@4  */
  YYSYMBOL_tipo = 43,                      /* tipo  */
  YYSYMBOL_id_list = 44,                   /* id_list  */
  YYSYMBOL_id_decl = 45,                   /* id_decl  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_statement_list = 47,            /* statement_list  */
  YYSYMBOL_print_list = 48,                /* print_list  */
  YYSYMBOL_print_item = 49,                /* print_item  */
  YYSYMBOL_read_list = 50,                 /* read_list  */
  YYSYMBOL_expression = 51                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   115,   113,   133,   134,   135,   138,   138,
     139,   139,   142,   145,   146,   151,   154,   171,   184,   187,
     188,   189,   191,   192,   193,   196,   199,   202,   203,   208,
     227,   248,   268,   270,   274,   275,   276,   278,   279,   281,
     282,   283,   284,   285,   286,   287,   288,   289
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\";\"",
  "\"identifier\"", "\"=\"", "\"+\"", "\"-\"", "\"{\"", "\"}\"", "\"(\"",
  "\")\"", "\"print\"", "\",\"", "\"cadena\"", "\"*\"", "\"void\"",
  "\"var\"", "\"const\"", "\"int\"", "\"if\"", "\"else\"", "\"do\"",
  "\"while\"", "\"read\"", "\"/\"", "\"<\"", "\">\"", "\"<=\"", "\">=\"",
  "\"==\"", "\"!=\"", "\"number\"", "SIGNO", "NOELSE", "$accept",
  "program", "$@1", "$@2", "body", "declaration", "$@3", "$@4", "tipo",
  "id_list", "id_decl", "statement", "statement_list", "print_list",
  "print_item", "read_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-22)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,     4,    -6,   -22,    20,   -22,    16,    19,    21,   -22,
     179,    27,   -22,   -22,    36,   -22,   -22,    37,    48,    38,
      40,   -22,   -22,    12,   186,     1,    42,    42,    12,    39,
      12,    59,   -22,    12,    13,   -22,    51,   -22,   -22,   -22,
     -10,   -22,   144,   -22,    60,    60,    78,    55,    85,   -22,
      14,   -22,    56,   111,   -22,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    70,     1,    69,    15,   -22,
      18,    48,    12,    48,    72,    82,   -22,   -22,    34,    34,
     -22,   -22,   151,   151,   151,   151,   151,   151,   -22,   -22,
      12,   -22,    60,   -22,    66,   118,   -22,   -22,   -22,   144,
     -22,    48,    87,   -22,   -22
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     0,     0,     0,     7,
       0,     0,    26,     4,     0,     8,    10,     0,     0,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,    37,     0,    18,    25,    30,
       0,    27,    29,    12,     0,     0,     0,     0,     0,    31,
       0,    40,     0,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,    13,
       0,     0,     0,     0,     0,     0,    47,    39,    33,    34,
      35,    36,    41,    42,    43,    44,    45,    46,    22,    28,
       0,     9,     0,    11,    20,     0,    21,    23,    32,    16,
      14,     0,     0,    19,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,    61,    49,
       3,   -18,   -22,   -22,    31,   -22,   -21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    10,    21,    26,    27,    44,    68,
      69,    22,    24,    40,    41,    50,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      29,    65,    36,    66,     3,    32,    38,    46,    33,    48,
       4,    34,    51,    53,    52,    39,    32,    32,    91,    33,
      33,    93,    34,    34,     5,    74,     7,    75,    92,     9,
       8,    92,    23,    35,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    35,    35,    25,    28,    30,    57,
      31,    95,    11,    94,    54,    96,    12,    55,    56,    58,
      14,    43,    47,    49,    67,    72,    57,    76,    17,    99,
      18,    19,    20,    88,    90,    97,    58,    59,    60,    61,
      62,    63,    64,   103,    55,    56,    98,   101,    45,    71,
     104,    55,    56,    57,    70,   100,    73,    89,     0,     0,
      57,     0,     0,    58,    59,    60,    61,    62,    63,    64,
      58,    59,    60,    61,    62,    63,    64,    55,    56,     0,
       0,     0,    77,     0,    55,    56,    57,     0,     0,   102,
       0,     0,     0,    57,     0,     0,    58,    59,    60,    61,
      62,    63,    64,    58,    59,    60,    61,    62,    63,    64,
      55,    56,     0,     0,     0,     0,     0,    55,    56,    57,
       0,     0,     0,     0,     0,     0,    57,     0,     0,    58,
      59,    60,    61,    62,    63,    64,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    11,     0,     0,     0,    12,    13,     0,
      11,    14,     0,     0,    12,    37,    15,    16,    14,    17,
       0,    18,    19,    20,     0,     0,    17,     0,    18,    19,
      20
};

static const yytype_int8 yycheck[] =
{
      18,    11,    23,    13,     0,     4,    24,    28,     7,    30,
      16,    10,    33,    34,     1,    14,     4,     4,     3,     7,
       7,     3,    10,    10,     4,    11,    10,    13,    13,     8,
      11,    13,     5,    32,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    32,    32,    10,    10,    10,    15,
      10,    72,     4,    71,     3,    73,     8,     6,     7,    25,
      12,    19,    23,     4,     4,    10,    15,    11,    20,    90,
      22,    23,    24,     3,     5,     3,    25,    26,    27,    28,
      29,    30,    31,   101,     6,     7,     4,    21,    27,    11,
       3,     6,     7,    15,    45,    92,    11,    66,    -1,    -1,
      15,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      25,    26,    27,    28,    29,    30,    31,     6,     7,    -1,
      -1,    -1,    11,    -1,     6,     7,    15,    -1,    -1,    11,
      -1,    -1,    -1,    15,    -1,    -1,    25,    26,    27,    28,
      29,    30,    31,    25,    26,    27,    28,    29,    30,    31,
       6,     7,    -1,    -1,    -1,    -1,    -1,     6,     7,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    25,    26,    27,    28,
      29,    30,    31,     4,    -1,    -1,    -1,     8,     9,    -1,
       4,    12,    -1,    -1,     8,     9,    17,    18,    12,    20,
      -1,    22,    23,    24,    -1,    -1,    20,    -1,    22,    23,
      24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,     0,    16,     4,    38,    10,    11,     8,
      39,     4,     8,     9,    12,    17,    18,    20,    22,    23,
      24,    40,    46,     5,    47,    10,    41,    42,    10,    46,
      10,    10,     4,     7,    10,    32,    51,     9,    46,    14,
      48,    49,    51,    19,    43,    43,    51,    23,    51,     4,
      50,    51,     1,    51,     3,     6,     7,    15,    25,    26,
      27,    28,    29,    30,    31,    11,    13,     4,    44,    45,
      44,    11,    10,    11,    11,    13,    11,    11,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,     3,    49,
       5,     3,    13,     3,    46,    51,    46,     3,     4,    51,
      45,    21,    11,    46,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    37,    38,    36,    39,    39,    39,    41,    40,
      42,    40,    43,    44,    44,    45,    45,    46,    46,    46,
      46,    46,    46,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     9,     2,     2,     0,     0,     5,
       0,     5,     1,     1,     3,     1,     3,     4,     3,     7,
       5,     5,     5,     5,     7,     2,     0,     1,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     1,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* $@1: %empty  */
#line 113 "microC.y"
          { l = creaLS();
            codigoTotal = creaLC(); }
#line 1504 "microC.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 115 "microC.y"
                  { if(strcmp((yyvsp[0].str), "main") != 0){
                printf("Error en línea %d: %s es un id de programa incorrecto\n", yylineno, (yyvsp[0].str));
                errores++;
                    }
                  }
#line 1514 "microC.tab.c"
    break;

  case 4: /* program: $@1 "void" "identifier" $@2 "(" ")" "{" body "}"  */
#line 121 "microC.y"
          {
            if (errores == 0){
               imprimirLS(l);
               imprimirLC(codigoTotal);
               
            }else{
                printf("\nErrores semanticos: %d\n", errores);
            }
            liberaLS(l); 
          }
#line 1529 "microC.tab.c"
    break;

  case 5: /* body: body declaration  */
#line 133 "microC.y"
                        { concatenaLC(codigoTotal, (yyvsp[0].codigo)); }
#line 1535 "microC.tab.c"
    break;

  case 6: /* body: body statement  */
#line 134 "microC.y"
                        { concatenaLC(codigoTotal, (yyvsp[0].codigo)); }
#line 1541 "microC.tab.c"
    break;

  case 7: /* body: %empty  */
#line 135 "microC.y"
                        { (yyval.codigo) = creaLC(); }
#line 1547 "microC.tab.c"
    break;

  case 8: /* $@3: %empty  */
#line 138 "microC.y"
                  { t = VARIABLE; }
#line 1553 "microC.tab.c"
    break;

  case 9: /* declaration: "var" $@3 tipo id_list ";"  */
#line 138 "microC.y"
                                                    { (yyval.codigo) = (yyvsp[-1].codigo); }
#line 1559 "microC.tab.c"
    break;

  case 10: /* $@4: %empty  */
#line 139 "microC.y"
                  { t = CONSTANTE; }
#line 1565 "microC.tab.c"
    break;

  case 11: /* declaration: "const" $@4 tipo id_list ";"  */
#line 139 "microC.y"
                                                      { (yyval.codigo) = (yyvsp[-1].codigo); }
#line 1571 "microC.tab.c"
    break;

  case 12: /* tipo: "int"  */
#line 142 "microC.y"
              { (yyval.str) = "int"; }
#line 1577 "microC.tab.c"
    break;

  case 13: /* id_list: id_decl  */
#line 145 "microC.y"
                  { (yyval.codigo) = (yyvsp[0].codigo); }
#line 1583 "microC.tab.c"
    break;

  case 14: /* id_list: id_list "," id_decl  */
#line 146 "microC.y"
                              { (yyval.codigo) = (yyvsp[-2].codigo);
                            concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                            liberaLC((yyvsp[0].codigo)); }
#line 1591 "microC.tab.c"
    break;

  case 15: /* id_decl: "identifier"  */
#line 151 "microC.y"
              {
            declarar_id((yyvsp[0].str), t);
            (yyval.codigo) = creaLC(); }
#line 1599 "microC.tab.c"
    break;

  case 16: /* id_decl: "identifier" "=" expression  */
#line 154 "microC.y"
                             {
            declarar_id((yyvsp[-2].str),t);
            (yyval.codigo) = creaLC();
            if(errores == 0){
                // Generar codigo para la asignacion
                (yyval.codigo) = (yyvsp[0].codigo);
                Operacion o;
                o.op = "sw";
                o.res = recuperaResLC((yyvsp[0].codigo));
                asprintf(&(o.arg1), "_%s", (yyvsp[-2].str));
                o.arg2 = NULL;
                insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                liberarReg(o.res);
            }
        }
#line 1619 "microC.tab.c"
    break;

  case 17: /* statement: "identifier" "=" expression ";"  */
#line 171 "microC.y"
                                   { verificar_id((yyvsp[-3].str));
                                     // Verificacion temporal
                                     if (errores == 0){
                                        (yyval.codigo) = (yyvsp[-1].codigo);
                                        Operacion o;
                                        o.op = "sw";
                                        o.res = recuperaResLC((yyvsp[-1].codigo));
                                        asprintf(&(o.arg1), "_%s", (yyvsp[-3].str));
                                        o.arg2 = NULL;
                                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                                        liberarReg(o.res);
                                     }
                                     concatenaLC(codigoTotal,(yyvsp[-1].codigo));   }
#line 1637 "microC.tab.c"
    break;

  case 18: /* statement: "{" statement_list "}"  */
#line 184 "microC.y"
                                   { if(errores == 0){
                                        (yyval.codigo) = (yyvsp[-1].codigo); 
                                     } }
#line 1645 "microC.tab.c"
    break;

  case 19: /* statement: "if" "(" expression ")" statement "else" statement  */
#line 187 "microC.y"
                                                               { }
#line 1651 "microC.tab.c"
    break;

  case 20: /* statement: "if" "(" expression ")" statement  */
#line 188 "microC.y"
                                                           { }
#line 1657 "microC.tab.c"
    break;

  case 21: /* statement: "while" "(" expression ")" statement  */
#line 189 "microC.y"
                                                 { (yyval.codigo) = statement_while((yyvsp[-2].codigo),(yyvsp[0].codigo)); 
                                        /*concatenaLC(codigoTotal, $$);*/ }
#line 1664 "microC.tab.c"
    break;

  case 22: /* statement: "print" "(" print_list ")" ";"  */
#line 191 "microC.y"
                                           { (yyval.codigo) = (yyvsp[-2].codigo); }
#line 1670 "microC.tab.c"
    break;

  case 23: /* statement: "read" "(" read_list ")" ";"  */
#line 192 "microC.y"
                                         { (yyval.codigo) = (yyvsp[-2].codigo); }
#line 1676 "microC.tab.c"
    break;

  case 24: /* statement: "do" statement "while" "(" expression ")" ";"  */
#line 193 "microC.y"
                                                          { }
#line 1682 "microC.tab.c"
    break;

  case 25: /* statement_list: statement_list statement  */
#line 196 "microC.y"
                                          { (yyval.codigo) = (yyvsp[-1].codigo);
                                            concatenaLC((yyval.codigo), (yyvsp[0].codigo));
                                            liberaLC((yyvsp[0].codigo)); }
#line 1690 "microC.tab.c"
    break;

  case 26: /* statement_list: %empty  */
#line 199 "microC.y"
                        { (yyval.codigo) = creaLC(); }
#line 1696 "microC.tab.c"
    break;

  case 27: /* print_list: print_item  */
#line 202 "microC.y"
                        { (yyval.codigo) = (yyvsp[0].codigo); }
#line 1702 "microC.tab.c"
    break;

  case 28: /* print_list: print_list "," print_item  */
#line 203 "microC.y"
                                       { (yyval.codigo) = (yyvsp[-2].codigo);
               concatenaLC((yyval.codigo), (yyvsp[0].codigo));
               liberaLC((yyvsp[0].codigo)); }
#line 1710 "microC.tab.c"
    break;

  case 29: /* print_item: expression  */
#line 208 "microC.y"
                        { if(errores == 0){
                                (yyval.codigo) = (yyvsp[0].codigo);
                                Operacion o;
                                o.op = "li";
                                o.res = "$v0";
                                o.arg1 = "1";
                                o.arg2 = NULL;
                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                                o.op = "move";
                                o.res = "$a0";
                                o.arg1 = recuperaResLC((yyvsp[0].codigo));
                                o.arg2 = NULL;
                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                                o.op = "syscall";
                                o.res = o.arg1 = o.arg2 = NULL;
                                insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                                liberarReg(recuperaResLC((yyvsp[0].codigo)));
                            }
              }
#line 1734 "microC.tab.c"
    break;

  case 30: /* print_item: "cadena"  */
#line 227 "microC.y"
                 { declarar_cadena((yyvsp[0].str),CADENA); 
                    if(errores == 0){
                        (yyval.codigo) = creaLC();
                        Operacion o;
                        o.op = "li";
                        o.res = "$v0";
                        o.arg1 = "4";
                        o.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                        o.op = "la";
                        o.res = "$a0";
                        asprintf(&(o.arg1), "$str%d", numCadena-1);
                        o.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                        o.op = "syscall";
                        o.res = o.arg1 = o.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                    }
                 }
#line 1758 "microC.tab.c"
    break;

  case 31: /* read_list: "identifier"  */
#line 248 "microC.y"
                { verificar_id((yyvsp[0].str)); 
                    if(errores == 0){
                        (yyval.codigo) = creaLC();
                        Operacion o;
                        o.op = "li";
                        o.res = "$v0";
                        o.arg1 = "5";
                        o.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                        o.op = "syscall";
                        o.res = o.arg1 = o.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                        o.op = "sw";
                        asprintf(&(o.res), "_%s", (yyvsp[0].str));
                        o.arg1 = "$v0";
                        o.arg2 = NULL;
                        insertaLC((yyval.codigo), finalLC((yyval.codigo)), o);
                        concatenaLC(codigoTotal, (yyval.codigo));
                    }
                 }
#line 1783 "microC.tab.c"
    break;

  case 32: /* read_list: read_list "," "identifier"  */
#line 268 "microC.y"
                              { verificar_id((yyvsp[0].str)); }
#line 1789 "microC.tab.c"
    break;

  case 33: /* expression: expression "+" expression  */
#line 270 "microC.y"
                                       { (yyval.codigo) = expresion_bin("add", (yyvsp[-2].codigo), (yyvsp[0].codigo));
                                        
                                        
                                        }
#line 1798 "microC.tab.c"
    break;

  case 34: /* expression: expression "-" expression  */
#line 274 "microC.y"
                                 { (yyval.codigo) = expresion_bin("sub", (yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1804 "microC.tab.c"
    break;

  case 35: /* expression: expression "*" expression  */
#line 275 "microC.y"
                                 { (yyval.codigo) = expresion_bin("mul", (yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1810 "microC.tab.c"
    break;

  case 36: /* expression: expression "/" expression  */
#line 276 "microC.y"
                                 { comprobar_division((yyvsp[0].codigo));
                                   (yyval.codigo) = expresion_bin("div", (yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1817 "microC.tab.c"
    break;

  case 37: /* expression: "number"  */
#line 278 "microC.y"
           { (yyval.codigo) = expresion_num((yyvsp[0].str)); }
#line 1823 "microC.tab.c"
    break;

  case 38: /* expression: "identifier"  */
#line 279 "microC.y"
           { verificar_id((yyvsp[0].str));
             (yyval.codigo) = expresion_id((yyvsp[0].str)); }
#line 1830 "microC.tab.c"
    break;

  case 39: /* expression: "(" expression ")"  */
#line 281 "microC.y"
                           { (yyval.codigo) = (yyvsp[-1].codigo); }
#line 1836 "microC.tab.c"
    break;

  case 40: /* expression: "-" expression  */
#line 282 "microC.y"
                                    { (yyval.codigo) = expresion_bin("neg", (yyvsp[0].codigo), NULL); }
#line 1842 "microC.tab.c"
    break;

  case 41: /* expression: expression "<" expression  */
#line 283 "microC.y"
                                    { }
#line 1848 "microC.tab.c"
    break;

  case 42: /* expression: expression ">" expression  */
#line 284 "microC.y"
                                    { }
#line 1854 "microC.tab.c"
    break;

  case 43: /* expression: expression "<=" expression  */
#line 285 "microC.y"
                                    { }
#line 1860 "microC.tab.c"
    break;

  case 44: /* expression: expression ">=" expression  */
#line 286 "microC.y"
                                    { }
#line 1866 "microC.tab.c"
    break;

  case 45: /* expression: expression "==" expression  */
#line 287 "microC.y"
                                    { }
#line 1872 "microC.tab.c"
    break;

  case 46: /* expression: expression "!=" expression  */
#line 288 "microC.y"
                                    { }
#line 1878 "microC.tab.c"
    break;

  case 47: /* expression: "(" error ")"  */
#line 289 "microC.y"
                      { }
#line 1884 "microC.tab.c"
    break;


#line 1888 "microC.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 292 "microC.y"


// Accion que se ejecuta al detectar un error sintáctico y suma el contador de errores
void yyerror(const char *msg){
    printf("Error sintáctico en línea %d: %s\n", yylineno, msg);
    errores++;
}

// Accion que comprueba si la division tiene como denominador un 0 y suma el contador de errores
void comprobar_division(ListaC expre){
    if (expre == 0){
        printf("División por 0 en línea %d\n", yylineno);
        errores++;
    }
}

// Accion que declara un id en la tabla de simbolos, comprobando que no haya sido declarado previamente
void declarar_id(char *id, Tipo t){
     PosicionLista p = buscaLS(l, id);
     if(p != finalLS(l)){
          printf("Error en linea %d: variable %s redeclarada\n", yylineno, id);
          errores++;
     }else{
          Simbolo s;
          s.nombre = id;
          s.valor = 0;
          s.tipo = t;
          insertaLS(l, finalLS(l),s);
     }
}

void declarar_cadena(char *cadena, Tipo t){
    PosicionLista p = buscaLS(l, cadena);
    if(p != finalLS(l)){
    }else{
        PosicionLista p = buscaLS(l, cadena);
        Simbolo s;
        s.nombre = cadena;
        s.valor = numCadena++;
        s.tipo = t;
        insertaLS(l, finalLS(l),s);
    }
}

char *nuevaEtiqueta(){
    char *aux;
    asprintf(&aux, "$l%d", contador_etiq++);
    return aux;
}



void imprimirLS(Lista l){
     printf("##################\n");
     printf("# Seccion de datos\n");
     printf("    .data\n\n");
     PosicionLista p = inicioLS(l);

         // cadenas
    p = inicioLS(l);
    while (p != finalLS(l)) {
        Simbolo aux = recuperaLS(l, p);
        if(aux.tipo == CADENA){
            printf("$str%d:\n    .asciiz %s\n", aux.valor, aux.nombre);
        }
        p = siguienteLS(l, p);
    }
    p = inicioLS(l);
    while (p != finalLS(l)) {
        Simbolo aux = recuperaLS(l, p);
        if(aux.tipo == VARIABLE || aux.tipo == CONSTANTE){
            printf("_%s:\n    .word %d\n", aux.nombre, aux.valor);
        }
        p = siguienteLS(l, p);
    }
    printf("\n");
}

void verificar_id(char *id){
    PosicionLista p = buscaLS(l, id);
    if(p == finalLS(l)){
        printf("Error en línea %d: variable '%s' no declarada\n", yylineno, id);
        errores++;
    } else {
        Simbolo s = recuperaLS(l, p);
        if(s.tipo == CONSTANTE){
            printf("Error en línea %d: '%s' es una constante\n", yylineno, id);
            errores++;
        }
    }
}

void inicializarRegs(){
    for(int i = 0; i < 10; i++){
        registros[i] = false;
    }
}

char *obtenerReg(){
    // Buscar registro $tX libre
    for(int i = 0; i < 10; i++){
        if(registros[i] == false){
            registros[i] = true;
            char *reg;
            asprintf(&reg, "$t%d", i);
            return reg;
        }
    }
    printf("Error: registros agotados!\n");
    exit(1);
}

void liberarReg(char *reg){
    // reg == $tX
    assert(reg[0] == '$');
    assert(reg[1] == 't');
    int index = (reg[2]) - '0';
    assert(index >= 0);
    assert(index <= 9);
    registros[index] = false;

}

ListaC expresion_num(char *num){
    ListaC codigo = creaLC();
    Operacion o;
    o.op = "li";
    o.res = obtenerReg();
    o.arg1 = num;
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    guardaResLC(codigo, o.res);
    return codigo;
}

ListaC expresion_id(char *id){
    ListaC codigo = creaLC();
    Operacion o;
    o.op = "lw";
    o.res = obtenerReg();
    asprintf(&(o.arg1), "_%s", id);
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    guardaResLC(codigo, o.res);
    return codigo;
}

ListaC expresion_bin(char *op, ListaC expr1, ListaC expr2){
    ListaC codigo = expr1;
    Operacion o;
    o.op = op;
    o.res = recuperaResLC(expr1);
    o.arg1 = recuperaResLC(expr1);
    if(expr2 != NULL){
        concatenaLC(codigo, expr2);
        o.arg2 = recuperaResLC(expr2);
        liberarReg(o.arg2);
        liberaLC(expr2);
    } else {
        o.arg2 = NULL;
    }
    insertaLC(codigo, finalLC(codigo), o);
    return codigo;
}

ListaC statement_while(ListaC expr, ListaC stat){  
    char *etiq_inicio = nuevaEtiqueta();
    char *etiq_fin = nuevaEtiqueta();
    Operacion o;
    o.op = etiq_inicio;
    o.res = o.arg1 = o.arg2 = NULL;
    ListaC codigo = creaLC();
    insertaLC(codigo, finalLC(codigo), o);
    concatenaLC(codigo, expr);
    o.op = "beqz";
    o.res = recuperaResLC(expr);
    o.arg1 = etiq_fin;
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    concatenaLC(codigo, stat);
    o.op = "b";
    o.res = etiq_inicio;
    o.arg1 = NULL;
    o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    o.op = etiq_fin;
    o.res = o.arg1 = o.arg2 = NULL;
    insertaLC(codigo, finalLC(codigo), o);
    liberarReg(recuperaResLC(expr));
    //liberaLC(expr);
    //liberaLC(stat);
    return codigo;
}



void imprimirLC(ListaC codigo){
    printf("##################\n");
    printf("# Seccion de codigo\n");
    printf("    .text\n");
    printf("    .global main\n");
    printf("main:\n");
    PosicionListaC p = inicioLC(codigo);
    while (p != finalLC(codigo)) {
        Operacion oper = recuperaLC(codigo,p);
        if(oper.op[0] == '$'){
            // Etiqueta de salto
            printf("%s:\n", oper.op);   // ✅ Usa el nombre real de la etiqueta
            p = siguienteLC(codigo, p); // ✅ Avanza el puntero
        }else{
            printf("    %s",oper.op);
            if (oper.res) printf(" %s",oper.res);
            if (oper.arg1) printf(",%s",oper.arg1);
            if (oper.arg2) printf(",%s",oper.arg2);
            printf("\n");
            p = siguienteLC(codigo,p);
        }
  }
    printf("    li $v0, 10\n");
    printf("    syscall\n");
}
