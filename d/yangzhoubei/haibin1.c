
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
���ﺣ���ˡ����߾���ãã�Ĵ󺣡��������������Ļ����ߵ�������
���ãã�󺣣����˺���������
LONG);

  set("exits", ([ 
 "northeast":__DIR__"haibin2",
 "southwest":__DIR__"caodi3",
"northwest":"/d/shanhaiguan/nanchengmen"
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_linghui","linghui");

}

int do_linghui()
{
   object ob;
   string time,msg;
   
   ob=this_player();
   
   if(ob->query_skill("fuying-spear",1)<160)
   return 0;
   if(ob->query("perform_quest/fengsha"))
   return 0;
   if(ob->query("perform_quest/fengyu"))
   return 0;
   
   time=NATURE_D->game_time();
   if(strsrch(time,"����")==-1
    &&strsrch(time,"����")==-1
     )
    return notify_fail("������ʲôҲ��᲻������\n");
   
   msg="$N���ź��ߵĺ�Х���������˻��Ĵ��Ű��ߵĽ�ʯ�����ɵöԷ�ӥǹ�����˸������ʶ��\n";
   message_vision(msg,ob);
   ob->set("perform_quest/fengyu",1);
   return 1;
}