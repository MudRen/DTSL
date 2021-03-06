
#include <ansi.h>

inherit ITEM;

mapping skill_name=([
"force":"基本内功",
"dodge":"基本轻功",
"parry":"基本招架",
"sword":"基本剑法",
"blade":"基本刀法",
"whip":"基本鞭法",
"hammer":"基本锤法",
"strike":"基本掌法",
"leg":"基本腿法",
"finger":"基本指法",
"cuff":"基本拳法",
"staff":"基本杖法",
"spear":"基本枪法",
"unarmed":"基本拳脚",
]);

void create()
{
        string *snames,sname;
        
        snames=keys(skill_name);
        sname=snames[random(sizeof(snames))];
        
        set_name(HIY+skill_name[sname]+NOR, ({sname+" book", "book","shu"}));
        set_weight(500);
        
        set("unit", "本");
        set("long", "这是一本讲述"+skill_name[sname]+"的武学书籍。\n");
        set("material", "paper");
        set("skill", ([
                        "name": sname,
                        "exp_required": 1000+random(1000),
                        "sen_cost": 20+random(10),
                        "difficulty":1+random(5),
                        "max_skill": 100+random(150),
        ]) );
        
}

