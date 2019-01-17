
#include <ansi.h>

inherit ITEM;

int do_zhong(string arg);

void create()
{
   set_name(HIG"����"NOR, ({ "shu zhong","shu","zhong"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "Щ");
     set("long","����һЩ���֣�������(zhong)�ڵ��ϡ�\n");
     set("nogive_player",1);
   }
   setup();
}

void init()
{
  add_action("do_zhong","zhong");
}

#define HERE "/d/huashan/"

string *where=({
HERE+"julingzu",HERE+"wushangdong",HERE+"yunvfeng",HERE+"chaoyangfeng",HERE+"yingyangdong",
HERE+"quanzhenya",HERE+"jintiangong",HERE+"luoyanfeng",HERE+"lianhuafeng",HERE+"lianhuaping"
});

int do_zhong(string arg)
{
   object ob;
   string here;
   
   ob=this_player();
   if(!ob->query_temp("try_bai_buchen_actoin1"))
   return 0;
   if(!arg)
   return notify_fail("��Ҫ��ʲô��\n");
   if(!present(arg,ob))
   return notify_fail("������û�����������\n");
   if(!id(arg))
   return notify_fail("������������֡�\n");
   
   here=base_name(environment(ob));
   
   if(member_array(here,where)==-1)
    return notify_fail("������ֲ����������\n");
   
   message_vision(HIY"$N"+HIY+"��������������ƹ��������ӷ𣡣�\n"NOR+
   "$N������һ�����֡�\n",ob);
   
   where=where-({here});
   if(sizeof(where)<=0){
   	
   	ob->set_temp("try_bai_buchen_ok",1);
   	ob->delete_temp("try_bai_buchen_actoin1");
   	destruct(this_object());
   	
   }
   
   return 1;
}