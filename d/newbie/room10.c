
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����ƪ");
  set ("long", @LONG
�����ǰ�ʦѧ�յĵ�һ����������Ҫʹ��  help menpai ���鿴��
�����鿴������ϸ�Ľ��ܣ�Ȼ���پ���Ͷ�뵽�ĸ����ɡ��ڴ������ǲ�
������ʦ�ģ�����Ҫ����ѡ�񡣰�ʦ�������� bai������Ҫ�������ʦ
Ϊʦ������ʹ�� bai lao��ѧϰʦ���ļ����� xue�������ʹ�����ַ�
ʽ��ѧϰ��һ�� xue ʦ�� ���ܵ����֣����� xue ʦ�� �������� for
����������ʦ���ļ��ܣ������ʹ�� cha ʦ������������á�
LONG);

  set("exits", ([ 
 "east":__DIR__"room11",
 "west":__DIR__"room12",
 "north":__DIR__"room13",
 "south":__DIR__"room7",
        ]));
  
  set("objects",([
       __DIR__"npc/laoshi":1,
       ]));
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

