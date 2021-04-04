# nathanielevan's build of dwm

[dwm](https://dwm.suckless.org/) is a dynamic window manager for X by [suckless](https://suckless.org). This repository hosts nathanielevan's dwm configuration, including a selection of patches hosted in [the suckless website](https://dwm.suckless.org/patches/) to make it usable. 

Included in this build:
- Colour configuration based on the Nord colour scheme
- [Actual full screen patch](https://dwm.suckless.org/patches/actualfullscreen)
- [Always center patch](https://dwm.suckless.org/patches/alwayscenter)
- [Autostart patch](https://dwm.suckless.org/patches/autostart)
- [Fix borders patch](https://dwm.suckless.org/patches/alpha)
- [Focus on click patch](https://dwm.suckless.org/patches/focusonclick)
- [Fake signals patch](https://dwm.suckless.org/patches/fsignal)
- [Full gaps toggle patch](https://dwm.suckless.org/patches/fullgaps)
- [Per tag patch](https://dwm.suckless.org/patches/pertag)
- [Push up/down patch](https://dwm.suckless.org/patches/push)
- [Status on all monitors patch](https://dwm.suckless.org/patches/statusallmons)
- [Status padding patch](https://dwm.suckless.org/patches/statuspadding)
- [Systray patch](https://dwm.suckless.org/patches/systray)
  * Includes personal modification to add vertical padding for systray icons, see commit [945bc3a](https://github.com/nathanielevan/dwm/commit/945bc3ae8ff42de9fe9614527e85bf391a921693)
- [Urgent border patch](https://dwm.suckless.org/patches/urgentborder)

Keybinds:
- Super+d to launch dmenu_run.
- Super+Shift+Enter to spawn a terminal window.
- Super+{1-9} to go to tag ("workspace") 1-9.
- Super+Shift+{1-9} to move a window to tag ("workspace") 1-9.
- Super+j/k to move focus down/up the window stack.
- Super+Shift+j/k to move a window down/up the window stack.
- Super+Enter to set a window as the master window.
- Super+Shift+q to close a window.
- and many more, check out [config.def.h](config.def.h) for the complete configuration.
