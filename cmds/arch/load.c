/***
��ȡ��ҵĵ���������ҵ������Ƶ�NPC���ϣ�Ȼ��
�ƶ�����ʦ��ߡ�
*****/

#include <job_money.h>
void create()
{
  seteuid(ROOT_UID);
}

int main(object me,string id)
{
   object ob,user,clone_user;	
   
   if(!id)
   return notify_fail("��ʹ�� load id ��ʽ.\n");
   ob=new(LOGIN_OB);
   ob->set("id",id); 
   if(!ob->restore())
   return notify_fail("��ȡ����ʧ�ܣ�\n");
   user=LOGIN_D->make_body(ob);
   if(!user)
   return notify_fail("��ȡ����ʧ�ܣ�\n");
   if(!user->restore())
   return notify_fail("��ȡ����ʧ�ܣ�\n");
   clone_user=new("/d/clone/npc/npc");
   copy_object(clone_user,user);
   destruct(ob);
   destruct(user);
   clone_user->move(environment(me));
   tell_object(me,"��ҵ������Ƴɹ���\n");
   return 1;
}
  