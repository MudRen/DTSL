
inherit __DIR__"cityroom.c";


void create ()
{
  set ("short","̫ԭ����");
  set ("long", @LONG
������̫ԭ�ĸ��ã�˭ռ�������Ҳ����ζ��ռ����̫ԭ�ǡ���
��䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ���
����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","taiyuan");
  set("city_name","̫ԭ");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",5000);
  set("person",1000);
  set("city_type","�е�");
  restore();
  set("check_victory",0);
  set("exits",([
   "south":"/d/taiyuan/xinggong",
  
  ]));
 
  setup();
  save();
  
 
}
