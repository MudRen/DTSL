
inherit ROOM;
#include <ansi.h>
#include <job_money.h>
#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"gangkou"
#define TO "/d/gaoli/gangkou"
#include "/std/shiproom.c";
void create ()
{
  set ("short","�ۿ�");
  set ("long", @LONG
�������ݵĶ��ŵĸۿڡ���������ԭһ�󷱻����У���������ĸ�
��Ҳ�Ƿǳ������֡���˵���������������������������Ҳ�кܶ����
�������ˣ��ǳ����֡�������һ������(pai).
LONG);

  set("exits", ([ 
      "west":"/d/yangzhou/dongmen",
      ]));
  set("item_desc",([
  "pai":"ÿ�δ�������ʮ������Ʊ���ա�\n",
  ]));
  set("valid_startroom", 1);
  set("outdoors","yangzhou"); 
  set("no_duhe",1);
  setup();
 
}


int valid_leave(object ob,string dir)
{
  if(dir=="enter"){
  switch(MONEY_D->player_pay(ob,1000)){
  	case 0:return notify_fail("ˮ��˵������Ĵ�Ǯ������!\n");
  	case 2:return notify_fail("ˮ��˵������Ʊ�����Ҳ����ģ�\n");
  	default:break;}
   return ::valid_leave(ob,dir);}	
   return ::valid_leave(ob,dir);
}
