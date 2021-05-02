
#include <weapon.h>

inherit BLADE;

int do_badao(string arg);

void create()
{
   set_name("����", ({ "blade","perform_bajue_blade"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("material", "iron");
     set("long", "����һѰ���ĵ�����������Լ�����߽��ء�\n");
     set("wield_msg", "$N���һ�����λε�$n�������С�\n");
     set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
     set("no_save",1);
     set("eff_times",3);
     set("nogive_player",1);
     set("no_drop",1);
   }
   init_blade(25,80,80);
   setup();
}

void init()
{
   add_action("do_badao","badao");
}

int wield()
{
      object owner;
      
      if(!environment()) return 0;
      if( !(owner = environment())->is_character() ) return 0;
      return notify_fail("�����������װ����\n");
}


int do_badao(string arg)
{
   object ob;
   int cost;
   string msg;
   int flag=0;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("��Ҫ��ʲô����ϰ�ε���\n");
   if(!id(arg))
   return 0;
   if(!ob->query_temp("perform_quest/bajue_action1"))
   return 0;
   if(ob->query("char_lev/perform_bajue_fail"))
   return notify_fail("�㲻�ʺ������ģ��������˰ɣ�\n");
  
   msg="$N���յ������ȶ�����৵�һ�°γ���"+query("name")+"��\n";
   
   if( ob->query("MKS")!=ob->query("lingnan_menpai/lingnan_MKS")
    ||ob->query("PKS")!=ob->query("lingnan_menpai/lingnan_PKS")
    ||ob->query("deadtimes")!=ob->query("lingnan_menpai/lingnan_deadtimes")
    ||ob->query("age")>=50
    ||ob->query("kill_same_party_flags")
    ||ob->query("kill_good_party_flags")
    )
    flag=1;
    
   if(!flag){
     msg+="\n$N����̽���ֻ������ȶ���ÿһ��ÿһ����ƶ�������ͬһ���ٶ��£����ٶȾ���\n"+
          "���䡣$N�İε�����ֱ������غ��䱳����Զ�����Ÿ����εı�����Ϊһ������\n"+
          "�����㳣������ǧ���򷨵�ζ����û��˿����϶������Ѱ����ʹ�˸е���������ʽ��\n"+
          "���ĵ�һ�������Ǿ���أ�������û�п�ʼ��û���սᡣ \n";
     ob->set("perform_quest/bajue",1);
     msg+="\n$N����һЦ�������ӵ���"+query("name")+"��\n\n";
     message_vision(msg,ob);
     destruct(this_object());
     return 1;
   }
  
    msg+="$N����û����ᵽ�κζ��������ɵ�������ȱ��һ�仰��\n"+
         "�����еĵ����㶮���Ƕ����������ǲ�����\n"+
         "$NͻȻ�����Լ������������쵶�˾������ɵ�һ���ѹ���\n"+
         "�����ӵ���"+query("name")+"��\n\n";
    
    message_vision(msg,ob);
    ob->set("char_lev/perform_bajue_fail",1);
    destruct(this_object());
    return 1;
 
}