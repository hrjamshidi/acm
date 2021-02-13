/*

 * fsdata_custom.c
 *
 *  Created on: Sep 10, 2020
 *      Author: User




 * fsdata_custom.c
 *
 * Created: 2/9/2018 9:23:18 AM
 *  Author: rico

*/

#include "lwip/opt.h"
#include "lwip/def.h"
#include "fs.h"
#include "fsdata.h"
#include "ff.h"

#include <string.h>

 char *data = "<html><head></head><body><h1>Welcome to ACAM Controller board v2.0</h1></body></html>";
 int size = 85;

int fs_open_custom(struct fs_file *file, const char *name)
{

    file->len = size;
    file->index = 0;

	return 1;
}


void fs_close_custom(struct fs_file *file)
{


}

int fs_read_custom(struct fs_file *file, char *buffer, int count)
{


    memcpy(buffer, data, count);
    file->index = count;
    //buffer = data;


	return size;
}

struct fsdata_file *FS_ROOT = NULL;

