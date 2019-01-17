
inherit NPC;

#include <ansi.h>

string do_action1();
int do_action2(string arg);

void create()
{
   set_name("老板",({ "lao ban","ban","lao" }) );
        set("gender", "男性" );
        set("age",42);
   set("long", "这是洛阳「平福老店」香料铺的老板。\n");       
   set("combat_exp", 50);
   
   set("inquiry",([
    "香料":(:do_action1:),
    ]));
    
   setup();
  
}

void init()
{
   add_action("do_action2","answer");
}

string do_action1()
{
   object ob,obj;
   
   ob=this_player();
   
   if(ob->query_temp("tmz_quest/yun_buy_xiangliao")&&
      !ob->query_temp("tmz_quest/xiangliao")&&
      !ob->query_temp("bai_wanwan_step1"))
   return "我们这里都是名贵的香料，可不会轻易给你！\n";
  if(ob->query_temp("tmz_quest/yun_buy_xiangliao")){
   ob->delete_temp("tmz_quest/yun_buy_xiangliao");
   ob->set_temp("tmz_quest/yun_buy_xiangliao2",1);
  }
   
   return "请问"+RANK_D->query_respect(ob)+"需要什么材料做的香料？";
 
}

int do_action2(string arg)
{
   object ob,obj;
   
   ob=this_player();
   
   if(!ob->query_temp("tmz_quest/yun_buy_xiangliao2")&&
      !ob->query_temp("bai_wanwan_step1"))
   return 0;
   
   if(!arg)
   return notify_fail("你要回答什么问题？\n");
   
   if(arg!="极品丹桂花"){
     command("sigh");
     command("say 看来"+RANK_D->query_respect(ob)+"还不是真正的识货之人啊！");
     return 1;
   }
 if(ob->query_temp("tmz_quest/xiangliao")){
    command("sigh");
    command("say 看来"+RANK_D->query_respect(ob)+"还不是真正的识货之人啊！");
     return 1; 
   }
   if(present("elite_thing_xiangxiao",ob)){
     command("say 虽然你是识货之人，但也不能要太多的香料啊！");
     return 1;
   }
   obj=new(__DIR__"obj/xiangliao");
   obj->move(ob);
   
   tell_object(ob,query("name")+"给了你一"+obj->query("unit")+
                obj->query("name")+"。\n");
   command("handshake2 "+ob->query("id"));
   command("say 看来"+RANK_D->query_respect(ob)+"是真正的识货之人啊！");
   ob->delete_temp("tmz_quest/yun_buy_xiangliao2");
   ob->query_temp("tmz_quest/xiangliao");
   return 1;
}


   
