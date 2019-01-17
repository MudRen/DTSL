
inherit ITEM;

int do_action(string arg);

void create()
{
   set_name("��������", ({ "dao jue","jue","bai_songque_linghui_book" }) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("nogive_player",1);
     set("no_drop",1);
     set("eff_times",3);
     set("long", "����һ���飬��˵���Դ���������������\n");
   }
  
   setup();
}

void init()
{
  add_action("do_action","linghui");
}

int do_action(string arg)
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("��Ҫ���ʲô��\n");
   if(!id(arg))
   return notify_fail("�������������ᣡ\n");
   
   if(random(100)<80){
      add("eff_times",-1);
      msg="$Nڤ˼���룬ȴ˿����᲻��ʲô����\n";
      message_vision(msg,ob);
      if(query("eff_times")<=0){
      	ob->set("char_lev/bai_songque_fail",1);
      	ob->save();
      	destruct(this_object());
      	return 1;
      }
     return 1;
   }
    
   msg="$N���������ͼ����ͻȻ������֣����һ��������ᵽ�ˣ���\n";
   message_vision(msg,ob);
   ob->set("char_lev/bai_songque_ok",1);
   ob->save();
   destruct(this_object());
   return 1;
}