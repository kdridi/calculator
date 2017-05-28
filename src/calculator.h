#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

extern int sym[26];
extern int yydebug;

typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern int yyparse();
extern void yyerror(char *s);
extern YY_BUFFER_STATE yy_scan_string (char *str);
extern void yy_delete_buffer (YY_BUFFER_STATE buffer);

#endif // _CALCULATOR_H_
