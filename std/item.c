// item.c

#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

void setup()
{
	seteuid(getuid());
}
int is_get_of(object player,object ob)
{
  return 1;
}
int is_wield_of(object player,object ob)
{
  return 1;
}
int is_wear_of(object player,object ob)
{
  return 1;
}