
#include <ansi.h> 
inherit ITEM;

int do_apply(string arg);

void create()
{
   set_name("����ѧ�ķ���", ({"book"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("eff_times",1);
                set("rumor",1);
                set("long","����һ������ѧ�ķ�������������[linghui]��������Լ����书��\n");
               
        }
}


void init()
{
   add_action("do_apply","linghui");
   if(userp(environment(this_object()))){
   	set("no_give",1);
   	set("no_get",1);
   	set("no_drop",1);
   	set("no_steal",1);}
}

int do_apply(string arg)
{
    object ob;
    
    ob=this_player();
    
    if(!arg)
    return notify_fail("��ʹ�� linghui xx �ĸ�ʽ��\n");
    if(!ob->query_skill(arg,1))
    return notify_fail("��û��ѧ��������ܡ�\n");
    
    if(query("eff_times")<=0){
    delete("no_get");
   delete("no_give");
   delete("no_steal");
   delete("no_drop");
    return notify_fail("�Ȿ���Ѿ�û��ʲô�ô��ˡ�\n");}
    
    message_vision(HIY"$N"+HIY+"���˿����е�"+name()+"����ʱ����"+to_chinese(arg)+"���˽�һ������ߣ�\n"NOR,ob);
    
    ob->improve_skill(arg,ob->query_int()*ob->query("max_pot")*2/3);
    
    add("eff_times",-1);
    
    if(query("eff_times")<=0)
     call_out("dest_ob",5);
       
    return 1;
}

void dest_ob()
{
   tell_object(environment(this_object()),name()+"�����������Ƭ�����紵ɢ�ˡ�\n");
   destruct(this_object());
   return;
}