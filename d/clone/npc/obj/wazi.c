
#include <ansi.h>
inherit ITEM;

int do_action(string arg);

void create()
{
   set_name(HIC"ʥ��"HIG"����"NOR, ({ "wa zi","zi"}) );
   set_weight(150);
   
     set("material", "��");
     set("unit", "˫");
     set("value",100);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("no_sell",1);     
   
   setup();
}

string long()
{
   
   return this_player()->name()+"��ã�ף��"HIY"ʥ����"NOR"���֣�\n"+
          "��л���"HIC"����˫��"NOR"��֧�֣�\n"+
          "����������·���ϳ��ֹ��ϣ���ϣ���ܹ��õ�������⣡\n"+
          "����һ˫ʥ�����ӣ�����㴩�������ͻ�õ�ʥ���ڵ����\n"+
          HIG"��chuan wa zi��\n"NOR;
       
}

void init()
{
  add_action("do_action","chuan");
}

int do_action(string arg)
{
   object ob;
   ob=this_player();
   
   if(!arg)
   return 0;
   if(!present(arg,ob))
   return 0;
   if(!id(arg))
   return 0;
   
   if(query("owner_ob")!=ob)
   return notify_fail("������Ӳ�����ģ��㲻�ܴ���\n");
   
   tell_object(ob,"\nͻȻԶ���������ֵ�����������æ�����￴��ȥ... ...\n\n");
   write(@LONG
   
   [1;32m ֻ�����һ����һ��ʥ���񻨳�������գ�[2;37;0m 
   
   [5m[1;32m
   ������� ��㣮������㣮
         ����        ����ʥ����������Ŷ~
        ���﨎      ���﨎  
       ��������    �������� ��������㣮���㣮��� ������
      ����������  ���������� ף��ʥ���ڿ��֣�
      ���||���!!���||���㣮��� ��������㣮����
               .  [2;37;0m   
LONG);
   
   ob->add("potential",800);
   ob->add("food",1000);
   ob->add("water",1000);
   
   tell_object(ob,query("name")+"��ͻȻð��һ��Ũ�̣�һʱ�����������������֮�С�\n"+
                  "������ɢ��"+query("name")+"�Ѿ���ʧ�ˡ�\n");
   
   destruct(this_object());
   return 1;
}