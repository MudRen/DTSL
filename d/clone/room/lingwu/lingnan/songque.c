
inherit NPC;
inherit F_MASTER;
inherit F_SAVE;
#include <ansi.h>

string query_save_file()
{

	string id2;

	if( !stringp(id2 = query("npc_id")) ) return 0;
	return DATA_DIR + "npc/boss/" + id2;
}
string do_quest();
void create()
{

   set_name("宋缺",({ "song que","song","que" }) );
        set("gender", "男性" );
		set("title",HIG"天刀"NOR);
        set("age", 52);
   set("long", "他就是宋家堡的堡主，人称[天刀]。他的刀法据说为武林第一。\n");

   set("combat_exp", 1500000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set("gin",5000);
   set("max_gin",5000);
   set("kee",5000);
   set("max_kee",5000);
   set("sen",5000);
   set("max_sen",5000);
   set("force",5000);
   set("max_force",5000);
   set_skill("tiandao-bajue",300);
   set_skill("blade",300);
   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("unarmed",300);
   set_skill("cuff",300);
   set_skill("anxiang-fuying",300);
   set_skill("force",300);
   set_skill("tiangang-sanjue",300);
   set_skill("poyu-quan",300);
   set_skill("literate",300);
  //  set_skill("xukong-zhang",300);
   set("dodge",({"anxiang-fuying"}));
   set("hand",({"poyu-quan","xukong-zhang"}));
   set("blade",({"tiandao-bajue"}));
   create_family("宋家堡",3,"掌门");
   set("shili",([
      "name":"songjia_b",
      "leader":"songjia_b",
      ]));
    set("npc_id","songque");
    set("chat_chance_combat",50);
   set("chat_msg_combat",({
	   (:apply_action,"tiandao-bajue",1,9:),
	   (:apply_action,"tiandao-bajue",2,9:),
	   (:apply_action,"tiandao-bajue",4,9:),
	   (:perform_action,"bajue":),
	   (:perform_action,"xukong":),
	   (:perform_action,"shuangjue":),
   }));
   set("inquiry",([
     "岭南一刀":(:do_quest:),
     ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
   carry_object(__DIR__"obj/chanyidao")->wield();
   restore();
}

void attempt_apprentice(object ob)
{
	if(ob->query("family"))
		if(ob->query("family/family_name")!="宋家堡")
		{ tell_object(ob,"宋缺皱皱眉头：我们宋家堡从来不收叛徒的！\n");
	  return;
		}
	if(ob->query("vocation")=="杀手")
	{ tell_object(ob,"宋缺皱皱眉头：我们宋家堡从来不收杀手的！\n");
	  return;
	}
	if(ob->query("beipan")>=3)
	{  tell_object(ob,"宋缺厌烦道：象你这种多个势力的叛徒，我可不要！\n");
	   return;
	}

	if((int)ob->query_skill("tiangang-sanjue",1)<150)
	{ tell_object(ob,"宋缺叹道：你的[天罡三诀]修为不够啊，再去好好学习吧！\n");
	return;}
	command("say 好,只要在宋家堡好好干,保证你将来啸傲江湖!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "song3");
}
int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("我们宋家堡可不要其他帮派的人！\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("我已经不是堡主了，和我说没用的！\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("你高声喊道：独尊堡称雄岭南！\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N朝$n笑道：希望$n能好好干，使我们宋家堡在岭南雄霸一方！\n",ob,me);
	tell_object(me,"请去势力名单榜处打 join 命令就算加入了！\n");
	CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s加入了岭南的宋家堡！\n",me->name()));
	return 1;
}
string do_quest()
{
  object ob;
  ob=this_player();
  if(ob->query_skill("tiangang-sanjue",1)<300)
  return "你的功夫太低了，现在还无法享有[岭南一刀]这个绰号！\n";
  if(ob->query("family_lingwu")=="songjia")
  return "长江后浪推前浪，你已经超越我了，还是快去领悟吧！\n";
  ob->set_temp("gage_song",1);
  return "好啊，你想成为岭南一刀，必须先打赢我[fight song]\n";
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_song"))
   return 1;
   message_vision(HIR"$N仰天长笑道：我宋家堡终于后继有人了！\n"NOR,victim);
   tell_object(killer,"你去我宋家堡的白虎堂，那里有我们门派的一个秘密！\n"+
                      "能不能领悟，就看你自己的造化了！\n");
   killer->set("family_lingwu","songjia");
   killer->set("title",HIR"岭南一刀"NOR);
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_songjia"))
   return 1;
  message_vision("$N朝$n叹了口气，你还是回去再磨练磨练吧！\n",killer,victim);
  return 1;
}
