#include "main.h"

#include <libsup/sup.h> /* all sup_**** functions */
#include <stdio.h> /* printf and perror */
#include <string.h> /* strncpy */
#include <sys/socket.h> /* socket and connect*/
#include <sys/un.h> /* sockaddr_un */
#include <unistd.h> /* sleep */
#include <stdlib.h> /* getenv */

const char *str_try = "Try:%s\n";
const char *str_fail = "%s failed with error code %i\n";
const char *str_success = "Request sent successfully.\n";

#define REQ_WAIT 1

int main(int argc, char **argv)
{
	/* Igni display socket */

	/* Socket descriptor */
	int fd;

	/* Address */
	struct sockaddr_un tmp_addr;

	/* ------------------- */

	/* Counters */
	int i;

	/* Error Code */
	int err;

	i = argc - 1;

	if (!i)
	{
		printf("No sockets listed. Nothing to test.\n");
		return 0;
	}

	while (i)
	{
		printf("Connecting to %s\n", argv[i]);

		fd = socket(AF_UNIX, SOCK_STREAM, 0);
		if (fd == -1)
		{
			perror("Failed to create socket");
			return -1;
		}

		printf("Socket descriptor: %i\n", fd);

		tmp_addr.sun_family = AF_UNIX;
		strncpy(tmp_addr.sun_path, argv[i], sizeof(tmp_addr.sun_path));

		printf("%s\n", tmp_addr.sun_path);

		if (connect(fd, (struct sockaddr*)&tmp_addr, sizeof(tmp_addr)) == -1)
		{
			perror("Failed to connect to server");
			exit(EXIT_FAILURE);
		}

		printf("Successfully connected.\n");

		sleep(REQ_WAIT);
	
		/* Configure Connection */
		printf(str_try, "sup_config(fd, 0)");
		err = sup_config(fd, 0);
		if (err) 
		{
			printf(str_fail, "sup_config(fd, 0)", err);
		}
		else 
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Load Asset */
		printf(str_try, "sup_asset_load(fd, 12, \"asset.obj\")");
		err = sup_asset_load(fd, 12, "asset.obj");
		if (err) 
		{
			printf(str_fail, "sup_asset_load(fd, 12, \"asset.obj\")", err);
		}
		else 
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Show Asset */
		printf(str_try, "sup_asset_show(fd, 12)");
		err = sup_asset_show(fd, 12);
		if (err) 
		{
			printf(str_fail, "sup_asset_show(fd, 12)", err);
		}
		else 
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Transform Asset */
		printf(str_try, "sup_asset_tform(fd, 12,\n\
	1.23, 4.56, 7.89,\n\
	98.7, 65.4, 32.1,\n\
	3.21, 6.54, 9.87)");

		err = sup_asset_tform(fd, 12,
				1.23, 4.56, 7.89,
				98.7, 65.4, 32.1,
				3.21, 6.54, 9.87
		);
		if (err)
		{
			printf(str_fail, "sup_asset_tform(fd, 12,\n\
	1.23, 4.56, 7.89,\n\
	98.7, 65.4, 32.1,\n\
	3.21, 6.54, 9.87)", err);
		}
		else 
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Load Action */
		printf(str_try, "sup_action_load(fd, 12, 34, \"Action\")");
		err = sup_action_load(fd, 12, 34, "Action");
		if (err) 
		{
			printf(str_fail, "sup_action_load(fd, 12, 34, \"Action\")", err);
		}
		else
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Set Action Frame */
		printf(str_try, "sup_action_set_frame(fd, 12, 34, 21)");
		err = sup_action_set_frame(fd, 34, 21);
		if (err) 
		{
			printf(str_fail, "sup_action_set_frame(fd, 12, 34, 21)", err);
		}
		else
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Set Action Weight */
		printf(str_try, "sup_action_set_weight(fd, 12, 34, 0.5f)");
		err = sup_action_set_weight(fd, 34, 0.5f);
		if (err) 
		{
			printf(str_fail, "sup_action_set_weight(fd, 12, 34, 0.5f)", err);
		}
		else
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Transform Viewpoint */
		printf(str_try, "sup_view_tform(fd,\n\
	1.23, 4.56, 7.89,\n\
	98.7, 65.4, 32.1)");

		err = sup_view_tform(fd,
				1.23, 4.56, 7.89,
				98.7, 65.4, 32.1
		);
		if (err)
		{
			printf(str_fail, "sup_view_tform(fd,\n\
	1.23, 4.56, 7.89,\n\
	98.7, 65.4, 32.1)", err);
		}
		else 
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Set Field of View */
		printf(str_try, "sup_view_set_fov(fd, 90.0)");
		err = sup_view_set_fov(fd, 90.0);
		if (err) 
		{
			printf(str_fail, "sup_view_set_fov(fd, 90.0)", err);
		}
		else
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Destroy Action */
		printf(str_try, "sup_action_destroy(fd, 34)");
		err = sup_action_destroy(fd, 34);
		if (err) 
		{
			printf(str_fail, "sup_action_destroy(fd, 34)", err);
		}
		else
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Hide Asset */
		printf(str_try, "sup_asset_hide(fd, 12)");
		err = sup_asset_hide(fd, 12);
		if (err)
		{
			printf(str_fail, "sup_asset_hide(fd, 12)", err);
		}
		else
		{
			printf(str_success);
		}

		sleep(REQ_WAIT);

		/* Destroy Asset */
		printf(str_try, "sup_asset_destroy(fd, 12)");
		err = sup_asset_destroy(fd, 12);
		if (err) 
		{
			printf(str_fail, "sup_asset_destroy(fd, 12)", err);
		}
		else 
		{
			printf(str_success);
		}

		/* Socket has been tested */
		printf("closing socket %i\n", fd);
		close(fd);

		--i;
	}

	return 0;
}

