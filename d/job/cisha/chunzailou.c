inherit ROOM;

int do_install(string arg);

void create ()
{
  set ("short","����¥");
  set ("long", @LONG
�����ǾŽ��Ĵ�԰�ԵĴ���¥�������ǾŽ��������ļ�Ժ�������
Ů���䲻�Ϲ�ɫ���㣬��Ҳ�Ƶ����ǳ��������ˡ��м������û�֦��
չ��Ů�������ſ��к��ſ��ˡ�����ķ��䲻ʱ������Ц������������
¥�����滹��һ��С���꣬��Ӧ������ɫ����ʳ��
LONG);

  set("exits", ([ 

  "down":__DIR__"chunyuan",
         ]));
  set("objects",([
     __DIR__"jiuke":1,
     __DIR__"jianke":1,
     __DIR__"zhanggui":1,
     __DIR__"girl":1,
     "/d/job/xiang/xiang":1,
     ]));
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object ob,string dir)
{
  if(ob->query_temp("dtsl_job_cisha/step3")&&dir=="down"&&
     !ob->query_temp("dtsl_job_cisha/step4"))
  return notify_fail("������¥̫Σ���ˣ��㻹����������������ɣ�\n");
  return ::valid_leave(ob,dir);
}
