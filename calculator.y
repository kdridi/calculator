%{
#include <stdio.h>

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int sym[26];
int yylex();
%}

%union {
	int number;
	int var;
};

%type <number> expression
%type <number> term
%type <number> factor

%token <var> VAR
%token <number> NUMBER

%%

prog
	: expressions
	;

expressions
	: expression '\n'     { printf("%d\n\n", $1); } expressions
	| /* NULL */
	;

expression
	: expression '+' term { $$ = $1 + $3; }
	| expression '-' term { $$ = $1 - $3; }
	| term
	;

term
	: term '*' factor     { $$ = $1 * $3; }
	| term '/' factor     { $$ = $1 / $3; }
	| factor
	;

factor
	: NUMBER
	| VAR                 { $$ = sym[$1]; }
	| '-' expression      { $$ = -$2; }
	| '(' expression ')'  { $$ = $2; }
	| VAR '=' expression  { sym[$1] = $3; $$ = $3; }
	;