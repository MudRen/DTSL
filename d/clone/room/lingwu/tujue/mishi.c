
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIB"����"NOR);
  set ("long", @LONG
������һ�����ң����ܺڶ����ģ��������κγ��ڡ�������
����ľ���ƺ��Ǻ�ɫ����ɫ����ɫ��
LONG);
 set("objects",([
   __DIR__"horse1":1,
   __DIR__"horse2":1,
   __DIR__"horse3":1,
   ]));
 set("valid_startroom", 1);
  setup();
 
}
