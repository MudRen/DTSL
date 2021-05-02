
inherit NPC;
inherit F_MASTER;
string do_quest1();
string do_quest2();
string do_jzzy_quest1();
string do_jzzy_quest2();
string do_jzzy_quest3();
void create()
{
   set_name("ʦ����",({ "shi feixuan","shi" }) );
        set("gender", "Ů��" );
        set("age", 22);
   set("long", "���ǴȺ���ի��ʦ������\n");

   set("combat_exp",4000000);
   set("str", 25);
   set("per", 30);
   set("max_gin",6000);
   set("max_kee",6000);
   set("max_sen",6000);
   set("max_force",6000);
   set("force",6000);
   set("attitude", "peaceful");
   set_skill("sword",300);
   set_skill("cuff",300);
   set_skill("parry",300);
   set_skill("strike",300);
   set_skill("dodge",300);
   set_skill("finger",300);
   set_skill("literate",300);
   set_skill("force",300);
   set_skill("sekong-jianfa",300);
  //  set_skill("piaokong-zhang",300);
  //  set_skill("jingxin-quan",300);
   set_skill("xiuluo-zhi",300);
   set_skill("wuwang-jing",300);
   set_skill("qingxin-force",300);
   set_skill("lingyun-shenfa",300);
   set("hand",({"piaokong-zhang","jingxin-quan","xiuluo-zhi"}));
   set("sword",({"sekong-jianfa"}));
   set("dodge",({"lingyun-shenfa"}));
   create_family("�Ⱥ���ի",6,"����");
   set("inquiry",([
      "������":"����������֮�������������ҵĵ�����\n",
      "����":"���ĵ�����ȷ���������˭�ָҺ������������أ�\n",
      "�����":(:do_quest1:),
      "��Ů":(:do_quest2:),
      "��ʯ��":(:do_jzzy_quest1:),
      "�޺�":(:do_jzzy_quest2:),
      "�Ħ��":(:do_jzzy_quest3:),
      ]));
   setup();
   carry_object(__DIR__"obj/baiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();

}

void attempt_apprentice(object ob)
{

	if(ob->query("gender")=="����")
	{
	  command("say ���ǴȺ���ի�����е��ӵġ�\n");
	  return;
	}

	if(ob->query("family_lingwu")=="jingzhai"){
	  command("say ���Ǳ�����Ů���ҿɲ�������Ϊͽ��\n");
	  return;}

	if(ob->query("family")&&ob->query("family/family_name")!="�Ⱥ���ի")
	{
	  command("say ���ǴȺ���ի�����������ɵ���ͽ�ġ�\n");
	  return;
	}
	if(ob->query("kar")<24)
	{
	  command("say �������������ڷ���Ե���㻹��Ͷ���������ɰɣ�\n");
	  return;
	 }
	if(ob->query_int()<31)
	{
	  command("say ���ͷ�Բ������������ú�ѧѧ�����ɣ�\n");
	  return;
	 }
	if(ob->query("int")<27)
	{
	  command("say �����������̫���ˣ������������ǴȺ���ի��û�����Ե���ˣ�\n");
	  return;
	 }
       if(ob->query_skill("qingxin-force",1)<150)
       {
       	 command("say ���[�������ƾ�]����������������ȥ�����ɣ�\n");
       	 return;
       	}
	command("say ��,��Ȼ�ܰݵ��ҵ����£�˵��������ܹ����������ļ��!\n");
	command("say ϣ�����Ժ������Ƽ�����Ϊ�����츣��\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "jingzhai2");
}

string do_quest1()
{
  object ob;
  ob=this_player();
  if(ob->query("family_lingwu")=="jingzhai")
  return "���Ѿ��Ǳ�����Ů�ˣ�����ֱ��ȥ��ʦ�������˼Ұɣ�\n";
  if(ob->query_skill("qingxin-force",1)<300)
  return "����书��ô�ͣ�ʦ�������˼��ǲ������ġ�\n";
  ob->set_temp("dtsl_fquest_jz/step1",1);
  return "ʦ�������˼�ϲ���徻���㻹�Ǳ�������ˡ�\n";
}

string do_quest2()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_fquest_jz/step1"))
  return "�Ƿ��ܳ�Ϊ���ŵ���Ů����ʦ�������˼Ҿ����ģ��ҿɲ���������\n";
  ob->delete_temp("dtsl_fquest_jz/step1");
  ob->set_temp("dtsl_fquest_jz/step2",1);
  return "������Ϊ���ŵ���Ů������Ҫ��սʤ�Ҳſ��ԡ�\n";
}

int surrender(object killer,object victim)
{
   if(killer->query_temp("dtsl_fquest_jz/step2")){
    killer->delete_temp("dtsl_fquest_jz/step2");
    killer->set_temp("dtsl_fquest_jz/step3",1);
    message_vision("$N��̾һ����û�뵽�����л�������ô��ɫ�ĵ��ӣ�\n",this_object());
    tell_object(killer,"ʦ�������������֣��������������Ҹ�����ʦ�������˼ҵ�������\n");
    tell_object(killer,"ʦ��������˵������˵�����˼��ڳ�������������ƶ����У���ȥ���ҿ��ɣ�\n");
    return 1;}
    return 1;
}

string do_jzzy_quest1()
{
   object ob;
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_jzzy/step5"))
   return "��˵�����ҿ���һ�㶼û��˵����\n";
   ob->set_temp("dtsl_quest_jzzy/step6",1);
   ob->delete_temp("dtsl_quest_jzzy/step5");
   return "��Ҳ���봨���ɴ��������׿��֪���£�����\n"+
          "����а���˴���ְ��ϣ�һ��ǳ��͵����вع��أ����ʯ��\n"+
          "���ϴ����ִ��ʥɮ�����У������֪�Ƿ�ħ����ɣ�������\n"+
          "�ϻ�����ս��£���֪��¸��ʮ��ǰԲ�Ż𻯡�������Թ��\n"+
          "��й���������书��ͽ��ͽ�����ϣ�˵�����˶������ڣ�����\n"+
          "��ɱ��Բʮ�����������ˣ���ɮΪ����������޹�����ֻ��\n"+
          "�����뿪��\n";
}
string do_jzzy_quest2()
{
   object ob;
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_jzzy/step6"))
   return "��˵�����ҿ���һ�㶼û��˵����\n";
   ob->set_temp("dtsl_quest_jzzy/step7",1);
   ob->delete_temp("dtsl_quest_jzzy/step6");
   return "��Щ�޺�����������ʥɮ�Ħ��ʲ�׻���ֱ����ơ�\n";
}

string do_jzzy_quest3()
{
object ob;
   ob=this_player();
   if(!ob->query_temp("dtsl_quest_jzzy/step7"))
   return "��˵�����ҿ���һ�㶼û��˵����\n";
   ob->set_temp("dtsl_quest_jzzy/step8",1);
   ob->delete_temp("dtsl_quest_jzzy/step7");
   return "�Ħ��ʲ����������ʿ�����д�´��ǵĸ�ɮ����\n"+
          "����˷𷨶��Ⱦ�춰����Կյľ��壬�似���ǳ�����ʥ��ȴ��\n"+
          "������ѧ���ˣ�ֻ�۷𷨡����������ڳ�������ң԰���·����\n"+
          "���Ĺ�����\n";
}
