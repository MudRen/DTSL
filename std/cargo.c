// cargo.c

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }


