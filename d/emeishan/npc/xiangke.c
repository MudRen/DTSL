
inherit NPC;

void create()
{
   set_name("香客",({ "xiang ke","ke"}) );
        set("gender", "男性" );
        set("age",30);
   set("long", "这是一位来峨眉山进香许愿的香客。\n");       
   set("combat_exp",100000);
   set("str", 30);
   set("attitude", "peaceful");
   set("chat_chance",30);  
   setup();
  
}

