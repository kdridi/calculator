#include "calculator.h"

int main(void)
{
    int ch;
    
    ch = 'a';
    while (ch <= 'z')
        sym[ch++ - 'a'] = 0;
    
    yydebug = 0;
    char string[] =
        "a=10+2*5\n"
        "b=99*a+a\n"
        "a\n"
        "b\n"
        "c\n"
        "";
    
    YY_BUFFER_STATE buffer = yy_scan_string(string);
    yyparse();
    yy_delete_buffer(buffer);
    
    return (0);
}
