
inherit NPC;

void create()
{
   set_name("̫��",({ "tai jian","tai","jian" }) );
        set("gender", "����" );
        set("age", 30);
   set("long", "���������ʹ���һ��̫�ࡣ\n");
       
   set("combat_exp", 50);
   set("str", 10);
   set("per", 22);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	object ob;
	ob=this_player();
	
	if(!ob||is_fighting()) return;
	remove_call_out("welcome");
	call_out("welcome",1,ob);
	
}

void welcome(object ob)
{
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
	switch(random(2))
	{
	case 0:
	command("say �����⼸�컹Ҫ��Ů�������ǳ���ˣ�");
	break;
	
	case 1:
	command("say ����û�£�����С���Ӷ�Ǯȥ��");
	}
	
}
