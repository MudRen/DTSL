
inherit "/std/orgroom/cityroom.c";


void create ()
{
  set ("short","���ٸ���");
  set ("long", @LONG
���������ٵĸ��ã�˭ռ�������Ҳ����ζ��ռ�������ٳǡ���
��䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ���
����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","leshou");
  set("city_name","����");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",5000);
  set("person",1000);
  set("city_type","�е�");
  restore();
  set("check_victory",0);
  set("exits",([
   "southwest":"/d/leshou/beidajie1",
  
  ]));
 
  setup();
  save();
  
 
}
