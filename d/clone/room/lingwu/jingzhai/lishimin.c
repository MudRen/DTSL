
inherit NPC;
inherit F_SAVE;
#include <ansi.h>
string query_save_file()
{

	string id2;

	if( !stringp(id2 = query("npc_id")) ) return 0;
	return DATA_DIR + "npc/boss/" + id2;
}

void create()
{
   set_name("李世民",({ "li shimin","li","shimin" }) );
        set("gender", "男性" );
        set("age", 25);
   set("long", "这就是长安李阀的二少主李世民。\n");
   set("shili","li");
   set("combat_exp", 700000);
   set("str", 28);
   set("per", 26);
   set("attitude", "peaceful");
   set_skill("unarmed",170);
   set_skill("parry",170);
   set_skill("dodge",170);
   set_skill("force",170);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   set("shili",([
      "name": "lifa_b",
      "leader": "lifa_b",
      "deadtimes":0,
      ]));
   set("npc_id","lishimin");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  restore();
}

int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("我们李阀可不要其他帮派的人！\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("我已经不是堡主了，和我说没用的！\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("你高声喊道：李阀必定统一中原！\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N朝$n笑道：希望$n能好好干，早日帮我们李家统一天下！\n",ob,me);
	tell_object(me,"请去势力名单榜处打 join 命令就算加入了！\n");
	CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s加入了长安的李阀！\n",me->name()));
	return 1;
}
	

