#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

extern int sym[26];
extern int yydebug;

int yyparse(void);
void yyerror(char *s);

#endif // _CALCULATOR_H_
