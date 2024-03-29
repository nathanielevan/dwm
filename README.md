# nathanielevan's build of dwm

[dwm](https://dwm.suckless.org/) is a dynamic window manager for X by [suckless](https://suckless.org). This repository hosts nathanielevan's dwm configuration, including a selection of patches hosted in [the suckless website](https://dwm.suckless.org/patches/) to make it usable.

Included in this build:
- Personal colour configuration
- [Actual full screen patch](https://dwm.suckless.org/patches/actualfullscreen)
- [Autostart patch](https://dwm.suckless.org/patches/autostart)
- [Center patch](https://dwm.suckless.org/patches/center)
- [Decoration hints patch](https://dwm.suckless.org/patches/decoration_hints/)
- [Fix borders patch](https://dwm.suckless.org/patches/alpha)
- [Focus on click patch](https://dwm.suckless.org/patches/focusonclick)
- [Fake signals patch](https://dwm.suckless.org/patches/fsignal)
- [Full gaps toggle patch](https://dwm.suckless.org/patches/fullgaps)
- [Per tag patch](https://dwm.suckless.org/patches/pertag)
- [Push up/down patch](https://dwm.suckless.org/patches/push)
- [Status on all monitors patch](https://dwm.suckless.org/patches/statusallmons)
- [Status padding patch](https://dwm.suckless.org/patches/statuspadding)
- [Swallow patch](https://dwm.suckless.org/patches/swallow/)
- [Systray patch](https://dwm.suckless.org/patches/systray)
  * Includes personal modification to set tray icon size
- [Urgent border patch](https://dwm.suckless.org/patches/urgentborder)

Keybinds:
- Super+d to launch j4-dmenu-desktop.
- Super+Shift+d to launch dmenu_run.
- Super+Shift+Enter to spawn a terminal window.
- Super+{1-9} to go to tag ("workspace") 1-9.
- Super+Shift+{1-9} to move a window to tag ("workspace") 1-9.
- Super+j/k to move focus down/up the window stack.
- Super+Shift+j/k to move a window down/up the window stack.
- Super+Enter to set a window as the master window.
- Super+Shift+q to close a window.
- and many more, check out [config.def.h](config.def.h) for the complete configuration.

Dependencies:
- j4-dmenu-desktop (optional)
