
inherit NPC;

int is_apprentice_of(object ob)
{
	
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 20, level = ob->query_skill("literate", 1);
          
	if (level > 29) money = 30;
	if (level > 59) money = 80;
	if (level > 89) money = 100;
	if (level > 119) money = 200;
	if (level >=200) money=400;

	ob->delete_temp("mark/literate");
	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2:
			write("�����ڵ�ѧ����ÿ��" + MONEY_D->money_str(money) + "���뱸����Ǯ��\n");
			return 0;
	}
        ob->set_temp("mark/literate", 1);
        return 1;
}


