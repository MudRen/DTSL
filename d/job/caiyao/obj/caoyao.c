
inherit ITEM;

// ��������ָ�ʽһ����ˣ�ÿ���ĸ���
string *name=({
"����","lan cao","lan","cao",
"��֥","ling zhi","ling","zhi",
"������","he shouwu","he","shouwu",
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
                set("unit", "��");
                set("long","����һ�ò�ҩ������������ҩ��\n");
                set("value", 3);
                set("wei_med",1);
                set("heal",([
                        "heals":50+random(50),
                ]));
        }

        setup();
}
