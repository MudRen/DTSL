
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ɽ��");
  set ("long", @LONG
������һ������ɽ�ŵ�ɽ·����������˲��Ǻܶ࣬���ܴ����ܲ���
�ʻ��̲��������֣�����ɽ���ﴵ����������磬������������������
һЩ�����Ļ��㡣
LONG);

  set("exits", ([ 
"northdown":__DIR__"guanlu4",
"southup":__DIR__"shandao1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_jump","jump");
	
}

int do_jump(string arg)
{
   object ob;
   
   ob=this_player();
   
   if(!arg) return 0;
   if(arg!="ya"&&arg!="��") return 0;
   
   message_vision("$N����ɽ������ȥ��\n",ob);
   
   ob->move("/d/clone/room/iron/room2");
   
   return 1;
   
}