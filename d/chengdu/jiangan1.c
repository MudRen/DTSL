
#include <ansi.h>
#include <job_money.h>
inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangan1"
#define TO __DIR__"jiangan2"
#include "/std/shiproom.c";
void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����ǳ����ı��������˳������͵������ϵľ����ˡ���ǰ��ˮ��
����ֻ��һҶ���۰ڶ����������ˡ�
LONG);

  set("exits", ([ 

  "northeast":__DIR__"caodi1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

