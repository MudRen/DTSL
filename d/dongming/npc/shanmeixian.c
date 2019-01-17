
inherit	F_MASTER;
inherit NPC;
#include <ansi.h>
string do_quest();
string give_book();
int do_action1();

void create()
{
   int i;
   object *ob;
   
   set_name("������",({ "shan meixian","shan","meixian" }) );
   set("gender", "Ů��" );
   set("nickname","�������");
   set("age",48);
   set("long", "���Ƕ����ɵ�����������ˡ�\n");
       
    set("combat_exp",3000000);
   set("per", 26);
    set_skill("whip",300);
    set_skill("parry",300);
    set_skill("dodge",300);
    set_skill("force",300);
    set_skill("literate",300);
    set_skill("dongming-xinfa",300);
    set_skill("bihai-force",300);
    set_skill("shuiyun-xiufa",300);
    set_skill("strike",300);
    set_skill("nishang-piaoming",300);

    set("perform_quest/yanyu",1);
    set("apply_points",2000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform yanyu") :),
        (: command("exert shui") :),
        (: command("exert huo") :),
    }));

    set("max_gin",4000);
    set("max_sen",5000);
    set("max_kee",6000);
    set("max_force",8000);
    set("force",8000);
   create_family("������",2,"����");
      
   set("inquiry",([
     "����ս��":(:do_quest:),
     "ˮ���䷨":(:do_action1:),
     //"��������":(:give_book:),
     ]));
   setup();
   
   carry_object(__DIR__"obj/caiyi")->wear();
   
   ob=children(__DIR__"obj/baiyun-piao");
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
   carry_object(__DIR__"obj/baiyun-piao")->wield();
  
}
void attempt_apprentice(object ob)
{   
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if((int)ob->query("family/generation",1)<=2)
	{   
	   command("say �˻��Ӻ�˵��\n");
	   return;
	}
	
	if(ob->query("family"))
	if(ob->query("family/family_name")=="������")
	if(ob->query("family/master_name")=="������"){
	  command("say ��Ȼ���Ѿ����˵�����Ϊʦ���Ҿ��޷�������Ϊͽ�ˣ�");
	  return;
	}
	
	if(ob->query("gender")=="����"){
	
	command("say �Ҳ����е��ӵģ����������Ͷ�뱾�ɣ�ȥ�����ʰɣ�\n");
	return;
        }
        
        if(ob->query_skill("bihai-force",1)<150){
          command("say �̺��������Ƕ����ɵĸ������㲻�ú�ѧ����ô������Ϊ�����أ�");
          return;
        }
        if(ob->query("office_number")<60){
        command("say ��Ĺ�����ô�ͣ��ҿɲ�Ҫ��ô����ĵ��ӣ�\n");
        return;
        }
            
	command("say ����ս�ҷ������Ƕ���δ�����������⣬�����Ҫ�ú���ϰ���գ������������ɣ�\n");
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
  object ob,obj;
  
  ob=this_player();
  if(ob->query_skill("bihai-force",1)<200)
  return "��Ĺ���̫���ˣ����ڻ��޷���Խ�ģ�\n";
  if(ob->query("family_lingwu")=="dongming")
  return "���Ѿ��Ƕ���ս���ˣ�����ȥ��������Լ�����Ϊ�ɡ�\n";
  if(ob->query_temp("quest_fighter"))
  return "�㻹�ǿ�ȥսʤľ�˰ɣ�\n";
  ob->set_temp("gage_shan",1);
  
  obj=new(__DIR__"q_shanmeixian");
  obj->set("name",ob->name()+"��ľ��");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  
  obj->move(environment(ob));
  
   return "���Ϊ����ս����Ҫ��������û�����ʵ���ˣ������ľ�˴�һ�°ɡ�\n";
}
/*
int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_shan"))
   return 1;
   message("vision",HIG"�������ɡ����������������Х������Ӣ�����ˣ�"+killer->name()+"�ѳ�Ϊ���ɶ���ս��\n"NOR,users());
   message_vision(HIC"$N΢΢һЦ��û�뵽�Ҷ����ɻ����������ĺ���֮�㣡\n"NOR,victim);
   message_vision(HIC"$N��ɫͻȻ�����������������������Ҹ�����һ�����ɵ����ܣ�\n"NOR,victim); 
   tell_object(killer,"����������������ԣ�������˵���������һ�����������ķ��ĵط���\n"+
                      "��˵�ں��ߵ����´�����һֱû���ҵ��������ܲ����ҵ���������ˣ�\n");
   killer->set("family_lingwu","dongming");
   killer->set("title","����ս��");
   return 1;
}
int end_fight(object killer,object victim)
{
  if(!victim->query_temp("gage_shan"))
   return 1;
  message_vision("$N��$n̾�˿������㻹�ǻ�ȥ��ĥ��ĥ���ɣ�\n",killer,victim);
  return 1;
}
*/
string give_book()
{
   object ob,book;
   
   ob=this_player();
   if(ob->query("family/family_name")!="������")
   return "�㲻�Ƕ����ɵ��ӣ�����˵��û�õģ�\n";
   book=new(__DIR__"obj/book");
   book->move(ob);
   return "�������Ȿ��úõ�ѧϰ�ɣ�\n";
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_skill("shuiyun-xiufa",1)<160){
    command("say ���ˮ���䷨��Ϊ̫���ˣ����ڻ��޷�������еľ��ϣ�");
    return 1;
   }
   if(ob->query("perform_quest/duomeng")){
    command("say ���Ѿ�������Ʈ�ν����ľ��ϣ��޷�������ˮ���䷨�ľ��ϣ�");
    return 1;
   }
   if(ob->query("perform_quest/yanyu")){
    command("say ���Ѿ�������ˮ���䷨�ľ��ϣ��Ժ��Լ�ȥ��߰ɣ�");
    return 1;
   }
   if(ob->query("perform_quest/pili")){
    command("say ���Ѿ����������������ľ��ϣ��޷�������ˮ���䷨�ľ��ϣ�");
    return 1;
   }
   
   ob->set_temp("perform_quest/yanyu_action1",1);
   command("say ���������䷨����������ĸ�����󣬴��䷨���ҿ��������������Դ��ġ�");
   return 1;
}
