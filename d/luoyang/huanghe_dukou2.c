
#include <ansi.h>
inherit ROOM;
#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huanghe_dukou2"
#define TO __DIR__"huanghe_dukou1"
#include "/std/shiproom.c";
void create ()
{
  set ("short","�ƺӶɿ�");
  set ("long", @LONG
�����ǻƺӵĶɿڡ���ǰ�ƺӹ��������ƾ��ˡ�ֻ��һҶ��������
�������ˡ��кܶ�����������˴����ǳ����֡����С��С���������
�����򼴽��Ǵ�չʾ�Լ��Ļ�������ļ๤���ڴ����Ű���Ĺ��ˣ�
�ߴٵ�����������
LONG);

  set("exits", ([ 

  "northeast":"/d/liyang/dadao9",
"northwest":"/d/taiyuan/sroad8",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

