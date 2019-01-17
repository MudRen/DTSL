
inherit NPC;
#include <ansi.h>

mapping *quest=({
	([
          "ask":HIW"���� (100+100)/2 ���ڶ���?\n"NOR,
		  "ans":"100",
	]),
	([
	      "ask":HIW"�����峯֮����ʲô����?\n"NOR,
		  "ans":"�Ƴ�",
	]),
});

mapping *name_id=({
	([
		"name":"��",
		"id":"wang",
	]),
	([
		"name":"��",
		"id":"zhao",
	]),
	([
		"name":"��",
		"id":"liu",
	]),
	([
		"name":"ŷ��",
		"id":"ouyang",
	]),
});
string *name=({"�޵�","��","�޻�","��","����"});
int do_answer(string arg);
void create()
{   
    mapping nameid;
	nameid=name_id[random(sizeof(name_id))];
	set_name(nameid["name"]+name[random(sizeof(name))],({ nameid["id"]}) );
        set("gender", "����" );
        set("age", 12);
		
   set("long", "�����ε����������,ר�Ÿ����������[������]�¼���\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

int accept_fight(object ob)
{
	return notify_fail(ob->name()+"Ц��:���Ӷ��ڲ����ְ�!\n");
}

void die()
{  object ob;
   ob=this_player();
   message_vision("$NЦ��:���ǲ���սʿ!\n",ob);
   return;
}

void init()
{
	object *ob;object me,here;int i;
	add_action("do_answer","answer");
	me=this_object();

    here=environment(me);
	ob=all_inventory(here);
	for(i=0;i<sizeof(ob);i++)
	{  if(userp(ob[i]))
		if(!me->query("followed"))
		{
			
				me->set("followed",1);
				me->set_leader(ob[i]);
				message_vision(HIW"$N��������$nһ��ʱ��!\n"NOR,me,ob[i]);
				call_out("ask_quest",30+random(2),me,ob[i]);
				break;
			
		}
	}
	return;
}

void ask_quest(object me,object ob)
{
	mapping que;
	if(!objectp(ob)) {remove_call_out("ask_quest");return;}
	que=quest[random(sizeof(quest))];
	me->set("ans",que["ans"]);
	ob->set_temp("check",1);
	tell_object(ob,que["ask"]);
	remove_call_out("ask_quest");
	call_out("wait",15,me,ob,30);
	return;
}

void wait(object me,object ob,int i)
{
	if(!objectp(ob)) {remove_call_out("wait");return;}
	if(ob->query_temp("check"))
	{
		if(i==30) message_vision(HIW"$Nͱ��ͱ$n,��ʲô����?\n"NOR,me,ob);
		else if(i==20) message_vision(HIW"$N������$n��ͷ:�����,��ô�򵥵����ⶼ����?\n"NOR,me,ob);
		else if(i==10) message_vision(HIW"$N��$n��Ц��:�ҿ���ʮ�а˾��ǻ�������!\n"NOR,me,ob);
		else {
			   message_vision(HIW"$N��$n�е�:�����������,�Һ���Ū������!\n"NOR,me,ob);
	           call_out("goto_rock",1,me,ob);
		}
		i=i-10;
		call_out("wait",10,me,ob,i);
		return;
	}

    remove_call_out("wait");return;
}

void goto_rock(object me,object ob)
{
	if(!objectp(ob)) {remove_call_out("goto_rock");return;}
	me->set_leader(0);
	me->delete("followed");
	ob->delete_temp("check");
	me->delete("ans");
	message_vision("$N����$n̾��:�㻹��ȥ[˼����]ȥ�ڸİ�!\n",me,ob);
	ob->move(__DIR__"siguoya");
    remove_call_out("goto_rock");return;
}

int do_answer(string arg)
{
	object me;string target,ans,answer;object ob;
	me=this_player();
	if(!arg) return notify_fail("��ʹ��answer ���� ����\n");
	if(sscanf(arg,"%s %s",target,ans)!=2)
		return notify_fail("��ʹ��answer ���� ����\n");
	if(!objectp(ob=present(target,environment(me))))
		return notify_fail("����û�������!\n");
	if(!me->query_temp("check"))
		return notify_fail("С����û����������!\n");
	answer=ob->query("ans");
	if(answer!=ans)
		return notify_fail("С�����������ͷ:��ϸ��,�ú�����!\n");
	me->delete_temp("check");
	ob->delete("ans");
	ob->delete("followed");
	ob->set_leader(0);
	message_vision(HIW"$NЦ��:��,���Ǵ���$n��!\n"NOR,ob,me);
	return 1;
}