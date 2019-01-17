// vocation.c
// Create by Gmm@Jianghu 1999-8-22

#include <ansi.h>
inherit NPC;
int set_vocation(string yn,string number);

void create()
{
	set_name("С����", ({ "fang fang","fang" }));
	set("title", HIW"ְҵ������"NOR);
	set("gender", "����");
	set("age", 18);
	set("long","С����ר��Ϊ��������ְҵ����ҷ���ְҵ��\n");
	set("combat_exp", 100000000);
	set("attitude", "friendly");
	set("per",30);
	setup();
}

void init()
{	
	add_action("do_pick", "pick");
}

int accept_fight(object me)
{
	command("? " + this_player()->query("id"));
	command("say �����æ����Ҫ�����뵽������ȥ��лл��");
	return 0;
}

int do_pick(string number)
{
	if (this_player()->query("vocation") && !wizardp(this_player())) return notify_fail("���Ѿ���ְҵ�ˣ�\n");
	if (!number) return notify_fail("����������Ҫ��ְҵ��š�\n");
	switch(number)
	{
		case "1":
			cat("/doc/vocation/swordman");
			break;
		case "2":
			cat("/doc/vocation/robber");
			break;
		case "3":
			cat("/doc/vocation/fighter");
			break;
		case "4":
			cat("/doc/vocation/official");
			break;
		case "5":
			cat("/doc/vocation/shaman");
			break;
		case "6":
			cat("/doc/vocation/theif");
			break;
		case "7":
			cat("/doc/vocation/beggar");
			break;
		case "8":
			cat("/doc/vocation/doctor");
			break;
		case "9":
			cat("/doc/vocation/weaponman");
			break;
		case "10":
			cat("/doc/vocation/businessman");
			break;
		case "11":
			cat("/doc/vocation/nosex");
			break;
		case "12":
			cat("/doc/vocation/bonze");
			break;
		default:
			return notify_fail("��ֻ���ڣ���������ѡ��\n");
			break;
	}
	write(HIR"��ע�⣺ְҵһ��ȷ������Ӱ�����ڽ�����һ���������޷����ġ�\n\n"NOR);
	write(HIW"��ȷ��Ҫѡ������ְҵô��(y/n)"NOR);
	input_to ("set_vocation",number);
	return 1;
}

int set_vocation(string yn,string number)
{
	object me;
	me = this_player();
	if (yn!="y")
	{
		write(HIW"��ô��������ѡ��ְҵ��\n"NOR);
		return 1;
	}
	else switch(number)
	{
		case "1":
			me->set("vocation","swordman");
			if (me->query("gender")=="����") me->set("title","��������");
			else me->set("title","����Ů��");
		break;
		case "2":
			me->set("vocation","robber");
			if (me->query("gender")=="����") me->set("title","��ͽ");
			else me->set("title","Ů��");
		break;
		case "3":
			me->set("vocation","fighter");
			me->set("title","�䶷��");
		break;
		case "4":
			me->set("vocation","official");
			if (me->query("gender")=="����") me->set("title","С��");
			else me->set("title","Ů��");
		break;
		case "5":
			me->set("vocation","shaman");
			if (me->query("gender")=="����") me->set("title","��������");
			else me->set("title","Ů��ʿ");
		break;
		case "6":
			me->set("vocation","theif");
			if (me->query("gender")=="����") me->set("title","С͵");
			else me->set("title","Ů��");
		break;
		case "7":
			me->set("vocation","beggar");
			if (me->query("gender")=="����") me->set("title","Ҫ����");
			else me->set("title","Ů��ؤ");
		break;
		case "8":
			me->set("vocation","doctor");
			me->set("title","���ҽ��");
		break;
		case "9":
			me->set("vocation","weaponman");
			me->set("title","������");
		break;
		case "10":
			me->set("vocation","businessman");
			me->set("title","����С��");
		break;
		case "11":
			me->set("vocation","nosex");
			if (me->query("gender")=="����") me->set("title","С̫��");
			else return notify_fail("Ů�Բ��ܵ�̫�࣡\n");
		break;
		case "12":
			me->set("vocation","bonze");
			if (me->query("gender")=="����") me->set("title","С����");
			else me->set("title","С���");
		break;
	}
	write(HIW"��ѡ���ְҵ�ǣ�"HIY + to_chinese(me->query("vocation")) + HIW"��ף�������죡\n"NOR);
	return 1;
}