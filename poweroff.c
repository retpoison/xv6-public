#include "types.h"
#include "user.h"

char *argv[] = { "sh", 0 };

int
main()
{
	printf(1, "powering off...\n");

	halt();
	exit();
}
