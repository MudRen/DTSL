
inherit __DIR__"cityroom.c";


void create ()
{
  set ("short","���帮��");
  set ("long", @LONG
�����Ƕ���ĸ��ã�˭ռ�������Ҳ����ζ��ռ���˶���ǡ���
��䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ���
����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","dingxiang");
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
   "east":"/d/dingxiang/huanggong",
  
  ]));
 
  setup();
  save();
  
 
}
