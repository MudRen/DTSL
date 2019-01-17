
inherit ITEM;
#include <job_money.h>
#include <ansi.h>

string *dirs1=({
"/d/hengshan","/d/suiye"
});

string *dirs2=({
"/d/huashan","/d/emeishan","/d/taishan"
});

int do_shou(string arg);

void create()
{
   set_name("�˱�",({"zhang ben","zhang","ben"}));
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("no_drop",1);
     set("unit", "��");
   }
   setup();
}

void init()
{
  add_action("do_shou","shouzhang");
}

int do_shou(string arg)
{
  object ob,target;
  object killer;
  string name;
  string *dirs;
  
  ob=this_player();
  
  if(!arg||sscanf(arg,"with %s",name)!=1)
  return notify_fail("��ʹ��shouzhang with xxx �� xxx���ˡ�\n");
  
  if(!objectp(target=present(name,environment(ob))))
  return notify_fail("�����û������ˡ�\n");
  if(userp(target))
  return notify_fail("�Է�����������㡣\n");
  if(!living(target))
  return notify_fail("��������Է��ǻ�����\n");
  if(query("dm_shouzhang_target")!=base_name(target))
  return notify_fail(target->name()+"�۾�һ�ᣬ�������ˣ����ߴ�ط��˰ɣ�\n");
  
  if(query("dm_shouzhang_ok"))
  return notify_fail("�Ҳ����Ѿ�д���ˣ���������ȥ����ɣ�\n");
  
 
  if(ob->query("combat_exp")<500000){
   message_vision("$N������Ц�������������ô���������ô�����ǽ����أ�\n",target);
   message_vision("$N��æ���˱���д�˼����֡�\n",target);
   set("dm_shouzhang_ok",1);
   return 1;}
  //������200K��600K�Ժ��ɱ���ˡ�
  if(ob->query_temp("have_killed_killer")){
   ob->delete_temp("have_killed_killer");
   message_vision("$N������Ц������ô�ҺͶ��������أ������д��\n",target);
   message_vision("$N��æ���˱���д�˼����֡�\n",target);
   set("dm_shouzhang_ok",1);
   return 1;}
  
   if(query("fighting")){
  
    if(ob->query("combat_exp")<1000000)
     return notify_fail("���ͣ����ͣ�\n");
    else
     return notify_fail(target->name()+"������Ц�����㵽����û�����������\n");
   }
  
  set("fighting",1);
  
  if(ob->query("combat_exp")<1000000){
  
  killer=new(__DIR__"killer"); 
  killer->set_status(ob); 
  killer->move(environment(ob));
  message_vision(HIW"$N�۾�һ�᣺�ߣ�������ͷ�������ˣ����ò������ǻ��ˣ���\n"+
  "ҪǮû�У�Ҫ��һ������\n"NOR,target);
  tell_object(ob,target->name()+"����������������ɱ�����С���˵�����\n");
  message_vision("$N�첽���˽�����\n",killer);
  killer->kill_ob(ob);
  ob->add_temp_array("job_temp_killer",killer);
  return 1;
  }
  
  killer=new(__DIR__"killer"); 
  killer->set_status(ob);
  
  if(ob->query("combat_exp")<=1000000)
   dirs=dirs1;
  else
   dirs=dirs1+dirs2;
  
  if(!random_place(killer,dirs))
   return notify_fail(target->name()+"���ŵ����ȣ���һ��... ...\n");
  if(!environment(killer))
   return notify_fail(target->name()+"���ŵ����ȣ���һ��... ...\n");
  
  ob->add_temp_array("job_temp_killer",killer);//����killer������
                                               //��������������ɻ�quit.
                                               //����������
  tell_object(ob,target->name()+"������Ц������������������Ҳ���ԣ�\n"+
    "��������ɱ�����������߻���"+killer->name()+"��\n"+
    "��������"+MISC_D->find_place(environment(killer))+"��������û����������ˣ�\n");
  
  return 1;

}
 
  
