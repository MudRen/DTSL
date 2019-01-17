
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name("����", ({ "shan zi","shan","perform_quest_zhehuabaishi_obj" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("no_save",1);     
     set("material", "iron");
     set("times",3);
     set("no_give",1);
     set("long", "����һ��ֽ���ӡ�\n");
     set("wield_msg", "$N�ó�һ��$n��������,�������˼��¡�\n");
     set("unequip_msg", "$N�����е�$n���𣬷��뻳�С�\n");
   }
   init_blade(15,90,90);
   setup();
}

void init()
{
   add_action("do_hua","draw");

}

int do_hua(string arg)
{
   object ob,target;
   object obj;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("��Ҫ�������ϻ�˭����\n");
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("����û������ˡ�\n");
   if(!userp(target))
   return notify_fail("�㻹���Ҹ���������ɣ�\n");
   if(target->query("gender")=="����")
   return notify_fail("���Ǹ�����Ҫ��Ů����\n");
   if(target->query("age")>60)
   return notify_fail("��ô�ϵ�Ů�ӻ��ǲ�Ҫ���ˡ�\n");
   if(ob==target)
   return notify_fail("�����Լ�����\n");
   
   message_vision("$N�ó����ʣ���$n���񻭵��������ϡ�\n",ob,target);
   ob->add("perform_quest/zhi_damage",target->query("per"));
   if(query("drawed"))
   set("drawed",query("drawed")+"��"+target->name());
   else
   set("drawed",target->name());
   
   add("times",-1);
   ob->add("perform_quest/zhi_times",1);
   
   if(ob->query("perform_quest/zhi_times")>=3
     ||query("times")<=0){
     message_vision("\n$NͻȻ֮������˻���׷�����������֮�⣬��������һЦ���ӵ������ӣ�\n",ob);
     obj=new(__DIR__"shanzi2");
     obj->set("long","���ǻ�����ӵĳɳ��������ӡ�\n"+
                     "���滭����Ů���ֱ��ǣ�"+query("drawed")+"��\n");
     obj->move(ob);
     destruct(this_object());
     return 1;
   }
   
   return 1;
}