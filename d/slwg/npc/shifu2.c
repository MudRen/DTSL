
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("��ݽ�ͷ", ({"jiao tou","jiao"}));
        set("gender", "����");
        set("age", 44);
        set("long","���Ǿ�������ʯ����ݵĽ�ͷ��\n"+
                   "����Ժ���ѧһЩ�������򣬲�\n"+
                   "��Ҫ��Ǯ�ġ�\n");
        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("kee", 500); 
        set("max_kee", 500);
        set("gin", 100);
        set("max_gin", 100);
        set("sen",300);
        set("max_sen",300);
        set("combat_exp",300000);
        set("shen_type", 1);
         set("env/wimpy", 50);

        set_skill("parry",200);
        set_skill("dodge",200);
        set_skill("force",200);
        set_skill("sword",200);
        set_skill("blade",200);
        set_skill("cuff",200);
        set_skill("strike",200);
        set_skill("finger",200);
        set_skill("spear",200);
        set_skill("leg",200);
        set_skill("hammer",200);
        set_skill("whip",200);
        set("target_id","####");

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
        
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	
	int money;
	money=200;
        switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2:
			write("�����ڵ�ѧ����ÿ��" + MONEY_D->money_str(money) + "���뱸����Ǯ��\n");
			return 0;
	}
        return 1;
}



int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}