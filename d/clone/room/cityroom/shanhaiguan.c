
inherit "/std/orgroom/cityroom.c";


void create ()
{
  set ("short","ɽ���ظ���");
  set ("long", @LONG
������ɽ���صĸ��ã�˭ռ�������Ҳ����ζ��ռ����ɽ���سǡ�
����䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ�
�����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","shanhaiguan");
  set("city_name","ɽ����");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",5000);
  set("person",1000);
  set("city_type","�е�");
  restore();
  set("check_victory",0);
  set("exits",([
   "out":"/d/shanhaiguan/yamendating",
  
  ]));
 
  setup();
  save();
  
 
}
