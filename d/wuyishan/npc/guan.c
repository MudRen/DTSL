
inherit F_MASTER;
inherit NPC;
void create()
{
   int i;
   object *ob;
   set_name("����",({ "wan wan","wan"}) );
        set("gender", "Ů��" );
	set("title","��������");	
        set("age", 22);
   set("long", "���������ɵĊ���������ħ��Ҳ����������һ�����ġ�\n");
       
   set("combat_exp",3000000);
   set("str", 25);
   set("per", 29);
   set("attitude", "peaceful");
   set_skill("unarmed",280);
   set_skill("dodge",280);
   set_skill("parry",280);
   set_skill("force",280);
   set_skill("sword",280);
   set_skill("strike",280);
   set_skill("cuff",280);
   set_skill("jiutian-huanzhang",280);
   set_skill("linglong-yuquan",280);
   set_skill("tianmo-dafa",280);
   set_skill("tianmo-jianfa",280);
   set_skill("tianmo-huanzong",280);
   set_skill("tianmo-dai",300);
   set_skill("dagger",300);
   set_skill("tianmo-zhan",300);
   set("hand",({"tianmo-dai","jiutian-huanzhang","linglong-yuquan"}));
   set("dodge",({"tianmo-huanzong"}));
   set("force_skill",({"tianmo-dafa"}));
   set("sword",({"tianmo-jianfa"}));
   set("dagger",({"tianmo-zhan"}));
   set("gin",6000);
   set("max_gin",6000);
   set("kee",6000);
   set("max_kee",6000);
   set("sen",6000);
   set("max_sen",6000);
   set("force",6000);
   set("max_force",6000);
   create_family("������",3,"����");
   set("class","yin_guan");
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
	   (:perform_action,"lingxiao":),
   }));
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   ob=children(__DIR__"obj/dagger");
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
   carry_object(__DIR__"obj/dagger")->wield();
  
}
void attempt_apprentice(object ob)
{
	
	if(ob->query("gender")!="Ů��")
	{
	  command("say ��ֻ��Ů���ӵģ��㻹�����˰ɣ�\n");
	  return;
	}
	if(ob->query_int()<31)
	{
	  command("say �������̫���ˣ����޷�����Ϊͽ��\n");
	  return;
	}
	if(ob->query("family")&&ob->query("family/family_name")=="�Ⱥ���ի")
	{
	  command("say �ߣ��Ҳ�ȥ��������ˣ��㻹������Ұ����\n");
	  this_object()->kill_ob(ob);
	  return;
	}
	if((int)ob->query_skill("tianmo-dafa",1)<160)
	{
		tell_object(ob,"���[��ħ��]���δ��,���ܰ���Ϊʦ?\n");
		return;
	}
	command("say ��,��Ҫ�úú���ѧ��������ܴȺ���ի!\n");
	command("recruit "+ob->query("id"));
	return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yin_guan");
}

