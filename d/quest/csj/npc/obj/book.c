#include <ansi.h>
 inherit ITEM;

 void create()
 {
        set_name(YEL"长生诀" NOR, ({ "book","changsheng jue"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是武林中人人抢夺的秘籍长生诀。\n");
                set("unit", "本");
                set("material", "纸");              
                set("no_save",1);
               //set("no_give",1);
                set("no_throw",1);
                set("no_drop",1);
                //set("nogive_player",1);
        }
        setup();
}

void init()
{
  add_action("do_open","open");
  
}

void do_steal(object ob)
{
   if(query("no_steal"))
   return;
   if(ob->query_temp("kill_shilong"))
   return;
   set("no_steal",1);
   ob->set_temp("dtsl_quest_csj_action1",1);
   call_out("do_kill",300,ob);
}

void do_kill(object ob)
{
   object killer;
   object *guards,guard;
   ob=this_player();  
   if(!ob) return;
    
   killer=new("/d/quest/csj/npc/yuwen-huaji");
   killer->move(environment(ob));
 
   if(ob->query_temp("guarded")) {
/* 
  guards=ob->query_temp("guarded");
 
  if(arrayp(guards)){
   guards=guards-({ 0 });
    //guards=filter_array(guards,(:environment($1)==environment(ob):) );
    //guards=filter_array(guards,(:!userp($1):) );
    guards=filter_array(guards,(:$1->query("dtsl_quest_csj_npc"):) );
   }
*/
   killer->do_command("say 小贼，终于让我找到你！！\n");
   
     
     killer->kill_ob(ob);
     ob->kill_ob(killer);
     ob->delete_temp("guarded");
   return;
}
}
int do_open(string arg)
{
  object ob; 
  
  ob=this_player();
  
  if(!arg||(arg!="6"&&arg!="7"))
 return notify_fail("你要翻开第几页？\n");
 if(!ob->query("dtsl_quest_csj_ok"))
 return notify_fail("你翻开了书，什么也看不懂！\n");
 
 if(ob->query_skill("changsheng-jue",1)
   ||ob->query("force_quest/csj1")
   ||ob->query("force_quest/csj2"))
  return notify_fail("这书对你没什么用了。\n");
  
  if(arg=="6"){
    tell_object(ob,"你从中领会到了长生诀静的方面的初级功夫！\n");
    ob->set("force_quest/csj1",1);    
  }
  else{
   tell_object(ob,"你从中领会到了长生诀动的方面的初级功夫！\n");
    ob->set("force_quest/csj2",1);
  }
  ob->set("force_quest/csj_PKS",ob->query("PKS"));
  ob->set("force_quest/csj_deadtimes",ob->query("deadtimes")); 
  ob->set_skill("changsheng-jue",10);

  destruct(this_object()); 
  return 1;
 }
int is_get_of(object pal,object ob)
 {
 if(!pal->query("dtsl_quest_csj_ok"))
  return notify_fail("你不能拿起那本书！\n");
  return 1;
}
 
