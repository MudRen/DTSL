
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangbei"
#define TO __DIR__"jiangnan"
#include "/std/shiproom.c";
#include <job_money.h>

void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����ǳ����ı��������˳������͵��˺��ϵľ����ˡ���ǰ��ˮ��
����ֻ��һҶ���۰ڶ����������ˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaolu2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

