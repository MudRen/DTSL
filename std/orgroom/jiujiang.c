
inherit __DIR__"cityroom.c";


void create ()
{
  set ("short","�Ž�����");
  set ("long", @LONG
�����ǾŽ��ĸ��ã�˭ռ�������Ҳ����ζ��ռ���˾Ž��ǡ���
��䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ���
����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","jiujiang");
  set("city_name","�Ž�");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",5000);
  set("person",1000);
  set("city_type","�е�");
  restore();  
  set("check_victory",0);
  set("exits",([
   "out":"/d/jiujiang/yamen",
  
  ]));
 
  setup();
  save();
  
 
}
