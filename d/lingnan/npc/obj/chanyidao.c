
//Edit By Subzero
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(BLU"天刀"NOR, ({ "tian dao","blade","dao" }) );
   set_weight(40000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("no_save",1);
     set("rumor",1);
     set("super",5);
     set("value", 500000000);
     set("material", "iron");
     set("no_sell", 1);
     set("long", BLU"什么刀，可以让人握在手中，顿生无限豪气？什么刀，在其主人的手中\n"+
                    "从未逢一败？什么刀，可以傲视天下敢与天平齐？那就是武林中绝顶高\n"+
                    "手天刀宋缺所用的—天刀！此刀来历不详，传闻甚多，在天刀宋缺刀法\n"+
                    "大成后出现，有人疑为宋缺自己打造，也有人从此刀重达百斤、朴实黝\n"+
                    "黑外表推断此刀应为上古宝物。无论如何，集厚脊，薄身，钝头，利刃，\n"+
                    "于一身的宝刀，环视武林除少帅寇仲的宝刀井中月堪于相比外，只此一\n把而已。\n"NOR);
     set("wield_msg", BLU"$N"+BLU+"悠闲地把收在身后的左手移往胸前，手内赫然握有另一把造型高古、\n沉重异常的连鞘宝刀，淡淡一笑右手把宝刀从鞘内拔出。\n"NOR);
     set("unequip_msg", HIC"$N"+HIC+"嘴角逸出一丝笑意，立即把$n"+HIC+"冷酷的神情和眼中的杀气溶解，\n随即还刀入鞘。\n"NOR);
   }
   init_blade(200,200,200);
   setup();
}
