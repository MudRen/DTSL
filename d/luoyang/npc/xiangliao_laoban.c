
inherit NPC;

#include <ansi.h>

string do_action1();
int do_action2(string arg);

void create()
{
   set_name("�ϰ�",({ "lao ban","ban","lao" }) );
        set("gender", "����" );
        set("age",42);
   set("long", "����������ƽ���ϵ꡹�����̵��ϰ塣\n");       
   set("combat_exp", 50);
   
   set("inquiry",([
    "����":(:do_action1:),
    ]));
    
   setup();
  
}

void init()
{
   add_action("do_action2","answer");
}

string do_action1()
{
   object ob,obj;
   
   ob=this_player();
   
   if(ob->query_temp("tmz_quest/yun_buy_xiangliao")&&
      !ob->query_temp("tmz_quest/xiangliao")&&
      !ob->query_temp("bai_wanwan_step1"))
   return "�������ﶼ����������ϣ��ɲ������׸��㣡\n";
  if(ob->query_temp("tmz_quest/yun_buy_xiangliao")){
   ob->delete_temp("tmz_quest/yun_buy_xiangliao");
   ob->set_temp("tmz_quest/yun_buy_xiangliao2",1);
  }
   
   return "����"+RANK_D->query_respect(ob)+"��Ҫʲô�����������ϣ�";
 
}

int do_action2(string arg)
{
   object ob,obj;
   
   ob=this_player();
   
   if(!ob->query_temp("tmz_quest/yun_buy_xiangliao2")&&
      !ob->query_temp("bai_wanwan_step1"))
   return 0;
   
   if(!arg)
   return notify_fail("��Ҫ�ش�ʲô���⣿\n");
   
   if(arg!="��Ʒ����"){
     command("sigh");
     command("say ����"+RANK_D->query_respect(ob)+"������������ʶ��֮�˰���");
     return 1;
   }
 if(ob->query_temp("tmz_quest/xiangliao")){
    command("sigh");
    command("say ����"+RANK_D->query_respect(ob)+"������������ʶ��֮�˰���");
     return 1; 
   }
   if(present("elite_thing_xiangxiao",ob)){
     command("say ��Ȼ����ʶ��֮�ˣ���Ҳ����Ҫ̫������ϰ���");
     return 1;
   }
   obj=new(__DIR__"obj/xiangliao");
   obj->move(ob);
   
   tell_object(ob,query("name")+"������һ"+obj->query("unit")+
                obj->query("name")+"��\n");
   command("handshake2 "+ob->query("id"));
   command("say ����"+RANK_D->query_respect(ob)+"��������ʶ��֮�˰���");
   ob->delete_temp("tmz_quest/yun_buy_xiangliao2");
   ob->query_temp("tmz_quest/xiangliao");
   return 1;
}


   
