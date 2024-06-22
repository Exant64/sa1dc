# Sonic Adventure 1 (Dreamcast)
This is a matching decompilation of Sonic Adventure 1 (JP).
Currently it's only set up for building 1ST_READ.bin (the main executable).

# Setup
- Currently only works on WSL, will be moved to use wibo later on
- The splitter requires sh4dis (and python)
```
pip install sh4dis
```
- Obtain Katana 1.00J, and the folders katana/shinobi/include, katana/shc, katana/shinobi/lib
- Put the "include" folder in the repo
- Put the "shc" folder in the repo
- put lib's contents in shc/lib
- Obtain and extract the rom for Sonic Adventure 1 (JP) for the Dreamcast
- Put 1ST_READ.bin in the "rom" folder in the repo
- Run "make setup"

Todo:
- use wibo
