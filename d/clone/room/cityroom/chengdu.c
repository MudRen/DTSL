
inherit "/std/orgroom/cityroom.c";


void create ()
{
  set ("short","�ɶ�����");
  set ("long", @LONG
�����ǳɶ��ĸ��ã�˭ռ�������Ҳ����ζ��ռ���˳ɶ��ǡ���
��䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ���
����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","chengdu");
  set("city_name","�ɶ�");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",4000);
  set("person",1000);
  set("city_type","�е�");
  restore();
  set("check_victory",0);
  set("exits",([
   "south":"/d/chengdu/xidajie1",
  
  ]));
 
  setup();
  save();
  
 
}
