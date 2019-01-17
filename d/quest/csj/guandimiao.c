inherit ROOM;
#include <ansi.h>
int do_zuan(string arg);
void create()
{
	set("short",HIR"���ǹص���"NOR);
	set("long", @LONG
���������ݵı��ǹص������������������������ǵĹص���
Ҫ�õĶࡣ���ǽ���������ң��������������Ҳ��Խ��Խ���ˡ�
LONG);
        set("exits",([
          "west":"/d/yangzhou/beidajie2",
          ]));
	setup();      
}
void init()
{
  object ob;
  add_action("do_zuan","zuan");
  ob=previous_object();
  if(ob->query_temp("dtsl_quest_csj/step3")&&
     !present("shi long")&&
     !present("yuwen huaji")&&
     !query("no_man")){
    set("no_man",1);
    call_out("do_fight",1,ob);}
   return;
}
void do_fight(object ob)
{
  object killer,victim;
  if(!ob){
  remove_call_out("do_fight");
  return;}
  killer=new(__DIR__"npc/yuwen-huaji");
  victim=new(__DIR__"npc/shilong");
  killer->move(environment(ob));
  victim->move(environment(ob));
  killer->kill_ob(victim);
  victim->kill_ob(killer);
  COMBAT_D->do_attack(killer,victim,0,0,2);
  COMBAT_D->do_attack(victim,killer,0,0,2);
  COMBAT_D->do_attack(killer,victim,0,0,2);
  COMBAT_D->do_attack(victim,killer,0,0,2);
  COMBAT_D->do_attack(killer,victim,0,0,2);
  COMBAT_D->do_attack(victim,killer,0,0,2);
  message_vision(HIR"$Nһ����ʽ����þ�ȫ�����������ǽ��ײȥ��ֻ��\n"+
                    "���һ����ײ��һ���󶴣�$N����˲ʱ��ʧ�ںڶ�֮�У�\n"NOR,victim);
  message_vision("$N��Ц�����������ܵ�����ȥ��˵������һ�Σ��ټ�������\n",killer);
  destruct(killer);
  destruct(victim);
  remove_call_out("do_fight");
  return;
}
int do_zuan(string arg)
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_csj/step3"))
  return 0;
  message_vision("$N���ڶ������˽�ȥ��\n",ob);
  ob->set_temp("dtsl_quest_csj/step4");
  ob->move(__DIR__"migong");
  return 1;
}
