
#include <ansi.h> 
inherit ITEM;

int do_apply(string arg);

void create()
{
   set_name("丹药", ({"dan yao","yao"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("rumor",1);
                set("long","这是一枚丹药，你可以服用[fu]它来提高自己的内力修为。\n");
               
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
    return notify_fail("请使用 fu xx 的格式。\n");
    if(!objectp(target=present(arg,ob)))
    return notify_fail("你身上没有这个东西。\n");
    if(target!=this_object())
    return notify_fail("你不能服用这个东西。\n");
   
    message_vision(HIC"$N"+"服下了一枚丹药，顿时觉得内力的修为有了进一步的提高！\n"NOR,ob);
    ob->add("max_force",2);
    destruct(this_object());
    return 1;
}

