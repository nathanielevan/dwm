/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 12, .gappx = 12};
static const unsigned int snap      = 0;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 10;   /* systray right side spacing */
static const unsigned int iconspacing = 4;      /* systray icon spacing */
static const unsigned int trayiconsize = 16;   /* tray icon size */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int focusonwheel       = 0;
static const int horizpadbar        = 4;        /* horizontal padding for statusbar */
static const int vertpadbar         = 6;        /* vertical padding for statusbar */
// static const char *fonts[]          = { "FantasqueSansMono Nerd Font:pixelsize=15:antialias=true:autohint=true" };
// static const char *fonts[]          = { "FuraMono Nerd Font:pixelsize=14:antialias=true:autohint=true" };
// static const char *fonts[]          = { "InconsolataLGC Nerd Font:pixelsize=14:antialias=true:autohint=true" };
// static const char *fonts[]          = { "Input Nerd Font:pixelsize=14:antialias=true:autohint=true" };
static const char *fonts[]          = { "Iosevka Nerd Font:pixelsize=15:antialias=true:autohint=true" };
// static const char *fonts[]          = { "JetBrainsMono Nerd Font:pixelsize=14:antialias=true:autohint=true" };
// static const char *fonts[]          = { "JuliaMono Nerd Font:pixelsize=14:antialias=true:autohint=true" };
// static const char *fonts[]          = { "MesloLGM Nerd Font:pixelsize=14:antialias=true:autohint=true" };
// static const char *fonts[]          = { "mononoki Nerd Font:pixelsize=15:antialias=true:autohint=true" };
// static const char *fonts[]          = { "NotoSansMono Nerd Font:pixelsize=14:antialias=true:autohint=true" };
// static const char *fonts[]          = { "VictorMono Nerd Font:pixelsize=15:antialias=true:autohint=true" };
static const char dmenufont[]       = "Iosevka Nerd Font:pixelsize=15:antialias=true:autohint=true";
static const char dmenuprompt[]     = "run:";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { "#d4be98", "#282828", "#45403d" },
	[SchemeSel]  = { "#282828", "#d8a657", "#d8a657" },
	[SchemeUrg]  = { "#282828", "#ea6962", "#ea6962" },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  iscentered  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           0,         0,          1,          0,           0,        -1 },
	{ "firefox", NULL,     NULL,           0,         0,          0,          0,          -1,        -1 },
	{ "st-256color", NULL, NULL,           0,         0,          0,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 1;    /* 1 means respect decoration hints */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-p", dmenuprompt, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *j4dmenucmd[] = { "j4-dmenu-desktop", "--dmenu", "dmenu -i -r -p \"drun:\"", "--term", "st", "--no-generic", NULL };
// static const char *rofidruncmd[] = { "rofi", "-show", "drun", "-modi", "drun,run,window,ssh", NULL };
// static const char *rofiruncmd[] = { "rofi", "-show", "run", "-modi", "drun,run,window,ssh", NULL };
// static const char *rofiwincmd[] = { "rofi", "-show", "window", "-modi", "drun,run,window,ssh", NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = j4dmenucmd } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      pushdown,       {0} },
	{ MODKEY|ShiftMask,             XK_k,      pushup,         {0} },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_e,      spawn,          SHCMD("powermenu") },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD("setmonitor-dmenu") },
	{ 0, XF86XK_MonBrightnessUp,    spawn,                     SHCMD("light -A 5") },
	{ 0, XF86XK_MonBrightnessDown,  spawn,                     SHCMD("light -U 5") },
	{ 0,                            XK_Print,  spawn,          SHCMD("screenshot-full") },
	{ ShiftMask,                    XK_Print,  spawn,          SHCMD("screenshot-sel") },
	{ 0, XF86XK_AudioRaiseVolume,   spawn,                     SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%; pkill -RTMIN+10 dwmblocks") },
	{ 0, XF86XK_AudioLowerVolume,   spawn,                     SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%; pkill -RTMIN+10 dwmblocks") },
	{ 0, XF86XK_AudioMute,          spawn,                     SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle; pkill -RTMIN+10 dwmblocks") },
	{ 0, XF86XK_AudioMicMute,       spawn,                     SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle; pkill -RTMIN+10 dwmblocks") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signum>"` */
static Signal signals[] = {
	/* signum       function        argument  */
	{ 1,            quit,      {0} },
};
