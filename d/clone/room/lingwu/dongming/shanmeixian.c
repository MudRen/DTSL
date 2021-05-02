inherit	F_MASTER;
inherit NPC;
#include <ansi.h>
string do_quest();
void create()
{
   set_name("������",({ "shan meixian","shan","meixian" }) );
        set("gender", "Ů��" );
		set("title",HIR"�������"NOR);
        set("age", 32);
   set("long", "���Ƕ����ɵ������������.\n");

   set("combat_exp",2000000);
   set("str", 25);
   set("per", 25);
   set("attitude", "peaceful");
   set_skill("unarmed",300);
   set_skill("dodge",300);
   set_skill("cuff",300);
   set_skill("parry",300);
   set_skill("force",300);
   set_skill("sword",300);
   set_skill("strike",300);
   set_skill("literate",300);
   set_skill("youyue-zhangfa",300);
   set_skill("dongming-xinfa",300);
  //  set_skill("bihai-jianfa",300);
   set_skill("piaomeng-jianfa",300);
   set_skill("shuiyun-xiufa",300);
  //  set_skill("yuxiao-quanfa",300);
   set_skill("nishang-piaoming",300);
   set("dodge",({"nishang-piaoming"}));
   set("force_skill",({"dongming-xinfa"}));
   set("sword",({"piaomeng-jianfa"}));
   set("hand",({"shuiyun-xiufa","youyue-zhangfa"}));
   set("max_gin",5000);
   set("max_sen",5000);
   set("max_kee",5000);
   set("force",6000);
   set("max_force",6000);
   create_family("������",2,"����");
   set("chat_msg_combat",({
	   (:apply_action,"piaomeng-jianfa",1+random(4),9:),
	   (:apply_action,"youyue-zhangfa",1+random(4),9:),
	   (:perform_action,"lianhuan":),
	   (:perform_action,"liuyun":),
   }));
   set("inquiry",([
     "����ս��":(:do_quest:),
     ]));
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();

}
void attempt_apprentice(object ob)
{
    object me;me=this_object();
	if(ob->query("family"))
		if(ob->query("family/family_name")=="������")
		{ message_vision("$N��$n��Ц������������а��Ҳ������ʦ��\n",me,ob);
		me->kill_ob(ob);return;}
    if((int)ob->query_skill("dongming-xinfa",1)<180)
	{ command("say ���[�����ķ�]̫��ˣ������������Ϊͽ��\n");
	return;}
	command("say ��,ϣ�����ڶ���úøɣ���������Щ��������֮��!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "dongming3");
}
string do_quest()
{
  object ob;
  ob=this_player();
  if(ob->query_skill("dongming-xinfa",1)<300)
  return "��Ĺ���̫���ˣ����ڻ��޷���Խ�ģ�\n";
  if(ob->query("family_lingwu")=="dongming")
  return "����������ǰ�ˣ����Ѿ���Խ���ˣ����ǿ�ȥ����ɣ�\n";
  ob->set_temp("gage_zhu",1);
  return "�ð��������Ϊ����ս���������ȴ�Ӯ��[fight shan]\n";
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_shan"))
   return 1;
   message_vision(HIC"$N΢΢һЦ��û�뵽�Ҷ����ɻ����������ĺ���֮�㣡\n"NOR,victim);
   message_vision(HIC"$N��ɫͻȻ�����������������������Ҹ�����һ�����ɵ����ܣ�\n"NOR,victim);
   tell_object(killer,"����������������ԣ�������˵���������һ�����������ķ��ĵط���\n"+
                      "��˵�ں��ߵ����´�����һֱû���ҵ��������ܲ����ҵ���������ˣ�\n");
   killer->set("family_lingwu","dongming");
   killer->set("title",HIG"����ս��"NOR);
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_shan"))
   return 1;
  message_vision("$N��$n̾�˿������㻹�ǻ�ȥ��ĥ��ĥ���ɣ�\n",killer,victim);
  return 1;
}
