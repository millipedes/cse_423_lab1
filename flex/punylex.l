%option noinput nounput nodefault noyywrap yylineno

%{
#include <string.h>
#include "../main/include/constants_macros.h"
#include "../token/include/token_type.h"
#include "../stack/include/stack.h"

stack * indent_stack = NULL;

int update_stack(size_t value);
%}
%%

'(\\.|''|[^'\n])*' |
\"(\\.|\"\"|[^\"\n])*\"         { return STRING; }

<<EOF>>                         { return ENDMARKER; }
[\n\v\f\r][ ]+                  { return update_stack(strnlen(yytext,
                                           MAX_LEXEME_SIZE)); }
[\n\v\f\r]/[A-Za-z][A-Za-z0-9_]+ { return update_stack(strnlen(yytext,
                                           MAX_LEXEME_SIZE)); }
[ \n\v\f\r]

#.*                             { return COMMENT; }


"False"                         { return FALSE; }
"none"                          { return NONE; }
"True"                          { return TRUE; }
"and"                           { return AND; }
"as"                            { return AS; }
"assert"                        { return ASSERT; }
"break"                         { return BREAK; }
"class"                         { return CLASS; }
"continue"                      { return CONTINUE; }
"def"                           { return DEF; }
"del"                           { return DEL; }
"elif"                          { return ELIF; }
"else"                          { return ELSE; }
"except"                        { return EXCEPT; }
"finally"                       { return FINALLY; }
"for"                           { return FOR; }
"from"                          { return FROM; }
"if"                            { return IF; }
"import"                        { return IMPORT; }
"in"                            { return IN; }
"is not"                        { return IS_NOT; }
"is"                            { return IS; }
"lambda"                        { return LAMBDA; }
"nonlocal"                      { return NONLOCAL; }
"not in"                        { return NOT_IN; }
"not"                           { return NOT; }
"or"                            { return OR; }
"global"                        { return GLOBAL; }
"raise"                         { return RAISE; }
"return"                        { return RETURN; }
"try"                           { return TRY; }
"while"                         { return WHILE; }
"with"                          { return WITH; }
"yield"                         { return YIELD; }
"pass"                          { return PASS; }
[A-Za-z][A-Za-z0-9_]*           { return NAME; }

-?[0-9]+                        { return INT; }

-?[0-9]"."?                     |
-?"."[0-9]+                     |
-?[0-9]+"."[0-9]+               { return REAL; }

[\t]                            { return INDENT; }
"("                             { return LPAR; }
")"                             { return RPAR; }
"["                             { return LSQB; }
"]"                             { return RSQB; }
":"                             { return COLON; }
","                             { return COMMA; }
";"                             { return SEMI; }
"+"                             { return PLUS; }
"-"                             { return MINUS; }
"*"                             { return STAR; }
"/"                             { return SLASH; }
"|"                             { return VBAR; }
"&"                             { return AMPER; }
"<"                             { return LESS; }
">"                             { return GREATER; }
"="                             { return EQUAL; }
"."                             { return DOT; }
"%"                             { return PERCENT; }
"{"                             { return LBRACE; }
"}"                             { return RBRACE; }
"=="                            { return EQEQUAL; }
"!="                            { return NOTEQUAL; }
"<="                            { return LESSEQUAL; }
">="                            { return GREATEREQUAL; }
"~"                             { return TILDE; }
"^"                             { return CIRCUMFLEX; }
"<<"                            { return LEFTSHIFT; }
">>"                            { return RIGHTSHIFT; }
"**"                            { return DOUBLESTAR; }
"+="                            { return PLUSEQUAL; }
"-="                            { return MINEQUAL; }
"*="                            { return STAREQUAL; }
"/="                            { return SLASHEQUAL; }
"%="                            { return PERCENTEQUAL; }
"&="                            { return AMPEREQUAL; }
"|="                            { return VBAREQUAL; }
"^="                            { return CIRCUMFLEXEQUAL; }
"<<="                           { return LEFTSHIFTEQUAL; }
">>="                           { return RIGHTSHIFTEQUAL; }
"**="                           { return DOUBLESTAREQUAL; }
"//"                            { return DOUBLESLASH; }
"//="                           { return DOUBLESLASHEQUAL; }
"@"                             { return AT; }
"@="                            { return ATEQUAL; }
"->"                            { return RARROW; }
"..."                           { return ELLIPSIS; }
":="                            { return COLONEQUAL; }

%%

int update_stack(size_t value) {
  void * v_value = calloc(1, sizeof(int));
  INT_CAST(v_value) = (int)value;
  if(!indent_stack) {
    INT_CAST(v_value) = 0;
    indent_stack = init_stack(v_value);
    return INDENT;
  } else if(INT_STACK_LT(indent_stack, v_value)) {
    indent_stack = push(indent_stack, v_value);
    return INDENT;
  } else if(INT_STACK_GT(indent_stack, v_value)) {
    indent_stack = pop(indent_stack);
    free(v_value);
    return DEDENT;
  } else if(INT_STACK_CMP(indent_stack, v_value)) {
    free(v_value);
    return NODENT;
  } else {
    fprintf(stderr, "[UPDATE_STACK]: Error\n");
    exit(1);
  }
}
