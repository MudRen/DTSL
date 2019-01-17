/*
 * File    : ±¦½£É½ (/u/yanyan/dmjob/dmjob_6_3.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;
int do_cai(string arg);
void create()
{
	set("short", "±¦½£É½");
        set("long", @LONG
ÕâÀïÊÇÆÁ·çÉ½µÄ±¦½£É½¡£¾İËµÕâÀïµÄÌú¿ó·Ç³£ºÃ£¬ËùÒÔ¶«äéÅÉµÄµÜ
×Ó¿ÉÒÔ´òÔì³ö·Ç³£µÄ±øÆ÷¡£ÕâÀïµØÊÆÏÕÒª£¬É½ÑÂËÊÁ¢£¬ËÄÖÜÒ²ÊÇ´ç²İ²»
Éú¡£
LONG
);
        set("exits",([
	"northeast" : __DIR__"dmjob_4_5",
	"southwest" : __DIR__"dmjob_8_1",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}
void init()
{
	add_action("do_cai","kaicai");
}

int do_cai(string arg)
{
	object me,ob,tool;
	me=this_player();
	if(!arg||arg!="¿óÊ¯")
		return notify_fail("ÄãÏë¿ª²ÉÊ²Ã´£¿\n");
	if(!objectp(tool=me->query_temp("weapon")))
		return notify_fail("¿ÕÊÖÔõÃ´¿ª²É¿óÊ¯£¿\n");
	if(tool->query("skill_type")!="fork")
		return notify_fail("Äã»¹ÊÇÓÃ¸äÍ·¿ª²É°É£¡\n");
	if(me->is_busy())
		return notify_fail("ÄãÏÖÔÚºÜÃ¦£¬ĞªĞª°É!\n");
	if(me->is_fighting())
		return notify_fail("Äã»¹ÊÇÏÈ´òÍêÕÌÔÙËµ°É£¡\n");
	if(me->query("family/family_name")!="¶«äéÅÉ")
	return notify_fail("Ö»ÓĞ¶«äéÅÉµÄµÜ×Ó¿ÉÒÔÔÚÕâÀï¿ª²É¿óÊ¯£¡\n");
	if(me->query("combat_exp")<200000)
	return notify_fail("ÒÔÄãµÄÄÜÁ¦»¹²»¹»×Ê¸ñÔÚÕâÀï¿ª²É¡£\n");
	message_vision("$NÓÃ"+tool->name()+"¿ª²ÉÆğ¿óÊ¯À´¡£\n",me);
	me->receive_damage("sen",100+random(50));
	me->start_busy(3);
	if(random(9)>2)
	{ob=new("/obj/iron/iron");
	ob->move(me);
	message_vision("$N¿ª²É³öÒ»¿é"+ob->name()+"À´£¡\n",me);
	}
	else
	{
		message_vision("Í»È»Ò»¿é´ó¿óÊ¯´ÓÉ½ÉÏ¹öÁËÏÂÀ´£¡\nÖ±½ÓÔÒÏò$N!\n",me);
		if((int)me->query_skill("dodge",1)>=100&&random(100)>20)
		{
			message_vision("$N¼ûÊÆ²»ºÃ£¬Á¬Ã¦ÉÁÁË¿ªÀ´£¡\n",me);
            ob=new("/obj/iron/iron");
	        ob->move(me);
			return 1;
		}
		else
		{
			message_vision("$N±»¿óÊ¯ÔÒÁËÕıÖĞ£¡\n",me);
            ob=new("/obj/iron/iron");
	        ob->move(me);
			me->unconcious();
			return 1;
		}
	}
	return 1;
}