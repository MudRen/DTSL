
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ͷ");
  set ("long", @LONG
���������������ı�����ͷ���ܶ��̴�ͣ�������ϻ����»����ŷ���
ǰǰ���æ�Ĳ����ֺ�����˵�������ڱ��ոս��볤��û��õ�ͬ�����
���ˣ��Ӷ������˹��д��ɣ����������Ĳ�����
LONG);

  set("exits", ([ 
 "west":__DIR__"tongxingshe",
       ]));
       
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

