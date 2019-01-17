
inherit ROOM;

int do_move();
void create ()
{
  set ("short","�᷿");
  set ("long", @LONG
������һ��С�᷿��ֻ����������ɵģ�����������ʲô���ڡ���
�ߵ�ǽ�Ϲ���һ�����ӣ�����д�š��ҡ���������ȥ���Աߺ����м�
�����ӡ�ǽ�ϻ���һ�����ذ��֣��ƺ�������[move]һ�¡�
LONG);

  set("exits", ([ 
  "north":__DIR__"wu"+(1+random(8)),
  "west":__DIR__"wu"+5,
  "east":__DIR__"wu"+(1+random(8)),
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
  object weapon;
  ob=this_player();
  if(!ob->query_temp("dtsl_lev1_quest_chanzhang/step9"))
  return notify_fail("��ʹ��������Ҳ�Ʋ������֡�\n");
  ob->delete_temp("dtsl_lev1_quest_chanzhang/step9");
  ob->set_temp("dtsl_lev1_quest_chanzhang/step10",1);
  message_vision("$N���˰���һ�¡�\n",ob);
  weapon=new(__DIR__"jinlong-zhang");
  message_vision("$Nֻ������һ����ǽ���ѿ�һ������һ�����Ȼ�����������\n",ob);
  weapon->move(ob);
  return 1;
}