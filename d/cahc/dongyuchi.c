
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�ڲ�����ӳ�£������Ķ����ؾ���������ĬĬ�ط�ӳ�ų���������
װ����̨¥���ϻ������������˼��ɾ����������������ۣ�����
��żפ��Զ���ƻ���㣬������Ӱө�⣬�����ѱ档 
LONG);

  set("exits", ([ 
 "north":__DIR__"ningbige",
 "east":__DIR__"tongxunmen",
 "westup":__DIR__"ganludian",
        ]));
   set("outdoors","changan");
   set("valid_startroom", 1);
  setup();
 
}