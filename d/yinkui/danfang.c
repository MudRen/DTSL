
#include <ansi.h>
inherit ROOM;
int do_search();

void create ()
{
  set ("short","����");
  set ("long", @LONG
�����������ɵĵ�������������Ϊ������һ��а�ɣ��ٲ���Ҫʹ��
д���Ŷ�ҩ�������Ķ���������������������ƶ�ҩ�ĵط���ֻ������
�������ƣ�͸©��һ�ɹ�������ա�
LONG);
  set("exits",([
	  "south":__DIR__"qingshilu5",
	  ]));

 
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_search","search");
}

int do_search()
{
   object ob,obj;
   
   ob=this_player();
   
   if(ob->is_busy())
   return notify_fail("����æ���أ�\n");
   message_vision("$N��������������\n",ob);
   
   obj=new(__DIR__"obj/yao");
   obj->move(ob);
   tell_object(ob,"��Ū��һ�㶫����\n");
   ob->start_busy(1+random(2));
   return 1;
}