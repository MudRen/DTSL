
inherit ITEM;

#include <ansi.h>

int query_autoload()
{
	object ob;
	
	ob=environment(this_object());
	if(!ob||!userp(ob)) return 0;
        
        ob->set("load_box_things",query("things"));
        
        
	return 1;
}


int do_put(string arg);
int do_get(string arg);

void create()
{
   set_name("����", ({ "he zi","box","he"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "��");
     set("unit", "��");
     set("value",400);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("no_steal",1);
     set("no_sell",1);
     set("save_box",1);
     set("long","��������ʢ�Ŷ����ĺ��ӡ�\n");
    
   }
   setup();
}


void init()
{
    object ob;
   
   add_action("do_put","fang");
   add_action("do_get","quchu");
     
      ob=environment();
   if(!ob||!userp(ob)) return;
   set("things",ob->query("load_box_things"));
    
   
}


string long()
{
    mapping *things;
    string msg;
    int i;
    
    things=query("things");
    
    if(sizeof(things)<=0)
     return query("long")+"\nĿǰ������û��ʲô������\n";
    msg="";
   for(i=0;i<sizeof(things);i++)
     msg +=HIY"��"+(i+1)+"��"+NOR+" "+things[i]["name"]+"\n";
   
   return query("long")+"\nĿǰ�������У�\n"+msg;
}

int do_put(string arg)
{
   object ob,target;
   mapping new_ob;
   mapping *old_ob;
   
   mixed *klist;
   mapping list;
   int i;
   
   ob=this_player();
   
   if(!arg)
    return notify_fail("��Ҫ��ʲô�����ŵ������\n");
   if(!objectp(target=present(arg,ob)))
   return notify_fail("������û�����������\n");
   
   if(target->query("rumor")||target->query("no_save")||
      target==this_object()||
      target->query("super"))
   return notify_fail("�����Ķ������ܷŵ����档\n");
   
   if(target->is_corpse())
     return notify_fail("��ôС�ĺ��ӿɷŲ���ȥʬ�塣\n");
     
   if(target->is_character())
     return notify_fail("��ôС�ĺ��ӿɷŲ���ȥ���ˡ�\n");
   
   if(target->query("food_supply"))
     return notify_fail("ʳ�ﻹ�Ƿŵ�����ɡ�\n");
   
   if(target->query("skill"))
     return notify_fail("�鼮���������ģ����ǲ�Ҫ�ŵ�����ȥ�ˡ�\n");
   if(target->query("money_id"))
     return notify_fail("Ǯ��������Ϳ����ˣ����±���͵��\n");
   
   if(sizeof(query("things"))>=12)
   return notify_fail("�����Ѿ����ˣ��Ų���ȥ�����ˣ�\n");
   if(target->query("equipped"))
     target->unequip();
   
   list=(mapping)target->query_entire_dbase();
   klist=keys(list);
   
   new_ob=allocate_mapping(sizeof(klist)+3);
   for(i=0;i<sizeof(klist);i++)
    new_ob[klist[i]]=list[klist[i]];
   
   new_ob["name"]=target->name();
   new_ob["place"]=base_name(target);
   new_ob["id"]=target->query("id");
   
   old_ob=query("things");
   if(old_ob) old_ob=old_ob+({new_ob});
    else old_ob=({new_ob});
   set("things",old_ob);
   ob->set("load_box_things",query("things"));
   tell_object(ob,"���"+target->name()+"�ŵ��˺����\n");
   
   destruct(target);
   return 1;
}

int do_get(string arg)
{
   object ob;
   int num;
   mapping *things;
   mapping base;
   string *base_item;
   object new_ob;
   int i;
   
   ob=this_player();
   
   if(!arg||sscanf(arg,"%d",num)!=1) 
   return notify_fail("��Ҫȡ���ڼ�����Ʒ��\n");
   if(num<=0) return notify_fail("�Լ����Լ����ң���\n");
   things=query("things");
   if(sizeof(things)<num)
   return notify_fail("��û���Ǽ���Ʒ��\n");
   
   new_ob=new(things[num-1]["place"]);
   if(!new_ob)
   return notify_fail("�����Ʒ��ʧ�ˣ��뾡�����ʦ˵����\n");
   base_item=keys(things[num-1]);
   for(i=0;i<sizeof(base_item);i++)
     if(base_item[i]!="place")
     new_ob->set(base_item[i],things[num-1][base_item[i]]);
   new_ob->set_name(things[num-1]["name"],({things[num-1]["id"]}));
   if(new_ob->move(ob))
    tell_object(ob,"��Ӻ�����ȡ����һ"+new_ob->query("unit")+new_ob->name()+"��\n");
   else return notify_fail("�㲻�ܴӺ������ó��Ǹ���Ʒ���뱨����ʦ��\n");
   if(num==1)
     things=things[num..<1];
   else things=things[0..num-2]+things[num..<1];
   set("things",things);
   ob->set("load_box_things",query("things"));
   return 1;
}