
inherit ITEM;

// 这里的名字格式一律如此，每行四个。
string *name=({
"兰草","lan cao","lan","cao",
"灵芝","ling zhi","ling","zhi",
"何首乌","he shouwu","he","shouwu",
});

void create()
{

        int i;

        i=random(sizeof(name));
        i=i-i%4;

        set_name(name[i], ({name[i + 1], name[i + 2], name[i + 3]}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long","这是一棵草药，可以用来炼药。\n");
                set("value", 3);
                set("wei_med",1);
                set("heal",([
                        "heals":50+random(50),
                ]));
        }

        setup();
}
