
inherit ROOM;
#include <ansi.h>
int do_enter(string arg);
void create()
{
	set("short", HIB"��ɽ��"NOR);
	set("long", @LONG
�����Ǽ�ɽ�Ķ��С��Ĵ��ںڵģ�������ָ����ʪ�������˽����
���С����￴������ɭ�ֲ����㲻��С��������
LONG);
	set("exits", ([
		"out":__DIR__"jiashan",
			]));
 if(sizeof(children(__DIR__"obj/qingmingjian"))<2)
      set("objects",([
		  __DIR__"obj/qingmingjian":1,
		  ]));
       set("valid_startroom", 1);   
set("no_clean_up",1);
       set("outdoors", "��ʯ·");  
	setup();
       
       
}

