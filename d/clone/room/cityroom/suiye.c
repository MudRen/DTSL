
inherit "/std/orgroom/cityroom.c";


void create ()
{
  set ("short","��Ҷ����");
  set ("long", @LONG
��������Ҷ�ĸ��ã�˭ռ�������Ҳ����ζ��ռ������Ҷ�ǡ���
��䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ���
����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","suiye");
  set("city_name","��Ҷ");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",5000);
  set("person",1000);
  set("city_type","�е�");
  restore();
  set("check_victory",0);
  set("exits",([
   "west":"/d/suiye/guanfu",
  
  ]));
 
  setup();
  save();
  
 
}
