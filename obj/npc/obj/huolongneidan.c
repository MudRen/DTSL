

#include <ansi.h>

inherit ITEM;


void create()
{
	set_name(HIR"火龙"HIY"内丹"NOR, ({ "huolong neidan" }) );
	set("unit", "个");
	set("long","这是一个火龙内丹，据说可以克制长生诀的冷内劲。\n");
	set("rumor",1);
	seteuid(getuid());
}

