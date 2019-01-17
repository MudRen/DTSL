
#include <ansi.h>

inherit ITEM;

mapping skill_name=([
"force":"�����ڹ�",
"dodge":"�����Ṧ",
"parry":"�����м�",
"sword":"��������",
"blade":"��������",
"whip":"�����޷�",
"hammer":"��������",
"strike":"�����Ʒ�",
"leg":"�����ȷ�",
"finger":"����ָ��",
"cuff":"����ȭ��",
"staff":"�����ȷ�",
"spear":"����ǹ��",
"unarmed":"����ȭ��",
]);

void create()
{
        string *snames,sname;
        
        snames=keys(skill_name);
        sname=snames[random(sizeof(snames))];
        
        set_name(HIY+skill_name[sname]+NOR, ({sname+" book", "book","shu"}));
        set_weight(500);
        
        set("unit", "��");
        set("long", "����һ������"+skill_name[sname]+"����ѧ�鼮��\n");
        set("material", "paper");
        set("skill", ([
                        "name": sname,
                        "exp_required": 1000+random(1000),
                        "sen_cost": 20+random(10),
                        "difficulty":1+random(5),
                        "max_skill": 100+random(150),
        ]) );
        
}

