
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"��ʯ·"NOR);
  set ("long", @LONG
������һ����ʯ·�ϡ�ֻ��Զ�������о�������������ƽ�����ȶ�
���ң�������ľ�����쳣���Ա߷���һ����¯����������İ��̣���
������еĺ����˼��ɾ�һ�㡣
LONG);

  set("exits", ([ 

  "north":__DIR__"huayuan",
  "out":__DIR__"door",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","jingzhai");
  
  set("valid_startroom", 1);
  setup();
 
}
int valid_leave(object ob,string dir)
{
  if(ob->query("family/family_name")=="�Ⱥ���ի"&&dir=="out"
   &&ob->query("combat_exp")<100000)
       return notify_fail("��Ĺ���̫��΢�ˣ�������իԺ������һ��ʱ���ڳ�ȥ�ɣ�\n");
  return ::valid_leave(ob,dir);
}    
