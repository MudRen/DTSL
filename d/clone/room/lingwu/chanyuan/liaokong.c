
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string do_quest();
string give_key();
void create()
{
   set_name("�˿�",({ "liao kong","liao","kong"}));
        set("gender", "����" );
        set("age", 52);
   set("long", "�����Ǿ�����Ժ�������˿մ�ʦ��\n");
   set("class","bonze"); 
   set("combat_exp",4000000);
   set("str", 28);
   set("per", 22);
  set("attitude", "peaceful");
   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("staff",300);
   set_skill("unarmed",300);
   set_skill("tiangang-quan",300);
   set_skill("cuff",300);
   set_skill("dujie-zhi",300);
   set_skill("finger",300);
   set_skill("literate",300);
   set_skill("chanzong-fofa",300);
   set_skill("force",300);
   set_skill("liuyun",300);
   set_skill("bikouchan",300);
   set_skill("wuxiang-zhangfa",300);
   set_skill("blade",300);
   set_skill("jinguang-daofa",300);
   set("staff",({"wuxiang-zhangfa"}));
   set("dodge",({"liuyun"}));
   set("hand",({"tiangang-quan","dujie-zhi"}));
   set("jiali",30);
   set("gin",6000);
   set("max_gin",6000);
   set("kee",6000);
   set("max_kee",6000);
   set("sen",6000);
   set("max_sen",6000);
   set("force",6000);
   set("max_force",6000);
   create_family("������Ժ",3,"����");
   set("chat_chance_combat",50);
   set("chat_msg_combat",({
	   (:apply_action,"wuxiang-zhangfa",1,9:),
	   (:apply_action,"wuxiang-zhangfa",3,9:),
	   (:apply_action,"tiangang-quan",3,9:),
	   (:apply_action,"dujie-zhi",3,9:),
	   (:perform_action,"fumo":),
	   (:perform_action,"dujie":),
	   (:perform_action,"pomo":),
   }));
   set("inquiry",([
     "��Խ":(:do_quest:),
     "����":(:give_key:),
     ]));
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())) return;
	if(!wizardp(ob)&&ob->query("family/family_name")!="������Ժ")
		call_out("kill_thief",1,ob,ob2);
	else call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())) return;
	switch(random(2))
	{
	case 0: message_vision("$N�����е��������ӷ�!\n",ob2);break;
	case 1: message_vision("$N��$n���������Ե�ˡ�\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}

void kill_thief(object ob,object ob2)
{
	if(!ob||!present(ob,environment())) return;
	message_vision("$N��$n����˵����ʩ��Ϊ��Ҫ����������ˮ��!\n",ob2,ob);
	ob2->kill_ob(ob);
	remove_call_out("kill_thief");
}

void attempt_apprentice(object ob)
{   
	string name,new_name;
	if(ob->query("family"))
		if(ob->query("family/family_name")!="������Ժ")
		{tell_object(ob,"���Ѿ��������ɵ�����!\n");return;}
	if(ob->query("gender")=="Ů��")
	{
		tell_object(ob,"�˿�Ц��:������Ժֻ���е��ӵ�,ʩ�����һ�����,����ȥ�Ⱥ���ի.\n");
		return;
	}
	if((int)ob->query("PKS",1)>=5)
	{
		tell_object(ob,"�˿�˫�ֺ�ʮ��:ʩ��,���ɱ��̫��,����ô������?\n");
		return;
	}
	if((int)ob->query_skill("bikouchan",1)<150)
	{
		tell_object(ob,"ʩ�����[�տ���]���δ��,�����������?\n");
		return;
	}
	name=ob->query("name");
	new_name="��"+name[2..3];
	ob->set("name",new_name);
	command("say �����ӷ�!ϣ��ʩ������ܳ������˵Ŀ���,��Ϊһ����ɮ,����!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
}

string do_quest()
{
  object ob;
  ob=this_player();
  if(ob->query_skill("bikouchan",1)<300)
  return "��Ĺ���̫���ˣ����ڻ��޷���Խ�ģ�\n";
  if(ob->query("family_lingwu")=="chanyuan")
  return "����������ǰ�ˣ����Ѿ���Խ���ˣ����ǿ�ȥ����ɣ�\n";
  ob->set_temp("gage_liaokong",1);
  return "��С�ӣ��й�����������Ҫ�볬Խ�ң��ͱ���Ӯ��[fight liao]\n";
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_liaokong"))
   return 1;
   message_vision(YEL"$N������$n�ļ���ҷ����ں�������ˣ��Ҹ�����һ�����ܣ�\n"NOR,victim,killer);
   tell_object(killer,"�˿մյ���ĸ�ǰ�������������ҷ�ǰ��������һ�����ң����ھͿ�����컯�ˣ�\n");
   ob=new(__DIR__"key");
   ob->move(killer);
   killer->set("family_lingwu","chanyuan");
   killer->set("title",HIY"����ʥɮ"NOR);
   tell_object(killer,"�˿ո�����һ���ƽ�Կ�ס�\n");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_liaokong"))
   return 1;
  message_vision("$N��$n̾�˿������㻹�ǻ�ȥ��ĥ��ĥ���ɣ�\n",killer,victim);
  return 1;
}
string give_key()
{
  object ob,key;
  ob=this_player();
  if(ob->query("family_lingwu")!="chanyuan")
  return "����˵ʲô��ƶɮ����һ�㶼��������\n";
  if(objectp(key=present("key",ob)))
    if(key->query("unique"))
    return "���Ѿ���Կ���ˣ���ȥѧϰ�ɣ�\n";
  key=new(__DIR__"key");
  key->move(ob);
  tell_object(ob,"�˿ո�����һ���ƽ�Կ�ס�\n");
  return "ϣ�����ܹ��𷨣��츣���գ�\n";
}