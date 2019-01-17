
inherit ROOM;

int do_push(string arg);
void create ()
{
  set ("short","����");
  set ("long", @LONG
������ǳ���ĵײ�����������������������ߴ�ͷ��ֱ����������
�׽�ʯ�������У������������ƺ���������ʲô�󷨡�����СϺ����
������������ȥ������һ����Ȥ�������м�����ʯ���ƺ������ƿ�����
LONG);

  set("exits", ([ 

  "east":__DIR__"haidi2",
  "west":__DIR__"haidi3",
  "north":__DIR__"haidi4",
  "south":__DIR__"haidi5",
      ]));

  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_push","push");
}

int do_push(string arg)
{
    object ob,book,fish;
    
    ob=this_player();
    if(!arg||arg!="��ʯ")
    return notify_fail("��Ҫ��ʲô��\n");
    
    if(ob->is_busy())
    return notify_fail("����æ���أ�\n");
    ob->start_busy(3);
    
    
    if(ob->query("family/family_name")!="������"
      ||ob->query("perform_quest/pili")
      ||ob->query("perform_quest/duomeng")
      ||ob->query("perform_quest/yanyu")
      )
    return notify_fail("�����˰��죬���ֽ�ʯ��˿������\n");
    if(ob->query_str()<35)
    return notify_fail("������Լ�������̫С���Ʋ�����ʯ��\n");
    
    message_vision("$N�Ѿ�������ֻ������¡��һ������ʯ���Ա��ƿ���\n",ob);
    tell_object(ob,"�㷢�ֽ�ʯ�±߲���һ���飡\n\n"+
                   "ͻȻ��һֻ�������˹���������Ե��˶����\n\n");
    
    fish=new(__DIR__"obj/shayu");
    book=new(__DIR__"obj/book");
    book->set("owner_ob",ob);
    book->move(fish);
    fish->set_status(ob);
    fish->move(environment(ob));
    fish->kill_ob(ob);
    return 1;
}