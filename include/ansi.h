//    File    :  /include/ansi.h
//    Creator    :  Gothic@TMI-2
//
//    The standard set of ANSI codes for mudlib use.

#ifndef ANSI_H
#define ANSI_H

#define ESC "\033"           /* Escape ESC(\e) */
#define CSI ESC + "["        /* Control Sequence Introducer */
#define SGR(x) CSI + x + "m" /* Set Graphics Rendition */

/* Foreground Colors 30 ~ 37 */

#define BLK SGR("30") /* 黑 */
#define RED SGR("31") /* 紅 */
#define GRN SGR("32") /* 綠 */
#define YEL SGR("33") /* 黃 */
#define BLU SGR("34") /* 藍 */
#define MAG SGR("35") /* 紫 */
#define CYN SGR("36") /* 青 */
#define WHT SGR("37") /* 白 */

/* Hi Intensity Foreground Colors 90 ~ 97 */

#define GRY SGR("1;30")  /* 灰 */
#define HIR SGR("1;31")  /* 紅 */
#define HIG SGR("1;32")  /* 綠 */
#define HIY SGR("1;33")  /* 黃 */
#define HIB SGR("1;34")  /* 藍 */
#define HIM SGR("1;35")  /* 紫 */
#define HIC SGR("1;36")  /* 青 */
#define HIW SGR("1;37")  /* 白 */

/* Background Colors 40 ~ 47 */

#define BBLK SGR("40") /* 黑 */
#define BRED SGR("41") /* 紅 */
#define BGRN SGR("42") /* 綠 */
#define BYEL SGR("43") /* 黃 */
#define BBLU SGR("44") /* 藍 */
#define BMAG SGR("45") /* 紫 */
#define BCYN SGR("46") /* 青 */
#define BWHT SGR("47") /* 白 */

/* High Intensity Background Colors 100 ~ 107 */

#define HBBLK SGR("1;40") /* 灰 */
#define HBRED SGR("1;41") /* 紅 */
#define HBGRN SGR("1;42") /* 綠 */
#define HBYEL SGR("1;43") /* 黃 */
#define HBBLU SGR("1;44") /* 藍 */
#define HBMAG SGR("1;45") /* 紫 */
#define HBCYN SGR("1;46") /* 青 */
#define HBWHT SGR("1;47") /* 白 */

// #define NOR ESC + "[m"   /* Puts everything back to normal */
#define NOR SGR("0")     /* 清除所有特殊属性 */
#define BOLD SGR("1")    /* Turn on BOLD mode */
#define ITALIC SGR("3")  /* Turn on ITALIC mode */
#define U SGR("4")       /* Initialize underscore mode */
#define BLINK SGR("5")   /* Initialize blink mode */
#define REV SGR("7")     /* Turns reverse video mode on */
#define HIREV SGR("1;7") /* Hi intensity reverse video  */
#define HIDE SGR("8")    /* 消隐(部分客户端不支持) */
#define BOFF SGR("21")   /* BOLD OFF */
#define IOFF SGR("23")   /* ITALIC OFF */
#define UOFF SGR("24")   /* UNDERLINE OFF */
#define ROFF SGR("27")   /* Reverse OFF */

/* Additional ansi Esc codes added to ansi.h by Gothic  april 23,1993 */
/* Note, these are Esc codes for VT100 terminals, and emmulators */
/*          and they may not all work within the mud             */

#define CLR ESC + "[2J"      /* Clear the screen  */
#define HOME ESC + "[H"      /* Send cursor to home position */
#define REF CLR + HOME       /* Clear screen and home cursor */
#define SAVEC ESC + "[s"     /* Save cursor position */
#define REST ESC + "[u"      /* Restore cursor to saved position */
#define FRTOP ESC + "[2;25r" /* Freeze top line */
#define FRBOT ESC + "[1;24r" /* Freeze bottom line */
#define UNFR ESC + "[r"      /* Unfreeze top and bottom lines */
#define REVINDEX ESC + "M"   /* Scroll screen in opposite direction */
#define BIGTOP ESC + "#3"    /* Dbl height characters, top half */
#define BIGBOT ESC + "#4"    /* Dbl height characters, bottem half */
#define SINGW ESC + "#5"     /* Normal, single-width characters */
#define DBL ESC + "#6"       /* Creates double-width characters */

#define BEEP "\07" /* Beep Sound BEL(\a) */

#endif
