
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string do_quest();
string give_key();
int do_action1();
int do_answer(string arg);
int do_action2();

void create()
{
   set_name("�˿�",({ "liao kong","liao","kong"}));
        set("gender", "����" );
        set("age", 52);
   set("long", "�����Ǿ�����Ժ�������˿մ�ʦ��\n");
   set("class","bonze"); 
   set("combat_exp",1500000);
   set("str", 28);
   set("per", 25);
   
   set_skill("dodge",400);
   set_skill("parry",400);
   set_skill("force",400);
   set_skill("staff",400);
   set_skill("cuff",400);
   set_skill("finger",400);
   set_skill("strike",400);

   set_skill("tiangang-quan",400);
   set_skill("fumo-zhangfa",400);
   set_skill("dujie-zhi",400);
   set_skill("rulai-shenzhang",400);
   set_skill("lianhua-step",400);

   set_skill("literate",400);
   set_skill("chanzong-fofa",410);
   set_skill("wuxiang-shengong",400);
   set_skill("bikouchan",400);


    set("perform_quest/liudao",1);
    set("perform_quest/pudu",1);
    set("perform_quest/tiangang",1);
    set("apply_points",2000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform liudao") :),
        (: command("perform pudu") :),
        (: command("perform tiangang") :),
        (: command("execute wuyu") :),
    }));

    set("max_gin",3000);
    set("max_sen",5000);
    set("max_kee",5000);
    set("max_force",10000);
    set("force",7000);

   
   create_family("������Ժ",3,"����");
  
   set("inquiry",([
     "��Խ":(:do_quest:),
     "����":(:give_key:),
     "����":(:do_action1:),
     "����":(:do_action2:),
     ]));
   setup();
  
}

void init()
{
   add_action("do_answer","answer");
}


void attempt_apprentice(object ob)
{   
	
	if(ob->query("family")
	   &&ob->query("family/family_name")=="������Ժ"
	   &&ob->query("family/generation",1)<=3){
	    command("say �����Ὺ��Ц��");
	    return;
	}
	if(ob->query("gender")=="Ů��")
	{
	    command("say ����ʩ����ΪŮ��֮���������е���ѧϰ�𷨡���ʩ������ϣ��\n"+
	            "�������Ŵ�ɵ��Ⱥ���ի��");
	    return;
	}
	if(ob->query("couple")){
	  command("say ��Ϊ�˷�ȴ������֮���Σ����Ǿ�����Ժ��Ҫ��˲��ʲ���֮ͽ��");
	  return;
	}
	if((int)ob->query("PKS",1)>=5)
	{
		command("say ʩ�����������أ����������Ϊͽ�أ�");
		return;
	}
	if(ob->query("bellicosity")>=100){
	  command("say ʩ������ɱ�����أ������ר�Ĺ��������أ�");
	  return;
	}
	if(ob->query_skill("wuxiang-shengong",1)<150){
	  command("say ��ġ������񹦡���Ϊ̫���ˣ�����ȥѧϰһ���ٰ���Ϊʦ�ɣ�");
	  return;
	}
	if(ob->query("office_number")<50){
	  command("say ��Ĺ���̫���ˣ��Ҳ�ϲ������ĵ��ӣ�");
	  return;
	}
	if(ob->query("family/generation",1)>5){
	  command("say ��ı���̫���ˣ���ΰ���Ϊʦ��");
	  return;
	}
	if(!ob->query_temp("try_bai_liaokong_ok")){
	  command("say ��û�����ҵĿ��飬�Ҳ�������Ϊͽ�ġ�");
	  return;
	}
	
	
	command("say �����ӷ�ϣ�������ܳ������˵Ŀ��գ���Ϊһ����ɮ�����𷨣�\n");
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
  object ob,obj;
  
  ob=this_player();
  if(ob->query_skill("wuxiang-shengong",1)<200)
  return "��Ĺ���̫���ˣ����ڻ��޷���Խ�ģ�\n";
  if(ob->query("family_lingwu")=="chanyuan")
  return "����������ǰ�ˣ����Ѿ���Խ���ˣ����ǿ�ȥ����ɣ�\n";
  
  if(ob->query_temp("quest_fighter"))
  return "�㻹�ǿ��սʤľ�˰ɣ�\n";
  ob->set_temp("gage_liaokong",1);
  
  obj=new(__DIR__"q_liaokong");
  obj->set("name",ob->name()+"��ľ��");
  obj->set("target_id",ob->query("id"));
  obj->set_temp("owner_ob",ob);
  ob->set_temp("quest_fighter",obj);
  ob->add_temp_array("job_temp_killer",obj);
  obj->move(environment(ob));
  
  return "��С�ӣ��й�����������Ҫ�볬Խ�ң��ͱ���Ӯ�����ľ�ˣ�\n";
}
/*
string no_color(string arg)
{
        arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}


int surrender(object killer,object victim)
{
   object ob;
   string newname;
   
   if(!killer->query_temp("gage_liaokong"))
   return 1;
   message("vision",HIG"��������Ժ��:�˿�����"+killer->name()+HIG+"���֣�����ӯ��������������һ��Ҫ���𷨣��츣���գ�\n"NOR,users());
   
   newname=killer->query("name");
   newname=no_color(newname);
   newname="��"+newname[2..3];
   killer->set("name",newname);
   killer->set("family/generation",3);
   tell_object(killer,HIY"��������Ժ���"+newname+"�����Ϊ����Ժ���������ӣ�\n"NOR);
   
   message_vision(YEL"$N������$n�ļ���ҷ����ں�������ˣ��Ҹ�����һ�����ܣ�\n"NOR,victim,killer);
   tell_object(killer,"�˿մյ���ĸ�ǰ�������������ҷ�ǰ��������һ�����ң����ھͿ�����컯�ˣ�\n");
   ob=new("/d/clone/room/lingwu/chanyuan/key");
   ob->move(killer);
   killer->set("family_lingwu","chanyuan");
   killer->set("title","����ʥɮ");
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
*/
string give_key()
{
  object ob,key;
  ob=this_player();
  if(ob->query("pker"))
  return "�ҷ��ų�����������ͨ���������ǲ��Ұ���\n";
  if(ob->query("family_lingwu")!="chanyuan")
  return "����˵ʲô��ƶɮ����һ�㶼��������\n";
  if(objectp(key=present("key",ob)))
    if(key->query("unique"))
    return "���Ѿ���Կ���ˣ���ȥѧϰ�ɣ�\n";
  key=new("/d/clone/room/lingwu/chanyuan/key");
  key->move(ob);
  tell_object(ob,"�˿ո�����һ���ƽ�Կ�ס�\n");
  return "ϣ�����ܹ��𷨣��츣���գ�\n";
}

int do_action1()
{
   object ob;
   string msg;
   
   ob=this_player();
   
        if(ob->query("family")
	   &&ob->query("family/family_name")=="������Ժ"
	   &&ob->query("family/generation",1)<=3){
	    command("say �����Ὺ��Ц��");
	    return 1;
	}
        
        if(ob->query("family/generation")<=4){
          command("say ���Ѿ��������飬�����ٴο����ˣ�");
          return 1;
        }
        
	if(ob->query("gender")=="Ů��")
	{
	    command("say ����ʩ����ΪŮ��֮���������е���ѧϰ�𷨡���ʩ������ϣ��\n"+
	            "�������Ŵ�ɵ��Ⱥ���ի��");
	    return 1;
	}
	
	if(ob->query("couple")){
	  command("say ��Ϊ�˷�ȴ������֮���Σ����Ǿ�����Ժ��Ҫ��˲��ʲ���֮ͽ��");
	  return 1;
	}
	
	if((int)ob->query("PKS",1)>=5)
	{
		command("say ʩ�����������أ����������Ϊͽ�أ�");
		return 1;
	}
	
	if(ob->query("bellicosity")>=100){
	  command("say ʩ������ɱ�����أ������ר�Ĺ��������أ�");
	  return 1;
	}
	if(ob->query_skill("wuxiang-shengong",1)<150){
	  command("say ��ġ������񹦡���Ϊ̫���ˣ�����ȥѧϰһ���ٰ���Ϊʦ�ɣ�");
	  return 1;
	}
	if(ob->query("office_number")<50){
	  command("say ��Ĺ���̫���ˣ��Ҳ�ϲ������ĵ��ӣ�");
	  return 1;
	}
	if(ob->query("family/generation",1)>5){
	  command("say ��ı���̫���ˣ���ΰ���Ϊʦ��");
	  return 1;
	}
	
	msg="$N΢��˫Ŀ����$n�������\n";
	message_vision(msg,this_object(),ob);
	ob->set_temp("try_bai_liaokong_action1",1);
	return 1;
}

#define ANSWER "���᱾�������������̨��������һ��δ��ǳ�����"


int do_answer(string arg)
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("try_bai_liaokong_action1"))
  return 0;
  if(!arg)
  return notify_fail("�������ʲô��\n");
  if(arg!=ANSWER)
  return notify_fail(query("name")+"΢΢ҡ��ҡͷ���տڲ��\n");
  message_vision("$N΢΢һЦ�����˵�ͷ��\n",this_object());
  ob->set_temp("try_bai_liaokong_ok",1);
  ob->delete_temp("try_bai_liaokong_action1");
  return 1;
}

int do_action2()
{
  object ob;
  string msg;
  
  ob=this_player();
  
  if(ob->query("class")!="bonze"){
   command("say �㻹���ȳ���������ɣ�");
   return 1;
  }
  if(ob->query("PKS")<=0){
    command("say ��û�п�ɱ�䣬�������");
    return 1;
  }
  command("say ��Ȼ���Ѿ���������������Ψ����������������ˣ�");
  msg="\n$N���ڵ��ϣ������е��������ӷ�\n\n"+
      "$n�е����ຣ�ޱߣ���ͷ�ǰ���\n\n"+
      "$Nʹ���һЦ��ȫ��������ײ������\n"+
      "ֻ���������죬$Nȫ������������ѣ�\n\n";
  message_vision(msg,ob,this_object());
  ob->set_temp("last_damage_msg",ob->name()+"�����Ծ��ˣ�");
  ob->delete_temp("last_damage_from");
  ob->add("PKS",-1);
  ob->die();
  ob->delete_temp("last_damage_msg");
  ob->set("last_damage_msg","�����Ծ�");
  return 1;
}
