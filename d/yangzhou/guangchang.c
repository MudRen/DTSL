
#include <ansi.h>
inherit ROOM;

int do_wa();
int do_pao();
int do_dig();
void create ()
{
  set ("short","������");
  set ("long", @LONG
���������ݳǵı������ˡ����������ݾ�ɫ��Ϊ�����ĵط�������
�ۼ�������ĺ������ǡ����ݱ����ǽ�ͨ����Ŧ���ټ������̻�ʤ�أ�
���Խ����ĺ��Ͷ�Ҫ�������䣬����ʾ�Լ���Ӣ�۱�ɫ�����������
˵���ķ�Ҫ������Ѱ�����־���[������]����Ū���������Ļ̡̻�
LONG);

  set("exits", ([ 
// "northeast":"/d/clone/room/paimai/paimaiwu",
 "east":__DIR__"guangchang1",
 "southwest":__DIR__"xihudi4",
 "northeast":__DIR__"beidajie1",
// "up":"u/kouzhong/chatroom",

        ]));
  set("objects",([
	  __DIR__"npc/yan":1,
	  __DIR__"npc/gongzi":1,
	  "/d/clone/npc/liguan":1,
	 // "/u/chris/xunbao/baiwutong":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();

}

int valide_leave(object ob,string dir)
{
  if(dir=="northeast"&&!userp(ob))
   return 0;
  
  return ::valid_leave(ob,dir);
}

void init()
{
  add_action("do_wa","wa",);
  add_action("do_pao","pao");
  add_action("do_dig","dig");
}
int do_wa()
{
  object ob;
  object thing;
  ob=this_player();
  if(ob->query("sen")<=0)
  return notify_fail("�㾫��ƣ�������������ˣ�\n");
  if(ob->is_busy())
  return notify_fail("��Ķ���û���\n");
  ob->add("sen",-1);
  ob->start_busy(1);
  if(random(40)!=11){
  message_vision(CYN"$N�ſ���ָ���ݺݵ�������ȥ��\n"NOR,ob);
  return 1;}
  thing=new(__DIR__"obj/thing");
  thing->create_name();
  if(thing->query("name")=="��Կ��"){
      if(random(100)>90)	
      thing->set_weight(100);
  }
  thing->move(environment(ob));
  message_vision(CYN"$NͻȻ�ڵ�һ"+thing->query("unit")+thing->name()+"!\n"NOR,ob);
  return 1;
}
int do_pao()
{
  object ob;
  object thing;
  object weapon;
  ob=this_player();
  if(ob->query("sen")<=0)
  return notify_fail("�㾫��ƣ�������������ˣ�\n");
  if(!ob->query_temp("weapon"))
  return notify_fail("������������\n");
  weapon=ob->query_temp("weapon");
  if(weapon->query("skill_type")!="staff")
  return notify_fail("��ʹ�õ��������ԣ�\n");
  if(ob->is_busy())
  return notify_fail("��Ķ���û���\n");
  ob->add("sen",-1);
  ob->start_busy(1);
  if(random(40)!=11){
  message_vision(CYN"$N����"+weapon->name()+",�����Ϻݺ���ȥ��\n"NOR,ob);
  return 1;}
  thing=new(__DIR__"obj/thing");
  thing->create_name();
  thing->move(environment(ob));
  message_vision(CYN"$NͻȻ�ٵ�һ"+thing->query("unit")+thing->name()+"!\n"NOR,ob);
  return 1;
}
int do_dig()
{
  object ob;
  object thing;
  object weapon;
  ob=this_player();
  if(ob->query("sen")<=0)
  return notify_fail("�㾫��ƣ�������������ˣ�\n");
  if(!ob->query_temp("weapon"))
  return notify_fail("������������\n");
  weapon=ob->query_temp("weapon");
  if(weapon->query("skill_type")!="sword"&&
     weapon->query("skill_type")!="blade"&&
     weapon->query("skill_type")!="dagger")
  return notify_fail("��ʹ�õ��������ԣ�\n");
  if(ob->is_busy())
  return notify_fail("��Ķ���û���\n");
  ob->add("sen",-1);
  ob->start_busy(1);
  if(random(40)!=11){
  message_vision(CYN"$N����"+weapon->name()+",�����Ϻݺ���ȥ��\n"NOR,ob);
  return 1;}
  thing=new(__DIR__"obj/thing");
  thing->create_name();
  thing->move(environment(ob));
  message_vision(CYN"$NͻȻ�ڵ�һ"+thing->query("unit")+thing->name()+"!\n"NOR,ob);
  return 1;
}
