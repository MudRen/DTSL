#include <job_money.h>
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("������",({"pan tu","pan","tu"}));
       set("gender", "����" );
       set("age", 32);
    set("combat_exp", 800000);
   set("str", 30);
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",3000);
   set("force",3000);
 setup();
 add_money("silver",40+random(10));
}

void die()
{
  object ob;
  int exp,sil;
  ob=this_object()->query_temp("last_damage_from");
  if(!objectp(ob)) return ::die();
  if(ob->query("id")==this_object()->query("job/p_id")){
  message_vision(HIR"$N�Һ�һ�����е������Ӷ�ʮ�����һ���ú���\n"NOR,this_object());
  exp=190+random(10);
  sil=ob->query("max_pot");
  add_shili(ob,exp,sil);
  ob->add("potential",random(10));
  if(ob->query("potential")>ob->query("max_pot"))
	ob->set("potential",ob->query("max_pot"));
  tell_object(ob,"��Ϊ��������"+HIW+chinese_number(exp)+NOR+
              "�㾭��,"+MONEY_D->money_str(sil)+"��\n");
  tell_object(ob,"���Ǳ��Ҳ����ˣ�\n");
  ob->set("busy_time",time());
  ob->delete_temp("bhjob");}
  return ::die();
}

int kill_object(object killer,object victim)
{
  message_vision("$N��Ц��������Ҳ��ץ�ң���������\n",killer);
  message_vision("$N����һ�Σ��ټ�������\n",killer);
  destruct(killer);
  return 1;
}

void init()
{
  set("last",time());
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N�Ҵҵ����ˡ�\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
  if(clear()) return 1;
  return ::chat();
}