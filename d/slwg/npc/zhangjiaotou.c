
inherit NPC;
#include <ansi.h>

string give_job();
int do_ok(string arg);

void create()
{
   set_name("�Ž�ͷ",({ "zhang jiaotou","zhang","jiao","tou"}) );
        set("gender", "����" );
        set("age", 32);
        
        set("str",30);
        set("dex",30);
        
        set("slwg_jiaotou",1);
        set("target_id","####");
        set("long","����ʯ����ݵĽ�ͷ��\n");
        
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("force",80);
        set_skill("cuff",80);
        
        set_skill("male-cuff",30);
        set_skill("babu-ganchan",80);
        
        set("max_force",200);
        set("force",200);
        
        set_temp("apply/damage",10+random(10));
        
        set("combat_exp",50000);
        
        set("inquiry",([
           "����":(:give_job:),
           ]));
        
    setup();
   
}
/*
void init()
{
   object ob;
   
   ob=this_player();
   if(!ob) return;
   remove_call_out("welcome");
   call_out("welcome",1,ob);
}

void welcome(object ob)
{
   if(!ob) return;
   
   if(environment(ob)!=environment())
   return;
   
   
     command("hi "+ob->query("id"));
     tell_object(ob,query("name")+"����Ц������������ "+HBMAG+HIW+"qiecuo jiao"+NOR+" �ɡ�\n");
  return;
}*/

void init()
{
  add_action("do_ok","task");
}

int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}


string *jobs=({
"÷��׮","վ׮","��ʯ��","��ɳ��"
});
  
string give_job()
{
   object ob;
   int i;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=20000)
   return "��ľ�����ô�ߣ��������ϰ���տ�̫���ˣ�\n";
   
   if(time()-ob->query("busy_time")<10+random(5))
    return "ѧϰ���ղ�Ҫ���룬������Ϣһ�¡�\n";
   
   if(ob->query_temp("slwg_job"))
   return "�Ҳ�������ȥ��ϰ"+ob->query_temp("slwg_job")+"��"+
   "��ô����͵��������\n";
   
   i=random(sizeof(jobs));
   
   ob->set_temp("slwg_job",jobs[i]);
   
   return "�ҿ������ʲ�����ȥ���䳡ȥ��ϰ"+jobs[i]+"�� "+HIG+"(lianwu "+jobs[i]+")"+NOR+
          "\n��ǧ��Ҫ͵����\n";
}
   
int do_ok(string arg)
{
   object ob;
   int exp,pot,sil;
  
   ob=this_player();
   
   if(!ob->query_temp("slwg_job"))
   return notify_fail("��˵ʲô�ҿ�����������\n");
   
   if(!ob->query_temp("slwg_job_ok"))
   return notify_fail("��������ϰ���գ���ȴ͵�������Ǹô�\n");
   
   ob->delete_temp("slwg_job");
   ob->delete_temp("slwg_job_ok");
   ob->delete_temp("slwg_job_times");
   
   exp=20+random(10);
   pot=5+random(5);
   sil=100+random(100);
   
   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot"))
    ob->set("potential",ob->query("max_pot"));
   ob->add("deposit",sil);
   
   ob->set("busy_time",time());
   
   ob->save();
   
   tell_object(ob,query("name")+"Ц���������ģ�������һ����Ϊ����ʯ�����������\n");
   tell_object(ob,query("name")+"��������"+HIW+chinese_number(exp)+NOR+"�㾭�飬"+
   HIY+chinese_number(pot)+NOR+"��Ǳ�ܡ�\n"+
   MONEY_D->money_str(sil)+"��\n");
   
   return 1;
}