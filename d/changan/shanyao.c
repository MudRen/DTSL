
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ɽ��");
  set ("long", @LONG
���ߵ�������ɽ�İ�ɽ�������������ǰ����·�Ե�û����ȴͻȻ
�䷢��û��·�ˣ��ò�ɨ�ˡ������Ĵ���ȥ���������������һ����ͤ��
ʹ�㲻��������ǰȥ��Ϣһ�¡�
LONG);

  set("exits", ([ 
"northdown":__DIR__"shandao2",
"west":__DIR__"liangting",
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
