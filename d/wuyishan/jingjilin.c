
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"������"NOR);
  set ("long", @LONG
���ߵ��˾������У����ﾣ��ïʢ��ÿ��һ�����кܴ��Σ�գ���
����ҪС���ˡ�
LONG);

  set("exits", ([ 

   "northeast":__DIR__"shanlu5",
             ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object ob,string dir)
{
  if(userp(ob)&&dir=="northeast"&&ob->query_skill("dodge",1)<100)
  {
     message_vision(HIR"$N��������������������һ�£�\n"NOR,ob);
     ob->receive_wound("kee",600);
     return notify_fail("���۵��߲����ˣ�\n");
     
  }
  message_vision("$N����һԽ�������Ǳ���������һ�£�\n",ob);
  ob->receive_wound("kee",400);
  return ::valid_leave(ob,dir);
}