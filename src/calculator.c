	
#include "calculator.h"

int main(void)
{
	int ch;

	ch = 'a';
	while (ch <= 'z')
		sym[ch++ - 'a'] = 0;

	yyparse();

	return (0);
}
