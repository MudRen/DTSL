
inherit NPC;

#include <ansi.h>

string do_action1();
string do_action2();

void create()
{
   set_name("����ϰ�",({ "lao ban","ban","lao" }) );
        set("gender", "����" );
        set("age",42);
   set("long", "����������ɽ���ӡ����̵��ϰ塣\n");       
   set("combat_exp", 50);
   
   set("inquiry",([
    "��ѿҶ":(:do_action1:),
    "һ�Ȼ�ѿҶ":(:do_action2:),
    ]));
    
   setup();
  
}

string do_action1()
{
   object ob,obj;
   
   ob=this_player();
   
   if(!ob->query_temp("tmz_quest/yun_buy_tea"))
   return "��������ǲ��̵ĺò裬�ҿɲ������׸��㣡\n";
   ob->delete_temp("tmz_quest/yun_buy_tea");
   
   obj=new(__DIR__"obj/tea");
   obj->move(ob);
   
   tell_object(ob,query("name")+"������һ"+obj->query("unit")+
                obj->query("name")+"��\n");
   return "ԭ����������ף������Ҫ�˲裬���ĸҲ����أ�\n";
}

string do_action2()
{
   object ob,obj;
   
   ob=this_player();
   
   if(!ob->query_temp("tmz_quest/yun_buy_tea"))
   return "��������ǲ��̵ĺò裬�ҿɲ������׸��㣡\n";
   ob->delete_temp("tmz_quest/yun_buy_tea");
   
   obj=new(__DIR__"obj/tea");
   obj->set("name",HIY"һ�Ȼ�ѿҶ"NOR);
   obj->set("super_tea",1);
   obj->move(ob);
   
   tell_object(ob,query("name")+"������һ"+obj->query("unit")+
                obj->query("name")+"��\n");
   return "ԭ����������ף������Ҫ�˲裬���ĸҲ����أ�\n";
}