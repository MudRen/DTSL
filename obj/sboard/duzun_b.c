
inherit "/std/sboard.c";

int do_appoint(string arg);

void create()
{
        set_name("����Ӣ�۰�", ({ "yingxiong bang","bang" }) );
        set("location", "/d/chengdu/zhutang");
        set("board_id", "duzun_b");
        set("deadtimes",0);
        set("money",0);
        set("exp",0);
        set("long", "���Ƕ���Ӣ�۰�\n" );
        seteuid(ROOT_UID);
        setup();
        set("capacity", 200);
       
}

int do_appoint(string arg)
{
   object me,ob;string name,hat;int i;
   me=this_player();
   if(!arg||sscanf(arg,"%s %s",name,hat)!=2)
   return notify_fail("��ʹ��renming(appoint) ĳ�� ĳְ��\n");
   if(me->query("shili/leader")!="duzun_b")
   return notify_fail("�㲻�Ƕ��𱤵ı�����û�����Ȩ����\n");
   if(!objectp(ob=present(name,environment(me))))
    return notify_fail("����û������ˡ�\n");
 
   if(ob->query("shili/name")!=me->query("shili/name"))
   return notify_fail("���������һ����������������ְ��\n");
   
   if(strlen(hat)>20)
   	return notify_fail("��üͷһ�壬�������ְ�������ʵ��̫���ˡ�\n");
   	
   ob->set("shili/guanzhi",hat);
   CHANNEL_D->do_channel(this_object(), "rumor",
   sprintf("���𱤱�������%sΪ%s!\n",ob->name(),hat));
   return 1;
} 