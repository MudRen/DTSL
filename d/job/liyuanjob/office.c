
inherit NPC;
#include <ansi.h>

int do_task(string arg);

void create()
{
   set_name("官差",({ "office" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是一个巡捕犯人的官差。\n");

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
   return notify_fail("请使用 task ok with xxx 来复命。\n");
   if(query("owner")!=ob)
   return notify_fail(query("name")+"把头高高昂起，一副理你都盎居的样子...\n");
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("这里没有这个人！\n");
   if(target->is_corpse())
   return notify_fail(query("name")+"一笑：我对死尸可没什么兴趣！\n");
   if(target->query("target_id")!=ob->query("id"))
   return notify_fail(query("name")+"皱皱眉：你好象缉拿错人了！\n");
   if(living(target))
   return notify_fail("你不把他弄昏我怎么缉拿啊？\n");
   ob->add_temp("liyuan_job/step",1);
   if(objectp(ob->query_temp("temp_ob")))
    destruct(ob->query_temp("temp_ob"));
   message_vision("$N朝$n鞠了个躬："+RANK_D->query_respect(ob)+"果然"+
                  "足够神勇！我这就带着"+target->name()+"回去交差了，\n"+
                  "我先走一步了，后会有期！\n",this_object(),ob);
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
      tell_object(query_leader(),"官兵朝你喝道：你跑那么快干什么？害得本官也这么累！\n");}
    i=0;}
   return ::chat();
}
