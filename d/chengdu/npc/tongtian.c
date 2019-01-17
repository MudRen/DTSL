
inherit NPC;

#include <ansi.h>

void create()
{
       set_name("����Ө", ({ "xia miaoying","xia"}) );
       set("gender", "Ů��" );
	   set("nickname","ͨ������");
       set("age", 42);
       set("long",
               "������˳�[ͨ������]������Ө��������\n���л�ͨ���������\n");
       set("combat_exp", 400000);
       set("attitude", "peaceful");
	   set("str",27);
	   set("per",23);
	   set("max_gin",500);
	   set("max_kee",500);
	   set("max_sen",800);
	   set("max_force",800);
	   set("force",800);
	   set_skill("force",120);
	   set_skill("unarmed",120);
	   set_skill("parry",120);
	   set_skill("dodge",120);
       set_skill("whip",120);
	   set("inquiry",([
					"ת��ְҵ":"����ת����ְҵΪ\n"+
					         "��������������������������ҩϵ��������ҩʦ����ҩʦ��ɱ�֡�\n"+
					         "�����ʹ������ zhuanzhi ��ת��ְҵ��\n",
	   ]));   
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 

}


void init()
{
	add_action("do_change_vocation","zhuanzhi");
	
}

int do_change_vocation(string arg)
{
	object ob;
	
	ob=this_player();
	
	if(is_busy()){
		command("say ��һ�£���æ���أ�");
		return 1;
	}
	
	if(!ob->query("vocation")){
		command("say ��ûѡ��ְҵ�����ڲ���ת��ְҵ��");
		return 1;
	}
	if(!arg)
		return notify_fail("��Ҫת��Ϊʲôְҵ��\n");
	if(ob->query("change_vocation")){
		command("say ���Ѿ�ת��һ��ְҵ�ˣ�����ת���ˣ�");
		return 1;
	}
	
	switch(arg){
		case "����������":  
			if(ob->query("vocation_fenzhi")=="weapon")
				return notify_fail("�㱾�����Ǳ�����������\n");
			if(ob->query("vocation")=="ҩʦ"){
				if(ob->query_skill("poison",1))
					ob->delete_skill("poison");
				else
					ob->delete_skill("bencao-shuli");
			}
			if(ob->query("vocation")=="ɱ��"){
				ob->delete_skill("yingzi-jianfa");
			}
			ob->set("vocation","����");
			ob->set("vocation_fenzhi","weapon");
			break;
		
		case "����������":  
			if(ob->query("vocation_fenzhi")=="armor")
				return notify_fail("�㱾�����ǻ�����������\n");
			if(ob->query("vocation")=="ҩʦ"){
				if(ob->query_skill("poison",1))
					ob->delete_skill("poison");
				else
					ob->delete_skill("bencao-shuli");
			}
			if(ob->query("vocation")=="ɱ��"){
				ob->delete_skill("yingzi-jianfa");
			}
			ob->set("vocation","����");
			ob->set("vocation_fenzhi","armor");
			break;	
		
		case "��ҩϵ����":  
			if(ob->query("vocation_fenzhi")=="poison")
				return notify_fail("�㱾�����Ƕ�ҩϵ������\n");
			if(ob->query("vocation")=="ҩʦ"){
				if(ob->query_skill("poison",1))
					ob->delete_skill("poison");
				else
					ob->delete_skill("bencao-shuli");
			}
			if(ob->query("vocation")=="ɱ��"){
				ob->delete_skill("yingzi-jianfa");
			}
			ob->set("vocation","����");
			ob->set("vocation_fenzhi","poison");
			break;	
		
		case "��ҩʦ":
			if(ob->query("vocation")=="ҩʦ")
				if(ob->query_skill("bencao-shuli",1))
					return notify_fail("�㱾��������ҩʦ��\n");
			
			if(ob->query("vocation")=="ҩʦ")
				ob->delete_skill("poison");
			if(ob->query("vocation")=="ɱ��"){
				ob->delete_skill("yingzi-jianfa");
			}
			if(ob->query("vocation")=="����"){
				ob->delete_skill("duanzao-jishu");
				ob->delete("vocation_fenzhi");
			}
			ob->set("vocation","ҩʦ");
			break;
		
		case "��ҩʦ":
			if(ob->query("vocation")=="ҩʦ")
				if(ob->query_skill("poison",1))
					return notify_fail("�㱾�����ǰ�ҩʦ��\n");
			
			if(ob->query("vocation")=="ҩʦ")
				ob->delete_skill("bencao-shuli");
			if(ob->query("vocation")=="ɱ��"){
				ob->delete_skill("yingzi-jianfa");
			}
			if(ob->query("vocation")=="����"){
				ob->delete_skill("duanzao-jishu");
				ob->delete("vocation_fenzhi");
			}
			ob->set("vocation","ҩʦ");
			break;
		
		case "ɱ��":
			if(ob->query("vocation")=="ɱ��")
				return notify_fail("�㱾������ɱ�֡�\n");
			if(ob->query("vocation")=="����"){
				ob->delete_skill("duanzao-jishu");
				ob->delete("vocation_fenzhi");
			}
			if(ob->query("vocation")=="ҩʦ"){
				if(ob->query_skill("poison",1))
					ob->delete_skill("poison");
				else
					ob->delete_skill("bencao-shuli");
			}
			ob->set("vocation","ɱ��");
		  break;
		default:
			return notify_fail("��ֻ��ת����ְҵΪ"+
				"��������������������������ҩϵ��������ҩʦ����ҩʦ��ɱ�֡�\n");
	}
	
	ob->set("change_vocation",time());
	ob->add("combat_exp",-ob->query("combat_exp")/100);
	
	command("say �����飬�����飬��·������������... ...");
	command("say ְҵת���ɹ���");
	
	start_busy(2);
	
	return 1;
	
}