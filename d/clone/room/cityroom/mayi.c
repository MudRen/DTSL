
inherit "/std/orgroom/cityroom.c";


void create ()
{
  set ("short","���ظ���");
  set ("long", @LONG
���������صĸ��ã�˭ռ�������Ҳ����ζ��ռ�������سǡ���
��䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ���
����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","mayi");
  set("city_name","����");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",2000);
  set("person",500);
  set("city_type","С");
  restore();
  set("check_victory",0);
  set("exits",([
   "southwest":"/d/mayi/center",
  
  ]));
 
  setup();
  save();
  
 
}
