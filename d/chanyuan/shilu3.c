
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ·");
  set ("long", @LONG
�����Ǵ��۱�����ʯ·����������Ժ�Ľ��أ�ƽʱ��׼���˽�ȥ
�ġ��о�������ͭ��֮�����ֻ��ʮ����Ĵ��������������ط���
���������Ӱ�����ָ���Ī�⣬���˲�������������龰��
LONG);

  set("exits", ([ 
	  "westup":__DIR__"daxiong-baodian",
	  "enter":__DIR__"tongdian",
  
         ]));
 
set("outdoors","chanyuan");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(dir=="east"&&(objectp(present("bu chi",environment(me)))||objectp(present("bu ju",environment(me))))&&!wizardp(me)
	   &&me->query("family/family_name")!="������Ժ")
		return notify_fail("ֻ��һ������������˵����ʩ��������!\n");
	return ::valid_leave(me,dir);
}

