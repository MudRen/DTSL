
inherit ROOM;
int do_move();

void create ()
{
  set ("short","�᷿");
  set ("long", @LONG
������һ��С�᷿��ֻ����������ɵģ�����������ʲô���ڡ���
�ߵ�ǽ�Ϲ���һ�����ӣ�����д�š��롱��������ȥ���Աߺ����м�
�����ӡ�ǽ�ϻ���һ�����ذ��֣��ƺ�������[move]һ�¡�
LONG);

  set("exits", ([ 
  "north":__DIR__"wu"+(1+random(8)),
  "west":__DIR__"wu"+(1+random(8)),
  "east":__DIR__"wu"+2,
  "south":__DIR__"wu"+(1+random(8)),
     ]));

  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_move","move");
}

int do_move()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_lev1_quest_chanzhang/step7"))
  return notify_fail("��ʹ��������Ҳ�Ʋ������֡�\n");
  ob->delete_temp("dtsl_lev1_quest_chanzhang/step7");
  ob->set_temp("dtsl_lev1_quest_chanzhang/step8",1);
  message_vision("$N���˰���һ�¡�\n",ob);
  return 1;
}