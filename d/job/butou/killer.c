
inherit JOBNPC;

void create()
{
   set_name("����",({ "dao zei","dao","zei" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "����һ�������ڽ����ĵ��������ձ������Ĳ�ͷͨ����\n");

   set("combat_exp",100000);
   set("str", 28);
   set("per", 20);
   set("attitude", "friendly");
   set_skill("dodge",80);
 set_skill("dujie-zhi",80);
 set_skill("linglong-yuquan",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set_skill("force",1500);
   set_skill("xiuluo-zhi",80);
  //  set_skill("sanhua-zhi",80);
  //  set_skill("pojun-quan",80);
  //  set_skill("xukong-zhang",80);
   set_skill("cuff",80);
   set_skill("finger",80);
   set_skill("strike",80);
   set_skill("huanmo-shenfa",80);
   set("max_force",1500);
   set("max_gin",1500);
   set("max_kee",1500);
   set("max_sen",1500);
   set("jiali",50);
   setup();

}

void die()
{
	object ob;object here;
	ob=this_object()->query_temp("last_damage_from");
	if(!ob) return ::die();
	if(member_array(ob->query("id"),query("target_id"))==-1)
	return ::die();
		ob->set_temp("butou_job_ok",1);
	return ::die();
}
