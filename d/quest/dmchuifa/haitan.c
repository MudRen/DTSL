
inherit ROOM;

int do_jump(string arg);
void create ()
{
  set ("short","��̲");
  set ("long", @LONG
������һƬ��̲�����캣�紵������������������⡣��ˮ��ס��
�Ĵ��Ű��ߵĽ�ʯ������һ����ĺ�������������˵�����и��书����
�ܾͲ��ڴ˴�����֪�����Ǽ١�
LONG);

  set("exits", ([ 

  "south":"/d/dongming/haitan2",
      ]));

  set("valid_startroom", 1);
  set("outdoors","dongming");
  setup();
 
}

void init()
{
 add_action("do_jump","jump");
}

int do_jump(string arg)
{
   object ob;
   
   ob=this_player();
   if(!arg||arg!="��")
   return notify_fail("��Ҫ����������\n");
   if(ob->query_skill("leiting-chuifa",1)<160
    ||ob->query("perform_quest/duomeng")
    ||ob->query("perform_quest/yanyu")
    ||ob->query("perform_quest/pili")
     ){
    ob->start_busy(3);
    return notify_fail("������һ��ײ�����Աߵ���ʯ�ϣ���ð���ǣ�\n");
   }
   message_vision("$N������һ����������ˮ����ȥ��\n",ob);
   ob->move(__DIR__"haidi1");
   return 1;
}
