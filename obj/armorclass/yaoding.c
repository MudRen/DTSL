
inherit ITEM;

#include "itemsave.h"

void create()
{
        set_name("ҩ��", ({ "yao ding","ding","yaoshi_yaoding"}) );
        set("long", "����һ������ҩ���С����\n");
        set("unit", "��" );
        set("yaoshi_tool",1);
        set_max_encumbrance(2000000);
        setup();
}

int is_container() { return 1; }

void init()
{
  add_action("do_put","put");

}

int do_put(string arg)
{
   object ob,obj;
   
   ob=this_player();
   
   if(!arg) return notify_fail("��Ҫ��ʲô�ŵ�ҩ���\n");
   obj=present(arg,ob);
   
   if(!obj) return notify_fail("������û�����������\n");
   
   if(sizeof(all_inventory(this_object()))>=20)
   return notify_fail("ҩ�����ҩ��̫���ˣ�\n");
   
   if(!obj->query("medicine_type")&&
      !obj->query("poison_type")
     )
     return notify_fail("��ֻ����ҩ���з�ҩ�\n");
   
   message_vision("$N��"+obj->query("name")+"�ŵ���ҩ���\n",ob);
   
   obj->move(this_object());
   
   return 1;
}