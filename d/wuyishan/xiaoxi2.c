
#include <ansi.h>
inherit ROOM;

int do_tiao(string arg);
void create ()
{
  set ("short","СϪ");
  set ("long", @LONG
������һ��СϪ����������СϪ������ɽ���ˡ��Ա���һ�����񷤣�
�����Ѿ����������ˣ���֪������ȥ����ʲô�����
LONG);

  set("exits", ([ 

   "south":__DIR__"shulin4",
 
          ]));
set("objects",([
 "/d/clone/npc/beast/yetu":2,
 ]));
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_tiao","tiao");
}

int do_tiao(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="��")
  return notify_fail("����Ҫ����������\n");
  if(ob->is_busy())
  return notify_fail("����æ���أ�\n");
  if(ob->is_fighting())
  return notify_fail("���������أ�\n");
  if(ob->query_skill("dodge",1)>=101)
  return notify_fail("���������ûʲô��ͣ��������\n");
  if(ob->query("sen")<25)
  return notify_fail("�������������ͷ���ۻ���ͣ��������\n");
  ob->add("sen",-25);
  ob->improve_skill("dodge",ob->query_int()/2+ob->query_cor());
  if(ob->query_skill("dodge",1)<50)
  message_vision(YEL"$N�͵س������˹�ȥ������һ�����ȣ�ˤ����ˮ�У�\n"NOR,ob);
  else if(ob->query_skill("dodge",1)<100)
  message_vision(YEL"$N�͵س������˹�ȥ���񷤻��˼��Σ�����æԾ�ذ��ߣ�\n"NOR,ob);
  else if(ob->query_skill("dodge",1)<150)
  message_vision(YEL"$N�͵س������˹�ȥ��δ����ҡ�Σ��Ѿ�������Ծ�ذ��ߣ�\n"NOR,ob);
  return 1;
}
