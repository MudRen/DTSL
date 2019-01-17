

#include <ansi.h>
#include <combat.h>

void remove_broken_weapon(object ob);

mapping weapon_actions = ([
   "��": ([
     "damage_type":   "����",
     "action":     "$N�Ӷ�$w��ն��$n��$l",
     "parry":     20,
     ]),
   "��": ([
     "damage_type":   "����",
     "action":     "$N��$w��$n��$l��ȥ",
     "dodge":     20,
     ]),
   "��": ([
     "damage_type":   "����",
     "action":     "$N��$w����$n��$l������ȥ",
     "parry":     -20,
     ]),
   "��": ([
     "action":     "$N����$w����׼$n��$lһ���ҿ�",
     "damage_type":   "����",
     "damage":     30,
     "dodge":     30,
     ]),
   "��": ([
     "damage_type":   "����",
     "action":     "$N��$w��$n��$l��ȥ",
     "dodge":     15,
     "parry":     -15,
     ]),
   "��": ([
     "action":     "$N��$w��$n��$l�ݺݵ�һͱ",
     "damage_type":   "����",
     "dodge":     -30,
     "parry":     -30,
     ]),
   "��": ([
     "action":     "$Nһ��$w����$n��$lһ��",
     "damage_type":   "����",
     "dodge":     -20,
     "parry":     30,
     ]),
   "��": ([
     "action":     "$N��$wһ���$n��$l��ȥ",
     "damage_type":   "����",
     "dodge":     -20,
     "parry":     30,
     ]),
   "impale": ([
     "action":     "$N��$w��$n��$lֱ����ȥ",
     "damage_type":   "����",
     "dodge":     -10,
     "parry":     -10,
     ]),
   "rake": ([
     "action":     "$N�߾�$w����$n��$l����һ��",
     "damage_type":   "����",
     "dodge":     -15,
     "parry":     15,
     ]),
   "��": ([
     "action":     "$Nһ�����������$w������$n��$l����һ��",
     "damage_type":   "����",
     "dodge":     -10,
     "parry":     -10,
     ]),
   "��": ([
     "action":     "$N����$w����$n��$l����һ��",
     "damage_type":   "����",
     //"post_action":   (: call_other, __FILE__, "bash_weapon" :),
     ]),
   "��": ([
     "action":     "$N�߸߾���$w����$n��$l��ͷ����",
     "damage_type":   "����",
     //"post_action":   (: call_other, __FILE__, "bash_weapon" :),
     ]),
   "��": ([
     "action":     "$N����$w���͵ض�׼$n��$l���˹�ȥ",
     "damage_type":   "����",
     //"post_action":   (: call_other, __FILE__, "bash_weapon" :),
     ]),
   "��": ([
     "action":     "$N��$w��׼$n��$l���˹�ȥ",
     "damage_type":   "����",
     "post_action":   (: call_other, __FILE__, "throw_weapon" :),
     ]),
   "��": ([
     "action":     "$N�乭�����ֻ����ಡ���һ����$w�ѵ�$n��$l",
     "damage_type":   "����",
     "post_action":   (: call_other, __FILE__, "throw_weapon" :),
     ]),
]);

varargs mapping query_action(object weapon)
{
   string verb, *verbs;
//   object me, wp1, wp2;

   verbs = weapon->query("verbs");

   // 4/27/98 mon changed following 4 "hit" to "impale"
   // as "hit" is not defined in weapon_actions.
   if( !pointerp(verbs) ) return weapon_actions["impale"];
   else {
     verb = verbs[random(sizeof(verbs))];
     if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
     else return weapon_actions["impale"];
   }   
}

varargs mapping query_apply_action()
{
   string verb, *verbs;
//   object me, wp1, wp2;

   verbs = previous_object()->query("apply/verbs");

   if( !pointerp(verbs) ) return weapon_actions["impale"];
   else {
     verb = verbs[random(sizeof(verbs))];
     if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
     else return weapon_actions["impale"];
   }   
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
   if( objectp(weapon) ) {
     if( (int)weapon->query_amount()==1 ) {
        weapon->unequip();
        tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n\n");
     }
     weapon->add_amount(-1);
   }
}

void bash_weapon(object me, object victim, object weapon, int damage)
{
   object ob;
   int wap, wdp;

   if( objectp(weapon)
   &&   damage==RESULT_PARRY
   &&   ob = victim->query_temp("weapon") ) {
     wap = (int)weapon->weight() / 500
        + (int)weapon->query("rigidity")
        + (int)me->query("str");
     wdp = (int)ob->weight() / 500
        + (int)ob->query("rigidity")
        + (int)victim->query("str");
     wap = random(wap);
     if( wap > 2 * wdp ) {
        message_vision(HIW "$Nֻ��������" + ob->name() + "�ѳֲ��������ַɳ���\n" NOR,
          victim);
        ob->unequip();
        ob->move(environment(victim));
        victim->reset_action();
     } else if( wap > wdp ) {
        message_vision("$Nֻ��������" + ob->name() + "һ����Щ���֣�\n",
          victim);
     } else if( wap > wdp / 2 ) {
        message_vision(HIW "ֻ������ž����һ����$N���е�" + ob->name()
          + "�Ѿ���Ϊ���أ�\n" NOR, victim );
        ob->unequip();
        ob->move(environment(victim));
        ob->set("name", "�ϵ���" + ob->query("name"));
        //ob->set("value", (int)ob->query("value") / 20);
        ob->set("value", 0);
        //so can't sell broken weapon.
        //otherwise may have problem in pawn shop
        //when the broken weapon disappeared.
        ob->set("weapon_prop", 0);
        ob->set("armor_prop", 0);
        call_out("remove_broken_weapon",
          random(300)+60,ob);
                        //added by mon 10/27/97
        victim->reset_action();
     } else {
        message_vision("$N��" + weapon->name() + "��$n��" + ob->name()
          + "�����ð�����Ļ��ǡ�\n", me, victim);
     }
   }
}

void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "һ��΢�紵����"+ob->name()+"��ΪƬƬ��������ʧ�����ˡ�\n");
    destruct(ob);
  }
}
int weapon_fracture(object weapon)
{
 if(weapon->query("flag")) return 1;
  weapon->set("flag",1);
  weapon->set("org_name",weapon->name());
  weapon->set("name","�ϵ���"+weapon->name());
  return 1;
  
}

int poison_bash(object ob,object victim)
{
  string name,id;
  int damage,last;
  if(!this_object()->query("poison"))
  return 1;
  
  name=this_object()->query("poison/name");
  id=this_object()->query("poison/id");
  damage=this_object()->query("poison/damage");
  last=this_object()->query("poison/last");
  message_vision("$N������$n"+this_object()->query("name")+"�ϵ�"+name+"����\n",victim,ob);
  victim->apply_condition("poison_sys",last);
  return 1;
}
