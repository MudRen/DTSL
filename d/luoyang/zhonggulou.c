
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"�ӹ�¥"NOR);
  set ("long", @LONG
���ӹ�¥����������ǧ��  ���ˮ����������̫ƽ����˵�������
�����һλ��ʿ��������������ΰ���ӹ�¥���ߣ���������Ѿ�������
�����꣬��ϧʱ�ֻ��ң���֪��ʲôʱ�������������̫ƽ��
LONG);

  set("exits", ([ 
  
	  "east":__DIR__"baihujie2",
	  "up":__DIR__"zhulou",
         ]));
  set("objects",([
  __DIR__"npc/houxibai":1,
  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object ob,string dir)
{
  if(ob->query("family/family_name")!="������"&&
     dir=="up")
  return notify_fail("ֻ�л����ɲſ�����ȥ��\n");
  if(ob->query("pker"))
  return notify_fail("ͨ�������ǲ�Ҫ��ȥ�ˣ�\n");
  return ::valid_leave(ob,dir);
}

