
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
   
   set_name("��ȱ",({ "song que","song","que" }) );
        set("gender", "����" );
		set("title",HIG"�쵶"NOR);
        set("age", 52);
   set("long", "�������μұ��ı������˳�[�쵶]�����ĵ�����˵Ϊ���ֵ�һ��\n");
       
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
   set_skill("xukong-zhang",300);
   set("dodge",({"anxiang-fuying"}));
   set("hand",({"poyu-quan","xukong-zhang"}));
   set("blade",({"tiandao-bajue"}));
   create_family("�μұ�",3,"����");
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
     "����һ��":(:do_quest:),
     ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
   carry_object(__DIR__"obj/chanyidao")->wield();
   restore();
}

void attempt_apprentice(object ob)
{   
	if(ob->query("family"))
		if(ob->query("family/family_name")!="�μұ�")
		{ tell_object(ob,"��ȱ����üͷ�������μұ�����������ͽ�ģ�\n");
	  return;
		} 
	if(ob->query("vocation")=="ɱ��")
	{ tell_object(ob,"��ȱ����üͷ�������μұ���������ɱ�ֵģ�\n");
	  return;
	}
	if(ob->query("beipan")>=3)
	{  tell_object(ob,"��ȱ�ᷳ�����������ֶ����������ͽ���ҿɲ�Ҫ��\n");
	   return;
	}
	  
	if((int)ob->query_skill("tiangang-sanjue",1)<150)
	{ tell_object(ob,"��ȱ̾�������[�������]��Ϊ����������ȥ�ú�ѧϰ�ɣ�\n");
	return;}
	command("say ��,ֻҪ���μұ��úø�,��֤�㽫��Х������!\n");
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
	 return notify_fail("�����μұ��ɲ�Ҫ�������ɵ��ˣ�\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("���Ѿ����Ǳ����ˣ�����˵û�õģ�\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("��������������𱤳������ϣ�\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N��$nЦ����ϣ��$n�ܺúøɣ�ʹ�����μұ��������۰�һ����\n",ob,me);
	tell_object(me,"��ȥ���������񴦴� join �����������ˣ�\n");
	CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s���������ϵ��μұ���\n",me->name()));
	return 1;
}
string do_quest()
{
  object ob;
  ob=this_player();
  if(ob->query_skill("tiangang-sanjue",1)<300)
  return "��Ĺ���̫���ˣ����ڻ��޷�����[����һ��]����ºţ�\n";
  if(ob->query("family_lingwu")=="songjia")
  return "����������ǰ�ˣ����Ѿ���Խ���ˣ����ǿ�ȥ����ɣ�\n";
  ob->set_temp("gage_song",1);
  return "�ð��������Ϊ����һ���������ȴ�Ӯ��[fight song]\n";
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_song"))
   return 1;
   message_vision(HIR"$N���쳤Ц�������μұ����ں�������ˣ�\n"NOR,victim);
   tell_object(killer,"��ȥ���μұ��İ׻��ã��������������ɵ�һ�����ܣ�\n"+
                      "�ܲ������򣬾Ϳ����Լ����컯�ˣ�\n");
   killer->set("family_lingwu","songjia");
   killer->set("title",HIR"����һ��"NOR);
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_songjia"))
   return 1;
  message_vision("$N��$n̾�˿������㻹�ǻ�ȥ��ĥ��ĥ���ɣ�\n",killer,victim);
  return 1;
}