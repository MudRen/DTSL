
inherit NPC;
#include <ansi.h>

int do_task(string arg);

void create()
{
   set_name("�ٲ�",({ "office" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һ��Ѳ�����˵Ĺٲ\n");

   set("combat_exp", 200000);
   set("str", 28);
   set_skill("finger",70);
   set_skill("strike",170);
   set_skill("cuff",70);
   set_skill("parry",70);
   set_skill("dodge",170);
   set_skill("force",70);
   set_skill("huanmo-shenfa",170);
   set_skill("tiangang-sanjue",70);
   set_skill("bencao-shuli",70);
   // set_skill("xukong-zhang",170);
   set("max_force",200);
   set("force",200);
   set("max_sen",1000000000);
   setup();

}

void init()
{
   if(!query("last_time"))
    set("last_time",time());
   add_action("do_task","task");

}

int clean_up()
{
  if(time()-query("last_time")<3600)
   return 0;
  return 1;
}

int do_task(string arg)
{
   object ob;
   object target;

   ob=this_player();
   if(sscanf(arg,"ok with %s",arg)!=1||!arg)
   return notify_fail("��ʹ�� task ok with xxx ��������\n");
   if(query("owner")!=ob)
   return notify_fail(query("name")+"��ͷ�߸߰���һ�����㶼���ӵ�����...\n");
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("����û������ˣ�\n");
   if(target->is_corpse())
   return notify_fail(query("name")+"һЦ���Ҷ���ʬ��ûʲô��Ȥ��\n");
   if(target->query("target_id")!=ob->query("id"))
   return notify_fail(query("name")+"����ü��������ô����ˣ�\n");
   if(living(target))
   return notify_fail("�㲻����Ū������ô���ð���\n");
   ob->add_temp("liyuan_job/step",1);
   if(objectp(ob->query_temp("temp_ob")))
    destruct(ob->query_temp("temp_ob"));
   message_vision("$N��$n���˸�����"+RANK_D->query_respect(ob)+"��Ȼ"+
                  "�㹻���£�����ʹ���"+target->name()+"��ȥ�����ˣ�\n"+
                  "������һ���ˣ�������ڣ�\n",this_object(),ob);
   destruct(target);
   destruct(this_object());
   return 1;
}

int i=0;
int chat()
{
   i++;
   if(i==5){
   if(query_leader())
    if(environment(this_object())!=environment(query_leader())){
      move(environment(query_leader()));
      tell_object(query_leader(),"�ٱ�����ȵ���������ô���ʲô�����ñ���Ҳ��ô�ۣ�\n");}
    i=0;}
   return ::chat();
}
