
inherit NPC;

void create()
{
   set_name("采参人",({ "man"}) );
        set("gender", "男性" );
           set("long", "这是一个长年在长白山采参的人。\n");
          set("combat_exp", 50000);
        set("inquiry",([
              "梵清惠":"哦，据说她经常在浮云坪一带出现，去年还买过我的人参呢！\n",
              ]));
   set("str",30);
   set("attitude", "peaceful");
   setup();
  
}

