
inherit __DIR__"cityroom.c";


void create ()
{
  set ("short","���⸮��");
  set ("long", @LONG
����������ĸ��ã�˭ռ�������Ҳ����ζ��ռ��������ǡ���
��䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ���
����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","saiwai");
  set("city_name","����");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",1000);
  set("person",100);
  set("city_type","С");
  restore();
  set("check_victory",0);
  set("exits",([
   "south":"/d/saiwai/shop",
  
  ]));
 
  setup();
  save();
  
 
}
