
#include <ansi.h>
#include <org.h>

inherit ROOM;

void create ()
{
  set ("short","�׻���");
  set ("long", @LONG
��������߸��İ׻��ã�����ƽʱ���ر����ء������ȥ����߸�
Ӣ������Ϣ����ϰ�书�ĵط���ֻ�����治�ϴ��������������û�л�
������ɣ��㲻�ǲ��ܽ�ȥ�ġ�
LONG);

  set("exits", ([ 
 "enter":__DIR__"changlang1",
 "west":"/d/cahc/tiancedian",
      ]));
  set("objects",([
   "/d/clone/room/orgsaferoom/npc/huwei":2,
  ]));
  set("valid_startroom", 1);
  set("shili/name","lifa_b");
  setup();
 
}

int valid_leave(object ob,string dir)
{
  if(present("orgsafe_guard",environment(ob))
    &&dir=="enter"
    &&!ORG_D->if_friend_org(ob,this_object())
    &&ob->query("shili/name")!=query("shili/name"))
  return notify_fail("����һ����ס�㣺�㲻�Ǳ�������Ա�����ǲ�Ҫ��ȥ�ĺã�\n");
  
  return 1;
  
}
  