
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("����", ({ "he shang","he","shang"}) );
       set("gender", "����" );
       set("age", 30);
       set("long","�����������ĺ���,����ֻ���������������ط𷨡�\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
       set("class","bonze");
	   /*set("inquiry",([
		   "����":(:ask_quest:),
		   ]));*/
       set("jj_flag",3);
       setup();
 carry_object(__DIR__"obj/sengyi")->wear();


}

