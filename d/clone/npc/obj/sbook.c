
inherit ITEM;

int do_linghui(string arg);

void create()
{
        set_name("《武学心法》", ({"book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
   set("long", "这是一本《武学心法》，你可以用它来提高[linghui]自己的任何一项技能。\n"+
               "但是只能使用5次。\n");
               set("use_times",5);
               set("no_give",1);
               set("no_drop",1);
               set("no_get",1);
        set("material", "paper");}
        setup();
}

void init()
{

  add_action("do_linghui","linghui");
}

int do_linghui(string arg)
{
   object ob;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("你要领会什么技能？\n");
   if(!ob->query_skill(arg,1))
   return notify_fail("你没学过这个技能。\n");
   if(query("use_times")<=0)
   return notify_fail("这本武学心法已经没什么用了。\n");
   add("use_times",-1);
   ob->set_skill(arg,ob->query_skill(arg,1)+3);
   tell_object(ob,"你的"+to_chinese(arg)+"提高了！\n");
   return 1;
}