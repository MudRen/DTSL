
#include <ansi.h> 
inherit ITEM;

int do_apply(string arg);

void create()
{
   set_name("�����⸿ӡ��", ({"book"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("eff_times",2);
                set("rumor",1);
                set("random_quest",1);
                set("long","����һ�������⸿ӡ���������ʹ��[shiyong]��������Լ����书��\n");
               
        }
}


void init()
{
   add_action("do_apply","shiyong");
   if(userp(environment(this_object()))){
   	set("no_give",1);
   	set("no_get",1);
   	set("no_drop",1);
   	set("no_steal",1);}
}

int is_get_of(object me,object ob)
{
   object *inv;
   int i;
   
   inv=all_inventory(me);
   for(i=0;i<sizeof(inv);i++)
    if(inv[i]->query("random_quest"))
      return notify_fail("����������������\n");
   return 1;
}

int do_apply(string arg)
{
    object ob;
    object target;
    string target_name;
    int ap,vp;
    
    ob=this_player();
    
    if(!arg||sscanf(arg,"on %s",target_name)!=1)
    return notify_fail("��ʹ�� shiyong on Ŀ�� �ĸ�ʽ��\n");
    if(!objectp(target=present(target_name,environment(ob))))
    return notify_fail("����Χû������ˡ�\n");
    if(!ob->is_fighting(target))
    return notify_fail("�ⲻ��������ս����Ŀ�ꡣ\n");
    
    if(query("eff_times")<=0){
    delete("no_get");
   delete("no_give");
   delete("no_steal");
   delete("no_drop");
    return notify_fail("���ӡ���Ѿ�û��ʲô�ô��ˡ�\n");}
    
    message_vision(HIY"$N"+HIY+"���˿����е�"+name()+"����ʱ������ѧ��Ϊ���˽�һ������ߣ�\n"NOR,ob);
    message_vision(MAG"\n$N"+MAG+"�͵س�$n"+MAG+"���ؿ�ץȥ��\n"NOR,ob,target);
    ob->add_temp("apply/dodge",200);
    
    add("eff_times",-1);
    
    if(query("eff_times")<=0)
     call_out("dest_ob",5);
    
    ap=COMBAT_D->get_attack(ob,target,ob->query("actions"),0);
    vp=COMBAT_D->get_dodge(ob,target);
  
    if(living(target)&&(((ap-vp*2/3)>50+random(50))||!living(target)||random(ap+vp)>vp
     ||vp<3*ap)){
     	 message_vision(YEL"$N"+YEL+"��ʱ����������к�������������ĵػ��˼��Σ�\n"NOR,target);
         target->set("force",0);}
    else
      message_vision("$N����ḻ���ܿ���$n�����ƣ�\n",target,ob);
    
    ob->add_temp("apply/dodge",-200);
    
    return 1;
}

void dest_ob()
{
   tell_object(environment(this_object()),name()+"�����������Ƭ�����紵ɢ�ˡ�\n");
   destruct(this_object());
   return;
}