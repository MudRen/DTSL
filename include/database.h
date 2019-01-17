// database.h

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <mudlib.h>

static string DB_HOST       = "localhost";
static string DB_USER       = "cqmud";
static string DB_NAME       = INTERMUD_MUD_NAME + "_mud";

static string WEB_DB_HOST   = "localhost";
static string WEB_DB_USER   = "cqmud";
static string WEB_DB_NAME   = "discuz";

static int ROW_LIMIT        = 10;

#define BBS_FORUMS     "forums"
#define BBS_THREADS    "threads"
#define BBS_POSTS      "posts"
#define BBS_MEMBERS    "members"

#endif
