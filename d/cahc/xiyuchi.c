
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�ڲ�����ӳ�£������������ؾ���������ĬĬ�ط�ӳ�ų���������
װ����̨¥���ϻ������������˼��ɾ����������������ۣ�����
��żפ��Զ���ƻ���㣬������Ӱө�⣬�����ѱ档 
LONG);

  set("exits", ([ 
 "eastup":__DIR__"ganludian",
 "west":__DIR__"tongmingmen",
        ]));
   set("outdoors","changan");
   set("valid_startroom", 1);
  setup();
 
}