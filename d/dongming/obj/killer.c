
inherit NPC;

void create()
{
   set_name("强盗",({ "qiang dao","qiang","dao" }) );
   set("gender", "男性" );
   set("long", "这是一个凶恶的强盗。\n");
       
   set("combat_exp",80000);
   
   setup();
  
}
