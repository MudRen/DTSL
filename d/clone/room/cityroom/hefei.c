
inherit "/std/orgroom/cityroom.c";


void create ()
{
  set ("short","�Ϸʸ���");
  set ("long", @LONG
�����ǺϷʵĸ��ã�˭ռ�������Ҳ����ζ��ռ���˺Ϸʳǡ���
��䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ���
����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","hefei");
  set("city_name","�Ϸ�");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",5000);
  set("person",1000);
  set("city_type","�е�");
  restore();
  set("check_victory",0);
  set("exits",([
   "south":"/d/hefei/xidajie2",
  
  ]));
 
  setup();
  save();
  
 
}
