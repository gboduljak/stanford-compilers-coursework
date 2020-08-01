/*
 *  The scanner definition for COOL.
 */
/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%option noyywrap

%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>
#include <stdlib.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */

int comment_depth = 0;
int should_terminate = 0;
int in_nested_comment = 0;
int string_const_length = 0;

%}

%x NESTED_COMMENT
%x SIMPLE_COMMENT
%x STRING_CONSTANT
%x ESCAPE

/*
 * Define names for regular expressions here.
 */
DIGIT               [0-9]
LOWERCASE_LETTER    [a-z]
UPPERCASE_LETTER    [A-Z]
LETTER              ({LOWERCASE_LETTER}|{UPPERCASE_LETTER})
BLANK               (" "|\f|\r|\t|\v)
OPERATOR            ("+"|"-"|"*"|\/)
SINGLE_CHAR_TOKEN   ("~"|"<"|"="|"("|")"|"{"|"}"|";"|":"|"."|","|"@")

CLASS       (?i:class)
ELSE        (?i:else)
FI          (?i:fi)
IF          (?i:if)
IN          (?i:in)
INHERITS    (?i:inherits)
LET         (?i:let)
LOOP        (?i:loop)
POOL        (?i:pool)
THEN        (?i:then)
WHILE       (?i:while)
CASE        (?i:case)
ESAC        (?i:esac)
OF          (?i:of)
NEW         (?i:new)
ISVOID      (?i:isvoid)
NOT         (?i:not)

INT_CONST   {DIGIT}+
BOOL_CONST_TRUE  (t)(?i:rue)
BOOL_CONST_FALSE (f)(?i:alse)
TYPEID      ("SELF_TYPE"|{UPPERCASE_LETTER}({LETTER}|{DIGIT}|"_")*)
OBJECTID    ("self"|{LETTER}({LETTER}|{DIGIT}|"_")*)
DARROW      "=>"
LE          "<="
ASSIGN      "<-"

NESTED_COMMENT_START   "\(\*"
NESTED_COMMENT_END     "\*\)"
SIMPLE_COMMENT_START   "--"
SIMPLE_COMMENT_END     "--"

STR_CONST_START            \"
STR_CONST_END              \"
%%

 /*
  * Keywords
  */
  
{CLASS}     return (CLASS);
{ELSE}      return (ELSE);
{FI}        return (FI);
{IF}        return (IF);
{IN}        return (IN);
{INHERITS}  return (INHERITS);
{LET}       return (LET);
{LOOP}      return (LOOP);
{POOL}      return (POOL);
{THEN}      return (THEN);
{WHILE}     return (WHILE);
{CASE}      return (CASE);
{ESAC}      return (ESAC);
{OF}        return (OF);
{NEW}       return (NEW);
{ISVOID}    return (ISVOID);
{NOT}       return (NOT);
{DARROW}    return (DARROW);
{ASSIGN}	  return (ASSIGN);
{LE}		    return (LE);

 /*
  *  Nested comments
  */

{NESTED_COMMENT_START} { comment_depth++; BEGIN(NESTED_COMMENT); in_nested_comment = 1; }
<NESTED_COMMENT>{NESTED_COMMENT_START} { comment_depth++; }
<NESTED_COMMENT>{NESTED_COMMENT_END} {
  comment_depth--;

  if (comment_depth < 0) {
    cool_yylval.error_msg = "Unmatched *)";
	  return (ERROR);
  }

  if (comment_depth == 0) {
    in_nested_comment = 0;
    BEGIN(INITIAL);
  }
}
<NESTED_COMMENT><<EOF>> {
    if (should_terminate)
      yyterminate();
      
    cool_yylval.error_msg = "EOF in comment";
    should_terminate = 1;
    return (ERROR);
}
<NESTED_COMMENT>\n        { curr_lineno++; }
<NESTED_COMMENT>.         {  }

{NESTED_COMMENT_END} {
  if (!in_nested_comment) {
    cool_yylval.error_msg = "Unmatched *)";
	  return (ERROR);
  }
}

 /*
  *  Simple comments
  */

{SIMPLE_COMMENT_START} { BEGIN(SIMPLE_COMMENT); }
<SIMPLE_COMMENT>\n        { curr_lineno++; BEGIN(INITIAL); }
<SIMPLE_COMMENT>.         {  }


 /*
  *  String tokens
  */

{STR_CONST_START}  { BEGIN(STRING_CONSTANT); }
<STRING_CONSTANT>{STR_CONST_END} {
  string_buf_ptr = (char*) &string_buf;
  cool_yylval.symbol = idtable.add_string(string_buf_ptr, string_const_length);
  string_const_length = 0;
  BEGIN(INITIAL);
  return (STR_CONST);
}
<STRING_CONSTANT><<EOF>> {
    if (should_terminate)
      yyterminate();
      
    cool_yylval.error_msg = "EOF in string constant";
    should_terminate = 1;
    return (ERROR);
}
<STRING_CONSTANT>\0 {
  	cool_yylval.error_msg = "String contains null character";
    string_const_length = 0;
		BEGIN(ESCAPE);
		return ERROR;
}
<STRING_CONSTANT>\n {
  	cool_yylval.error_msg = "Unterminated string constant";
    string_const_length = 0;
    curr_lineno++;
	  BEGIN(INITIAL);
		return ERROR;
}
<STRING_CONSTANT>"\\n" {
    if (string_const_length + 1< MAX_STR_CONST) {
      string_buf[string_const_length++] = '\n'; 
    } 
    else {
      cool_yylval.error_msg = "String constant too long";
      string_const_length = 0;
      BEGIN(ESCAPE);
      return (ERROR); 
    }
}
<STRING_CONSTANT>"\\t" {
    if (string_const_length + 1 < MAX_STR_CONST) {
      string_buf[string_const_length++] = '\t'; 
    } 
    else {
      cool_yylval.error_msg = "String constant too long";
      string_const_length = 0;
      BEGIN(ESCAPE);
      return (ERROR); 
    }
}
<STRING_CONSTANT>"\\b" {
    if (string_const_length + 1 < MAX_STR_CONST) {
      string_buf[string_const_length++] = '\b'; 
    } 
    else {
      cool_yylval.error_msg = "String constant too long";
      string_const_length = 0;
      BEGIN(ESCAPE);
      return (ERROR); 
    }
}
<STRING_CONSTANT>"\\f" {
    if (string_const_length + 1 < MAX_STR_CONST) {
      string_buf[string_const_length++] = '\f'; 
    } 
    else {
      cool_yylval.error_msg = "String constant too long";
      string_const_length = 0;
      BEGIN(ESCAPE);
      return (ERROR); 
    }
}
<STRING_CONSTANT>"\\"[^\0] {
    if (string_const_length + 1 < MAX_STR_CONST) {
      string_buf[string_const_length++] = yytext[1]; 
    } 
    else {
      cool_yylval.error_msg = "String constant too long";
      string_const_length = 0;
      BEGIN(ESCAPE);
      return (ERROR); 
    }
}
<STRING_CONSTANT>. {
    if (string_const_length + 1 < MAX_STR_CONST ) {
      string_buf[string_const_length++] = yytext[0];
    }
    else {
      cool_yylval.error_msg = "String constant too long";
        string_const_length = 0;

      BEGIN(ESCAPE);
      return (ERROR); 
    }
}

<ESCAPE>[\n|"]	 { BEGIN(INITIAL);  }
<ESCAPE>[^\n|"]	 { }


 /*
  * Single character tokens
  */
  
{SINGLE_CHAR_TOKEN} { return (int)(yytext[0]); }
{OPERATOR} { return (int)(yytext[0]); }

 /*
  * Bool constant
  */
{BOOL_CONST_TRUE} {
	cool_yylval.boolean = true;
	return (BOOL_CONST);
}
{BOOL_CONST_FALSE} {
	cool_yylval.boolean = false;
	return (BOOL_CONST);
}

 /*
  * Int constant
  */

{INT_CONST} {
  cool_yylval.symbol = idtable.add_string(yytext);
  return (INT_CONST);
}

 /*
  * TypeId constant
  */

{TYPEID} {
  cool_yylval.symbol = idtable.add_string(yytext);
  return (TYPEID);
}

{OBJECTID} {
  cool_yylval.symbol = idtable.add_string(yytext);
  return (OBJECTID);
}

 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */


 /*
  * Line tracking
  */
\n	 { curr_lineno++; }
{BLANK}+ {}


 /*
  * Error match
  */
.		{
			cool_yylval.error_msg = yytext;
			return (ERROR);
		}

%%
