/***
提取玩家的档案。将玩家档案复制到NPC身上，然后
移动到巫师身边。
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
   return notify_fail("请使用 load id 格式.\n");
   ob=new(LOGIN_OB);
   ob->set("id",id); 
   if(!ob->restore())
   return notify_fail("提取档案失败！\n");
   user=LOGIN_D->make_body(ob);
   if(!user)
   return notify_fail("提取档案失败！\n");
   if(!user->restore())
   return notify_fail("提取档案失败！\n");
   clone_user=new("/d/clone/npc/npc");
   copy_object(clone_user,user);
   destruct(ob);
   destruct(user);
   clone_user->move(environment(me));
   tell_object(me,"玩家档案复制成功！\n");
   return 1;
}
  