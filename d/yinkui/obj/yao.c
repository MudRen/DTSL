
#include <ansi.h>
inherit ITEM;

int do_feed(string arg);

mapping *name=({
  ([
     "name":"金枪不倒丸",
     "id":({"wan","yao"}),
     "long":"这是一枚金枪不倒丸，辟守玄弟子多用此药。\n",
     "unit":"枚",
     "super":0,
   ]),
  ([
     "name":"子午散",
     "id":({"ziwu san","san","yao"}),
     "long":"这是一包子午散，毒性比较厉害。\n",
     "unit":"包",
     "super":0,
   ]),
   ([
     "name":"春药",
     "id":({"chun yao","yao"}),
     "long":"这是一包春药，可不要轻易服用！\n",
     "unit":"包",
     "super":0,
    ]),
   ([
      "name":"五毒散",
      "id":({"wudu san","san","yao"}),
      "long":"这是一包五毒散，药性强烈，服用后浑身如百虫叮咬。\n",
      "unit":"包",
      "super":1,
    ]),
   ([
      "name":"蛇胆",
      "id":({"she dan","dan","yao"}),
      "long":"这是一枚毒蛇胆。\n",
      "unit":"枚",
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
   return notify_fail("你弄到的是假药，毫无用处！\n");
   if(!arg)
   return notify_fail("你要给谁喂药？\n");
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("这里没有这个人。\n");
   if(!target->query("youqiuyan"))
   return notify_fail("你不能给对方喂这个药！\n");
   if(living(target))
   return notify_fail("你把对方弄昏再喂药吧！\n");
   if(!ob->query_temp("wanhuan_quest1"))
   return notify_fail("你扳不开"+target->name()+"的嘴，无法喂药！\n");
   
   message_vision("\n$N扳开$n的嘴，将"+query("name")+"灌到了$n的嘴里！\n",
                 ob,target);
   target->set("flag_ob",ob);
   destruct(this_object());
   return 1;
}