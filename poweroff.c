#include "types.h"
#include "user.h"

char *argv[] = { "sh", 0 };

int
main()
{
	int pid, wpid;

	printf(1, "poweroff: saving seed\n");
	pid = fork();
	if (pid < 0)
		printf(1, "poweroff: fork failed\n");
	if (pid == 0) {
		exec("saveseed", argv);
		printf(1, "poweroff: exec saveseed failed\n");
	}
	while ((wpid = wait()) >= 0 && wpid != pid)
		printf(1, "zombie!\n");
	printf(1, "poweroff: save done\n");
	printf(1, "powering off...\n");

	halt();
	exit();
}
