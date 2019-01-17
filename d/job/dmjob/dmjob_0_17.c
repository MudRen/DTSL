/*
 * File    : ·ÉÌìÁë (/u/yanyan/dmjob/dmjob_0_17.c)
 * Author  : [1;37mÕæ±ùºÓ[2;37;0m(yanyan@´óÌÆË«Áú  )
 * Date    : Thu Oct 18 11:38:33 2001
 */
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "·ÉÌìÁë");
        set("long", @LONG
ÕâÀïÊÇÆÁ·çÉ½µÄ·ÉÌìÁëÁË¡£ÄÏ±ßÊÇÒ»×ùÉ½·å¡£¶«±ßÓĞÒ»×ùĞüÑÂ¡£Õâ
ÀïµØÊÆºÜ¸ß£¬¿ÉÒÔ¿´µ½Õû¸öÆÁ·çÉ½µÄ¾°É«¡£µ±Ìì¿ÕÇçÀÊÖ®Ê±£¬¼¸ºõ¿ÉÒÔ
ÓÃÊÖÀ´´¥ÃşÌì¿Õ¡£¾İËµ´ËÁëÊÇÏÉÈËÊ©Õ¹·¨Êõ°áÀ´£¬ËùÒÔÃüÃûÎª·ÉÌìÁë¡£
ÕâÀïÓĞÒ»¿é´óÊ¯Í·£¬ËÆºõ¿ÉÒÔÔÒÒ»ÏÂ¡£
LONG
);
        set("exits",([
	"southwest" : __DIR__"dmjob_2_15",
	"eastdown" : __DIR__"dmjob_2_19",
	"east" : __DIR__"dmjob_0_19",
        ]));
set("outdoors","dmjob");
        setup();
//        replace_program(ROOM);
}

void init()
{
   add_action("do_ci","za");
}

int do_ci(string arg)
{
   object me,weapon;
   me=this_player();
   if(!arg||arg!="Ê¯Í·")
   return notify_fail("ÄãÒªßÆÊ²Ã´£¿\n");
   if(!objectp(weapon=me->query_temp("weapon")))
   return notify_fail("Ã»ÓĞÎäÆ÷£¬ÄãÒªÓÃÊÖÔÒÂğ£¿\n");
   if(weapon->query("skill_type")!="hammer")
   return notify_fail("Äã»Ó¶¯"+weapon->name()+"»ÎÁË¼¸ÏÂ£¬·¢ÏÖºÁÎŞÓÃ´¦£¡\n");
   if(weapon->query("flag")==1)
   return notify_fail("Äã¾ÚÉ¥µÄ·¢ÏÖÊÖÖĞµÄ±øÈĞÒÑ¾­¶ÏµôÁË£¡\n");
   if(me->query("sen")<20)
   return notify_fail("Äã¾«ÉñÌ«²îÁË£¡\n");
   if(me->query_skill("hammer",1)>=101)
   return notify_fail("ÄãµÄ»ù±¾´¸·¨ºÜ¸ßÁË£¬ÔÚÕâÀïÒÑ¾­ÎŞ·¨Ìá¸ßÁË£¡\n");
   if(me->is_busy())
   return notify_fail("ÄãÕıÃ¦×ÅÄØ£¡\n");
   
   message_vision(YEL"$N´óº°Ò»Éù£¬»ÓÎè×ÅÊÖÖĞµÄ"+weapon->name()+"³¯Ê¯Í·ÔÒÈ¥£¡\n"NOR,me);
   me->improve_skill("hammer",me->query_int()/2+20+random(5));
   me->add("sen",-20);
   if(me->query_skill("hammer",1)<50)
   message_vision("$N±»ÕğµÄºóÍËÁË¼¸²½¡£\n",me);
   else if(me->query_skill("hammer",1)<100)
   message_vision("Ö»ÌıÅöµÄÒ»Éù£¬Ê¯Í·±»$NÔÒ³öÒ»¸ö´ó¿Ó¡£\n",me);
   else if(me->query_skill("hammer",1)<150)
   message_vision("Ö»ÌıÅöµÄÒ»Éù£¬Ê¯Í·±»$NÔÒµÃÁÑ³öµÀ³¤ÎÆ£¡\n",me);
  
   return 1;
}
