
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ӫ");
  set ("long", @LONG
�����ǳ������־��ı�Ӫ���ٱ������佫��ָ�����жӲ���������
��ô����û��ս�£��ٱ��ǻ��������������ʿ���ǲ������κ���и��
����ɲ��������˵����ĵط�������û��ǸϿ��뿪��
LONG);

  set("exits", ([ 
 "east":__DIR__"csdajie2",
       ]));
  set("objects",([
	  __DIR__"npc/bing2":2,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

