
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit ROOM;

void create ()
{
  set ("short",HIY"�Ͻ��"NOR);
  set ("long", @LONG
������ǻʵ�ÿ�쳯�����Ͻ���ˡ���������ׯ�����¡��������
�Եý�̻Իͣ����ľ�ͷ�����������õ������ӱ����ˡ���������
�������ߴ�����ӣ����������Ž��������ӵ����ߴ���һЩ��ɴ�����
������վ�ں�ߣ������Ż��ϵİ�ȫ��
LONG);

  set("exits", ([ 
  "east":__DIR__"dongdian",
  "west":__DIR__"xidian",
  "out":__DIR__"shijie1",
         ]));

  set("objects",([
   __DIR__"npc/gongnv1":1,
   __DIR__"npc/taijian1":1,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

