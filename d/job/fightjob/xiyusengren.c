
inherit F_FIGHT_OWNER;


void create()
{
       set_name("西域僧人", ({ "seng ren","seng","ren"}) );
       set("gender", "男性" );
       set("age", 30);
       set("long","这是一个西域僧人，据说他有独特的练功法门。\n");
       set("combat_exp", 12500);
       set("target_id","###");
       set("attitude", "peaceful");
       set("class","bonze");
       set("inquiry",([
	   "木头人":(:do_action1:),
	   "铁罗汉":(:do_action2:),
	   "皮傀儡":(:do_action3:),
       ]));
       
       set("chat_chance",70);
       set("chat_msg",({
       	"西域僧人高喊道：卖练功道具了！木头人、铁罗汉和皮傀儡喽！\n",
       	(:random_move:),
       	}));
              
       setup();

}

