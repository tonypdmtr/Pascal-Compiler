#include <stdio.h>

#include "backend-x86.c"
#include "encode.c"
#include "message.c"
#include "symtab.c"
#include "tree.c"
#include "types.c"
#include "utils.c"

FILE *errfp;		/* file to which message.c will write */

/* For debugging purposes only */
#ifdef YYDEBUG
extern int yydebug;
#endif

int main()
{
	int status, yyparse();

	errfp = stderr;
	ty_types_init();
	st_init_symtab();
	st_establish_data_dump_func(stdr_dump);
#ifdef YYDEBUG
	yydebug = 1;		/* DEBUG */
#endif
	status = yyparse();
	//st_dump();
	return status;
}
