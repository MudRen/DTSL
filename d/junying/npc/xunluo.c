// bing.c �ٱ�
#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("Ѳ�߱�", ({ "xunluo bing", "bing" }));
	set("age", 23);
	set("gender", "����");
	set("long", "����Ѳ�߱�������������ִ��Ѳ������\n");
	set("attitude", "peaceful");

        set("str", 34);
        set("dex", 36);
	set("combat_exp", 30000);
	set("shen_type", 1);
	setup();
        carry_object("/u/smokes/junying/obj/blade")->wield();
        carry_object("/u/smokes/junying/obj/junfu")->wear();
}

void init()
{
object ob;
ob=this_player();
switch(random(2)+1)
{
case 1:
      remove_call_out("abort");
      call_out("abort",1,ob);
      break;
case 2:
     remove_call_out("killu");
     call_out("killu",1,ob);
     break;
}
}

int accept_fight(object me)
{
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	kill_ob(me);
	return 1;
}
int abort(object ob)
{
message_vision("Ѳ�߱���ϸ������$N��˵�������Ǹ�ʲô�ģ����ߣ���\n",ob);
return 1;
}
int killu(object ob)
{
message_vision("Ѳ�߱�����$Nһ�ۣ��������ģ�˵������ϸ����ץ��������\n",ob);
ob->move("/u/smokes/junying/laofan");
message_vision(HIY"$N���ؽ����η���\n"NOR,ob);
return 1;
}