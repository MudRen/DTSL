
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short",BLU"ʯ��"NOR);
  set ("long", @LONG
������һ��ʯ�ݣ�����ǳ�������ɢ��������ʪ����Ϣ��������
���м���ľͷ�ˣ�վλ���ã��ƺ���ĳ���󷨵����С����ӵĽ���ɢ��
�ż������ã��ڶ����������������㡣
LONG);
  set("exits",([
	  "eastup":__DIR__"qingshilu2",
	  ]));
  set("objects",([
    __DIR__"npc/tmz_robot":4,
    ]));
  set("valid_startroom", 1);
  set("no_fight",1);
  setup();
 
}

void init()
{
   object ob;
   
   ob=this_player();
   
   if(!ob) return;
   if(ob->query("potential")<=0)
   return;
   if(!living(ob))
   return;
   
   remove_call_out("do_fight");
   call_out("do_fight",1,ob);
}

void do_fight(object ob)
{
    string msg;
    object *who;
    int i;
    
    if(!ob) return;
    
    if(environment(ob)!=this_object())
    return;
    if(ob->query("pker")){
      msg="\nֻ�����һ��������������$N˵����ͨ�����������ӣ���\n\n";
      message_vision(msg,ob);
      ob->move(__DIR__"qingshilu2");
      ob->unconcious();
      return;
    }
    if(!ob->query_skill("tianmo-zhen",1)||
       !userp(ob)){
      msg="\nֻ���ĸ�ľ��һ�볯$Nײ����$N��æ���˳�ȥ��\n\n";
      message_vision(msg,ob);
      ob->move(__DIR__"qingshilu2");
      return;
    }
    
    who=all_inventory(this_object());
    
    for(i=0;i<sizeof(who);i++){
      if(who[i]->query("tmz_robot"))
        who[i]->fight_ob(ob);
    }
   return;
}