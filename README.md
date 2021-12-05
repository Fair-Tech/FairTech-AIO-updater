# FairTech-AIO-Updater
[Releases](https://github.com/Fair-Tech/FairTech-AIO-updater/releases)


<p align="center">
<img src = "https://fairtech.us/updater_logo.jpg"\><br>
</p>

A Nintendo Switch homebrew app to download and update CFWs, sigpatches, FWs and cheat codes. Supports FairTech AIO Custom Firmware Package.

Works on **unpatched**(Erista) and **patched**(v2/Mariko) Switches.

## How to install
Copy the `FairTech-AIO-Updater/` directory to `/switch/` on your sdcard.

## Description of the features
### ⬦ Update CFW
- Download the most popular Switch CFWs. After downloading the CFW archive, the program will ask you whether you want to override your existing .ini files. 
  - If you would like to preserve additional files or directories, write their path (one line each) in `/config/aio-switch-updater/preserve.txt` and they won't be overwritten when updating.
  - Place [this file](https://github.com/Fair-Tech/FairTech-AIO-updater/blob/master/copy_files.txt) in `/config/aio-switch-updater/copy_files.txt` in order to have specific copy operations performed after each download. This is mainly meant for users with trinkets who want payloads automatically copied to a directory.
  - A custom Atmosphère url can be entered in [this file](https://github.com/Fair-Tech/FairTech-AIO-updater/blob/master/customPacks.json) and it will show on the `Update Atmopshère` menu. This can be used to support third-party packs through aio-switch-updater

### ⬦ Update Sigpatches
- For Atmosphère. Downloads sigpatches, which are patches required for launching unofficial .NSPs. Both AMS and Hekate+AMS sigpatches are available.

### ⬦ Download firmwares
- Download firmware files to `/firmware` that can then be installed using DayBreak.

### ⬦ Download cheats
- Downloads and extracts daily-updated cheat code. The program will only extract cheat codes for the games you own. By default, this homebrew will overwrite the existing cheats. If you have your own cheat files that you'd like to keep as is, you can turn off cheat updates for specific titles in `Tools->Cheat Menu`.
- Since v2.0.0, aio-switch-updater can also download cheat sheets from [`CheatSlips.com`](https://www.cheatslips.com/). 
- Since v2.6.0, aio-switch-updater can also download individual cheat codes from the GBAtemp database.

## Extras (in the `Tools` tab)
- Reboot to specific payload.
- Download payloads to `/bootloader/payloads`.
- Change software color scheme of Joy-Cons. Additional color profiles can be found in the releases and should be copied to `config/aio-switch-updater/jc_profiles.json`. Use [this webpage](https://hamletdufromage.github.io/JC-color-picker/JCpicker.html) to generate your own profiles.
- Change software color scheme of Pro Controllers (has to be paired as Player 1). Additional color profiles can be found in the releases and should be copied to `config/FairTech-AIO-Updater/pc_profiles.json`.
- Consult installed cheat codes.
- Launch the Switch's web browser.
- Edit internet settings (DNS, IP address, MTU, etc). Add you own configs to `config/aio-switch-updater/internet.json`. You can find a template in the root of the repo.
- Tabs can be hidden through the `Hide tabs` menu, and more entries can be hidden by manually editing [`config/FairTech-AIO-Updater/hide_tabs.json`](https://github.com/Fair-Tech/FairTech-AIO-updater/blob/master/hide_tabs.json).

## Screenshots
<details><summary>Expand to view the screenshots</summary>

![update_ams](https://user-images.githubusercontent.com/61667930/125843308-94666f64-c538-465f-88b1-10dbc1e2024e.jpg)
![deepsea_builder](https://user-images.githubusercontent.com/61667930/125843328-829d9e92-617a-4a92-b85f-2f2abd096f5f.jpg)
![downloading](https://user-images.githubusercontent.com/61667930/125843333-e18faf45-6034-4dfa-841b-3e20259e4dc9.jpg)
![get_cheats](https://user-images.githubusercontent.com/61667930/125843305-4f1b4a91-f182-4e15-9d5b-af0e2ec7fd9e.jpg)
![get_individual_cheat](https://user-images.githubusercontent.com/61667930/125843316-0527d3f2-5b6e-42da-83ef-0f8e67646eb3.jpg)
![tools_menu](https://user-images.githubusercontent.com/61667930/125843312-394cc38e-de75-4f71-942d-9d38d3d37b29.jpg)
![joycon_color_swapper](https://user-images.githubusercontent.com/61667930/125843319-c81d372e-58dc-432b-8f8c-828f768ae817.jpg)

</details>

## Build

<details><summary>Expand to view the build instructions</summary>

You need to have installed devkitPro and devkitARM in order to compile this project.

Install the required dependencies:
```bash
$ sudo (dkp-)pacman -Sy
```
```bash
$ sudo (dkp-)pacman -S  switch-glfw \
                        switch-curl \
                        switch-glm \
                        switch-mbedtls \
                        switch-zlib
```
Use [`switch-ex-curl`](https://github.com/eXhumer/switch-ex-curl) instead of `switch-curl` to use this app with an invalid SSL certificate.

Clone the repository
```bash
$ git clone --recursive https://github.com/Fair-Tech/FairTech-AIO-Updater
$ cd FairTech-AIO-Updater
```

Compile 
```bash
$ cd aiosu-forwarder
$ make
$ cd ..
$ make
```

</details>

## Contribute

PRs and suggestions are encouraged! If you wish to help with the localization of the app, you can translate the files in `resources/i18n/`. To easily find the non-translated strings and translate them, you may use `localizer.py` (e.g. `python localizer.py -r resources//i18n//en-US//menus.json -w resources//i18n//fr//menus.json`).

## Disclaimer
I do not own, host nor distribute any of the files that can be downloaded with this homebrew tool. At the owner's request, I will immediately remove the ability to download any problematic file.

## Special thanks
- [natinusala](https://github.com/natinusala) for the Borealis library.
- [tiansongyu](https://github.com/tiansongyu) for bringing support for multi-language and for his Chinese translation.
- [yyoossk](https://github.com/yyoossk) for the Japanese locale.
- [sergiou87](https://github.com/sergiou87) for the Spanish locale.
- [pedruhb](https://github.com/pedruhb) for the Brazilian locale.
- [AD2076](https://github.com/AD2076) for the Italian locale.
- [qazrfv1234](https://github.com/qazrfv1234) for the Traditional Chinese locale.
- [Team Neptune](https://github.com/Team-Neptune) whose rcm code I used.
- [fennectech](https://github.com/fennectech) for helping test the app and providing suggestions.
- [HamletDuFromage](https://github.com/HamletDuFromage) for creating the app that this was forked from.
- Iliak for cheatslips.com.

### Like the app?
Donations are never expected, but always appreciated! You can support me via [CashApp](https://cash.app/$FairTech1) or [PayPal](https://www.paypal.com/paypalme/NicholasFair1). 

<img src="images/cashappqr.jpg" width="300" />  <img src="images/paypalqr.jpg" width ="300" /> 
