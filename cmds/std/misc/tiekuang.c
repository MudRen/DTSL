
inherit ITEM;

#include <ansi.h>

void create()
{
   
   set_name(HIB"����"NOR,({"tiekuang"}));
   set_weight(1000);   
   set("unit", "��");
   set("no_sell",1);
   set("no_save",1);
   set("long","����һ��û�о���ʶ�𣨣ӣȣɣ£ɣţ��������㻹��֪��������;��\n");
   setup();
   
}

void init()
{
        add_action("do_shibie","shibie");
}

int set_status(object me)
{
   int dlev;
   int flag=0;
   
   if(me->query("vocation")=="ɱ��"){
     if(me->query("job_office_number/ɱ������")>=1000
      &&!me->query("find_best_iron")
       ){
       me->set("find_best_iron",1);
       set("dlev",300);//ɱ������1000�Σ����Եõ���õĿ�ʯһ�Ρ�
       return 1;
     }
    flag=2;
   }
   else flag=0;
  
  dlev=(1+random(2+flag))*50;
  
  set("dlev",dlev);
  
  return 1;
}


int do_shibie()
{
         
         int lev;
         int dlev;
         int dtype;
         int damage,strong;
         
         object me = this_player();    
         object iron = this_object();    
         
        if(me->query("vocation")!="����")
        return notify_fail("�㲻������������ʶ������!\n");
        if(iron->query("no_shibie")==1)
                return notify_fail("��������Ѿ�ʶ�����!\n");
        
        lev=(int)me->query_skill("duanzao-jishu",1);       
        dlev=query("dlev");
        if(lev<dlev){
         
          return notify_fail("��Ķ��켼��̫���ˣ�������ʶ��ÿ�ʯ��\n");
        }
        
        damage=dlev/50*15+random(10);
        strong=dlev/50*30+random(10);
        
        set("weapon/damage",damage);
        set("weapon/strong",strong);
                
        iron->set("long","����һ���������Ĺ�Чָ���ǣ�\n�˺���"+damage+"\n��̣�"+strong+"��\n");
        iron->set("no_shibie",1);
        message_vision("$N����ʯϸ������һ�飬����֪�����������ã�\n",me);
        me->add("vocation_score",1);//�� 10 ̫����
        message_vision("$N��ְҵ���������ˡ�\n",me);

        return 1;
}


