
#include <ansi.h>
inherit ITEM;

int do_feed(string arg);

mapping *name=({
  ([
     "name":"��ǹ������",
     "id":({"wan","yao"}),
     "long":"����һö��ǹ�����裬���������Ӷ��ô�ҩ��\n",
     "unit":"ö",
     "super":0,
   ]),
  ([
     "name":"����ɢ",
     "id":({"ziwu san","san","yao"}),
     "long":"����һ������ɢ�����ԱȽ�������\n",
     "unit":"��",
     "super":0,
   ]),
   ([
     "name":"��ҩ",
     "id":({"chun yao","yao"}),
     "long":"����һ����ҩ���ɲ�Ҫ���׷��ã�\n",
     "unit":"��",
     "super":0,
    ]),
   ([
      "name":"�嶾ɢ",
      "id":({"wudu san","san","yao"}),
      "long":"����һ���嶾ɢ��ҩ��ǿ�ң����ú������ٳ涣ҧ��\n",
      "unit":"��",
      "super":1,
    ]),
   ([
      "name":"�ߵ�",
      "id":({"she dan","dan","yao"}),
      "long":"����һö���ߵ���\n",
      "unit":"ö",
      "super":0,
   ]),
});

void create()
{
   mapping names;
   
   names=name[random(sizeof(name))];
  
   set_name(names["name"],names["id"]);
   set_weight(50);
  
     set("long",names["long"]);
     set("unit", names["unit"]);
     set("super",names["super"]);
     set("nogive_player",1);
     
   
      setup();
}

void init()
{
   add_action("do_feed","wei");
}

int do_feed(string arg)
{
   object ob,target;
   
   ob=this_player();
   
   if(!query("super"))
   return notify_fail("��Ū�����Ǽ�ҩ�������ô���\n");
   if(!arg)
   return notify_fail("��Ҫ��˭ιҩ��\n");
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("����û������ˡ�\n");
   if(!target->query("youqiuyan"))
   return notify_fail("�㲻�ܸ��Է�ι���ҩ��\n");
   if(living(target))
   return notify_fail("��ѶԷ�Ū����ιҩ�ɣ�\n");
   if(!ob->query_temp("wanhuan_quest1"))
   return notify_fail("��ⲻ��"+target->name()+"���죬�޷�ιҩ��\n");
   
   message_vision("\n$N�⿪$n���죬��"+query("name")+"�ൽ��$n�����\n",
                 ob,target);
   target->set("flag_ob",ob);
   destruct(this_object());
   return 1;
}