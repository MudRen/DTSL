
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string do_quest1();
string do_quest2();
string do_jzzy_quest1();
string do_jzzy_quest2();
string do_jzzy_quest3();
int do_skjf_quest1();
int do_skjf_quest2();
int do_skjf_quest3();

void create()
{
   int i;
   object *ob;
   
   set_name("ʦ����",({ "shi feixuan","shi" }) );
   set("gender", "Ů��" );
   set("age", 23);
   set("long", "���ǴȺ���ի��ʦ������\n");
       
    set("combat_exp",5000000);
   set("int", 30);
   set("per", 30);
    set("max_gin",5000);
    set("max_sen",6000);
    set("max_kee",7000);
    set("max_force",9000);
    set("force",9000);
    set_skill("sword",300);
    set_skill("parry",300);
    set_skill("dodge",300);
    set_skill("finger",300);
    set_skill("literate",300);
    set_skill("force",300);
    set_skill("sekong-jianfa",300);
    set_skill("xiuluo-zhi",300);
    set_skill("wuwang-jing",320);
    set_skill("qingxin-force",300);
    set_skill("lingyun-shenfa",300);

    set("perform_quest/kong",1);
    set("apply_points",2000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform kong") :),
        (: command("perform lingxi") :),
        (: command("execute wuwang") :),
        (: command("exert qingxin") :),
    }));

  
   create_family("�Ⱥ���ի",4,"����");
   set("inquiry",([
      "������":(:do_skjf_quest3:),
      "����":"���ĵ�����ȷ���������˭�ָҺ������������أ�\n",
      "�����":(:do_quest1:),
      "��Ů":(:do_quest2:),
      "��ʯ��":(:do_jzzy_quest1:),
      "�޺�":(:do_jzzy_quest2:),
      "�Ħ��ʲ":(:do_jzzy_quest3:),
      "ɫ�ս���":(:do_skjf_quest1:),
      "��а֮ս":(:do_skjf_quest2:),
      ]));
   setup();
   carry_object(__DIR__"obj/baiyi")->wear();
   ob=children(__DIR__"obj/sekongjian");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"�����е�"+ob[i]->query("name")+"�����������ջ�ȥ�ˣ�\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"��һ�������ˡ�\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/sekongjian")->wield();
  
}

void attempt_apprentice(object ob)
{   
	
	int lev;
	
	if(ob->query("gender")=="����")
	{
	  command("say ���ǴȺ���ի�����е��ӵģ������һ�����ȥ������Ժ�ɣ�\n");
	  return;
	}
	if(ob->query("family")&&ob->query("family/family_name")=="�Ⱥ���ի"
	  &&ob->query("family/generation")<=4)
	{
	  command("say �⻰�Ӻ�˵��\n");
	  return;
	}
	if(ob->query("kar")<24)
	{
	  command("say �������������ڷ���Ե���㻹��Ͷ���������ɰɣ�\n");
	  return;
	}
	if(ob->query("per")<25){
	  command("say �����ò̫���ˣ��ҿɲ�Ҫ�����ĵ��ӣ�");
	  return;
	}
	if(ob->query_int()<31)
	{
	  command("say ���ͷ�Բ������������ú�ѧѧ�����ɣ�\n");
	  return;
	}
	
	if(ob->query("PKS")>=5){
	  command("say ����������̫�࣬�ҿɲ�Ҫ�����ĵ��ӣ�");
	  return;
	}
	
	if(ob->query("bellicosity")>=100){
	  command("say ������ɱ�����أ�����������ŵ��书��");
	  return;
	}
	
	if(ob->query_skill("qingxin-force",1)<100){
	  command("say ����������ƾ���Ϊ̫���ˣ����޷�����Ϊ���ӣ�");
	  return;
	}
	if(ob->query("office_number")<20){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
        lev=ob->query_skill("finger",1);
        lev=lev*lev/(lev+100);
        ob->party_reward_skill("sword",lev);
        tell_object(ob,HIY"��ӻ���ָ�������Ե��˻���������\n"NOR);
	
	command("say �ã���Ȼ�ܰݵ��ҵ����£�˵��������ܹ����������ļ��!\n");
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
  
  if(ob->query_temp("quest_fighter"))
  return "�㻹�ǿ�ȥսʤ�Լ���ľ�˰ɣ�\n";
  
  if(ob->query_skill("qingxin-force",1)<200)
  return "����书��ô�ͣ�ʦ�������˼��ǲ������ġ�\n";
  ob->set_temp("dtsl_fquest_jz/step1",1);
  return "ʦ�������˼�ϲ���徻���㻹�Ǳ�������ˡ�\n";
}

string do_quest2()
{
  object ob,obj;
  
  ob=this_player();
  if(!ob->query_temp("dtsl_fquest_jz/step1"))
  return "�Ƿ��ܳ�Ϊ���ŵ���Ů����ʦ�������˼Ҿ����ģ��ҿɲ���������\n";
  ob->delete_temp("dtsl_fquest_jz/step1");
  ob->set_temp("dtsl_fquest_jz/step2",1);
  
  obj=new(__DIR__"q_shi");
  obj->set("name",ob->name()+"��ľ��");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  
  obj->move(environment(ob));
  
  return "������Ϊ���ŵ���Ů������Ҫ��սʤ���ľ�˲ſ��ԡ�\n";
}
/*
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
*/

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

int do_skjf_quest1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query("perform_quest/kong")){
     command("say ���Ѿ�������ɫ�ս����ľ��裬�Լ�ȥ��߰ɣ�");
     return 1;
   }
   if(ob->query_skill("sekong-jianfa",1)<160){
     command("say ���ɫ�ս���̫���ˣ��޷�������еľ��裡");
     return 1;
   }
   ob->set_temp("perform_quest/kong_action1",1);
   command("say ɫ�ս���������һ�������а֮սʱ�����˽������衣");
   return 1;
}

int do_skjf_quest2()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/kong_action1")){
     command("say ��а֮ս�����ޱȣ�Ҫ�������������������Ҳ�޷�սʤ�纡�");
     return 1;
   }
   
   ob->set_temp("perform_quest/kong_action2",1);
   ob->delete_temp("perform_quest/kong_action1");
   command("say ���꣬�Һ���һս�����ޱȣ�Ҫ�������������������Ҳ�޷�սʤ�纡�\n���껹����ɱ�����ˡ�");
   return 1;
}

int do_skjf_quest3()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("perform_quest/kong_action2")){
     command("say �Һܾ�û�������ˣ���֪�������������");
     return 1;
   }
   
   ob->set_temp("perform_quest/kong_action3",1);
   ob->delete_temp("perform_quest/kong_action2");
   command("say ���������������Ȫ�ľ���֮�������������������õ�һ�λ��䡣");
   return 1;
}
