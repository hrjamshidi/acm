/*

 * fsdata_custom.c
 *
 *  Created on: Sep 10, 2020
 *      Author: User




 * fsdata_custom.c
 *
 * Created: 2/9/2018 9:23:18 AM
 *  Author: rico



#include "lwip/opt.h"
#include "lwip/def.h"
#include "fs.h"
#include "fsdata.h"
#include "ff.h"

#include <string.h>


-----------------------------------------------------------------------------------
int fs_open_custom(struct fs_file *file, const char *name)
{


	return 0;
}

-----------------------------------------------------------------------------------
void fs_close_custom(struct fs_file *file)
{


}

int fs_read_custom(struct fs_file *file, char *buffer, int count)
{
return 0;
}

void *FS_ROOT = NULL;
*/
extern struct fsdata_file *FS_ROOT;
