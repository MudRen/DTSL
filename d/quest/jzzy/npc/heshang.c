
inherit NPC;
string do_quest();
void create()
{
       set_name("和尚", ({ "he shang","he","shang"}) );
       set("gender", "男性" );
       set("age",18);
       set("long","这是在这家寺庙出家的小和尚。\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
       set("class","bonze");
	   set("inquiry",([
		   "主持":(:do_quest:),
		   ]));
       setup();
 
}
string do_quest()
{
 
  return "主持因开罪了魔门里一个极难缠的人物，\n"+
         "故寺内的和尚均到附近的寺院栖身避祸，\n"+
         "一天不摆平争执，绝不敢回来。\n";
}