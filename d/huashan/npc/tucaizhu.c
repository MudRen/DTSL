
inherit NPC;

void create()
{
   set_name("������",({ "tu caizhu","caizhu"}) );
   set("gender", "����" );
   set("age", 40);
   set("long", "����һ�������������ڸ��Լ���Ů����Ů����\n");
       
   set("combat_exp", 20000);
   set("str", 18);
   set("inquiry",([
	   "Ů��":"�ҵ�Ů��һ��Ҫ��Ǯ��û��Ǯ���붼���룡\n",
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

