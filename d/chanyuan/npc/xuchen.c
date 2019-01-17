
inherit NPC;
inherit F_MASTER;

#include <ansi.h>

int do_action1();
int do_action2();

void create()
{
   set_name("�鳾",({ "xu chen","xu","chen"}));
        set("gender", "����" );
        set("age",26);
   set("long", "���Ǿ�����Ժ�ĸ�ɮ֮һ��\n");
   set("class","bonze"); 
   set("combat_exp", 100000);
   set("str", 28);
   set("per", 22);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("cuff",100);
   set_skill("force",100);
   
   set_skill("wuxiang-shengong",100);
   set_skill("luohan-quan",100);
   set_skill("lianhua-step",100);
   set_skill("bikouchan",100);
   set_skill("chanzong-fofa",110);
   set_skill("literate",110);
   
   set("gin",1000);
   set("max_gin",1000);
   set("kee",800);
   set("max_kee",800);
   set("sen",800);
   set("max_sen",800);
   set("force",1000);
   set("max_force",1000);
   
   set("inquiry",([
     "���":(:do_action1:),
     "����":(:do_action2:),
     ]));
     
   create_family("������Ժ",7,"ɮ��");
   setup();
  
}

void attempt_apprentice(object ob)
{   
	
	if(ob->query("family")
	   &&ob->query("family/family_name")=="������Ժ"
	   &&ob->query("family/generation",1)<=7){
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
	
	tell_object(ob,HIY"\n���Ϊ�˾�����Ժ���׼ҵ��ӣ�\n\n"NOR);
	command("say �����ӷ�ʩ�����ȵ������׼ҵ��ӣ�������ͬ������ʽ����Ϊ���ɵ��ӣ�\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "chanyuan1");
}

int do_action1()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="������Ժ"){
     command("say �㲻�Ǳ��ɵ��ӣ����޷�������ȡ�");
     return 1;
   }
   if(ob->query("class")=="bonze"){
     command("say ���Ѿ���������ˡ�");
     return 1;
   }
   if(ob->query_skill("chanzong-fofa",1)<100){
     command("say ��ķ���Ϊ̫���ˣ������Ȳ�Ҫ��ȵĺã�");
     return 1;
   }
   if(ob->query("PKS")>=5){
     command("say ���������أ����治��Ҫ�����ĵ��ӣ�");
     return 1;
   }
   if(ob->query("bellicosity")>=100){
     command("say ��ɱ�����أ���ô�ᾲ���������ң�");
     return 1;
   }
   command("say �á���ѧϰ��Ҳ��һ��ʱ���ˣ���δ�󳹴��򣬵������·�Ե��\n"+
           "Ҳ���г������ˡ�");
   msg="$N�����Ĺ��£�ֻ��$n����һ�ӣ�$N��ͷ��Ϥ�����¡�\n\n"+
       "$N��ʽ�����ˡ�\n";
   message_vision(msg,ob,this_object());
   ob->set("class","bonze");
   return 1;
}

int do_action2()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="������Ժ"){
     command("say �㲻�Ǳ��ɵ��ӣ��������������ʲô��");
     return 1;
   }
   if(ob->query("class")!="bonze"){
     command("say �㻹���ȳ�����˵�ɡ�");
     return 1;
   }
   
   if(ob->query("PKS")>=5){
     command("say ���������أ���������������⣿");
     return 1;
   }
   if(ob->query("bellicosity")>=100){
     command("say ��ɱ�����أ���������������⣿");
     return 1;
   }
   if(ob->query("family/generation")<=7){
     command("say ������˵Ц��");
     return 1;
   }
   if(time()-ob->query("mud_flags/try_beifen_time")<300){
     command("say �����˵�������˲��ɸ��꣬��ô��ô��������ˣ�");
     return 1;
   }
   
   ob->delete("mud_flags/try_beifen_time");
   msg="$N��$nһЦ���ã������ҿ�����Ĺ�������ˣ�\n";
   message_vision(msg,this_object(),ob);
   
   ob->set_temp("try_beifen",1);
   fight_ob(ob);
   return 1;
}

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
   string msg,newname;
   
   if(killer->query_temp("try_beifen")){
      msg="\n$N��$nһ��ʮ����������ţ������ӷ𣡿������ȷ�ǽ�����һ��������\n"+
          "�Ժ�����Ǳ��ɡ��项�ֱ������ˣ�\n\n";
      message_vision(msg,victim,killer);
      newname=killer->query("name");
      newname=no_color(newname);
      newname="��"+newname[0..1];
      killer->set("name",newname);
      tell_object(killer,HIY"�Ժ���������ǡ�"+newname+"��\n���Ϊ�˾�����Ժ���ߴ����ӡ�\n\n"NOR);
      killer->set("family/generation",7);
      killer->delete_temp("try_beifen");
   }
   return 1;
}

int end_fight(object killer,object victim)
{
     string msg;
   
   if(killer->query_temp("try_beifen")){
      msg="\n$N��$n����һ����˵�������������мǲ����ḡ�������ɵ�һ�������һ���ӡ�\n"+
      "����Ŭ���ɣ���\n\n";
      message_vision(msg,killer,victim);     
      killer->delete_temp("try_beifen");
      killer->set("mud_flags/try_beifen_time",time());
   }
   return 1;
}	
