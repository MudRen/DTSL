
inherit __DIR__"cityroom.c";


void create ()
{
  set ("short","���Ȼ븮��");
  set ("long", @LONG
���������Ȼ�ĸ��ã�˭ռ�������Ҳ����ζ��ռ�������Ȼ�ǡ�
����䱸ɭ�ϣ������ٱ���������ء�ռ����к���Զ��������Լ�
�����������������Ҳ�Ǿ���ս�𲻶ϡ�
LONG);
  
  set("city_id","tuyuhun");
  set("city_name","���Ȼ�");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",5000);
  set("person",1000);
  set("city_type","�е�");
  restore();
  set("check_victory",0);
  set("exits",([
   "south":"/d/tuyuhun/silk8",
  
  ]));
 
  setup();
  save();
  
 
}
