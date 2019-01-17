// user_weapon.c ��������

inherit EQUIP;

int wield()
{
	object owner;
	if(!(owner = environment()) return 0;
	if( !owner->is_character() ) return 0;
	if (query("saved") != me->query("id")) return notify_fail("�ⲻ����ı�����\n");
	
	return ::wield();
}

mixed no_get()
{
	object me = this_player();

	if (!me) return 0;
	if (query("saved") != me->query("id")) return "�ⲻ����ı�����\n";
	return 0;
}

void create()
{
	set_name("��ͨ��", ({ "user weapon" }));
	set_weight(5000);
	if (clonep()) {
		set_default_object(__FILE__);
		set("no_get", (: no_get :));
	} else {
		set("unit", "��");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N�ó�$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
		set("wield_maxneili", 100000);
		set("wield_neili", 10);
		set("wield_str", 20);
		set("imbued", 1);
	}
	set("flag", 4);
	set("verbs", ({ "slash", "hack", "slice", "thrust" }) );
	set("weapon_prop/damage", 1);
	set("skill_type", "sword");
	setup();
}

int weapon_setup(mapping mp)
{
	string *vb;
	int i;
	
	if( !clonep(this_object()) )
		return 0;
	if( !mapp(mp) ) return 0;
	
	vb = keys(mp);
	
	for( i = 0; i < sizeof(vb); i++ )
		set(vb[i], mp[vb[i]]);
	
	set_name(mp["name"], mp["id"]);
	set_weight(mp["weight"]);
	set("actions", (: call_other, WEAPON_D, "query_action" :) );
	
	return 1;
}

int weapon_fix()
{	
	delete("weapon_mp/broken");
	delete("broken");	
}
