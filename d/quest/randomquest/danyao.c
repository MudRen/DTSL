
#include <ansi.h> 
inherit ITEM;

int do_apply(string arg);

void create()
{
   set_name("��ҩ", ({"dan yao","yao"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("rumor",1);
                set("long","����һö��ҩ������Է���[fu]��������Լ���������Ϊ��\n");
               
        }
}


void init()
{
   add_action("do_apply","fu");
   if(userp(environment(this_object()))){
   	set("no_give",1);
   	set("no_get",1);
   	set("no_drop",1);
   	set("no_steal",1);}
}


int do_apply(string arg)
{
    object ob;
    object target;
    
    ob=this_player();
    
    if(!arg)
    return notify_fail("��ʹ�� fu xx �ĸ�ʽ��\n");
    if(!objectp(target=present(arg,ob)))
    return notify_fail("������û�����������\n");
    if(target!=this_object())
    return notify_fail("�㲻�ܷ������������\n");
   
    message_vision(HIC"$N"+"������һö��ҩ����ʱ������������Ϊ���˽�һ������ߣ�\n"NOR,ob);
    ob->add("max_force",2);
    destruct(this_object());
    return 1;
}

