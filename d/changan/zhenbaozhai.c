#include <ansi.h>
inherit ROOM;

int do_zuan(string arg);
void create ()
{
  set ("short","�䱦ի");
  set ("long", @LONG
����һ���䱦����ꡣ����������Ŀ�İڷ���һ������ֵ���ǵ���
�����档������Ŀ��Ͼ�ӣ��ۻ����ң��ϰ������д������Ĺ˿͡�
LONG);

  set("exits", ([ 
 "east":__DIR__"xishixijie1",
      ]));
  set("objects",([
         __DIR__"npc/zhubao-boss":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_zuan","zuan");
}
int do_zuan(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="�ص�")
  return notify_fail("ʲô��\n");
  message_vision("$NС�ĵ��˿�һ��ľ�壬���˽�ȥ��\n",ob);
  ob->move(__DIR__"didao1");
  return 1;
}
