9Key Quadrature Encoder Mod
===

**Modification of the 9Key firmware to allow for Quadrature Encoders by Elisha Shaddock**

![9key_encoder](https://i.imgur.com/fcio7RV.jpg)

Build: Desolder the pull up resisters on the back of your encoder, and attatch CLK, DT, SW, and GND to MCU via the breakout pads on board. Leave VCC/+ disconnected.
Video of process to come, for now, the current bindings are:

1. SW:  B2
2. DT:  B6
3. CLK: B5
4. GND: B1

The encoders pads and button are read as part of the main key matrix as apposed to being read seperately as in the official encoder implementation
This is the layout of the matrix

COL2ROW| COL 1 | COL 2 | COL 3 | COL 4  
:---:|:---:|:---:|:---:|:---:
**ROW 1** | 1 | 2 | 3 | N/A
**ROW 2** | 4 | 5 | 6 | N/A
**ROW 3** | 7 | 8 | 9/FN | N/A
**ROW 4** | N/A | N/A | N/A | SW
**ROW 5** | N/A | N/A | N/A | DT
**ROW 6** | N/A | N/A | N/A | CLK

You can find a short build guide with pictures [HERE](https://imgur.com/gallery/N7z9zTr)

![quad](https://i.imgur.com/FWweDUG.jpg)

---

![9key](http://i.imgur.com/a3wWc7h.jpg)
![9KeyBehind](http://i.imgur.com/2PWf5wu.jpg)

A compact minipad (3x3) keyboard made and sold by Bishop Keyboards.

Keyboard Maintainer: QMK Community  
Hardware Supported: 9key PCB, Pro Micro ATmega32U4  
Hardware Availability: [BishopKeyboards.com](http://bishopkeyboards.com/)

Make example for this keyboard (after setting up your build environment):

    make 9key_encoder:default

See [build environment setup](https://docs.qmk.fm/build_environment_setup.html) then the [make instructions](https://docs.qmk.fm/make_instructions.html) for more information.
