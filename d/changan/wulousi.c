

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��©��");
  set ("long", @LONG
��©�¹�ģ���󣬵����ɱ��£����ؾ���������������С�
�������������᷿����Ժ��Ժ�ڻ�ľ���裬�о����¡�
LONG);

  set("exits", ([ 
"south":__DIR__"xishibeikou2",
 "enter":"/d/quest/busiyin/woshi",
       ]));
  set("objects",([
          "d/job/jj/heshang3":1,
	  "/d/quest/busiyin/zhuchi":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_lingwu","lingwu");

}

int do_lingwu(string arg)
{
   
   object ob,target;
   string name;
   int improve,cost_pot,cost_bel;
   
   ob=this_player();
   
   if(!arg||sscanf(arg,"with %s",name)!=1)
   return notify_fail("����Ҫһ��ɮ�˲���������ӡ��\n");
   if(!objectp(target=present(name,environment(ob))))
   return notify_fail("����û������ˡ�\n");
   if(!userp(target))
   return notify_fail(target->name()+"�ﲻ���㡣\n");
   if(target->query("class")!="bonze")
   return notify_fail(target->name()+"����ɮ�ˡ�\n");
   if(ob->query_skill("busi-yin",1)>target->query_skill("bikouchan",1))
   return notify_fail(target->name()+"�տ�����Ϊ̫���ˣ��޷�������᲻��ӡ��\n");
   if(target->is_fighting())
   return notify_fail("�Է�����ս���С�\n");
   if(target->is_busy())
   return notify_fail("�Է���æ���أ�\n");
   if(ob->is_busy())
   return notify_fail("����æ���أ�\n");
   
   if(ob->query_skill("busi-yin",1)<120
     ||ob->query_skill("huachan",1))
    return notify_fail("��ʲôҲ���򲻳�����\n");
  
   if(ob->query("bellicosity")<=0)
   return notify_fail("���ɱ��̫���ˣ��޷�������ӡ��\n");
   if(ob->query("potential")<=0)
   return notify_fail("���Ǳ�ܲ�����\n");
   
  improve=ob->query("potential")/2;
   if(ob->query("bellicosity")<improve){
     cost_pot=ob->query("bellicosity");
     cost_bel=ob->query("bellicosity");
   }
   else{
     cost_pot=ob->query("potential");
     cost_bel=improve;
   }
     improve=cost_pot*10;
     
     ob->improve_skill("busi-yin",improve);
     ob->add("potential",-cost_pot);
     ob->add("bellicosity",-cost_bel);
     
     message_vision("\n$N�������ɱ���𽥻��⣬�Բ���ӡ�������������µ���ߡ�\n",ob);
     ob->start_busy(2);
     target->start_busy(1);
     return 1;
}
